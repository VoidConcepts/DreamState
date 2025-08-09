// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlatformingGameMode.generated.h"

/**
 *  Simple GameMode for a third person platforming game
 */
UCLASS(meta = (GUID = "50FD2400-470AF437-F9FD6AAF-2A32DCE0", FileName = "PlatformingGameMode.h", AbsoluePath = "D:/DreamState/Source/DreamState/Variant_Platforming/PlatformingGameMode.h" ))
class APlatformingGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	/** Constructor */
	APlatformingGameMode();
};
