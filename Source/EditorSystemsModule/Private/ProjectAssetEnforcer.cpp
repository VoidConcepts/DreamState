// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectAssetEnforcer.h"
#include "Editor/Blutility/Classes/EditorUtilityBlueprint.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"
#include "HAL/FileManager.h"
#include "AssetRegistry/AssetRegistryHelpers.h"
#include "EditorSystemsModule.h"


void UProjectAssetEnforcer::CheckChangedFilesFromRepoDiff(TArray<FString>& ChangedFiles, bool bCleanFileNamesOnly)
{
	FString GitCommand = TEXT("git");
	FString GitArgs = TEXT(" diff --name-status *.h");
	FString StdOut;
	FString StdErr;
	FString ProjectDir = FPaths::GetProjectFilePath();
	ProjectDir = FPaths::GetPath(ProjectDir);

	UE_LOG(LogEditorSystemsModule, Log, TEXT("----------Preparing Git Command Execution----------"));
	UE_LOG(LogEditorSystemsModule, Log, TEXT(" Executing Git Command: ' %s %s '"), *GitCommand, *GitArgs);

	FPlatformProcess::ExecProcess(
		*GitCommand,
		*GitArgs,
		nullptr,
		&StdOut,
		&StdErr,
		*ProjectDir
	);

	/* Error Checking just in case Git returns an Error or something goes wrong */
	/* If The Error message is Not empty BUT contains the text "Warning", it's fine. */
	if (!StdErr.IsEmpty() && StdErr.Contains("Warning"))
	{
		UE_LOG(LogEditorSystemsModule, Warning, TEXT("Git responded with a Warning: %s"), *StdErr);
	}
	/* On the other hand if it's not empty and DOESN'T contain the text, "Warning", something is amiss. Real Error. */
	else if (!StdErr.IsEmpty())
	{
		UE_LOG(LogEditorSystemsModule, Error, TEXT("Git Produced an Error: %s"), *StdErr);
		return;
	}


	/* Check for the results from the Git Command. */
	if (!StdOut.IsEmpty())
	{
		UE_LOG(LogEditorSystemsModule, Log, TEXT("----------Returned Git Results----------"));

		TArray<FString> DiffArray;
		StdOut.ParseIntoArray(DiffArray, TEXT("\n"), true);

		for (const FString& RelativeFilePathNameWithStatus : DiffArray)
		{
			FString IndividualHeaderFileName = FPaths::GetCleanFilename(RelativeFilePathNameWithStatus);

			FString FileStatusIndicator;
			FString RelativePath;

			RelativeFilePathNameWithStatus.Split(TEXT("\t"), &FileStatusIndicator, &RelativePath);

			/* Cheeky String tricks here. !! We can treat String like arrays of Characters...which...when I think about it.
			 * That does make sense because that is what they are. This lets the Switch-Case work */
			TCHAR StatusLeter = FileStatusIndicator[0];
			FString FileStatus;

			switch (StatusLeter)
			{
			case TEXT('A'): FileStatus = TEXT("Added");
				break;
			case TEXT('M'): FileStatus = TEXT("Modified");
				break;
			case TEXT('D'): FileStatus = TEXT("Deleted");
				break;
			case TEXT('R'): FileStatus = TEXT("Renamed");
				break;
			case TEXT('C'): FileStatus = TEXT("Copied");
				break;
			case TEXT('U'): FileStatus = TEXT("Unmerged");
				break;
			case TEXT('X'): FileStatus = TEXT("Unknown");
				break;
			case TEXT('B'): FileStatus = TEXT("Broken");
				break;
			default: FileStatus = TEXT("Untracked or Unmodified");
				break;
			}

			FString FullFilePath = FPaths::Combine(*ProjectDir, *RelativePath);
			UE_LOG(LogEditorSystemsModule, Log, TEXT("%s: %s \n" "RootFilePath: '%s' "), *FileStatus, *IndividualHeaderFileName, *FullFilePath);

			if (bCleanFileNamesOnly)
			{
				ChangedFiles.Add(IndividualHeaderFileName);
			}
			else
			{
				ChangedFiles.Add(RelativePath);
			}
		}
	}
	else if (StdOut.IsEmpty())
	{
		UE_LOG(LogEditorSystemsModule, Log, TEXT(" Git Command: ' %s %s ' did not return any results from the Diff."), *GitCommand, *GitArgs)
	}
}

void UProjectAssetEnforcer::ReadMetadataTags(FString FileToLoad, TArray<FString>& Result, bool& bMatchedText)
{
	bool bFileWasLoaded = FFileHelper::LoadFileToStringArray(Result,*FileToLoad);
	
}

void UProjectAssetEnforcer::SaveTextToFile(FString CompleteTextFile, const FString FilePath)
{
	FFileHelper::SaveStringToFile(CompleteTextFile, *FilePath);
}


