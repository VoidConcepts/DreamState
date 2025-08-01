#include "GameFrameworkModule.h"
#include "GameFrameworkModuleInterface.h"
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
#include "Modules/ModuleManager.h"
DEFINE_LOG_CATEGORY(LogGameFrameworkModule)
#define LOCTEXT_NAMESPACE "FGameFrameworkModuleModule"

void FGameFrameworkModuleModule::StartupModule()
{
	FName ModuleName = "GameFrameworkModule";
	IModuleInterface* ModuleInterfacePtr = FModuleManager::Get().GetModule(ModuleName);
	// Step 1: Get the generic IModuleInterface pointer from the Module Manager.
	// This is the only type the manager knows about.
	
	if (ModuleInterfacePtr)
	{
		// Step 2: Cast the generic pointer to your concrete Module class type.
		// This is the crucial step. We are telling the compiler, "I know that this
		// generic module is actually my FGameFrameworkModuleModule."
		IGameFrameworkModuleInterface* ModuleInterface = static_cast<FGameFrameworkModuleModule*>(ModuleInterfacePtr);
	
		//We store the location in a pointer so this class can always find any other ModuleInterface
		GameFrameworkModuleInterfacePtr = ModuleInterface;
	
		// Step 3: Now that you have a valid pointer to the Module's interface,
		// you can call the registration function and pass in a pointer to this module.
		ModuleInterface->Register_IGameFrameworkModuleInterface(this);
		
	}
	
}


void FGameFrameworkModuleModule::ShutdownModule()
{
	
}

void FGameFrameworkModuleModule::Register_IGameFrameworkModuleInterface(IGameFrameworkModuleInterface* InInterface)
{
	GameFrameworkModuleInterfacePtr = InInterface;
}

void FGameFrameworkModuleModule::Register_IActorCharactersModuleInterface(IActorCharactersModuleInterface* InInterface)
{
	ActorCharactersModuleInterfacePtr = InInterface;
}

void FGameFrameworkModuleModule::Register_IAnimationModuleInterface(IAnimationModuleInterface* InInterface)
{
	AnimationModuleInterfacePtr = InInterface;
}

void FGameFrameworkModuleModule::Register_ICharacterAIModuleInterface(ICharacterAIModuleInterface* InInterface)
{
	CharacterAIModuleInterfacePtr = InInterface;
}

void FGameFrameworkModuleModule::Register_IDreamStateModuleInterface(IDreamStateModuleInterface* InInterface)
{
	DreamStateModuleInterfacePtr = InInterface;
}

void FGameFrameworkModuleModule::Register_IGameAudioModuleInterface(IGameAudioModuleInterface* InInterface)
{
	GameAudioModuleInterfacePtr = InInterface;
}

void FGameFrameworkModuleModule::Register_IGameDataAssetModuleInterface(IGameDataAssetModuleInterface* InInterface)
{
	GameDataAssetModuleInterfacePtr = InInterface;
}

void FGameFrameworkModuleModule::Register_IGamemodeManagerModuleInterface(IGamemodeManagerModuleInterface* InInterface)
{
	GamemodeManagerModuleInterfacePtr = InInterface;
}

void FGameFrameworkModuleModule::Register_IGameNetworkModuleInterface(IGameNetworkModuleInterface* InInterface)
{
	GameNetworkModuleInterfacePtr = InInterface;
}

void FGameFrameworkModuleModule::Register_IGameplayAbilitySystemModuleInterface(IGameplayAbilitySystemModuleInterface* InInterface)
{
	GameplayAbilitySystemModuleInterfacePtr = InInterface;
}

void FGameFrameworkModuleModule::Register_IGameStateDataModuleInterface(IGameStateDataModuleInterface* InInterface)
{
	GameStateDataModuleInterfacePtr = InInterface;
}

void FGameFrameworkModuleModule::Register_IHeadsUpDisplayModuleInterface(IHeadsUpDisplayModuleInterface* InInterface)
{
	HeadsUpDisplayModuleInterfacePtr = InInterface;
}

void FGameFrameworkModuleModule::Register_IVFXModuleInterface(IVFXModuleInterface* InInterface)
{
	VFXModuleInterfacePtr = InInterface;
}

void FGameFrameworkModuleModule::Register_IWorldManagerModuleInterface(IWorldManagerModuleInterface* InInterface)
{
	WorldManagerModuleInterfacePtr = InInterface;
}

IGameFrameworkModuleInterface* FGameFrameworkModuleModule::Get_IGameFrameworkModuleInterface()
{
	return GameFrameworkModuleInterfacePtr;
}


IActorCharactersModuleInterface* FGameFrameworkModuleModule::Get_IActorCharactersModuleInterface()
{
	return ActorCharactersModuleInterfacePtr;
}

IAnimationModuleInterface* FGameFrameworkModuleModule::Get_IAnimationModuleInterface()
{
	return AnimationModuleInterfacePtr;
}

ICharacterAIModuleInterface* FGameFrameworkModuleModule::Get_ICharacterAIModuleInterface()
{
	return CharacterAIModuleInterfacePtr;
}

IDreamStateModuleInterface* FGameFrameworkModuleModule::Get_IDreamStateModuleInterface()
{
	return DreamStateModuleInterfacePtr;
}

IGameAudioModuleInterface* FGameFrameworkModuleModule::Get_IGameAudioModuleInterface()
{
	return GameAudioModuleInterfacePtr;
}

IGameDataAssetModuleInterface* FGameFrameworkModuleModule::Get_IGameDataAssetModuleInterface()
{
	return GameDataAssetModuleInterfacePtr;
}

IGamemodeManagerModuleInterface* FGameFrameworkModuleModule::Get_IGamemodeManagerModuleInterface()
{
	return GamemodeManagerModuleInterfacePtr;
}

IGameNetworkModuleInterface* FGameFrameworkModuleModule::Get_IGameNetworkModuleInterface()
{
	return GameNetworkModuleInterfacePtr;
}

IGameplayAbilitySystemModuleInterface* FGameFrameworkModuleModule::Get_IGameplayAbilitySystemModuleInterface()
{
	return GameplayAbilitySystemModuleInterfacePtr;
}

IGameStateDataModuleInterface* FGameFrameworkModuleModule::Get_IGameStateDataModuleInterface()
{
	return GameStateDataModuleInterfacePtr;
}

IHeadsUpDisplayModuleInterface* FGameFrameworkModuleModule::Get_IHeadsUpDisplayModuleInterface()
{
	return HeadsUpDisplayModuleInterfacePtr;
}

IVFXModuleInterface* FGameFrameworkModuleModule::Get_IVFXModuleInterface()
{
	return VFXModuleInterfacePtr;
}

IWorldManagerModuleInterface* FGameFrameworkModuleModule::Get_IWorldManagerModuleInterface()
{
	return WorldManagerModuleInterfacePtr;
}




#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGameFrameworkModuleModule, GameFrameworkModule)
