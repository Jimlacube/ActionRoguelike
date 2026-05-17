// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueBTDecorator_IsLowHealth.h"

#include "AIController.h"
#include "ActionSystem/RogueActionSystemComponent.h"

bool URogueBTDecorator_IsLowHealth::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp,
                                                               uint8* NodeMemory) const
{
	APawn* Pawn = OwnerComp.GetAIOwner()->GetPawn();
	check(Pawn)
	
	URogueActionSystemComponent* ActionSystemComponent = Pawn->GetComponentByClass<URogueActionSystemComponent>();
	if (ensure(ActionSystemComponent))
	{
		return (ActionSystemComponent->GetHealth() / ActionSystemComponent->GetHealthMax()) <= HealthLowerThanPercent;
	}
	
	return false;
}
