#pragma once

#include "CoreMinimal.h"
#include "GameStateDataModuleInterface.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogGameStateDataModule, Log, All)
class IGameFrameworkModuleInterface;
 
/*
 * Module: GameStateDataModule
 *
 * This module acts as the "scoreboard," tracking and replicating the current state of the game to all clients.
 * It contains the GameState and PlayerState classes, which are essential for a multiplayer environment.
 * The GameState tracks session-wide information like the current game time, objectives, and team scores.
 * The PlayerState tracks data specific to an individual player, such as their name, score, or ping.
 * This module's primary role is to observe, record, and share the dynamic state of the game as it unfolds.
 */

class FGameStateDataModuleModule : public IModuleInterface, public IGameStateDataModuleInterface
{
public:

	IGameFrameworkModuleInterface* GameFrameworkModuleInterfacePtr = nullptr;


	virtual AGameStateBase* Get_DreamStateGameState() const override;
	virtual APlayerState* Get_DreamStatePlayerState() const override;

		
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
