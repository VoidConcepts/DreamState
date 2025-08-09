// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterAIModuleDefinitions.generated.h"

/**
*
**/

//=================================================================================================
// INGREDIENTS (Structs)
// Hint: Use for unique, embedded data. Fast and lightweight.
//=================================================================================================

/** A template for a reusable struct of unique data. */
USTRUCT(BlueprintType)
struct FCharacterAIModule
{
	GENERATED_BODY()

public:
	// Unique properties go here
	
};

//=================================================================================================
// SHARED RECIPES (Data Assets)
// Hint: Use for simple, shared "sources of truth" that don't need manual loading.
//=================================================================================================

/** A template for a shared Data Asset. */
UCLASS(meta = (GUID = "18C03EE1-43DD32DB-4A65959C-2CF24D1D", FileName = "CharacterAIModuleDefinitions.h", AbsoluePath = "D:/DreamState/Source/GameDataAssetModule/Public/Definitions/CharacterAIModuleDefinitions.h" ))
class GAMEDATAASSETMODULE_API UCharacterAIModuleDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	// Shared properties go here
};

//=================================================================================================
// FINAL PRODUCT (Primary Data Asset)
// Hint: Use for top-level archetypes you want to manage with the Asset Manager.
//=================================================================================================

/** A template for a top-level, load-on-demand archetype. */
UCLASS(meta = (GUID = "18C03EE1-43DD32DB-4A65959C-2CF24D1D", FileName = "CharacterAIModuleDefinitions.h", AbsoluePath = "D:/DreamState/Source/GameDataAssetModule/Public/Definitions/CharacterAIModuleDefinitions.h" ))
class GAMEDATAASSETMODULE_API UCharacterAIModulePrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// Composition of structs and shared Data Assets goes here
};
