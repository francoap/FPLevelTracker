// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FPLevelTrackerSettings.generated.h"

/**
 * 
 */
UCLASS(config = Engine, defaultconfig)
class UFPLevelTrackerSettings : public UObject
{
	GENERATED_BODY()
	
public:

	UFPLevelTrackerSettings();

	/** List here all the content paths that you want to be scanned by the Level Tracker */
	UPROPERTY(Config, EditDefaultsOnly, BlueprintReadOnly, Category = "Level Scanner")
	TArray<FString> ContentPathsToScan;

};
