// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SideScrollingUI.generated.h"

/**
 *  Simple Side Scrolling game UI
 *  Displays and manages a pickup counter
 */
UCLASS(meta = (GUID = "9FA5DC74-4B2AD321-0F4820B4-51DD7C6E", FileName = "SideScrollingUI.h", AbsoluePath = "D:/DreamState/Source/DreamState/Variant_SideScrolling/SideScrollingUI.h" ))
class USideScrollingUI : public UUserWidget
{
	GENERATED_BODY()
	
public:

	/** Update the widget's pickup counter */
	UFUNCTION(BlueprintImplementableEvent, Category="UI")
	void UpdatePickups(int32 Amount);
};
