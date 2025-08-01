// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributes.generated.h"

/**
 * These are the base attributes belonging to any playable class. These attributes are used to derive other attributes
 * called, "Attribute Stats", these will never be used in combat formulas, like damage. The values stored in these attributes
 * will be used in specific formulas not related to combat or damage. They will be in effect, "Increasing a characters,
 * Constitution", will raise their Health.
 *
 * Defined are the Attributes, Basic Accessors provided by Epic in a Macro, and their replication formulas.
 */
UCLASS()
class GAMEPLAYABILITYSYSTEMMODULE_API UBaseAttributes : public UAttributeSet
{
	GENERATED_BODY()
public:

	/* This function here is responsible for marking the variables we want to replicate. */
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/* Constitution */
	UPROPERTY(BlueprintReadOnly, Category = "Defensive Attributes", ReplicatedUsing = OnRep_Constitution)
	FGameplayAttributeData Constitution;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Constitution);
	

	/* Toughness */
	UPROPERTY(BlueprintReadOnly, Category = "Defensive Attributes", ReplicatedUsing = OnRep_Toughness)
	FGameplayAttributeData Toughness;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Toughness);
	

	/* Fortitude */
	UPROPERTY(BlueprintReadOnly, Category = "Defensive Attributes", ReplicatedUsing = OnRep_Fortitude)
	FGameplayAttributeData Fortitude;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Fortitude);
	

	/* Vitality */
	UPROPERTY(BlueprintReadOnly, Category = "Defensive Attributes", ReplicatedUsing = OnRep_Vitality)
	FGameplayAttributeData Vitality;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Vitality);
	

	/* Healing */
	UPROPERTY(BlueprintReadOnly, Category = "Defensive Attributes", ReplicatedUsing = OnRep_Healing)
	FGameplayAttributeData Healing;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Healing);
	

	/* Enthrallment */
	UPROPERTY(BlueprintReadOnly, Category = "Defensive Attributes", ReplicatedUsing = OnRep_Enthrallment)
	FGameplayAttributeData Enthrallment;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Enthrallment);
	

	/* Wisdom */
	UPROPERTY(BlueprintReadOnly, Category = "Utility Attributes", ReplicatedUsing = OnRep_Wisdom)
	FGameplayAttributeData Wisdom;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Wisdom);
	

	/* Dexterity */
	UPROPERTY(BlueprintReadOnly, Category = "Utility Attributes", ReplicatedUsing = OnRep_Dexterity)
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Dexterity);
	

	/* Agility */
	UPROPERTY(BlueprintReadOnly, Category = "Utility Attributes", ReplicatedUsing = OnRep_Agility)
	FGameplayAttributeData Agility;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Agility);
	

	/* Finesse */
	UPROPERTY(BlueprintReadOnly, Category = "Utility Attributes", ReplicatedUsing = OnRep_Finesse)
	FGameplayAttributeData Finesse;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Finesse);
	

	/* Intelligence */
	UPROPERTY(BlueprintReadOnly, Category = "Utility Attributes", ReplicatedUsing = OnRep_Intelligence)
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Intelligence);
	

	/* Vigor */
	UPROPERTY(BlueprintReadOnly, Category = "Utility Attributes", ReplicatedUsing = OnRep_Vigor)
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Vigor);
	

	/* Ambition */
	UPROPERTY(BlueprintReadOnly, Category = "Utility Attributes", ReplicatedUsing = OnRep_Ambition)
	FGameplayAttributeData Ambition;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Ambition);
	

	/* Strength */
	UPROPERTY(BlueprintReadOnly, Category = "Offensive Attributes", ReplicatedUsing = OnRep_Strength)
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Strength);
	

	/* Charisma */
	UPROPERTY(BlueprintReadOnly, Category = "Offensive Attributes", ReplicatedUsing = OnRep_Charisma)
	FGameplayAttributeData Charisma;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Charisma);
	

	/* Coordination */
	UPROPERTY(BlueprintReadOnly, Category = "Offensive Attributes", ReplicatedUsing = OnRep_Coordination)
	FGameplayAttributeData Coordination;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Coordination);
	

	/* Severity */
	UPROPERTY(BlueprintReadOnly, Category = "Offensive Attributes", ReplicatedUsing = OnRep_Severity)
	FGameplayAttributeData Severity;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Severity);
	

	/* Precision */
	UPROPERTY(BlueprintReadOnly, Category = "Offensive Attributes", ReplicatedUsing = OnRep_Precision)
	FGameplayAttributeData Precision;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Precision);
	

	/* Technique */
	UPROPERTY(BlueprintReadOnly, Category = "Offensive Attributes", ReplicatedUsing = OnRep_Technique)
	FGameplayAttributeData Technique;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Technique);
	

	/* Focus */
	UPROPERTY(BlueprintReadOnly, Category = "Offensive Attributes", ReplicatedUsing = OnRep_Focus)
	FGameplayAttributeData Focus;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseAttributes, Focus);
	


	
	UFUNCTION()
	virtual void OnRep_Constitution(const FGameplayAttributeData& OldConstitution);
	
	UFUNCTION()
	virtual void OnRep_Toughness(const FGameplayAttributeData& OldToughness);
	
	UFUNCTION()
	virtual void OnRep_Fortitude(const FGameplayAttributeData& OldFortitude);
	
	UFUNCTION()
	virtual void OnRep_Vitality(const FGameplayAttributeData& OldVitality);
	
	UFUNCTION()
	virtual void OnRep_Healing(const FGameplayAttributeData& OldHealing);
	
	UFUNCTION()
	virtual void OnRep_Enthrallment(const FGameplayAttributeData& OldEnthrallment);
	
	UFUNCTION()
	virtual void OnRep_Wisdom(const FGameplayAttributeData& OldWisdom);
	
	UFUNCTION()
	virtual void OnRep_Dexterity(const FGameplayAttributeData& OldDexterity);
	
	UFUNCTION()
	virtual void OnRep_Agility(const FGameplayAttributeData& OldAgility);
	
	UFUNCTION()
	virtual void OnRep_Finesse(const FGameplayAttributeData& OldFinesse);
	
	UFUNCTION()
	virtual void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence);
	
	UFUNCTION()
	virtual void OnRep_Vigor(const FGameplayAttributeData& OldVigor);
	
	UFUNCTION()
	virtual void OnRep_Ambition(const FGameplayAttributeData& OldAmbition);
	
	UFUNCTION()
	virtual void OnRep_Strength(const FGameplayAttributeData& OldStrength);
	
	UFUNCTION()
	virtual void OnRep_Charisma(const FGameplayAttributeData& OldCharisma);
	
	UFUNCTION()
	virtual void OnRep_Coordination(const FGameplayAttributeData& OldCoordination);
	
	UFUNCTION()
	virtual void OnRep_Severity(const FGameplayAttributeData& OldSeverity);
	
	UFUNCTION()
	virtual void OnRep_Precision(const FGameplayAttributeData& OldPrecision);
	
	UFUNCTION()
	virtual void OnRep_Technique(const FGameplayAttributeData& OldTechnique);
	
	UFUNCTION()
	virtual void OnRep_Focus(const FGameplayAttributeData& OldFocus);
	
};
