// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameNetworkModuleDefinitions.generated.h"

/**
*
**/

//=================================================================================================
// INGREDIENTS (Structs)
// Hint: Use for unique, embedded data. Fast and lightweight.
//=================================================================================================

/** A template for a reusable struct of unique data. */
USTRUCT(BlueprintType)
struct FGameNetworkModule
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
UCLASS(meta = (GUID = "3B6ED868-42188FA0-6785BF80-9ACA0B09", FileName = "GameNetworkModuleDefinitions.h", AbsoluePath = "D:/DreamState/Source/GameDataAssetModule/Public/Definitions/GameNetworkModuleDefinitions.h" ))
class GAMEDATAASSETMODULE_API UGameNetworkModuleDataAsset : public UDataAsset
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
UCLASS(meta = (GUID = "3B6ED868-42188FA0-6785BF80-9ACA0B09", FileName = "GameNetworkModuleDefinitions.h", AbsoluePath = "D:/DreamState/Source/GameDataAssetModule/Public/Definitions/GameNetworkModuleDefinitions.h" ))
class GAMEDATAASSETMODULE_API UGameNetworkModulePrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// Composition of structs and shared Data Assets goes here
};
