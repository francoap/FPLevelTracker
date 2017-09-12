// Copyright (c) 2017 Franco Pulido

#include "FPWorldSettings.h"

#include "Engine/Texture2D.h"
#include "Kismet/KismetSystemLibrary.h"

AFPWorldSettings::AFPWorldSettings()
{
	Title = NSLOCTEXT("FPLevelTracker", "DefaultTitle", "Untitled Map");
	Description = NSLOCTEXT("FPLevelTracker", "DefaultDescription", "A new cool map");
	Author = UKismetSystemLibrary::GetPlatformUserName();
	Thumbnail = nullptr;
	Meta = TEXT("");
}

#if WITH_EDITOR
void AFPWorldSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	// One or more of this object properties were edited in editor

	if (Thumbnail)
	{
		// User edited thumbnail texture reference so we generate the string path for the new texture asset
		ThumbnailReference = Thumbnail->GetPathName();
	}
	else
	{
		ThumbnailReference.Empty();
	}
}
#endif
