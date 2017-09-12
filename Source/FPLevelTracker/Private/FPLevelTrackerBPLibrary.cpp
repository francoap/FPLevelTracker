// Copyright (c) 2017 Franco Pulido

#include "FPLevelTrackerBPLibrary.h"

#include "ARFilter.h"
#include "AssetRegistryModule.h"
#include "FileManager.h"
#include "FPLevelTrackerSettings.h"

TArray<FFPLevelTrackerData> UFPLevelTrackerBPLibrary::GetAllLevelsTrackerData()
{
	TArray<FFPLevelTrackerData> Result;

	TArray<FAssetData> MapAssets;
	GetAllLevelsAssetData(MapAssets);

	if (MapAssets.Num() > 0)
	{
		for (int32 i = 0; i < MapAssets.Num(); i++)
		{
			Result.Add(GenerateLevelTrackerDataFromAssetData(MapAssets[i]));
		}
	}

	return Result;
}

void UFPLevelTrackerBPLibrary::GetAllLevelsAssetData(TArray<FAssetData>& LevelAssetDatas)
{
	LevelAssetDatas.Empty();

	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

	TArray<FString> Paths = GetDefault<UFPLevelTrackerSettings>()->ContentPathsToScan;

	AssetRegistry.ScanPathsSynchronous(Paths, false);

	FARFilter ARFilter;
	ARFilter.ClassNames.Add(UWorld::StaticClass()->GetFName());
	
	for (FString Path : Paths)
	{
		if (!Path.IsEmpty())
		{
			ARFilter.PackagePaths.Add(*Path);
		}		
	}

	ARFilter.bRecursivePaths = true;
	ARFilter.bIncludeOnlyOnDiskAssets = true;
	ARFilter.bRecursiveClasses = true;

	TArray<FAssetData> AssetList;
	if (AssetRegistry.GetAssets(ARFilter, AssetList))
	{
		for (int32 i = 0; i < AssetList.Num(); i++)
		{
			LevelAssetDatas.Add(AssetList[i]);
		}
	}
}

FFPLevelTrackerData UFPLevelTrackerBPLibrary::GenerateLevelTrackerDataFromAssetData(const FAssetData& AssetData)
{
	FText Title;
	FText Description;
	FString Author;
	FString Thumbnail;
	FString Meta;

	// Here we return all of the level tracker tag values (properties declared as AssetRegistrySearchable in WorldSettings)
	AssetData.GetTagValue<FText>(FName("Title"), Title);
	AssetData.GetTagValue<FText>(FName("Description"), Description);
	AssetData.GetTagValue<FString>(FName("Author"), Author);
	AssetData.GetTagValue<FString>(FName("ThumbnailReference"), Thumbnail);
	AssetData.GetTagValue<FString>(FName("Meta"), Meta);

	FFPLevelTrackerData TrackerData;

	TrackerData.Title = Title;
	TrackerData.Description = Description;
	TrackerData.Author = Author;
	TrackerData.Thumbnail = Thumbnail;
	TrackerData.Meta = Meta;
	TrackerData.MapPackageName = AssetData.PackageName;
	TrackerData.MapAssetName = AssetData.AssetName;

	return TrackerData;
}
