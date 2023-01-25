// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"

// Sets default values
ABrick::ABrick()
{
	bReplicates = true;
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Rooot = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Rooot;
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	
	PawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");

	meshComponent->SetupAttachment(Rooot);
	SpringArm->SetupAttachment(meshComponent);
	Camera->SetupAttachment(SpringArm);


	meshComponent->SetSimulatePhysics(true);
	meshComponent->SetEnableGravity(false);
	MovementForce = 100000;

	SpringArm->TargetArmLength = 400.0f;

	meshComponent->BodyInstance.bLockYRotation = true;
	meshComponent->BodyInstance.bLockXRotation = true;
	meshComponent->BodyInstance.bLockZRotation = true;

	meshComponent->BodyInstance.bLockXTranslation = true;
	meshComponent->BodyInstance.bLockZTranslation = true;
}


//void ABrick::GoLeftOrRight(float Axis) {
//	//UE_LOG(LogTemp, Warning, TEXT("Move forward axis %f"), Axis);
//	FVector ForceToAdd = FVector(0, 1, 0) * (100000 * (Axis));
//	//AddMovementInput(GetActorRightVector(), Axis, false);
//	meshComponent->AddForce(-ForceToAdd);
//}


// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame

void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



 //Called to bind functionality to input
//void ABrick::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	//Super::SetupPlayerInputComponent(PlayerInputComponent);
//	//PlayerInputComponent->BindAxis("GoLeter/Righter", this, &ABrick::GoLeftOrRight);
//
//}

