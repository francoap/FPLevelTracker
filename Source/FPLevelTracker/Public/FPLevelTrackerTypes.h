// Copyright (c) 2017 Franco Pulido

#pragma once

#include "CoreMinimal.h"
#include "FPLevelTrackerTypes.generated.h"

USTRUCT(BlueprintType)
struct FFPLevelTrackerData
{
	GENERATED_BODY()

	/** This level title */
	UPROPERTY(BlueprintReadOnly)
	FText Title;

	/** A short description for this level */
	UPROPERTY(BlueprintReadOnly)
	FText Description;

	/** Author */
	UPROPERTY(BlueprintReadOnly)
	FString Author;

	/** Holds a string reference to the thumbnail so it can be lazy loaded from other places */
	UPROPERTY(BlueprintReadOnly)
	FString Thumbnail;

	/** String containing metadata that you can retrieve and parse as you want. */
	UPROPERTY(BlueprintReadOnly)
	FString Meta;

	UPROPERTY(BlueprintReadOnly)
	FName MapPackageName;

	UPROPERTY(BlueprintReadOnly)
	FName MapAssetName;

};