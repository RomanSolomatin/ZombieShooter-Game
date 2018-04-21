// Fill out your copyright notice in the Description page of Project Settings.

#include "ZombieSpawner.h"
#include "ZombieShooter.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AZombieSpawner::AZombieSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set up root component
	ZombieSpawnRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"), false);
	RootComponent = ZombieSpawnRootComponent;

	// Set up Box component and attach BoxComponent to root component
	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"), false);
	SpawnVolume->AttachTo(ZombieSpawnRootComponent);

}

// Called when the game starts or when spawned
void AZombieSpawner::BeginPlay()
{

	Super::BeginPlay();
	if(Role >= ROLE_Authority)
		SpawnZombie();
}

// Called every frame
void AZombieSpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AZombieSpawner::SpawnZombie()
{
	ZombieBoxSpawnExtent = this->SpawnVolume->GetScaledBoxExtent();
	ZombieBoxSpawnLocation = this->SpawnVolume->GetComponentLocation();
	FTimerHandle SpawnZombieTimerHandle;

	GetWorld()->GetTimerManager().SetTimer(SpawnZombieTimerHandle, this, &AZombieSpawner::SpawnSingleZombie, 1, true, 0);
}

void AZombieSpawner::SpawnSingleZombie()
{
	TArray<AActor*> ZombieArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ZombieBlueprintClass, ZombieArray);
	if (ZombieArray.Num() < MaxZombieNum)
	{
		FVector ZombieSpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(ZombieBoxSpawnLocation, ZombieBoxSpawnExtent);
		auto ZombieInstance = GetWorld()->SpawnActor(ZombieBlueprintClass, &ZombieSpawnLocation);
	}
}

