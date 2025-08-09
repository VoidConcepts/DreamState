#include "ProjectAssetEnforcer.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"
#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Editor.h"
#include "Misc/ScopedSlowTask.h"
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY(LogProjectAssetEnforcer);

void UProjectAssetEnforcer::ProcessChangedFilesFromRepoDiff(bool bDryRun)
{
    // We'll call your existing CheckChangedFilesFromRepoDiff to gather changed files (relative paths)
    TArray<FString> ChangedFiles;
    CheckChangedFilesFromRepoDiff(ChangedFiles, false);

    InitializeStatusHandlers();

    FString ProjectDir = FPaths::GetPath(FPaths::GetProjectFilePath());

    for (const FString& RelativePath : ChangedFiles)
    {
        // Git returns lines like "A\tSource/Module/Public/MyActor.h" or "R100\told.h\tnew.h"
        // Your original parsing produced RelativePath already, but CheckChangedFilesFromRepoDiff must also return status letter.
        // If not, we should re-run ExecProcess and parse per-line with status included.

        // For compatibility with your previous function, re-run the git and parse status lines here.
        // Simpler: call ExecProcess once and parse - below is a small re-parse approach:
        // But to keep this method single-responsibility, we assume ChangedFiles is just lines like "<status>\t<path>" for now.

        FString Line = RelativePath;
        FString FileStatusIndicator, LeftPath, RightPath;
        Line.Split(TEXT("\t"), &FileStatusIndicator, &LeftPath);

        // If rename, there will be two tabs: "R100\toldpath\tnewpath"
        TArray<FString> Tokens;
        Line.ParseIntoArray(Tokens, TEXT("\t"), true);

        TCHAR StatusLetter = FileStatusIndicator.IsEmpty() ? TCHAR('\0') : FileStatusIndicator[0];

        // map
        EFileStatus Status = EFileStatus::Unknown;
        switch (StatusLetter)
        {
        case 'A': Status = EFileStatus::Added; break;
        case 'M': Status = EFileStatus::Modified; break;
        case 'D': Status = EFileStatus::Deleted; break;
        case 'R': Status = EFileStatus::Renamed; break;
        case 'C': Status = EFileStatus::Copied; break;
        case 'U': Status = EFileStatus::Unmerged; break;
        case 'X': Status = EFileStatus::Unknown; break;
        case 'B': Status = EFileStatus::Broken; break;
        default: Status = EFileStatus::UntrackedOrUnmodified; break;
        }

        // derive paths
        FString OldRel, NewRel;
        FString OldFull, NewFull;

        if (Status == EFileStatus::Renamed && Tokens.Num() >= 3)
        {
            OldRel = Tokens[1];
            NewRel = Tokens[2];
            OldFull = FPaths::Combine(ProjectDir, OldRel);
            NewFull = FPaths::Combine(ProjectDir, NewRel);
            DispatchStatus(Status, NewRel, NewFull, OldRel); // pass old -> new
        }
        else
        {
            // Tokens[1] is path for A/M/C...
            if (Tokens.Num() >= 2)
            {
                FString Rel = Tokens[1];
                FString Full = FPaths::Combine(ProjectDir, Rel);
                DispatchStatus(Status, Rel, Full, TEXT(""));
            }
            else
            {
                // fallback: skip noisy line
                UE_LOG(LogProjectAssetEnforcer, Warning, TEXT("Unparsable git diff line: %s"), *Line);
            }
        }
    }
}

void UProjectAssetEnforcer::InitializeStatusHandlers()
{
    // bind handlers (signature: Rel, Full, OldRel, bDryRun)
    StatusHandlers.Add(EFileStatus::Added,
        [this](const FString& Rel, const FString& Full, const FString& OldRel, bool bDryRun)
        {
            HandleAddedFile(Rel, Full, bDryRun);
        });

    StatusHandlers.Add(EFileStatus::Modified,
        [this](const FString& Rel, const FString& Full, const FString& OldRel, bool bDryRun)
        {
            HandleModifiedFile(Rel, Full, bDryRun);
        });

    StatusHandlers.Add(EFileStatus::Renamed,
        [this](const FString& Rel, const FString& Full, const FString& OldRel, bool bDryRun)
        {
            // OldRel contains old relative path when renamed
            HandleRenamedFile(OldRel, Rel, Full, bDryRun);
        });

    StatusHandlers.Add(EFileStatus::Copied,
        [this](const FString& Rel, const FString& Full, const FString& OldRel, bool bDryRun)
        {
            HandleCopiedFile(Rel, Full, bDryRun);
        });

    // Add other handlers as necessary (Deleted / Unmerged / Unknown) to log or flag for manual work
    StatusHandlers.Add(EFileStatus::Deleted,
        [this](const FString& Rel, const FString& Full, const FString& OldRel, bool bDryRun)
        {
            UE_LOG(LogProjectAssetEnforcer, Log, TEXT("Deleted: %s"), *Rel);
            // TODO: Consider cleaning up orphan BPs or keeping redirector logic
        });

    StatusHandlers.Add(EFileStatus::Unknown,
        [this](const FString& Rel, const FString& Full, const FString& OldRel, bool bDryRun)
        {
            UE_LOG(LogProjectAssetEnforcer, Warning, TEXT("Unknown status for: %s"), *Rel);
        });
}

