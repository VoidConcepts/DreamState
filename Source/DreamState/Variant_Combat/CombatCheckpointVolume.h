// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "CombatCheckpointVolume.generated.h"

UCLASS(meta = (GUID = "5556EF61-4B2A2631-FF6C4B87-345EB2B9", FileName = "CombatCheckpointVolume.h", AbsoluePath = "D:/DreamState/Source/DreamState/Variant_Combat/CombatCheckpointVolume.h" ))
class ACombatCheckpointVolume : public AActor
{
	GENERATED_BODY()
	
	/** Collision box volume */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true"))
	UBoxComponent* Box;

public:	
	
	/** Constructor */
	ACombatCheckpointVolume();

protected:

	/** Set to true after use to avoid accidentally resetting the checkpoint */
	bool bCheckpointUsed = false;

	/** Handles overlaps with the box volume */
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
