// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "RogueBTDecorator_IsLowHealth.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API URogueBTDecorator_IsLowHealth : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, Category="AI")
	float HealthLowerThanPercent = 0.3f;
	
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
