#pragma once

#include "CoreMinimal.h"
#include "AnimationModuleInterface.h"
#include "Modules/ModuleManager.h"
DECLARE_LOG_CATEGORY_EXTERN(LogAnimationModule, Log, All)
class IGameFrameworkModuleInterface;
/*
 * Module: AnimationModule
 *
 * This module exclusively handles the skeletal animation systems for actors.
 * It contains Animation Blueprints, Blend Spaces, Animation Montages, and any custom Animation Instance classes.
 * The logic here drives how characters and other animated objects physically express their state and actions.
 * By separating this, you ensure that the complex logic of animation does not get tangled with core gameplay code.
 * This module will be responsible for everything from a character's walk cycle to complex combat animations.
 */

class FAnimationModuleModule : public IModuleInterface, public IAnimationModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

	IGameFrameworkModuleInterface* GameFrameworkModuleInterfacePtr = nullptr;
	

};
