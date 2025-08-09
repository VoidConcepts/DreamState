// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInput/Public/InputAction.h"
#include "SideScrollingPlayerController.generated.h"

class ASideScrollingCharacter;
class UInputMappingContext;

/**
 *  A simple Side Scrolling Player Controller
 *  Manages input mappings
 *  Respawns the player pawn at the player start if it is destroyed
 */
UCLASS(meta = (GUID = "4EB8B5ED-446228C9-0581BDA7-3B7CDC21", FileName = "SideScrollingPlayerController.h", AbsoluePath = "D:/DreamState/Source/DreamState/Variant_SideScrolling/SideScrollingPlayerController.h" ))
class ASideScrollingPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	/** Input mapping context for this player */
	UPROPERTY(EditAnywhere, Category="Input")
	TArray<UInputMappingContext*> DefaultMappingContexts;

	/** Character class to respawn when the possessed pawn is destroyed */
	UPROPERTY(EditAnywhere, Category="Respawn")
	TSubclassOf<ASideScrollingCharacter> CharacterClass;

protected:

	/** Initialize input bindings */
	virtual void SetupInputComponent() override;

	/** Pawn initialization */
	virtual void OnPossess(APawn* InPawn) override;

	/** Called if the possessed pawn is destroyed */
	UFUNCTION()
	void OnPawnDestroyed(AActor* DestroyedActor);

};
