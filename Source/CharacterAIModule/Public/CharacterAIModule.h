#pragma once

#include "CoreMinimal.h"
#include "CharacterAIModuleInterface.h"
#include "Modules/ModuleManager.h"
DECLARE_LOG_CATEGORY_EXTERN(LogCharacterAIModule, Log, All)
class IGameFrameworkModuleInterface;
/*
 * Module: CharacterAIModule
 *
 * This module contains the "brains" for any non-player characters, providing them with autonomous behavior.
 * It will house all AI Controllers, Behavior Trees, Blackboards, and custom AI tasks or services.
 * The logic here dictates how NPCs perceive the world, make decisions, and execute actions.
 * This is where you will define enemy tactics, friendly NPC routines, and any other simulated intelligence.
 * By isolating AI, you can develop complex behaviors without cluttering the character classes themselves.
 */

class FCharacterAIModuleModule : public IModuleInterface, public ICharacterAIModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

	IGameFrameworkModuleInterface* GameFrameworkModuleInterfacePtr = nullptr;
	

};
