#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySystemModuleInterface.h"
#include "Modules/ModuleManager.h"
DECLARE_LOG_CATEGORY_EXTERN(LogGameplayAbilitySystemModule, Log, All)
class UAbilitySystemComponent;
class IGameFrameworkModuleInterface;
/*
 * Module: GameplayAbilitySystemModule
 *
 * This module contains everything related to Unreal's Gameplay Ability System (GAS).
 * It will house your Gameplay Abilities, Gameplay Effects, Attribute Sets, and Ability System Components.
 * This is where you define all character skills, status effects, buffs, debuffs, and resource costs.
 * GAS provides a robust and networked framework for complex character abilities.
 * By dedicating a module to it, you keep this powerful but intricate system organized and self-contained.
 */

class FGameplayAbilitySystemModuleModule : public IModuleInterface, public IGameplayAbilitySystemModuleInterface
{
public:

	IGameFrameworkModuleInterface* GameFrameworkModuleInterfacePtr = nullptr;
	


	virtual TSubclassOf<UAbilitySystemComponent> Get_DreamStateAbilitySystemComponent() const override;
	
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
