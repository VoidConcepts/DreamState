#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ProjectAssetEnforcer.generated.h"

UENUM()
enum class EFileStatus : uint8
{
	Added,
	Modified,
	Deleted,
	Renamed,
	Copied,
	Unmerged,
	Unknown,
	Broken,
	UntrackedOrUnmodified
};

DECLARE_LOG_CATEGORY_EXTERN(LogProjectAssetEnforcer, Log, All);

UCLASS()
class UProjectAssetEnforcer : public UObject
{
	GENERATED_BODY()

public:
	// Existing methods...
	void CheckChangedFilesFromRepoDiff(TArray<FString>& ChangedFiles, bool bCleanFileNamesOnly);

	// New/extended entry:
	void ProcessChangedFilesFromRepoDiff(bool bDryRun = true);

protected:
	// Dispatcher
	void InitializeStatusHandlers();
	void DispatchStatus(EFileStatus Status, const FString& RelativePath, const FString& FullPath, const FString& OptionalOldPath = TEXT(""));

	// Handlers (main thread / editor thread as needed)
	void HandleAddedFile(const FString& RelativePath, const FString& FullPath, bool bDryRun);
	void HandleModifiedFile(const FString& RelativePath, const FString& FullPath, bool bDryRun);
	void HandleRenamedFile(const FString& OldRelativePath, const FString& NewRelativePath, const FString& NewFullPath, bool bDryRun);
	void HandleCopiedFile(const FString& RelativePath, const FString& FullPath, bool bDryRun);

	// Utilities
	FString GenerateUUIDString() const;
	bool AtomicWriteFile(const FString& FilePath, const FString& NewContents, FString& OutBackupPath) const;
	bool HeaderContainsUUID(const FString& FilePath, FString& OutUUID) const;
	bool InsertUUIDIntoHeader(const FString& FilePath, const FString& UUID, FString& OutNewText) const;

private:
	TMap<EFileStatus, TFunction<void(const FString&, const FString&, const FString&, bool)>> StatusHandlers;
};
