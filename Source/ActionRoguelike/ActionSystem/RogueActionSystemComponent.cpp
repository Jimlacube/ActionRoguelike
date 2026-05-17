// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueActionSystemComponent.h"


URogueActionSystemComponent::URogueActionSystemComponent()
{
	
}

bool URogueActionSystemComponent::IsAtHealthMax() const
{
	return FMath::IsNearlyEqual(Attributes.Health, Attributes.HealthMax);
}

void URogueActionSystemComponent::ApplyHealthChange(float InValueChange)
{
	float OldHealth = Attributes.Health;

	float MaxHealth = Attributes.HealthMax;
	
	Attributes.Health = FMath::Clamp(Attributes.Health + InValueChange, 0.0f, MaxHealth);
	
	if (!FMath::IsNearlyZero(OldHealth))
	{
		OnHealthChanged.Broadcast(Attributes.Health, OldHealth);
	}
	
	UE_LOG(LogTemp, Log, TEXT("New health: %f, Max health: %f"), Attributes.Health, MaxHealth);
}

float URogueActionSystemComponent::GetHealth() const
{
	return Attributes.Health;
}

float URogueActionSystemComponent::GetHealthMax() const
{
	return Attributes.HealthMax;
}
