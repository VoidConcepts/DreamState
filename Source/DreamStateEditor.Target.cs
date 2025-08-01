// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DreamStateEditorTarget : TargetRules
{
	public DreamStateEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;
		ExtraModuleNames.Add("DreamState");
		RegisterModulesCreatedByRider();
	}

	private void RegisterModulesCreatedByRider()
	{
		ExtraModuleNames.AddRange(new string[] { "GameFrameworkModule", "VFXModule", "GameAudioModule", "AnimationModule", "ActorCharactersModule", "GameplayAbilitySystemModule", "GameStateDataModule", "HeadsUpDisplayModule", "GamemodeManagerModule", "WorldManagerModule", "GameNetworkModule", "EditorSystemsModule", "CharacterAIModule", "GameDataAssetModule" });
	}
}
