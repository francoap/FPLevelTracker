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

	if (Thumbnail)
	{
		ThumbnailReference = Thumbnail->GetPathName();
	}
	else
	{
		ThumbnailReference.Empty();
	}
}
#endif
