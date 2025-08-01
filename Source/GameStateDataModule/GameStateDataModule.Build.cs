using UnrealBuildTool;

public class GameStateDataModule : ModuleRules
{
    public GameStateDataModule(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "GameFrameworkModule",
                "GameDataAssetModule"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "GameplayAbilities",
                
            }
        );
        
        PublicIncludePaths.AddRange( 
            new string[]
            {
                
            }
        );
    }
}