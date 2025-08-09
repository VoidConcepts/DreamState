// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CombatActivationVolume.generated.h"

class UBoxComponent;

/**
 *  A simple volume that activates a list of actors when the player pawn enters.
 */
UCLASS(meta = (GUID = "6C88A93A-4818DFCA-2BB0B3AB-13799139", FileName = "CombatActivationVolume.h", AbsoluePath = "D:/DreamState/Source/DreamState/Variant_Combat/CombatActivationVolume.h" ))
class ACombatActivationVolume : public AActor
{
	GENERATED_BODY()

	/** Collision box volume */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true"))
	UBoxComponent* Box;
	
protected:

	/** List of actors to activate when this volume is entered */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Activation Volume")
	TArray<AActor*> ActorsToActivate;

public:	
	
	/** Constructor */
	ACombatActivationVolume();

protected:

	/** Handles overlaps with the box volume */
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
