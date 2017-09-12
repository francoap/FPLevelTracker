// Fill out your copyright notice in the Description page of Project Settings.

#include "FPLevelTrackerSettings.h"

#if WITH_EDITOR
#include "ISettingsModule.h"
#include "ModuleManager.h"
#endif


UFPLevelTrackerSettings::UFPLevelTrackerSettings()
{
	ContentPathsToScan.Add("/Game");

#if WITH_EDITOR
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>(FName(TEXT("Settings")));
	if (SettingsModule)
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "FP Level Tracker",
			NSLOCTEXT("LevelTrackerSettings", "LevelTrackerSettingsName", "FP Level Tracker"),
			NSLOCTEXT("LevelTrackerSettings", "LevelTrackerSettingsDescription", "Level Tracker Settings"),
			GetMutableDefault<UFPLevelTrackerSettings>()
		);
	}
#endif
}
