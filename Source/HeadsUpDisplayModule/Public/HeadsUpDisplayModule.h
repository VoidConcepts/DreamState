#pragma once

#include "CoreMinimal.h"
#include "HeadsUpDisplayModuleInterface.h"
#include "Modules/ModuleManager.h"
DECLARE_LOG_CATEGORY_EXTERN(LogHeadsUpDisplayModule, Log, All)
class IGameFrameworkModuleInterface;
/*
 * Module: HeadsUpDisplayModule
 *
 * This module is responsible for all user interface (UI) and user experience (UX) elements.
 * It contains all the UMG widgets, from the main menu and settings screens to the in-game HUD.
 * Its job is to translate invisible game data into a visible, understandable format for the player.
 * This includes displaying health bars, ammo counts, objective markers, and inventory screens.
 * It is the primary channel through which the game communicates vital information back to the player.
 */

class FHeadsUpDisplayModuleModule : public IModuleInterface, public IHeadsUpDisplayModuleInterface
{
public:

	IGameFrameworkModuleInterface* GameFrameworkModuleInterfacePtr = nullptr;

    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
