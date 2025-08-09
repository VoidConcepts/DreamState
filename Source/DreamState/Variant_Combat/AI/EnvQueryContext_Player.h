// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "EnvQueryContext_Player.generated.h"

/**
 *  UEnvQueryContext_Player
 *  Basic EnvQuery Context that returns the first local player
 */
UCLASS(meta = (GUID = "B94D570A-4D8C6201-713ED084-98F9B086", FileName = "EnvQueryContext_Player.h", AbsoluePath = "D:/DreamState/Source/DreamState/Variant_Combat/AI/EnvQueryContext_Player.h" ))
class UEnvQueryContext_Player : public UEnvQueryContext
{
	GENERATED_BODY()
	
public:

	/** Provides the context locations or actors for this EnvQuery */
	virtual void ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const override;
};
