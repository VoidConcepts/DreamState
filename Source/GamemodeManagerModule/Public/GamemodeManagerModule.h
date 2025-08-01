#pragma once

#include "CoreMinimal.h"
#include "GamemodeManagerModuleInterface.h"
#include "Modules/ModuleManager.h"
DECLARE_LOG_CATEGORY_EXTERN(LogGamemodeManagerModule, Log, All)
class IGameFrameworkModuleInterface;
/*
 * Module: GamemodeManagerModule
 *
 * This module acts as the "referee," defining the rules and managing the flow of the game session.
 * It contains the GameMode and PlayerController classes, which are central to regulating gameplay.
 * The GameMode, existing only on the server, enforces rules like win/loss conditions and player spawning.
 * The PlayerController translates player input into actions within the game world.
 * This module is fundamentally about defining *how* the game is played and what actions are permissible.
 */
class FGamemodeManagerModuleModule : public IModuleInterface, public IGamemodeManagerModuleInterface
{
public:

    IGameFrameworkModuleInterface* GameFrameworkModuleInterfacePtr = nullptr;
    


    
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
