// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSets/BaseAttributes.h"

#include "Net/UnrealNetwork.h"

void UBaseAttributes::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Constitution, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Toughness, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Fortitude, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Vitality, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Healing, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Enthrallment, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Wisdom, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Dexterity, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Agility, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Finesse, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Intelligence, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Vigor, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Ambition, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Strength, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Charisma, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Coordination, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Severity, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Precision, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Technique, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseAttributes, Focus, COND_OwnerOnly, REPNOTIFY_Always);

}

void UBaseAttributes::OnRep_Constitution(const FGameplayAttributeData& OldConstitution)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Constitution, OldConstitution);
}

void UBaseAttributes::OnRep_Toughness(const FGameplayAttributeData& OldToughness)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Toughness, OldToughness);
}

void UBaseAttributes::OnRep_Fortitude(const FGameplayAttributeData& OldFortitude)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Fortitude, OldFortitude);
}

void UBaseAttributes::OnRep_Vitality(const FGameplayAttributeData& OldVitality)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Vitality, OldVitality);
}

void UBaseAttributes::OnRep_Healing(const FGameplayAttributeData& OldHealing)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Healing, OldHealing);
}

void UBaseAttributes::OnRep_Enthrallment(const FGameplayAttributeData& OldEnthrallment)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Enthrallment, OldEnthrallment);
}

void UBaseAttributes::OnRep_Wisdom(const FGameplayAttributeData& OldWisdom)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Wisdom, OldWisdom);
}

void UBaseAttributes::OnRep_Dexterity(const FGameplayAttributeData& OldDexterity)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Dexterity, OldDexterity);
}

void UBaseAttributes::OnRep_Agility(const FGameplayAttributeData& OldAgility)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Agility, OldAgility);
}

void UBaseAttributes::OnRep_Finesse(const FGameplayAttributeData& OldFinesse)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Finesse, OldFinesse);
}

void UBaseAttributes::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Intelligence, OldIntelligence);
}

void UBaseAttributes::OnRep_Vigor(const FGameplayAttributeData& OldVigor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Vigor, OldVigor);
}

void UBaseAttributes::OnRep_Ambition(const FGameplayAttributeData& OldAmbition)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Ambition, OldAmbition);
}

void UBaseAttributes::OnRep_Strength(const FGameplayAttributeData& OldStrength)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Strength, OldStrength);
}

void UBaseAttributes::OnRep_Charisma(const FGameplayAttributeData& OldCharisma)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Charisma, OldCharisma);
}

void UBaseAttributes::OnRep_Coordination(const FGameplayAttributeData& OldCoordination)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Coordination, OldCoordination);
}

void UBaseAttributes::OnRep_Severity(const FGameplayAttributeData& OldSeverity)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Severity, OldSeverity);
}

void UBaseAttributes::OnRep_Precision(const FGameplayAttributeData& OldPrecision)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Precision, OldPrecision);
}

void UBaseAttributes::OnRep_Technique(const FGameplayAttributeData& OldTechnique)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Technique, OldTechnique);
}

void UBaseAttributes::OnRep_Focus(const FGameplayAttributeData& OldFocus)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributes, Focus, OldFocus);
}
