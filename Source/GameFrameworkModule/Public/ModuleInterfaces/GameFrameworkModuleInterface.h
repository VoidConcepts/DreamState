// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorCharactersModuleInterface.h"
#include "AnimationModuleInterface.h"
#include "CharacterAIModuleInterface.h"
#include "DreamStateModuleInterface.h"
#include "GameAudioModuleInterface.h"
#include "GameDataAssetModuleInterface.h"
#include "GamemodeManagerModuleInterface.h"
#include "GameNetworkModuleInterface.h"
#include "GameplayAbilitySystemModuleInterface.h"
#include "GameStateDataModuleInterface.h"
#include "HeadsUpDisplayModuleInterface.h"
#include "VFXModuleInterface.h"
#include "WorldManagerModuleInterface.h"
#include "UObject/Interface.h"

#include "GameFrameworkModuleInterface.generated.h"


// This class does not need to be modified.
UINTERFACE(NotBlueprintable)
class UGameFrameworkModuleInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */

class GAMEFRAMEWORKMODULE_API IGameFrameworkModuleInterface
{
	GENERATED_BODY()

public:
	virtual void Register_IGameFrameworkModuleInterface(IGameFrameworkModuleInterface* InInterface) = 0;
	virtual void Register_IActorCharactersModuleInterface(IActorCharactersModuleInterface* InInterface) = 0;
	virtual void Register_IAnimationModuleInterface(IAnimationModuleInterface* InInterface) = 0;
	virtual void Register_ICharacterAIModuleInterface(ICharacterAIModuleInterface* InInterface) = 0;
	virtual void Register_IDreamStateModuleInterface(IDreamStateModuleInterface* InInterface) = 0;
	virtual void Register_IGameAudioModuleInterface(IGameAudioModuleInterface* InInterface) = 0;
	virtual void Register_IGameDataAssetModuleInterface(IGameDataAssetModuleInterface* InInterface) = 0;
	virtual void Register_IGamemodeManagerModuleInterface(IGamemodeManagerModuleInterface* InInterface) = 0;
	virtual void Register_IGameNetworkModuleInterface(IGameNetworkModuleInterface* InInterface) = 0;
	virtual void Register_IGameplayAbilitySystemModuleInterface(IGameplayAbilitySystemModuleInterface* InInterface) = 0;
	virtual void Register_IGameStateDataModuleInterface(IGameStateDataModuleInterface* InInterface) = 0;
	virtual void Register_IHeadsUpDisplayModuleInterface(IHeadsUpDisplayModuleInterface* InInterface) = 0;
	virtual void Register_IVFXModuleInterface(IVFXModuleInterface* InInterface) = 0;
	virtual void Register_IWorldManagerModuleInterface(IWorldManagerModuleInterface* InInterface) = 0;

	virtual IGameFrameworkModuleInterface* Get_IGameFrameworkModuleInterface() = 0;
	virtual IActorCharactersModuleInterface* Get_IActorCharactersModuleInterface() = 0;
	virtual IAnimationModuleInterface* Get_IAnimationModuleInterface() = 0;
	virtual ICharacterAIModuleInterface* Get_ICharacterAIModuleInterface() = 0;
	virtual IDreamStateModuleInterface* Get_IDreamStateModuleInterface() = 0;
	virtual IGameAudioModuleInterface* Get_IGameAudioModuleInterface() = 0;
	virtual IGameDataAssetModuleInterface* Get_IGameDataAssetModuleInterface() = 0;
	virtual IGamemodeManagerModuleInterface* Get_IGamemodeManagerModuleInterface() = 0;
	virtual IGameNetworkModuleInterface* Get_IGameNetworkModuleInterface() = 0;
	virtual IGameplayAbilitySystemModuleInterface* Get_IGameplayAbilitySystemModuleInterface() = 0;
	virtual IGameStateDataModuleInterface* Get_IGameStateDataModuleInterface() = 0;
	virtual IHeadsUpDisplayModuleInterface* Get_IHeadsUpDisplayModuleInterface() = 0;
	virtual IVFXModuleInterface* Get_IVFXModuleInterface() = 0;
	virtual IWorldManagerModuleInterface* Get_IWorldManagerModuleInterface() = 0;

	


	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
};
