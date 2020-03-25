// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANK_API AMyAIController : public AAIController
{
	GENERATED_BODY()
public:
	

private:
	ATank* GetPlayerTank() const;
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;

};
