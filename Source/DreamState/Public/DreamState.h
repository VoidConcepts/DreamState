// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DreamStateModuleInterface.h"

DECLARE_LOG_CATEGORY_EXTERN(LogDreamState, Log, All)
class IGameFrameworkModuleInterface;

class FDreamStateModuleModule : public IModuleInterface, public IDreamStateModuleInterface
{
public:

	IGameFrameworkModuleInterface* GameFrameworkModuleInterfacePtr = nullptr;
	

	
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
