// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "GameplayAbilitySystemModuleInterface.generated.h"

class UAbilitySystemComponent;
// This class does not need to be modified.
UINTERFACE()
class UGameplayAbilitySystemModuleInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAMEFRAMEWORKMODULE_API IGameplayAbilitySystemModuleInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	virtual TSubclassOf<UAbilitySystemComponent> Get_DreamStateAbilitySystemComponent() const = 0;
};
