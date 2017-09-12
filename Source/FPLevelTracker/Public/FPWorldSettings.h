// Copyright (c) 2017 Franco Pulido

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "FPWorldSettings.generated.h"

/**
 * 
 */
UCLASS()
class FPLEVELTRACKER_API AFPWorldSettings : public AWorldSettings
{
	GENERATED_BODY()

public:

	AFPWorldSettings();

	/** This level title */
	UPROPERTY(Category = LevelTracker, EditAnywhere, AssetRegistrySearchable)
	FText Title;

	/** A short description for this level */
	UPROPERTY(Category = LevelTracker, EditAnywhere, AssetRegistrySearchable)
	FText Description;

	/** Author */
	UPROPERTY(Category = LevelTracker, EditAnywhere, AssetRegistrySearchable)
	FString Author;

	/** Thumbnail image */
	UPROPERTY(EditAnywhere, Category = "Level Tracker")
	UTexture2D* Thumbnail;

	/** String containing metadata that you can retrieve and parse as you want. */
	UPROPERTY(Category = LevelTracker, EditAnywhere, AssetRegistrySearchable)
	FString Meta;

	/** Holds a string reference to the thumbnail so it can be lazy loaded from other places */
	UPROPERTY(AssetRegistrySearchable)
	FString ThumbnailReference;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

};
