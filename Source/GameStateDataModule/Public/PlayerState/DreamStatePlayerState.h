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
UCLASS()
class GAMESTATEDATAMODULE_API ADreamStatePlayerState : public APlayerState
{
	GENERATED_BODY()


	public:
	ADreamStatePlayerState();
	
	IGameStateDataModuleInterface* GameStateDataModuleInterfacePtr;
	
	virtual void PostInitializeComponents() override;
	
	
};
