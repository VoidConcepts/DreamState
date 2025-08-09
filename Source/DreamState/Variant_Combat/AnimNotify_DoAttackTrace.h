// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_DoAttackTrace.generated.h"

/**
 *  AnimNotify to tell the actor to perform an attack trace check to look for targets to damage.
 */
UCLASS(meta = (GUID = "B28D1916-4C871E79-DB51A286-DE021A1D", FileName = "AnimNotify_DoAttackTrace.h", AbsoluePath = "D:/DreamState/Source/DreamState/Variant_Combat/AnimNotify_DoAttackTrace.h" ))
class UAnimNotify_DoAttackTrace : public UAnimNotify
{
	GENERATED_BODY()
	
protected:

	/** Source bone for the attack trace */
	UPROPERTY(EditAnywhere, Category="Attack")
	FName AttackBoneName;

public:

	/** Perform the Anim Notify */
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

	/** Get the notify name */
	virtual FString GetNotifyName_Implementation() const override;
};
