// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeStats.generated.h"


/**
 * 
 */
UCLASS(meta = (GUID = "0B275635-4EACF7CD-100304AB-59611632", FileName = "BaseAttributeStats.h", AbsoluePath = "D:/DreamState/Source/GameplayAbilitySystemModule/Public/AttributeSets/BaseAttributeStats.h" ))
class GAMEPLAYABILITYSYSTEMMODULE_API UBaseAttributeStats : public UAttributeSet
{
	GENERATED_BODY()

public:
	
	
	/* This function here is responsible for marking the variables we want to replicate. */
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	/* Health */
	UPROPERTY(BlueprintReadOnly, Category = "Defensive Stats", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, Health);

	/* Defense */
	UPROPERTY(BlueprintReadOnly, Category = "Defensive Stats", ReplicatedUsing = OnRep_Defense)
	FGameplayAttributeData Defense;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, Defense);

	/* AbilityDefense */
	UPROPERTY(BlueprintReadOnly, Category = "Defensive Stats", ReplicatedUsing = OnRep_AbilityDefense)
	FGameplayAttributeData AbilityDefense;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, AbilityDefense);

	/* HealthRegen */
	UPROPERTY(BlueprintReadOnly, Category = "Defensive Stats", ReplicatedUsing = OnRep_HealthRegen)
	FGameplayAttributeData HealthRegen;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, HealthRegen);

	/* HealingPower */
	UPROPERTY(BlueprintReadOnly, Category = "Defensive Stats", ReplicatedUsing = OnRep_HealingPower)
	FGameplayAttributeData HealingPower;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, HealingPower);

	/* LifeSteal */
	UPROPERTY(BlueprintReadOnly, Category = "Defensive Stats", ReplicatedUsing = OnRep_LifeSteal)
	FGameplayAttributeData LifeSteal;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, LifeSteal);

	/* Mana */
	UPROPERTY(BlueprintReadOnly, Category = "Utility Stats", ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, Mana);

	/* Endurance */
	UPROPERTY(BlueprintReadOnly, Category = "Utility Stats", ReplicatedUsing = OnRep_Endurance)
	FGameplayAttributeData Endurance;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, Endurance);

	/* MovementSpeed */
	UPROPERTY(BlueprintReadOnly, Category = "Utility Stats", ReplicatedUsing = OnRep_MovementSpeed)
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, MovementSpeed);

	/* AttackSpeed */
	UPROPERTY(BlueprintReadOnly, Category = "Utility Stats", ReplicatedUsing = OnRep_AttackSpeed)
	FGameplayAttributeData AttackSpeed;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, AttackSpeed);

	/* ManaRegen */
	UPROPERTY(BlueprintReadOnly, Category = "Utility Stats", ReplicatedUsing = OnRep_ManaRegen)
	FGameplayAttributeData ManaRegen;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, ManaRegen);

	/* EnduranceRegen */
	UPROPERTY(BlueprintReadOnly, Category = "Utility Stats", ReplicatedUsing = OnRep_EnduranceRegen)
	FGameplayAttributeData EnduranceRegen;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, EnduranceRegen);

	/* CoolDownReduction */
	UPROPERTY(BlueprintReadOnly, Category = "Utility Stats", ReplicatedUsing = OnRep_CoolDownReduction)
	FGameplayAttributeData CoolDownReduction;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, CoolDownReduction);

	/* Power */
	UPROPERTY(BlueprintReadOnly, Category = "Offensive Stats", ReplicatedUsing = OnRep_Power)
	FGameplayAttributeData Power;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, Power);

	/* AbilityPower */
	UPROPERTY(BlueprintReadOnly, Category = "Offensive Stats", ReplicatedUsing = OnRep_AbilityPower)
	FGameplayAttributeData AbilityPower;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, AbilityPower);

	/* BasicAttackPower */
	UPROPERTY(BlueprintReadOnly, Category = "Offensive Stats", ReplicatedUsing = OnRep_BasicAttackPower)
	FGameplayAttributeData BasicAttackPower;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, BasicAttackPower);

	/* CriticalMagnitude */
	UPROPERTY(BlueprintReadOnly, Category = "Offensive Stats", ReplicatedUsing = OnRep_CriticalMagnitude)
	FGameplayAttributeData CriticalMagnitude;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, CriticalMagnitude);

	/* CriticalChance */
	UPROPERTY(BlueprintReadOnly, Category = "Offensive Stats", ReplicatedUsing = OnRep_CriticalChance)
	FGameplayAttributeData CriticalChance;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, CriticalChance);

	/* Impact */
	UPROPERTY(BlueprintReadOnly, Category = "Offensive Stats", ReplicatedUsing = OnRep_Impact)
	FGameplayAttributeData Impact;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, Impact);

	/* Clarity */
	UPROPERTY(BlueprintReadOnly, Category = "Offensive Stats", ReplicatedUsing = OnRep_Clarity)
	FGameplayAttributeData Clarity;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributeStats, Clarity);


	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);
	
	UFUNCTION()
	virtual void OnRep_Defense(const FGameplayAttributeData& OldDefense);
	
	UFUNCTION()
	virtual void OnRep_AbilityDefense(const FGameplayAttributeData& OldAbilityDefense);
	
	UFUNCTION()
	virtual void OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen);
	
	UFUNCTION()
	virtual void OnRep_HealingPower(const FGameplayAttributeData& OldHealingPower);
	
	UFUNCTION()
	virtual void OnRep_LifeSteal(const FGameplayAttributeData& OldLifeSteal);
	
	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);
	
	UFUNCTION()
	virtual void OnRep_Endurance(const FGameplayAttributeData& OldEndurance);
	
	UFUNCTION()
	virtual void OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed);
	
	UFUNCTION()
	virtual void OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed);
	
	UFUNCTION()
	virtual void OnRep_ManaRegen(const FGameplayAttributeData& OldManaRegen);
	
	UFUNCTION()
	virtual void OnRep_EnduranceRegen(const FGameplayAttributeData& OldEnduranceRegen);
	
	UFUNCTION()
	virtual void OnRep_CoolDownReduction(const FGameplayAttributeData& OldCoolDownReduction);
	
	UFUNCTION()
	virtual void OnRep_Power(const FGameplayAttributeData& OldPower);
	
	UFUNCTION()
	virtual void OnRep_AbilityPower(const FGameplayAttributeData& OldAbilityPower);
	
	UFUNCTION()
	virtual void OnRep_BasicAttackPower(const FGameplayAttributeData& OldBasicAttackPower);
	
	UFUNCTION()
	virtual void OnRep_CriticalMagnitude(const FGameplayAttributeData& OldCriticalMagnitude);
	
	UFUNCTION()
	virtual void OnRep_CriticalChance(const FGameplayAttributeData& OldCriticalChance);
	
	UFUNCTION()
	virtual void OnRep_Impact(const FGameplayAttributeData& OldImpact);
	
	UFUNCTION()
	virtual void OnRep_Clarity(const FGameplayAttributeData& OldClarity);
	
};	
