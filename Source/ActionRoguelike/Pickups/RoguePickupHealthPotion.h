// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoguePickupBase.h"
#include "RoguePickupHealthPotion.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ARoguePickupHealthPotion : public ARoguePickupBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARoguePickupHealthPotion();

protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float HealingAmount = 100.0f;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnPickupOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
