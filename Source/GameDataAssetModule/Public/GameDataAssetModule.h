#pragma once

#include "CoreMinimal.h"
#include "GameDataAssetModuleInterface.h"

DECLARE_LOG_CATEGORY_EXTERN(LogGameDataAssetModule, Log, All)
class IGameFrameworkModuleInterface;
/*
 * Module: GameDataAssetModule
 *
 * This module is the definitive library for all of your game's fundamental, non-changing data.
 * It is composed almost entirely of UDataAsset-derived classes that define the "nouns" of your game.
 * Here you will define what constitutes a weapon, a character class, a quest, or an item.
 * This enables a powerful data-driven workflow, allowing you to create new content without recompiling code.
 * It effectively separates your game's content from its systems, promoting clean, reusable code.
 */

class FGameDataAssetModuleModule : public IModuleInterface, public IGameDataAssetModuleInterface
{
public:

	IGameFrameworkModuleInterface* GameFrameworkModuleInterfacePtr = nullptr;
	


    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
