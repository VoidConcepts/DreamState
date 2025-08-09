// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SideScrollingGameMode.generated.h"

class USideScrollingUI;

/**
 *  Simple Side Scrolling Game Mode
 *  Spawns and manages the game UI
 *  Counts pickups collected by the player
 */
UCLASS(meta = (GUID = "CF354B67-4B689495-81011995-5EFCACDA", FileName = "SideScrollingGameMode.h", AbsoluePath = "D:/DreamState/Source/DreamState/Variant_SideScrolling/SideScrollingGameMode.h" ))
class ASideScrollingGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:

	/** Class of UI widget to spawn when the game starts */
	UPROPERTY(EditAnywhere, Category="UI")
	TSubclassOf<USideScrollingUI> UserInterfaceClass;

	/** User interface widget for the game */
	UPROPERTY(BlueprintReadOnly, Category="UI")
	TObjectPtr<USideScrollingUI> UserInterface;

	/** Number of pickups collected by the player */
	UPROPERTY(BlueprintReadOnly, Category="Picups")
	int32 PickupsCollected = 0;

protected:

	/** Initialization */
	virtual void BeginPlay() override;

public:

	/** Receives an interaction event from another actor */
	virtual void ProcessPickup();
};
