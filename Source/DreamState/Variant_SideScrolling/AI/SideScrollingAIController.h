// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SideScrollingAIController.generated.h"

class UStateTreeAIComponent;

/**
 *  A basic AI Controller capable of running StateTree
 */
UCLASS(meta = (GUID = "7FD80F74-4976EE94-D1918ABF-7CEFBC92", FileName = "SideScrollingAIController.h", AbsoluePath = "D:/DreamState/Source/DreamState/Variant_SideScrolling/AI/SideScrollingAIController.h" ))
class ASideScrollingAIController : public AAIController
{
	GENERATED_BODY()
	
	/** StateTree Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UStateTreeAIComponent* StateTreeAI;

public:

	/** Constructor */
	ASideScrollingAIController();
};
