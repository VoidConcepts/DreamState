// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CombatLifeBar.generated.h"

/**
 *  A basic life bar user widget.
 */
UCLASS(meta = (GUID = "7E730A5E-4E9B3EBE-3B273F82-64554032", FileName = "CombatLifeBar.h", AbsoluePath = "D:/DreamState/Source/DreamState/Variant_Combat/CombatLifeBar.h" ))
class UCombatLifeBar : public UUserWidget
{
	GENERATED_BODY()

public:

	/** Sets the life bar to the provided 0-1 percentage value*/
	UFUNCTION(BlueprintImplementableEvent, Category="LifeBar")
	void SetLifePercentage(float Percent);

	// Sets the life bar fill color
	UFUNCTION(BlueprintImplementableEvent, Category="LifeBar")
	void SetBarColor(FLinearColor Color);
};
