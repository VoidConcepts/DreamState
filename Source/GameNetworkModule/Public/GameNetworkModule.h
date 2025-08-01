#pragma once

#include "CoreMinimal.h"
#include "GameNetworkModuleInterface.h"
#include "Modules/ModuleManager.h"
DECLARE_LOG_CATEGORY_EXTERN(LogGameNetworkModule, Log, All)
class IGameFrameworkModuleInterface;
/*
 * Module: GameNetworkModule
 *
 * This module is responsible for all logic directly related to multiplayer networking and data replication.
 * It will handle the complexities of client-server communication, ensuring the game state is synchronized.
 * Any custom networking components or logic for handling latency and packet loss will reside here.
 * This is where you will implement server-authoritative checks and client-side prediction.
 * By isolating network code, you can focus on the unique challenges of creating a stable multiplayer experience.
 */
class FGameNetworkModuleModule : public IModuleInterface, public IGameNetworkModuleInterface
{
public:

    IGameFrameworkModuleInterface* GameFrameworkModuleInterfacePtr = nullptr;
    

    
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
