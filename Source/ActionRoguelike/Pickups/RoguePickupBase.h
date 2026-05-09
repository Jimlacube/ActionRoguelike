// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoguePickupBase.generated.h"

class USphereComponent;

UCLASS()
class ACTIONROGUELIKE_API ARoguePickupBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARoguePickupBase();

protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision")
	TObjectPtr<USphereComponent> SphereComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mesh")
	TObjectPtr<UStaticMeshComponent> PickupMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sound")
	TObjectPtr<USoundBase> PickupSound;
	
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pickup")
	//float PickupValue = 100.0f;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void PostInitializeComponents() override;
	
	UFUNCTION()
	virtual void OnPickupOverlapBegin(UPrimitiveComponent* OverlappedComponent,
	                          AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                          const FHitResult& SweepResult);
	
	void Pickup();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
