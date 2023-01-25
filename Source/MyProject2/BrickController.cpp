// Fill out your copyright notice in the Description page of Project Settings.


#include "BrickController.h"

ABrickController::ABrickController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	this->PrimaryActorTick.bCanEverTick = true;
}


void ABrickController::SetPawn(APawn* InPawn) {
	Super::SetPawn(InPawn);
	APawn* ExectPawn = this->GetPawn();
	//this->MainCorePawn = (ExectPawn ? Cast<ABrick>(ExectPawn) : nullptr);
	this->MainCorePawn = Cast<ABrick>(ExectPawn);
}


void ABrickController::GoLeftOrRight(float Axis) {
	/*if(this->GetActorForwardVector().X > 0) {

	}*/
	FVector ForceToAdd = FVector(0, 1, 0) * (100000 * (Axis));

	MainCorePawn->meshComponent->AddForce(ForceToAdd);
}


void ABrickController::SetupInputComponent() {
	Super::SetupInputComponent();
	InputComponent->BindAxis("GoLeter/Righter", this, &ABrickController::GoLeftOrRight);
}

