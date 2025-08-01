#pragma once

#include "CoreMinimal.h"
#include "VFXModuleInterface.h"
DECLARE_LOG_CATEGORY_EXTERN(LogVFXModule, Log, All)

class IGameFrameworkModuleInterface;
/*
 * Module: VFXModule
 *
 * This module is dedicated to all visual effects that are not part of standard animation.
 * It will contain all Niagara systems, particle effects, and material-based visual effects.
 * This is where you create everything from muzzle flashes and explosions to magical spells and environmental effects.
 * By separating VFX, you acknowledge it as a distinct artistic and technical discipline.
 * This module provides the visual flair and impact that bring your game's actions to life.
 */
class FVFXModuleModule : public IModuleInterface, public IVFXModuleInterface
{
public:

    IGameFrameworkModuleInterface* GameFrameworkModuleInterfacePtr = nullptr;
    

    
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
