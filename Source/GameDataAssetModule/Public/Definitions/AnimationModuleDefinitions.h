// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AnimationModuleDefinitions.generated.h"

/**
*
**/

//=================================================================================================
// INGREDIENTS (Structs)
// Hint: Use for unique, embedded data. Fast and lightweight.
//=================================================================================================

/** A template for a reusable struct of unique data. */
USTRUCT(BlueprintType)
struct FAnimationModule
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
UCLASS(meta = (GUID = "37A31600-4F657000-D5CB56BF-CDE03CA1", FileName = "AnimationModuleDefinitions.h", AbsoluePath = "D:/DreamState/Source/GameDataAssetModule/Public/Definitions/AnimationModuleDefinitions.h" ))
class GAMEDATAASSETMODULE_API UAnimationModuleDataAsset : public UDataAsset
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
UCLASS(meta = (GUID = "37A31600-4F657000-D5CB56BF-CDE03CA1", FileName = "AnimationModuleDefinitions.h", AbsoluePath = "D:/DreamState/Source/GameDataAssetModule/Public/Definitions/AnimationModuleDefinitions.h" ))
class GAMEDATAASSETMODULE_API UAnimationModulePrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// Composition of structs and shared Data Assets goes here
};
