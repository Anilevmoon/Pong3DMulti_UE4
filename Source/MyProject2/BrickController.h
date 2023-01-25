// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Brick.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"
#include "BrickController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API ABrickController : public APlayerController
{
	GENERATED_BODY()
	public:
	ABrickController(const FObjectInitializer& ObjectInitializer);

	virtual void GoLeftOrRight(float Axis);
	//virtual void SetupInputComponent() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=CustomProperties) ABrick* MainCorePawn;

	//Overriding SetPawn
	virtual void SetPawn(APawn* InPawn) override;

	////Overriding SetupInputComponent
	virtual void SetupInputComponent() override;

	////When key is pressed, just show debug message.
	//UFUNCTION() void KeyPressed(float Value);


};
