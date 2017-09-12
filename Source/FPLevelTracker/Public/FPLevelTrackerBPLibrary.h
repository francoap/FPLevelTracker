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

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "FP Level Tracker")
	static TArray<FFPLevelTrackerData> GetAllLevelsTrackerData();

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "FP Level Tracker")
	static void GetAllLevelsAssetData(TArray<FAssetData>& LevelAssetDatas);

	static FFPLevelTrackerData GenerateLevelTrackerDataFromAssetData(const FAssetData& AssetData);

};
