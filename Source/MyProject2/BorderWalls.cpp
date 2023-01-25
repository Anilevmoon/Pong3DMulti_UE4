// Fill out your copyright notice in the Description page of Project Settings.


#include "BorderWalls.h"

// Sets default values
ABorderWalls::ABorderWalls()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent1 = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh1");
	RootComponent = MeshComponent1;
	MeshComponent1->SetSimulatePhysics(false);
}

// Called when the game starts or when spawned
void ABorderWalls::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABorderWalls::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