void UProjectAssetEnforcer::DispatchStatus(EFileStatus Status, const FString& RelativePath, const FString& FullPath, const FString& OptionalOldPath)
{
    bool bDryRun = true; // default; consider passing in args into Process method
    if (StatusHandlers.Contains(Status))
    {
        StatusHandlers[Status](RelativePath, FullPath, OptionalOldPath, bDryRun);
    }
    else
    {
        UE_LOG(LogProjectAssetEnforcer, Warning, TEXT("No handler for status: %d %s"), (int)Status, *RelativePath);
    }
}

/* ---------- Handlers ---------- */

void UProjectAssetEnforcer::HandleAddedFile(const FString& RelativePath, const FString& FullPath, bool bDryRun)
{
    UE_LOG(LogProjectAssetEnforcer, Log, TEXT("[A] HandleAddedFile: %s"), *RelativePath);

    // 1) quick parse header and attempt to locate UCLASS() metadata
    FString ExistingUUID;
    bool bHasUUID = HeaderContainsUUID(FullPath, ExistingUUID);

    if (bHasUUID)
    {
        UE_LOG(LogProjectAssetEnforcer, Log, TEXT("Header already contains UUID: %s"), *ExistingUUID);
    }
    else
    {
        // 2) generate UUID and insert in header (but only if not dry-run)
        FString NewUUID = GenerateUUIDString();
        UE_LOG(LogProjectAssetEnforcer, Log, TEXT("Generated UUID %s for %s"), *NewUUID, *RelativePath);

        FString NewText;
        bool bInsertOk = InsertUUIDIntoHeader(FullPath, NewUUID, NewText);
        if (!bInsertOk)
        {
            UE_LOG(LogProjectAssetEnforcer, Error, TEXT("Failed to insert UUID into header: %s"), *FullPath);
            return;
        }

        if (bDryRun)
        {
            UE_LOG(LogProjectAssetEnforcer, Log, TEXT("[DryRun] Would write updated header for: %s"), *RelativePath);
        }
        else
        {
            FString BackupPath;
            if (AtomicWriteFile(FullPath, NewText, BackupPath))
            {
                UE_LOG(LogProjectAssetEnforcer, Log, TEXT("Wrote header and backed up original to: %s"), *BackupPath);
                // TODO: stage & commit to branch if desired
            }
            else
            {
                UE_LOG(LogProjectAssetEnforcer, Error, TEXT("Atomic write failed for header: %s"), *FullPath);
                return;
            }
        }
    }

    // 3) Determine blueprint name, prefix, target directory
    // TODO: Implement naming rules. Example:
    FString BlueprintName = FString::Printf(TEXT("BP_%s"), *FPaths::GetBaseFilename(RelativePath));
    FString TargetPackagePath = FString::Printf(TEXT("/Game/%s"), *FPaths::GetPath(RelativePath)); // adjust mirror rules

    UE_LOG(LogProjectAssetEnforcer, Log, TEXT("Blueprint target: %s (package: %s)"), *BlueprintName, *TargetPackagePath);

    if (bDryRun)
    {
        UE_LOG(LogProjectAssetEnforcer, Log, TEXT("[DryRun] Would create blueprint %s in %s"), *BlueprintName, *TargetPackagePath);
    }
    else
    {
        // Use FKismetEditorUtilities::CreateBlueprint to create blueprint that inherits from new UClass
        // Example pseudo:
        // UClass* NativeClass = LoadClass<UObject>(nullptr, *FString::Printf(TEXT("...path to class...")));
        // UBlueprint* NewBP = FKismetEditorUtilities::CreateBlueprint(NativeClass, Package, FName(*BlueprintName), BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass());
        // Then set asset tags with UUID via AssetRegistry
    }
}

