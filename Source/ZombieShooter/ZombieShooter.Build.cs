// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class ZombieShooter : ModuleRules
{
	public ZombieShooter(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG" });

		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
	}
}
