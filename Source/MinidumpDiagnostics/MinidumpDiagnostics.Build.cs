// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MinidumpDiagnostics : ModuleRules
{
    public MinidumpDiagnostics(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateIncludePathModuleNames.Add("Launch");

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "ApplicationCore",
                "CrashDebugHelper",
                "PerforceSourceControl",
                "Projects"
            }
        );

    }
}