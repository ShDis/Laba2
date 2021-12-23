// Fill out your copyright notice in the Description page of Project Settings.


#include "Time.h"

// Sets default values
ATime::ATime()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	this->hour = 0;
	this->day = 0;
	this->year = 0;
	this->hourto = 23;
	this->dayto = 364;
	this->yearto = 99;
}

// Called when the game starts or when spawned
void ATime::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATime::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ATime::convertStartToHours(ATime e)
{
	return e.hour + e.day * 24 + e.year * 364 * 24;
}

int ATime::convertEndToHours(ATime e)
{
	return e.hourto + e.dayto * 24 + e.yearto * 364 * 24;
}




