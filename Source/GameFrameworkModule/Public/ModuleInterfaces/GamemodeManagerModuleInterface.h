// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GamemodeManagerModuleInterface.generated.h"

/**
 * 
 */
UINTERFACE()
class UGamemodeManagerModuleInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAMEFRAMEWORKMODULE_API IGamemodeManagerModuleInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	TScriptInterface<IGamemodeManagerModuleInterface> GamemodeManagerModule();
};