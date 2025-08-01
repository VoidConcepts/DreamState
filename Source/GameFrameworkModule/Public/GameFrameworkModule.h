#pragma once

#include "CoreMinimal.h"
#include "GameFrameworkModuleInterface.h"


DECLARE_LOG_CATEGORY_EXTERN(LogGameFrameworkModule, Log, All)

class ActorCharactersModuleInterface;
class AnimationModuleInterface;
class CharacterAIModuleInterface;
class DreamStateModuleInterface;
class GameAudioModuleInterface;
class GameDataAssetModuleInterface;
class GamemodeManagerModuleInterface;
class GameNetworkModuleInterface;
class GameplayAbilitySystemModuleInterface;
class GameStateDataModuleInterface;
class HeadsUpDisplayModuleInterface;
class VFXModuleInterface;
class WorldManagerModuleInterface;

/*
 * Module: GameFrameworkModule
 *
 * This module serves as the communication backbone for the entire project, primarily by providing interfaces.
 * It is designed to be a lightweight dependency that all other modules can safely include without creating circular references.
 * By implementing interfaces from this module, different systems can communicate without needing to know about each other's specific classes.
 * Think of this as the "switchboard" or "front desk" that hands out the tools for inter-module communication.
 * Its sole purpose is to facilitate clean, decoupled architecture and prevent code spaghetti.
 *
 * Any Newly Added Runtime Modules need to be added to the interface for this class as well as be implemented here as well.
 * This ensures that new module has two interfaces at its disposal:
 * 1. For Publishing Data within itself.
 * 2. For requesting Data (if needed) from other modules.
 */
class FGameFrameworkModuleModule : public IModuleInterface, public IGameFrameworkModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/* A set of basic functions for the IGameFrameworkModuleInterface */
	virtual void Register_IGameFrameworkModuleInterface(IGameFrameworkModuleInterface* InInterface) override;
	virtual IGameFrameworkModuleInterface* Get_IGameFrameworkModuleInterface() override;
	IGameFrameworkModuleInterface*  GameFrameworkModuleInterfacePtr = nullptr;
	
	/* A set of basic functions for the IActorCharactersModuleInterface */
	virtual void Register_IActorCharactersModuleInterface(IActorCharactersModuleInterface* InInterface) override;
	virtual IActorCharactersModuleInterface* Get_IActorCharactersModuleInterface() override;
	IActorCharactersModuleInterface*  ActorCharactersModuleInterfacePtr = nullptr;
	
	/* A set of basic functions for the IAnimationModuleInterface */
	virtual void Register_IAnimationModuleInterface(IAnimationModuleInterface* InInterface) override;
	virtual IAnimationModuleInterface* Get_IAnimationModuleInterface() override;
	IAnimationModuleInterface*  AnimationModuleInterfacePtr = nullptr;
	
	/* A set of basic functions for the ICharacterAIModuleInterface */
	virtual void Register_ICharacterAIModuleInterface(ICharacterAIModuleInterface* InInterface) override;
	virtual ICharacterAIModuleInterface* Get_ICharacterAIModuleInterface() override;
	ICharacterAIModuleInterface*  CharacterAIModuleInterfacePtr = nullptr;
	
	/* A set of basic functions for the IDreamStateModuleInterface */
	virtual void Register_IDreamStateModuleInterface(IDreamStateModuleInterface* InInterface) override;
	virtual IDreamStateModuleInterface* Get_IDreamStateModuleInterface() override;
	IDreamStateModuleInterface*  DreamStateModuleInterfacePtr = nullptr;
	
	/* A set of basic functions for the IGameAudioModuleInterface */
	virtual void Register_IGameAudioModuleInterface(IGameAudioModuleInterface* InInterface) override;
	virtual IGameAudioModuleInterface* Get_IGameAudioModuleInterface() override;
	IGameAudioModuleInterface*  GameAudioModuleInterfacePtr = nullptr;
	
	/* A set of basic functions for the IGameDataAssetModuleInterface */
	virtual void Register_IGameDataAssetModuleInterface(IGameDataAssetModuleInterface* InInterface) override;
	virtual IGameDataAssetModuleInterface* Get_IGameDataAssetModuleInterface() override;
	IGameDataAssetModuleInterface*  GameDataAssetModuleInterfacePtr = nullptr;
	
	/* A set of basic functions for the IGamemodeManagerModuleInterface */
	virtual void Register_IGamemodeManagerModuleInterface(IGamemodeManagerModuleInterface* InInterface) override;
	virtual IGamemodeManagerModuleInterface* Get_IGamemodeManagerModuleInterface() override;
	IGamemodeManagerModuleInterface*  GamemodeManagerModuleInterfacePtr = nullptr;
	
	/* A set of basic functions for the IGameNetworkModuleInterface */
	virtual void Register_IGameNetworkModuleInterface(IGameNetworkModuleInterface* InInterface) override;
	virtual IGameNetworkModuleInterface* Get_IGameNetworkModuleInterface() override;
	IGameNetworkModuleInterface*  GameNetworkModuleInterfacePtr = nullptr;
	
	/* A set of basic functions for the IGameplayAbilitySystemModuleInterface */
	virtual void Register_IGameplayAbilitySystemModuleInterface(IGameplayAbilitySystemModuleInterface* InInterface) override;
	virtual IGameplayAbilitySystemModuleInterface* Get_IGameplayAbilitySystemModuleInterface() override;
	IGameplayAbilitySystemModuleInterface*  GameplayAbilitySystemModuleInterfacePtr = nullptr;
	
	/* A set of basic functions for the IGameStateDataModuleInterface */
	virtual void Register_IGameStateDataModuleInterface(IGameStateDataModuleInterface* InInterface) override;
	virtual IGameStateDataModuleInterface* Get_IGameStateDataModuleInterface() override;
	IGameStateDataModuleInterface*  GameStateDataModuleInterfacePtr = nullptr;
	
	/* A set of basic functions for the IHeadsUpDisplayModuleInterface */
	virtual void Register_IHeadsUpDisplayModuleInterface(IHeadsUpDisplayModuleInterface* InInterface) override;
	virtual IHeadsUpDisplayModuleInterface* Get_IHeadsUpDisplayModuleInterface() override;
	IHeadsUpDisplayModuleInterface*  HeadsUpDisplayModuleInterfacePtr = nullptr;
	
	/* A set of basic functions for the IVFXModuleInterface */
	virtual void Register_IVFXModuleInterface(IVFXModuleInterface* InInterface) override;
	virtual IVFXModuleInterface* Get_IVFXModuleInterface() override;
	IVFXModuleInterface*  VFXModuleInterfacePtr = nullptr;
	
	/* A set of basic functions for the IWorldManagerModuleInterface */
	virtual void Register_IWorldManagerModuleInterface(IWorldManagerModuleInterface* InInterface) override;
	virtual IWorldManagerModuleInterface* Get_IWorldManagerModuleInterface() override;
	IWorldManagerModuleInterface*  WorldManagerModuleInterfacePtr = nullptr;
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	


  
  
  
  
  
  
  
  
  
  
  
  
  
  
};
