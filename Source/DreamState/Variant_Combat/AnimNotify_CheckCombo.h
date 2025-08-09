// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_CheckCombo.generated.h"

/**
 *  AnimNotify to perform a combo string check.
 */
UCLASS(meta = (GUID = "B8F264AF-431CAC2E-556761A4-7CA940CB", FileName = "AnimNotify_CheckCombo.h", AbsoluePath = "D:/DreamState/Source/DreamState/Variant_Combat/AnimNotify_CheckCombo.h" ))
class UAnimNotify_CheckCombo : public UAnimNotify
{
	GENERATED_BODY()
	
public:

	/** Perform the Anim Notify */
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

	/** Get the notify name */
	virtual FString GetNotifyName_Implementation() const override;
};
