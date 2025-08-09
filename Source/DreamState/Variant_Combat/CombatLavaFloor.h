// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CombatLavaFloor.generated.h"

class UStaticMeshComponent;
class UPrimitiveComponent;

/**
 *  A basic actor that applies damage on contact through the ICombatDamageable interface. 
 */
UCLASS(meta = (GUID = "36F1CB73-4A23E5DA-AE5B16BF-284DB49D", FileName = "CombatLavaFloor.h", AbsoluePath = "D:/DreamState/Source/DreamState/Variant_Combat/CombatLavaFloor.h" ))
class ACombatLavaFloor : public AActor
{
	GENERATED_BODY()
	
	/** Floor mesh */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

protected:

	/** Amount of damage to deal on contact */
	UPROPERTY(EditAnywhere, Category="Damage")
	float Damage = 10000.0f;

public:	

	/** Constructor */
	ACombatLavaFloor();

protected:

	/** Blocking hit handler */
	UFUNCTION()
	void OnFloorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
