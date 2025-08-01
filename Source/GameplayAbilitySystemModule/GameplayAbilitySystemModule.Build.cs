using UnrealBuildTool;

public class GameplayAbilitySystemModule : ModuleRules
{
    public GameplayAbilitySystemModule(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "GameFrameworkModule",
                "GameDataAssetModule", 
                "GameplayAbilities",
                "GameplayTags",
                "GameplayTasks"
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
                "GameplayAbilitySystemModule/public/AbilitySystemComponent/",
                "GameplayAbilitySystemModule/public/AttributeSets/",
            }
        );
    }
}