// Copyright (c) 2017 Franco Pulido

#include "FPLevelTracker.h"

#include "Engine/Engine.h"
#include "FPWorldSettings.h"

#define LOCTEXT_NAMESPACE "FFPLevelTrackerModule"

void FFPLevelTrackerModule::StartupModule()
{
	FWorldDelegates::GetAssetTags.AddLambda([](const UWorld* InWorld, TArray<UObject::FAssetRegistryTag>& OutTags)
	{
		// Add our world settings tracker data to the asset registry as part of the world
		AFPWorldSettings* Settings = Cast<AFPWorldSettings>(InWorld->GetWorldSettings());
		if (Settings)
		{
			Settings->GetAssetRegistryTags(OutTags);
		}
	});
}

void FFPLevelTrackerModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_GAME_MODULE(FFPLevelTrackerModule, FPLevelTracker)