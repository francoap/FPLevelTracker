// Copyright (c) 2017 Franco Pulido

#pragma once

#include "Engine.h"
#include "FPLevelTrackerTypes.h"
#include "FPLevelTrackerBPLibrary.generated.h"

UCLASS()
class FPLEVELTRACKER_API UFPLevelTrackerBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/** Returns an array of level tracker metadata structures for all the levels in the configured scan paths */
	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "FP Level Tracker")
	static TArray<FFPLevelTrackerData> GetAllLevelsTrackerData();

	/** Returns an array of FAssetData for all the levels in the configured scan paths */
	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "FP Level Tracker")
	static void GetAllLevelsAssetData(TArray<FAssetData>& LevelAssetDatas);

	/** Generates an FFPLevelTrackerData structure for a given level FAssetData */
	static FFPLevelTrackerData GenerateLevelTrackerDataFromAssetData(const FAssetData& AssetData);

};
