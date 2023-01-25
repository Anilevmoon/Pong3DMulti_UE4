// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

//#include "BrickController.h"

#include "GameFramework/Pawn.h"
#include "Brick.generated.h"

UCLASS()
class MYPROJECT2_API ABrick : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABrick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Root")
		class USceneComponent* Rooot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components")
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Components")
		class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UFloatingPawnMovement* PawnMovement;

public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
		class UStaticMeshComponent* meshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MovementForce;

	
	//void GoLeftOrRight(float Axis);
	//APlayerController PC1();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
