// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAiming.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()


public:
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = setup)
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

protected:
	UTankAiming* TankAiming = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
