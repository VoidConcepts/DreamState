// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WorldManagerModuleDefinitions.generated.h"

/**
*
**/

//=================================================================================================
// INGREDIENTS (Structs)
// Hint: Use for unique, embedded data. Fast and lightweight.
//=================================================================================================

/** A template for a reusable struct of unique data. */
USTRUCT(BlueprintType)
struct FWorldManagerModule
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
UCLASS(meta = (GUID = "8A87A06C-43EF5985-EE73498D-826979D3", FileName = "WorldManagerModuleDefinitions.h", AbsoluePath = "D:/DreamState/Source/GameDataAssetModule/Public/Definitions/WorldManagerModuleDefinitions.h" ))
class GAMEDATAASSETMODULE_API UWorldManagerModuleDataAsset : public UDataAsset
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
UCLASS(meta = (GUID = "8A87A06C-43EF5985-EE73498D-826979D3", FileName = "WorldManagerModuleDefinitions.h", AbsoluePath = "D:/DreamState/Source/GameDataAssetModule/Public/Definitions/WorldManagerModuleDefinitions.h" ))
class GAMEDATAASSETMODULE_API UWorldManagerModulePrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// Composition of structs and shared Data Assets goes here
};
