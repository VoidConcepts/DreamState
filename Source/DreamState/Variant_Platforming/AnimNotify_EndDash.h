// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_EndDash.generated.h"

/**
 *  AnimNotify to finish the dash animation and restore player control
 */
UCLASS(meta = (GUID = "99E50F36-44AA8219-8AF6CF82-9D27013B", FileName = "AnimNotify_EndDash.h", AbsoluePath = "D:/DreamState/Source/DreamState/Variant_Platforming/AnimNotify_EndDash.h" ))
class UAnimNotify_EndDash : public UAnimNotify
{
	GENERATED_BODY()
	
public:

	/** Perform the Anim Notify */
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

	/** Get the notify name */
	virtual FString GetNotifyName_Implementation() const override;
};
