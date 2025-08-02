// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DreamStateDataAsset.generated.h"

/**
 * 
 */
UCLASS(abstract)
class GAMEDATAASSETMODULE_API UDreamStateDataAsset : public UDataAsset
{
	

	virtual void GetAssetRegistryTags(FAssetRegistryTagsContext Context) const override;
	GENERATED_BODY()
};
