// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float) override;

private:

	void AimTrowardsCrosshair();
	bool GetSightRayHitLocation(FVector&) const;
	bool GetLookDirection(FVector2D, FVector&) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	UPROPERTY(EditAnywhere) float CrosshairXLocation = 0.5;
	UPROPERTY(EditAnywhere) float CrosshairYLocation = (1.0/3.0);
	UPROPERTY(EditAnywhere) float LineTraceRange = 1000000;
};
