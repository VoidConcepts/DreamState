#pragma once

#include "CoreMinimal.h"
#include "WorldManagerModuleInterface.h"
#include "Modules/ModuleManager.h"

class IGameFrameworkModuleInterface;
DECLARE_LOG_CATEGORY_EXTERN(LogWorldManagerModule, Log, All)


/*
 * Module: WorldManagerModule
 *
 * This module is responsible for managing the game world itself and any unique, overarching systems that affect it.
 * It can handle procedural generation, dynamic weather systems, or custom day/night cycles.
 * If your game has unique mechanics that manipulate the environment on a large scale, the logic will live here.
 * This is the place for hyper-specific C++ code that manages the state and rules of the physical game space.
 * It ensures that the world your players inhabit is dynamic, interesting, and governed by consistent rules.
 */

class FWorldManagerModuleModule : public IModuleInterface, public IWorldManagerModuleInterface
{
public:

	
	IGameFrameworkModuleInterface* GameFrameworkModuleInterfacePtr = nullptr;

    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
