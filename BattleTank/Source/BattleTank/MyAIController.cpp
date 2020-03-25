// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"

void AMyAIController::Tick(float deltaTime) {
	Super::Tick(deltaTime);
	if (GetPlayerTank()) {
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Non trovato"))
	}
}

ATank* AMyAIController::GetControlledTank() const{
	return Cast<ATank>(GetPawn());
}

ATank* AMyAIController::GetPlayerTank() const {
	APlayerController* playerTank = GetWorld()->GetFirstPlayerController();
	if (!playerTank) {
		return nullptr;
	}
	else {
		return Cast<ATank>(playerTank->GetPawn());
	}
}

void AMyAIController::BeginPlay() {
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled Tank not found"))
	}
	else {
		FVector position = ControlledTank->GetActorLocation();
		UE_LOG(LogTemp, Warning, TEXT("Ai Controlled Tank at position: x=%f y=%f z=%f"), position[0], position[1], position[2]);
	}
	auto playerTank = GetPlayerTank();
	if (!playerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI don't found the player controller"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI found the player controller"))
		UE_LOG(LogTemp, Warning, TEXT("AI found the player controller"))
	}
}