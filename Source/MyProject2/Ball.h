// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Ball.generated.h"

UCLASS()
class MYPROJECT2_API ABall : public AActor {
	GENERATED_BODY()

	public:
	// Sets default values for this actor's properties
	ABall();

	protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void StartMove();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Root")
		class USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UStaticMeshComponent* MeshComponent;

	public:
	const float Velocity = 600.0f;
	FVector velocityAtAnyMoment;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
