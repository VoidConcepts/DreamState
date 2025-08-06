using UnrealBuildTool;

public class EditorSystemsModule : ModuleRules
{
	public EditorSystemsModule(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"ToolMenus",
				"ToolMenusEditor",
				"SlateCore",
				"UnrealEd",
				"Projects",
				"EditorStyle",
				"Blutility"
			}
		);
	}
}