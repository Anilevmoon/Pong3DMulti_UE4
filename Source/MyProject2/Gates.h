// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gates.generated.h"

UCLASS()
class MYPROJECT2_API AGates : public AActor {
	GENERATED_BODY()

	public:
	// Sets default values for this actor's properties
	AGates();

	protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class UStaticMeshComponent* MeshComponent;

	public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
