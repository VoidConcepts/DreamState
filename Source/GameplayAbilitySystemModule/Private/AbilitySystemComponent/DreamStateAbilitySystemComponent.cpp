// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystemComponent/DreamStateAbilitySystemComponent.h"
#include "BaseAttributes.h"
#include "BaseAttributeStats.h"

// Sets default values for this component's properties
UDreamStateAbilitySystemComponent::UDreamStateAbilitySystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	CreateDefaultSubobject<UBaseAttributes>(TEXT("BaseAttributes"), false);
	CreateDefaultSubobject<UBaseAttributeStats>(TEXT("BaseAttributeStats"), false);
	SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	SetIsReplicated(true);
	

	// ...
}

UDreamStateAbilitySystemComponent* UDreamStateAbilitySystemComponent::GetDreamStateAbilitySystemComponent()
{
	return this;
}


// Called when the game starts
void UDreamStateAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDreamStateAbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

