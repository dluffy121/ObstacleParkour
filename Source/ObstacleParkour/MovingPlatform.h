// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEPARKOUR_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FString Name;

#pragma region Movement

private:
	void MovePlatform(float DeltaTime);

	bool ShouldPlatformReverseMovement() const;

public:
	UPROPERTY(EditAnywhere, Category = "Platform Movement")
		float MoveDistance = 10;

	UPROPERTY(EditAnywhere, Category = "Platform Movement")
		FVector PlatformVelocity = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(VisibleAnywhere, Category = "Platform Movement")
		FVector PlatformInitialLocation;

#pragma endregion

#pragma region Rotate

private:
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReverseRotate() const;

public:
	UPROPERTY(EditAnywhere, Category = "Platform Rotate")
		float RotateAngle = 10;

	UPROPERTY(EditAnywhere, Category = "Platform Rotate")
		FRotator PlatformAngularVelocity = FRotator(0.0f, 0.0f, 0.0f);

	UPROPERTY(VisibleAnywhere, Category = "Platform Rotate")
		FRotator PlatformInitialRotation;

#pragma endregion

#pragma region Scale

private:
	void ScalePlatform(float DeltaTime);

	bool ShouldPlatformRevereseScale() const;

public:
	UPROPERTY(EditAnywhere, Category = "Platform Scaling")
		float ScaleDistance = 10;

	UPROPERTY(EditAnywhere, Category = "Platform Scaling")
		FVector PlatformScaleVelocity = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(VisibleAnywhere, Category = "Platform Scaling")
		FVector PlatformInitalScale;

#pragma endregion

};
