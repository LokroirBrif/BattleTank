// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::Tick(float deltaSeconds) {
	Super::Tick(deltaSeconds);
	AimTrowardsCrosshair();

}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player Controlled Tank not found"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player Controlled Tank: %s"), *ControlledTank->GetName())
	}

}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());


}

void ATankPlayerController::AimTrowardsCrosshair() {
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	bool aiming_landscape = GetSightRayHitLocation(OUT HitLocation);
	if (aiming_landscape) {
		//GetControlledTank()->AimAt(HitLocation);
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const {
	int32 ViewPortSyzeX, ViewPortSyzeY;
	GetViewportSize(ViewPortSyzeX, ViewPortSyzeY);
	auto ScreenLocation = FVector2D(ViewPortSyzeX*CrosshairXLocation, ViewPortSyzeY*CrosshairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		) {
		HitLocation = HitResult.Location;
		return true;
	}
	else {
		HitLocation = FVector(0);
		return false;
	}
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	FVector CameraLocation; //discharge
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, OUT CameraLocation, OUT LookDirection);
}

