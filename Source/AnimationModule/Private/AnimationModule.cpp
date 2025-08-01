#include "AnimationModule.h"
#include "GameFrameworkModuleInterface.h"
#include "GameFrameworkModule.h"
#include "Modules/ModuleManager.h"
DEFINE_LOG_CATEGORY(LogAnimationModule)
#define LOCTEXT_NAMESPACE "FAnimationModuleModule"

void FAnimationModuleModule::StartupModule()
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
    	ModuleInterface->Register_IAnimationModuleInterface(this);
    	
    }
}

void FAnimationModuleModule::ShutdownModule()
{
    
}


#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FAnimationModuleModule, AnimationModule)