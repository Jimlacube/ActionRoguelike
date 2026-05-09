// Fill out your copyright notice in the Description page of Project Settings.


#include "RoguePickupBase.h"

#include "RogueGameTypes.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ARoguePickupBase::ARoguePickupBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Comp"));
	RootComponent = SphereComponent;
	SphereComponent->SetCollisionProfileName("Pickup");
	SphereComponent->SetSphereRadius(120.0f);
	
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pickup Mesh"));
	PickupMesh->SetupAttachment(SphereComponent);
	PickupMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void ARoguePickupBase::BeginPlay()
{
	Super::BeginPlay();	
}

void ARoguePickupBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ARoguePickupBase::OnPickupOverlapBegin);
}

void ARoguePickupBase::OnPickupOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	
}

void ARoguePickupBase::Pickup()
{
	UGameplayStatics::PlaySoundAtLocation(this, PickupSound, GetActorLocation(), FRotator::ZeroRotator);
	Destroy();
}

// Called every frame
void ARoguePickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

