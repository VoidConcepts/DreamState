using UnrealBuildTool;

public class GameDataAssetModule : ModuleRules
{
    public GameDataAssetModule(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "GameFrameworkModule", 
                "AssetRegistry",
                "GameplayAbilities",
                "GameplayTags",
                "GameplayTasks",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                
                    
            }
        );
        
        PublicIncludePaths.AddRange( 
            new string[]
            {
                
            }
        );
    }
}