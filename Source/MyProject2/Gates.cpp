// Fill out your copyright notice in the Description page of Project Settings.


#include "Gates.h"

// Sets default values
AGates::AGates() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	RootComponent = MeshComponent;
	MeshComponent->SetSimulatePhysics(false);
}

// Called when the game starts or when spawned
void AGates::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void AGates::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

