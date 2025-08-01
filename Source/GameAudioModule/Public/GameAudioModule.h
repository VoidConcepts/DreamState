#pragma once

#include "CoreMinimal.h"
#include "GameAudioModuleInterface.h"
#include "Modules/ModuleManager.h"
DECLARE_LOG_CATEGORY_EXTERN(LogGameAudioModule, Log, All)
class IGameFrameworkModuleInterface;
/*
 * Module: GameAudioModule
 *
 * This module is the central hub for all audio-related logic and assets within the game.
 * It manages Sound Cues, Sound Classes, attenuation settings, and any custom components for audio playback.
 * The responsibility of this module is to handle everything from ambient world sounds to character dialogue and UI feedback.
 * By consolidating audio here, you create a single point of control for managing volume, mixing, and spatialization.
 * It ensures a consistent and high-quality audio experience across the entire game.
 */

class FGameAudioModuleModule : public IModuleInterface, public IGameAudioModuleInterface
{
public:

	IGameFrameworkModuleInterface* GameFrameworkModuleInterfacePtr = nullptr;
	

	
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
