// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "GameAudioModuleInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UGameAudioModuleInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAMEFRAMEWORKMODULE_API IGameAudioModuleInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	TScriptInterface<IGameAudioModuleInterface> GameAudioModule();
};
