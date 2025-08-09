// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerState/DreamStatePlayerState.h"
#include "GameFrameworkModuleInterface.h"
#include "GameStateDataModuleInterface.h"
#include "GameStateDataModule.h"
#include "Runtime/CoreUObject/Public/UObject/AssetRegistryTagsContext.h"
#include "AbilitySystemComponent.h"



ADreamStatePlayerState::ADreamStatePlayerState()
{
	
}



void ADreamStatePlayerState::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	
	
	
}

void ADreamStatePlayerState::GetAssetRegistryTags(FAssetRegistryTagsContext Context) const
{
	Super::GetAssetRegistryTags(Context);
	FAssetRegistryTag AssetTag;
	
	
};
