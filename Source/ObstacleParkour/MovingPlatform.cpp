// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	PlatformInitialLocation = GetActorLocation();
	PlatformInitialRotation = GetActorRotation();
	PlatformInitalScale = GetActorScale3D();

	Name = GetName();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
	ScalePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformReverseMovement())
	{
		FVector moveDirection = PlatformVelocity.GetSafeNormal();
		PlatformInitialLocation += moveDirection * MoveDistance;
		SetActorLocation(PlatformInitialLocation);
		PlatformVelocity = -PlatformVelocity;

		return;
	}

	FVector newLocation = GetActorLocation() + PlatformVelocity * DeltaTime;
	SetActorLocation(newLocation, true);
}

bool AMovingPlatform::ShouldPlatformReverseMovement() const
{
	float distanceMoved = FVector::Distance(PlatformInitialLocation, GetActorLocation());

	if (distanceMoved > MoveDistance)
	{
		float overshoot = distanceMoved - MoveDistance;
		UE_LOG(LogTemp, Display, TEXT("%s : Movement Overshoot : %f"), *Name, overshoot);

		return true;
	}

	return false;
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator currentRotation = GetActorRotation();
	//float angleRotated = FVector::Distance(PlatformInitialRotation.Euler(), currentRotation.Euler());
	//if (angleRotated > RotateAngle)
	//{
	//	float overshoot = angleRotated - MoveDistance;
	//	UE_LOG(LogTemp, Display, TEXT("%s : Movement Overshoot : %f"), *Name, overshoot);

	//	FVector moveDirection = PlatformAngularVelocity.GetSafeNormal();
	//	PlatformInitialRotation += moveDirection * MoveDistance;
	//	SetActorRotation(PlatformInitialRotation);
	//	PlatformAngularVelocity = -PlatformAngularVelocity;
	//}
	currentRotation += PlatformAngularVelocity * DeltaTime;
	SetActorRotation(currentRotation);
}

void AMovingPlatform::ScalePlatform(float DeltaTime)
{
	if (ShouldPlatformRevereseScale())
	{
		FVector scaleDirection = PlatformScaleVelocity.GetSafeNormal();
		PlatformInitalScale += scaleDirection * ScaleDistance;
		SetActorScale3D(PlatformInitalScale);
		PlatformScaleVelocity = -PlatformScaleVelocity;

		return;
	}

	FVector newScale = GetActorScale3D() + PlatformScaleVelocity * DeltaTime;
	SetActorScale3D(newScale);
}

bool AMovingPlatform::ShouldPlatformRevereseScale() const
{
	float distanceScaled = FVector::Distance(PlatformInitalScale, GetActorScale3D());

	if (distanceScaled > ScaleDistance)
	{
		float overshoot = distanceScaled - ScaleDistance;
		UE_LOG(LogTemp, Display, TEXT("%s : Scale Overshoot : %f"), *Name, overshoot);

		return true;
	}

	return false;
}