void UProjectAssetEnforcer::HandleModifiedFile(const FString& RelativePath, const FString& FullPath, bool bDryRun)
{
    UE_LOG(LogProjectAssetEnforcer, Log, TEXT("[M] HandleModifiedFile: %s"), *RelativePath);

    // Default: skip. If header lost UUID or meta changed, repair.
    FString ExistingUUID;
    if (!HeaderContainsUUID(FullPath, ExistingUUID))
    {
        UE_LOG(LogProjectAssetEnforcer, Warning, TEXT("Modified header missing UUID; treating as Added for repair: %s"), *RelativePath);
        // reuse added handler logic, pass bDryRun flag
        HandleAddedFile(RelativePath, FullPath, bDryRun);
    }
    else
    {
        UE_LOG(LogProjectAssetEnforcer, Log, TEXT("No action required for modified file: %s"), *RelativePath);
    }
}

void UProjectAssetEnforcer::HandleRenamedFile(const FString& OldRelativePath, const FString& NewRelativePath, const FString& NewFullPath, bool bDryRun)
{
    UE_LOG(LogProjectAssetEnforcer, Log, TEXT("[R] HandleRenamedFile: %s -> %s"), *OldRelativePath, *NewRelativePath);

    // 1) If we can obtain the old header's UUID, use it as pivot to find Blueprints
    FString ProjectDir = FPaths::GetPath(FPaths::GetProjectFilePath());
    FString OldFull = FPaths::Combine(ProjectDir, OldRelativePath);

    FString OldUUID;
    if (!HeaderContainsUUID(OldFull, OldUUID))
    {
        UE_LOG(LogProjectAssetEnforcer, Warning, TEXT("Old header missing UUID (fallback): %s"), *OldRelativePath);
        // Option: parse mapping JSON to lookup old -> uuid
    }

    FString NewUUID;
    bool bNewHasUUID = HeaderContainsUUID(NewFullPath, NewUUID);
    if (!bNewHasUUID && !OldUUID.IsEmpty())
    {
        // propagate old UUID to new header (move)
        FString NewText;
        if (InsertUUIDIntoHeader(NewFullPath, OldUUID, NewText))
        {
            if (bDryRun)
            {
                UE_LOG(LogProjectAssetEnforcer, Log, TEXT("[DryRun] Would copy UUID %s to new header %s"), *OldUUID, *NewRelativePath);
            }
            else
            {
                FString Backup;
                if (AtomicWriteFile(NewFullPath, NewText, Backup))
                {
                    UE_LOG(LogProjectAssetEnforcer, Log, TEXT("Wrote UUID to new header and backed up original: %s"), *Backup);
                }
            }
        }
    }

    // 2) Reparent Blueprints: query Asset Registry by UUID metadata and update ParentClass
    if (!OldUUID.IsEmpty())
    {
        if (bDryRun)
        {
            UE_LOG(LogProjectAssetEnforcer, Log, TEXT("[DryRun] Would search AssetRegistry for Blueprints with UUID %s and reparent them to the new class"), *OldUUID);
        }
        else
        {
            // Example:
            // FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
            // FARFilter Filter; // configure to find assets with metadata tag "CoveGUID" == OldUUID
            // AssetRegistryModule.Get().GetAssets(Filter, OutAssets);
            // For each asset: use FKismetEditorUtilities::ChangeBlueprintParent()
        }
    }
}

void UProjectAssetEnforcer::HandleCopiedFile(const FString& RelativePath, const FString& FullPath, bool bDryRun)
{
    UE_LOG(LogProjectAssetEnforcer, Log, TEXT("[C] HandleCopiedFile: %s"), *RelativePath);

    // If the header contains the same UUID as an existing class, we should generate a new UUID and treat as added
    FString ExistingUUID;
    if (HeaderContainsUUID(FullPath, ExistingUUID))
    {
        // Check for collision (other classes with same UUID)
        // TODO: implement check across mapping JSON or scan headers
        bool bCollision = false; // placeholder - implement detection
        if (bCollision)
        {
            FString NewUUID = GenerateUUIDString();
            FString NewText;
            if (InsertUUIDIntoHeader(FullPath, NewUUID, NewText))
            {
                if (bDryRun)
                {
                    UE_LOG(LogProjectAssetEnforcer, Log, TEXT("[DryRun] Would replace duplicated UUID %s with %s in %s"), *ExistingUUID, *NewUUID, *RelativePath);
                }
                else
                {
                    FString Backup;
                    if (AtomicWriteFile(FullPath, NewText, Backup))
                    {
                        UE_LOG(LogProjectAssetEnforcer, Log, TEXT("Inserted new UUID into copied header: %s"), *FullPath);
                    }
                }
            }
        }
        else
        {
            UE_LOG(LogProjectAssetEnforcer, Log, TEXT("Copied file has unique UUID; no collison: %s"), *ExistingUUID);
        }
    }
    else
    {
        // No UUID: treat as Added
        HandleAddedFile(RelativePath, FullPath, bDryRun);
    }
}

