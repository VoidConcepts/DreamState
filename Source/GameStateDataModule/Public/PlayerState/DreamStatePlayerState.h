// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "GameStateDataModuleInterface.h"
#include "DreamStatePlayerState.generated.h"




class UAbilitySystemComponent;

/**
 * 
 */
UCLASS(meta = (GUID = "A1CFB0F0-4687FC45-37A1CBAE-6155BDE7", FileName = "DreamStatePlayerState.h", AbsoluePath = "D:/DreamState/Source/GameStateDataModule/Public/PlayerState/DreamStatePlayerState.h" ))
class GAMESTATEDATAMODULE_API ADreamStatePlayerState : public APlayerState
{
	GENERATED_BODY()


	public:
	ADreamStatePlayerState();
	
	IGameStateDataModuleInterface* GameStateDataModuleInterfacePtr;
	
	virtual void PostInitializeComponents() override;

	virtual void GetAssetRegistryTags(FAssetRegistryTagsContext Context) const override;
	
	
};
