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
}

ATime::ATime(int h, int d, int y)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	this->hour = abs(h % 24);
	this->day = abs(d % 365);
	this->year = abs(y % 100);
}

ATime::ATime(const ATime &e)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	this->hour = abs(e.hour % 24);
	this->day = abs(e.day % 365);
	this->year = abs(e.year % 100);
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

int ATime::convertToHours(int h, int d, int y)
{
	return h + d * 24 + y * 365 * 24;
}

int ATime::convertToHoursE(ATime *e)	
{
	ATime &e_var = *e;
	return ATime::convertToHours(e_var.hour, e_var.day, e_var.year);
}

int ATime::convertToHour(int hours)
{
	return hours % 24;
}

int ATime::convertToDay(int hours)
{
	return (hours / 24) % 365;
}

int ATime::convertToYear(int hours)
{
	return hours / (365 * 24);
}

bool ATime::setInterval(int h, int d, int y)
{
	if (!checkIsCorrect(h, d, y))
		return false;
	this->hour = h;
	this->day = d;
	this->year = y;
	return true;
}

bool ATime::setIntervalE(ATime *elem)
{
	if (elem == NULL)
		return false;
	return ATime::setInterval(elem->hour, elem->day, elem->year);
}

int ATime::getIntervalHour()
{
	return this->hour;
}

int ATime::getIntervalDay()
{
	return this->day;
}

int ATime::getIntervalYear()
{
	return this->year;
}

void ATime::getInterval(int& h, int& d, int& y)
{
	h = this->hour;
	d = this->day;
	y = this->year;
}

int ATime::getHour() 
{
	return this->hour;
}

int ATime::getDay() 
{
	return this->day;
}

int ATime::getYear() 
{
	return this->year;
}

bool ATime::checkIsCorrect(int h, int d, int y)
{
	if (h < 0 || h > 23)
		return false;
	if (d < 0 || d > 364)
		return false;
	if (y < 0 || y > 99)
		return false;
	return true;
}

void ATime::multiply(const float coef, ATime*& result)
{
	int hours = convertToHoursE(this) * coef;
	setInterval(ATime::convertToHour(hours), ATime::convertToDay(hours), ATime::convertToYear(hours));
	result = this;
}

void ATime::add(ATime* elem, ATime*& result)
{
	if (elem == NULL) //null check
	{
		result = this;
		return;
	}
	//ATime &e_var = *elem;

	int hours = convertToHoursE(this) + convertToHoursE(elem); //action

	if (hours > limit) //check limit
		hours = limit;

	setInterval(ATime::convertToHour(hours), ATime::convertToDay(hours), ATime::convertToYear(hours));
	result = this;
}

void ATime::substract(ATime* elem, ATime*& result)
{
	if (elem == NULL)
	{
		result = this;
		return;
	}

	int hours = convertToHoursE(this) - convertToHoursE(elem);
	if (hours < 0)
		hours = 0;

	setInterval(ATime::convertToHour(hours), ATime::convertToDay(hours), ATime::convertToYear(hours));
	result = this;
}

void ATime::equal(ATime* elem, bool& result)
{
	if (elem == NULL)
	{
		result = false;
		return;
	}

	if (elem->hour != this->hour || elem->day != this->day || elem->year != this->year)
	{
		result = false;
		return;
	}
		
	result = true;
}

void ATime::notEqual(ATime* elem, bool& result)
{
	if (elem == NULL)
	{
		result = true;
		return;
	}

	if (elem->hour == this->hour && elem->day == this->day && elem->year == this->year)
	{
		result = false;
		return;
	}

	result = true;
}

void ATime::isZero(bool& result)
{
	if (this->hour != 0 || this->day != 0 || this->year != 0)
	{
		result = false;
		return;
	}

	result = true;
}

void ATime::toHours(int& result)
{
	result = convertToHoursE(this);
}

void ATime::toYears(int& result)
{
	result = convertToYear(convertToHoursE(this));
}

void ATime::complement(int& result)
{
	result = limit - convertToHoursE(this);
}

/*
void ATime::plus(const ATime* e1, const ATime* e2, int& hour_out, int& day_out, int& year_out)
{
	ATime e = &e1 + &e2;
	hour_out = convertToHour(e);
	day_out = convertToDay(e);
	year_out = convertToYear(e);
}
*/

