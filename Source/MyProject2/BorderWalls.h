// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BorderWalls.generated.h"

UCLASS()
class MYPROJECT2_API ABorderWalls : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABorderWalls();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
		class UStaticMeshComponent* MeshComponent1;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
