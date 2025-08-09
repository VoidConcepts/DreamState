// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_CheckChargedAttack.generated.h"

/**
 *  AnimNotify to perform a charged attack hold check.
 */
UCLASS(meta = (GUID = "F232BF12-4D2CEBF8-E4BFAB82-235A0315", FileName = "AnimNotify_CheckChargedAttack.h", AbsoluePath = "D:/DreamState/Source/DreamState/Variant_Combat/AnimNotify_CheckChargedAttack.h" ))
class UAnimNotify_CheckChargedAttack : public UAnimNotify
{
	GENERATED_BODY()
	
public:

	/** Perform the Anim Notify */
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

	/** Get the notify name */
	virtual FString GetNotifyName_Implementation() const override;
};
