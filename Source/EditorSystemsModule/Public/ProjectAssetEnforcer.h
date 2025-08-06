// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityObject.h"
#include "ProjectAssetEnforcer.generated.h"

/**
 * 
 */
UCLASS(meta = (GUID = "E6113EF7-4357AE15-C3790EA8-29554136", FileName = "WorldManagerModuleBlueprintFunctionLibrary.h", FilePath = "D:/DreamState/Source\WorldManagerModule\Public"))
class EDITORSYSTEMSMODULE_API UProjectAssetEnforcer : public UEditorUtilityObject
{
	GENERATED_BODY()

public:
	/**
	 * @brief Outputs an array of changed files by a Repo Diff.
	 * @param[In] bCleanFileNamesOnly :	If True = "ExampleFileName.h" If  False = File as path. e.g. "Souce/Directory/SubDirectory/ExampleFileName.h" 
	 * @param[Out] ChangedFiles :	The resulting array of changed files. 
	 */
	UFUNCTION(BlueprintCallable)
	void CheckChangedFilesFromRepoDiff(TArray<FString>& ChangedFiles, bool bCleanFileNamesOnly = false);

	UFUNCTION(BlueprintCallable)
	void ReadMetadataTags(FString FileToLoad, TArray<FString>& Result, bool& bMatchedText);

	UFUNCTION(BlueprintCallable)
	void SaveTextToFile(FString CompleteTextFile, const FString FilePath);
};
