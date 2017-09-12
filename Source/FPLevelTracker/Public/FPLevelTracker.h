// Copyright (c) 2017 Franco Pulido

#pragma once

#include "ModuleManager.h"

class FFPLevelTrackerModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};