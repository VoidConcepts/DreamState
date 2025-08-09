// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CombatAIController.generated.h"

class UStateTreeAIComponent;

/**
 *	A basic AI Controller capable of running StateTree
 */
UCLASS(meta = (GUID = "9B5E7599-4A1E0AD3-8F9D7C96-C3542E62", FileName = "CombatAIController.h", AbsoluePath = "D:/DreamState/Source/DreamState/Variant_Combat/AI/CombatAIController.h" ))
class ACombatAIController : public AAIController
{
	GENERATED_BODY()

	/** StateTree Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UStateTreeAIComponent* StateTreeAI;

public:

	/** Constructor */
	ACombatAIController();
};
