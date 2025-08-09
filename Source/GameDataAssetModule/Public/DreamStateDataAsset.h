// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DreamStateDataAsset.generated.h"

/**
 * 
 */
UCLASS(meta = (GUID = "BC5E0DB4-4F6D327D-6EDABAB7-4865508B", FileName = "DreamStateDataAsset.h", AbsoluePath = "D:/DreamState/Source/GameDataAssetModule/Public/DreamStateDataAsset.h" ))
class GAMEDATAASSETMODULE_API UDreamStateDataAsset : public UDataAsset
{
	

	virtual void GetAssetRegistryTags(FAssetRegistryTagsContext Context) const override;
	GENERATED_BODY()
};
