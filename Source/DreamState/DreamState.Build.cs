// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DreamState : ModuleRules
{
	public DreamState(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"GameFrameworkModule",
			"GameDataAssetModule"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"DreamState",
			"DreamState/Variant_Platforming",
			"DreamState/Variant_Combat",
			"DreamState/Variant_Combat/AI",
			"DreamState/Variant_SideScrolling",
			"DreamState/Variant_SideScrolling/Gameplay",
			"DreamState/Variant_SideScrolling/AI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