/* ---------- Utilities ---------- */

FString UProjectAssetEnforcer::GenerateUUIDString() const
{
    FGuid NewGuid = FGuid::NewGuid();
    FString GuidStr = NewGuid.ToString(EGuidFormats::DigitsWithHyphens); // e.g. 01234567-89ab-cdef-0123-456789abcdef
    return GuidStr;
}

bool UProjectAssetEnforcer::AtomicWriteFile(const FString& FilePath, const FString& NewContents, FString& OutBackupPath) const
{
    // Write temp file
    FString TempPath = FilePath + TEXT(".tmp");
    if (!FFileHelper::SaveStringToFile(NewContents, *TempPath))
    {
        UE_LOG(LogProjectAssetEnforcer, Error, TEXT("Failed to write temp file: %s"), *TempPath);
        return false;
    }

    // Backup original
    FString BackupPath = FilePath + TEXT(".bak");
    if (!IFileManager::Get().Move(*BackupPath, *FilePath))
    {
        // If Move fails, try copy and delete
        if (!IFileManager::Get().Copy(*BackupPath, *FilePath))
        {
            UE_LOG(LogProjectAssetEnforcer, Warning, TEXT("Could not backup original file; continuing: %s"), *FilePath);
            // continue anyway
        }
        else
        {
            IFileManager::Get().Delete(*FilePath);
        }
    }

    // Move temp to original
    if (!IFileManager::Get().Move(*FilePath, *TempPath))
    {
        UE_LOG(LogProjectAssetEnforcer, Error, TEXT("Failed to replace original with temp file: %s -> %s"), *TempPath, *FilePath);
        return false;
    }

    OutBackupPath = BackupPath;
    return true;
}

bool UProjectAssetEnforcer::HeaderContainsUUID(const FString& FilePath, FString& OutUUID) const
{
    if (!FPaths::FileExists(FilePath))
    {
        return false;
    }
    FString Content;
    if (!FFileHelper::LoadFileToString(Content, *FilePath))
    {
        return false;
    }

    // Conservative search: look for CoveGUID or CoveGuid or Cove_GUID etc.
    // Pattern: CoveGUID="xxxx-xxxx-..."
    int32 Pos = INDEX_NONE;
    if (Content.FindChar(TEXT('C'), Pos)) // quick gate
    {
        // Look for CoveGUID=
        int32 Start = Content.Find(TEXT("CoveGUID"), ESearchCase::IgnoreCase, ESearchDir::FromStart);
        if (Start != INDEX_NONE)
        {
            int32 Quote = Content.Find(TEXT("\""), ESearchCase::IgnoreCase, ESearchDir::FromStart);
            // Simpler: regex-like parse
            const FString Pattern = TEXT("CoveGUID=\"");
            int32 P = Content.Find(Pattern, ESearchCase::IgnoreCase, ESearchDir::FromStart);
            if (P != INDEX_NONE)
            {
                int32 UUIDStart = P + Pattern.Len();
                int32 UUIDEnd = Content.Find(TEXT("\""), ESearchCase::IgnoreCase, ESearchDir::FromStart, UUIDStart);
                if (UUIDEnd != INDEX_NONE)
                {
                    OutUUID = Content.Mid(UUIDStart, UUIDEnd - UUIDStart);
                    return true;
                }
            }
        }
    }

    return false;
}

