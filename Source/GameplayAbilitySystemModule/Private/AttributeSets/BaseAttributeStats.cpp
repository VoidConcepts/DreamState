// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSets/BaseAttributeStats.h"

#include "Net/UnrealNetwork.h"

void UBaseAttributeStats::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, Health, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, Defense, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, AbilityDefense, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, HealthRegen, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, HealingPower, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, LifeSteal, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, Mana, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, Endurance, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, MovementSpeed, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, AttackSpeed, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, ManaRegen, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, EnduranceRegen, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, CoolDownReduction, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, Power, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, AbilityPower, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, BasicAttackPower, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, CriticalMagnitude, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, CriticalChance, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, Impact, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributeStats, Clarity, COND_OwnerOnly, REPNOTIFY_Always);
}

void UBaseAttributeStats::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, Health, OldHealth);
}

void UBaseAttributeStats::OnRep_Defense(const FGameplayAttributeData& OldDefense)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, Defense, OldDefense);
}

void UBaseAttributeStats::OnRep_AbilityDefense(const FGameplayAttributeData& OldAbilityDefense)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, AbilityDefense, OldAbilityDefense);
}

void UBaseAttributeStats::OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, HealthRegen, OldHealthRegen);
}

void UBaseAttributeStats::OnRep_HealingPower(const FGameplayAttributeData& OldHealingPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, HealingPower, OldHealingPower);
}

void UBaseAttributeStats::OnRep_LifeSteal(const FGameplayAttributeData& OldLifeSteal)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, LifeSteal, OldLifeSteal);
}

void UBaseAttributeStats::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, Mana, OldMana);
}

void UBaseAttributeStats::OnRep_Endurance(const FGameplayAttributeData& OldEndurance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, Endurance, OldEndurance);
}

void UBaseAttributeStats::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, MovementSpeed, OldMovementSpeed);
}

void UBaseAttributeStats::OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, AttackSpeed, OldAttackSpeed);
}

void UBaseAttributeStats::OnRep_ManaRegen(const FGameplayAttributeData& OldManaRegen)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, ManaRegen, OldManaRegen);
}

void UBaseAttributeStats::OnRep_EnduranceRegen(const FGameplayAttributeData& OldEnduranceRegen)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, EnduranceRegen, OldEnduranceRegen);
}

void UBaseAttributeStats::OnRep_CoolDownReduction(const FGameplayAttributeData& OldCoolDownReduction)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, CoolDownReduction, OldCoolDownReduction);
}

void UBaseAttributeStats::OnRep_Power(const FGameplayAttributeData& OldPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, Power, OldPower);
}

void UBaseAttributeStats::OnRep_AbilityPower(const FGameplayAttributeData& OldAbilityPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, AbilityPower, OldAbilityPower);
}

void UBaseAttributeStats::OnRep_BasicAttackPower(const FGameplayAttributeData& OldBasicAttackPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, BasicAttackPower, OldBasicAttackPower);
}

void UBaseAttributeStats::OnRep_CriticalMagnitude(const FGameplayAttributeData& OldCriticalMagnitude)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, CriticalMagnitude, OldCriticalMagnitude);
}

void UBaseAttributeStats::OnRep_CriticalChance(const FGameplayAttributeData& OldCriticalChance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, CriticalChance, OldCriticalChance);
}

void UBaseAttributeStats::OnRep_Impact(const FGameplayAttributeData& OldImpact)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, Impact, OldImpact);
}

void UBaseAttributeStats::OnRep_Clarity(const FGameplayAttributeData& OldClarity)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeStats, Clarity, OldClarity);
}
