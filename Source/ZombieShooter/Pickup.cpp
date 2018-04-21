// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
#include "ZombieShooter.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/* Initialize Pickup root and set it to RootComponent */
	PickupRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PickupRoot"), false);
	RootComponent = PickupRoot;

	/* Initialize mesh component and attach it RootComponent */
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"), false);
	PickupMesh->AttachTo(RootComponent);

	/* Initialize sphere collision component and attach it to RootComponent */
	PickupCollision = CreateDefaultSubobject<USphereComponent>(TEXT("PickupCollision"), false);
	PickupCollision->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}



