// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include <iostream>
#include "Brick.h"
#include "BorderWalls.h"
#include "FrontWalls.h"
#include "Gates.h"
#include <random>
#include <chrono>
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/InputComponent.h"

// Sets default values
ABall::ABall() {
	bReplicates = true;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.01f;
	/*Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;*/
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	RootComponent = MeshComponent;
	//MeshComponent->SetupAttachment(Root);

	MeshComponent->BodyInstance.bLockYRotation = true;
	MeshComponent->BodyInstance.bLockXRotation = true;
	MeshComponent->BodyInstance.bLockZRotation = true;

	MeshComponent->BodyInstance.bLockZTranslation = true;

	MeshComponent->SetSimulatePhysics(true);
	MeshComponent->SetEnableGravity(false);

	MeshComponent->OnComponentHit.AddDynamic(this, &ABall::OnCompHit);

	velocityAtAnyMoment = FVector(0, 0, 0);
	//UPrimitiveComponent Ball;
	/*MeshComponent->AddForce(FVector(-1000, 0, 0));*/

}

// Called when the game starts or when spawned
void ABall::BeginPlay() {
	
	Super::BeginPlay();
	StartMove();
}

void ABall::StartMove() {
	MeshComponent->SetWorldLocation(FVector(60.0f, 770.0f, 50.0f));
	int min = 1;
	int max = 2;

	std::random_device rd;
	std::mt19937 mersenne(rd());

	int preResult = static_cast<int>(mersenne()%(max - min + 1) + min);
	
	if(preResult == 1) MeshComponent->SetAllPhysicsLinearVelocity(FVector(Velocity, 0, 0));
	if(preResult == 2) MeshComponent->SetAllPhysicsLinearVelocity(FVector(-Velocity, 0, 0));
}

// Called every frame
void ABall::Tick(float DeltaTime) {
	velocityAtAnyMoment = MeshComponent->GetPhysicsLinearVelocity();
	UE_LOG(LogTemp, Warning, TEXT("LinearVelocity: %s"), *MeshComponent->GetPhysicsLinearVelocity().ToString());
	Super::Tick(DeltaTime);
	//Hitter = false;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("JUST HIT:FROOOONTWAAALLS %s"), *MeshComponent->GetPhysicsLinearVelocity().ToString()));
	//UE_LOG(LogTemp, Warning, TEXT("LinearVelocity: %s"), *MeshComponent->GetPhysicsLinearVelocity().ToString());
	//UE_LOG(LogTemp, Warning, TEXT("OtherVelocity %s"), *MeshComponent->GetComponentVelocity().ToString());
}

void ABall::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	//this.SetNotify
	/*if((OtherActor != NULL)&&(OtherActor != this)&&(OtherComp != NULL) && (OtherActor->IsA(ABrick::StaticClass()))*/
	if(OtherActor->IsA(ABrick::StaticClass())) {
		if(GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("JUST HIT: %s"), *OtherActor->GetName()))/*, *OtherActor->GetName()*HitComp->GetPhysicsLinearVelocity().ToString(), *this->GetActorRelativeScale3D().ToString() GetActorRelativeScale3D().ToString()*/;
			UE_LOG(LogTemp, Warning, TEXT("LinearVelocity: %s"), *HitComp->GetPhysicsLinearVelocity().ToString());
			MeshComponent->SetAllPhysicsLinearVelocity(FVector(FVector(velocityAtAnyMoment.X*1.05, velocityAtAnyMoment.Y, velocityAtAnyMoment.Z).MirrorByVector(FVector(1, 0, 0))));
			velocityAtAnyMoment.X = velocityAtAnyMoment.X*1.05;
			//	//FVector oldVelocity = HitComp->GetPhysicsLinearVelocity();
		////	FVector newVelocity = FVector(oldVelocity.X*(-1) + 200, oldVelocity.Y, oldVelocity.Z);
		//	HitComp->SetPhysicsLinearVelocity(FVector(-800, 50, 0));
		////	HitComp->AddForce(FVector(-600, 50, 0));
		////	HitComp->SetPhysicsLinearVelocity(newVelocity);
		//	
		}
		//return;
	}

	if(OtherActor->IsA(ABorderWalls::StaticClass())&&(OtherActor != NULL)&&(OtherActor != this)&&(OtherComp != NULL)) {
		if(GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("JUST HIT BOOORDERS: %s"), *OtherActor->GetName() /**HitComp->GetPhysicsLinearVelocity().ToString()*/));
			UE_LOG(LogTemp, Warning, TEXT("LinearVelocity: %s"), *MeshComponent->GetPhysicsLinearVelocity().ToString());

			if(velocityAtAnyMoment != FVector(0, 0, 0)) {
				MeshComponent->SetAllPhysicsLinearVelocity(velocityAtAnyMoment.MirrorByVector(FVector(0, 1, 0)));
				FVector(0, 0, 0);
			}
			//FVector oldVelocity = HitComp->GetPhysicsLinearVelocity();
			//FVector newVelocity = FVector(oldVelocity.X*(1), oldVelocity.Y*(-1), oldVelocity.Z);
			//HitComp->SetPhysicsLinearVelocity(FVector(0, 0, 0), false);

			//HitComp->SetPhysicsLinearVelocity(newVelocity, false);

		}
		//return;
	}

	if(OtherActor->IsA(AFrontWalls::StaticClass())&&(OtherActor != NULL)&&(OtherActor != this)&&(OtherComp != NULL)) {
		if(GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("JUST HIT:FROOOONTWAAALLS %s"), *MeshComponent->GetName() /**HitComp->GetPhysicsLinearVelocity().ToString()*/));

			if(velocityAtAnyMoment != FVector(0, 0, 0)) {
				MeshComponent->SetAllPhysicsLinearVelocity(velocityAtAnyMoment.MirrorByVector(FVector(1, 0, 0)));
				FVector(0, 0, 0);
			}

			UE_LOG(LogTemp, Warning, TEXT("LinearVelocity: %s"), *HitComp->GetPhysicsLinearVelocity().ToString());
			//FVector oldVelocity = MeshComponent->GetPhysicsLinearVelocity();
			//MeshComponent->SetAllPhysicsLinearVelocity(FVector( 0.0f, 0.0f, 0.0f ));
			//FVector newVelocity = FVector(-oldVelocity.X, oldVelocity.Y, oldVelocity.Z);
			//
			///*FVector newVelocit;
			//newVelocit.X = -oldVelocity.X;
			//newVelocit.Y = oldVelocity.Y;
			//newVelocit.Z = oldVelocity.Z;*/
			///*HitComp->SetPhysicsLinearVelocity(FVector(0, 0, 0), false);
			//HitComp->SetPhysicsLinearVelocity(newVelocity, false);*/

			//
			//MeshComponent->SetAllPhysicsLinearVelocity(newVelocity);

		}
		//return;
	}
	//Hitter = true;
}