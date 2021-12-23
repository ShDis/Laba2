// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Time.generated.h"

UCLASS()
class LABA2_API ATime : public AActor
{
	GENERATED_BODY()


public:	
	// Sets default values for this actor's properties
	ATime();

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//custom functions
	int convertStartToHours(ATime e);
	int convertEndToHours(ATime e);

private:
	UPROPERTY()
	int hour; //0-23
	UPROPERTY()
	int day; //0-364
	UPROPERTY()
	int year; //0-99
	UPROPERTY()
	int hourto; //0-23
	UPROPERTY()
	int dayto; //0-364
	UPROPERTY()
	int yearto; //0-99
};

ATime operator + (ATime e1, ATime e2)
{
	return e1; //temp
}

ATime operator long(ATime e)
{
	return e.hour;
}
