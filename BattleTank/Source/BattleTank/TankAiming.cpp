// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAiming.h"

// Sets default values for this component's properties
UTankAiming::UTankAiming()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAiming::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAiming::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAiming::AimAt(FVector HitLocation) {
	auto OurTankName = GetOwner()->GetName();
	FVector BarrelLocation = Barrel->GetComponentLocation();
	UE_LOG(LogTemp, Warning, TEXT("%s Aiming at: %s from %s"),*OurTankName , *HitLocation.ToString(), *BarrelLocation.ToString());
}

void UTankAiming::SetBarrelReference(UStaticMeshComponent* BarrelToSet) {
	this->Barrel = BarrelToSet;
}