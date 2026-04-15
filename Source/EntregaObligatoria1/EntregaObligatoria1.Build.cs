// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EntregaObligatoria1 : ModuleRules
{
	public EntregaObligatoria1(ReadOnlyTargetRules Target) : base(Target)
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
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"EntregaObligatoria1",
			"EntregaObligatoria1/Variant_Platforming",
			"EntregaObligatoria1/Variant_Platforming/Animation",
			"EntregaObligatoria1/Variant_Combat",
			"EntregaObligatoria1/Variant_Combat/AI",
			"EntregaObligatoria1/Variant_Combat/Animation",
			"EntregaObligatoria1/Variant_Combat/Gameplay",
			"EntregaObligatoria1/Variant_Combat/Interfaces",
			"EntregaObligatoria1/Variant_Combat/UI",
			"EntregaObligatoria1/Variant_SideScrolling",
			"EntregaObligatoria1/Variant_SideScrolling/AI",
			"EntregaObligatoria1/Variant_SideScrolling/Gameplay",
			"EntregaObligatoria1/Variant_SideScrolling/Interfaces",
			"EntregaObligatoria1/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