bool UProjectAssetEnforcer::InsertUUIDIntoHeader(const FString& FilePath, const FString& UUID, FString& OutNewText) const
{
    // Conservative text-based modification:
    // Find UCLASS(...). If meta=(...) exists inside, append CoveGUID="UUID". Otherwise add meta=(CoveGUID="UUID")
    FString Content;
    if (!FFileHelper::LoadFileToString(Content, *FilePath))
    {
        UE_LOG(LogProjectAssetEnforcer, Error, TEXT("Failed to load header for editing: %s"), *FilePath);
        return false;
    }

    // Find the first occurrence of UCLASS(
    int32 UClassPos = Content.Find(TEXT("UCLASS("), ESearchCase::IgnoreCase, ESearchDir::FromStart);
    if (UClassPos == INDEX_NONE)
    {
        UE_LOG(LogProjectAssetEnforcer, Error, TEXT("No UCLASS macro found in: %s"), *FilePath);
        return false;
    }

    // Find the closing parenthesis of the UCLASS( ... ) block (this is a simple heuristic; consider using an actual parser for robustness)
    int32 OpenParenPos = Content.Find(TEXT("("), ESearchCase::IgnoreCase, ESearchDir::FromStart, UClassPos);
    if (OpenParenPos == INDEX_NONE) return false;

    // Walk forwards to find matching closing ')'
    int32 Index = OpenParenPos + 1;
    int32 Depth = 1;
    int32 ContentLen = Content.Len();
    while (Index < ContentLen && Depth > 0)
    {
        TCHAR C = Content[Index];
        if (C == '(') Depth++;
        else if (C == ')') Depth--;
        Index++;
    }
    if (Depth != 0)
    {
        UE_LOG(LogProjectAssetEnforcer, Error, TEXT("Unbalanced parentheses in UCLASS macro for: %s"), *FilePath);
        return false;
    }

    int32 CloseParenPos = Index - 1;
    FString Inside = Content.Mid(OpenParenPos + 1, CloseParenPos - (OpenParenPos + 1));

    // Check for meta=
    int32 MetaPos = Inside.Find(TEXT("meta="), ESearchCase::IgnoreCase, ESearchDir::FromStart);
    FString NewInside = Inside;
    if (MetaPos != INDEX_NONE)
    {
        // naive insertion: find the parentheses after meta=
        int32 MetaStart = Inside.Find(TEXT("meta="), ESearchCase::IgnoreCase, ESearchDir::FromStart);
        int32 ParenStart = Inside.Find(TEXT("("), ESearchCase::IgnoreCase, ESearchDir::FromStart, MetaStart);
        if (ParenStart == INDEX_NONE)
        {
            UE_LOG(LogProjectAssetEnforcer, Error, TEXT("Found meta= but cannot find its parentheses in: %s"), *FilePath);
            return false;
        }
        // find matching ) for that meta
        int32 MetaIndex = ParenStart + 1;
        int32 MetaDepth = 1;
        int32 InsideLen = Inside.Len();
        while (MetaIndex < InsideLen && MetaDepth > 0)
        {
            TCHAR C = Inside[MetaIndex];
            if (C == '(') MetaDepth++;
            else if (C == ')') MetaDepth--;
            MetaIndex++;
        }
        if (MetaDepth != 0)
        {
            UE_LOG(LogProjectAssetEnforcer, Error, TEXT("Unbalanced parentheses for meta= in: %s"), *FilePath);
            return false;
        }
        int32 MetaClosePos = MetaIndex - 1;
        // Insert ,CoveGUID="UUID" before MetaClosePos
        FString MetaContent = Inside.Mid(ParenStart + 1, MetaClosePos - (ParenStart + 1));
        FString NewMetaContent = MetaContent;
        if (!MetaContent.Contains(TEXT("CoveGUID")))
        {
            if (!MetaContent.IsEmpty())
            {
                NewMetaContent = MetaContent + TEXT(",CoveGUID=\"") + UUID + TEXT("\"");
            }
            else
            {
                NewMetaContent = TEXT("CoveGUID=\"") + UUID + TEXT("\"");
            }
            // rebuild Inside
            NewInside = Inside.Left(ParenStart + 1) + NewMetaContent + Inside.Mid(MetaClosePos);
        }
        else
        {
            UE_LOG(LogProjectAssetEnforcer, Log, TEXT("Meta already contains CoveGUID in header: %s"), *FilePath);
            OutNewText = Content;
            return true;
        }
    }
    else
    {
        // No meta specified — append meta=(CoveGUID="UUID") to the existing args (handle empty inside)
        if (Inside.TrimStartAndEnd().IsEmpty())
        {
            NewInside = FString::Printf(TEXT("meta=(CoveGUID=\"%s\")"), *UUID);
        }
        else
        {
            NewInside = Inside + TEXT(",meta=(CoveGUID=\"") + UUID + TEXT("\")");
        }
    }

    // Reconstruct content
    FString NewContent = Content.Left(OpenParenPos + 1) + NewInside + Content.Mid(CloseParenPos);
    OutNewText = NewContent;
    return true;
}
