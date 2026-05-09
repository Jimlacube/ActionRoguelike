// Fill out your copyright notice in the Description page of Project Settings.


#include "RoguePickupHealthPotion.h"

#include "ActionSystem/RogueActionSystemComponent.h"


// Sets default values
ARoguePickupHealthPotion::ARoguePickupHealthPotion()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARoguePickupHealthPotion::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARoguePickupHealthPotion::OnPickupOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	TObjectPtr<URogueActionSystemComponent> ActionSystemComp = OtherActor->FindComponentByClass<URogueActionSystemComponent>();
	
	if (ensure(ActionSystemComp != nullptr) && !ActionSystemComp->IsAtMaxHealth())
	{
		ActionSystemComp->ApplyHealthChange(HealingAmount);
		
		Pickup();
	}
}

// Called every frame
void ARoguePickupHealthPotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

