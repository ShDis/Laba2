// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include <algorithm>

#include "Time.generated.h"

UCLASS()
class LABA2_API ATime : public AActor
{
	GENERATED_BODY()


public:
	// Sets default values for this actor's properties
	ATime();
	ATime(int h, int d, int y);
	ATime(ATime* e);

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// Custom functions
	UFUNCTION()
		static int convertToHours(int h, int d, int y);
	UFUNCTION()
		static int convertToHoursE(ATime *e);
	UFUNCTION()
		static int convertToHour(int hours);
	UFUNCTION()
		static int convertToDay(int hours);
	UFUNCTION()
		static int convertToYear(int hours);
	UFUNCTION(BlueprintCallable)
		bool setInterval(int h, int d, int y);
	UFUNCTION(BlueprintCallable, Category = "Time Interval Custom Nodes")
		bool setIntervalE(ATime *elem);
	UFUNCTION(BlueprintCallable, Category = "Time Interval Custom Nodes")
		int getIntervalHour();
	UFUNCTION(BlueprintCallable, Category = "Time Interval Custom Nodes")
		int getIntervalDay();
	UFUNCTION(BlueprintCallable, Category = "Time Interval Custom Nodes")
		int getIntervalYear();
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "getInterval"), Category = "Time Interval Custom Nodes")
		void getInterval(int& h, int& d, int& y);
	UFUNCTION()
		bool checkIsCorrect(int h, int d, int y);

	int getHour();
	int getDay();
	int getYear();
	
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "*"), Category = "Time Interval Custom Nodes")
		void multiply(const float coef, ATime*& result);
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "+"), Category = "Time Interval Custom Nodes")
		void add(ATime *elem, ATime*& result);
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "-"), Category = "Time Interval Custom Nodes")
		void substract(ATime* elem, ATime*& result);
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "=="), Category = "Time Interval Custom Nodes")
		void equal(ATime* elem, bool& result);
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "!="), Category = "Time Interval Custom Nodes")
		void notEqual(ATime* elem, bool& result);
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "isZero?"), Category = "Time Interval Custom Nodes")
		void isZero(bool& result);
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "toHours"), Category = "Time Interval Custom Nodes")
		void toHours(int& result);
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "toYears"), Category = "Time Interval Custom Nodes")
		void toYears(int& result);
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "~"), Category = "Time Interval Custom Nodes") // дополнение до конца столетия
		void complement(int& result);

private:
	UPROPERTY()
		int hour; // 0-23
	UPROPERTY()
		int day; // 0-364
	UPROPERTY()
		int year; // 0-99

	const int limit = 100 * 365 * 24 - 1;
};