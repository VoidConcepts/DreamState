using UnrealBuildTool;

public class GameFrameworkModule : ModuleRules
{
    public GameFrameworkModule(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore"
            }
        );
        
        PublicIncludePaths.AddRange( 
            new string[]
            {
                "GameFrameworkModule/Public/ModuleInterfaces"
            }
        );
    }
}