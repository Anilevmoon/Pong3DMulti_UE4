// Fill out your copyright notice in the Description page of Project Settings.


#include "FrontWalls.h"

// Sets default values
AFrontWalls::AFrontWalls()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh1");
	RootComponent = MeshComponent;
	MeshComponent->SetSimulatePhysics(false);

}

// Called when the game starts or when spawned
void AFrontWalls::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFrontWalls::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

