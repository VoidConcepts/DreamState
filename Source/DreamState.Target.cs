// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DreamStateTarget : TargetRules
{
	public DreamStateTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;
		ExtraModuleNames.Add("DreamState");
		RegisterModulesCreatedByRider();
	}

	private void RegisterModulesCreatedByRider()
	{
		ExtraModuleNames.AddRange(new string[] { "GameFrameworkModule", "VFXModule", "GameAudioModule", "AnimationModule", "ActorCharactersModule", "GameplayAbilitySystemModule", "GameStateDataModule", "HeadsUpDisplayModule", "GamemodeManagerModule", "WorldManagerModule", "GameNetworkModule", "CharacterAIModule", "GameDataAssetModule" });
	}
}
