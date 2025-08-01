// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "GameStateDataModuleInterface.generated.h"

 
// This class does not need to be modified.
UINTERFACE()
class UGameStateDataModuleInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAMEFRAMEWORKMODULE_API IGameStateDataModuleInterface
{
	GENERATED_BODY()


	virtual APlayerState* Get_DreamStatePlayerState() const = 0;
	virtual AGameStateBase* Get_DreamStateGameState() const = 0;
 
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
};
