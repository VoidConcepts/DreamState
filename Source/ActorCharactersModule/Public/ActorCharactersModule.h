#pragma once

#include "CoreMinimal.h"
#include "ActorCharactersModuleInterface.h"
#include "Modules/ModuleManager.h"

class IGameFrameworkModuleInterface;
DECLARE_LOG_CATEGORY_EXTERN(LogActorCharactersModule, Log, All)

/*
 * Module: ActorCharactersModule
 *
 * This module is responsible for the concrete implementation of all character-based actors in the game.
 * It contains the C++ classes for playable characters, non-playable characters (NPCs), and any other sentient entities.
 * The core logic for character movement, health, and interaction with the world resides here.
 * These classes will serve as the parent blueprints for all character variations you create in the editor.
 * Ultimately, this module defines the tangible, interactive beings that populate your game world.
 */

class FActorCharactersModuleModule : public IModuleInterface, public IActorCharactersModuleInterface
{
public:
	IGameFrameworkModuleInterface* GameFrameworkModuleInterfacePtr = nullptr;
	

	
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
