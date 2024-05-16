#pragma once
#include "weather.h"
#include <string>

class car
{
protected:
	int fuel_capacity, fuel_consumption;
public:
	char name[300];
	car();
	virtual float speed(int condition) = 0; //for different conditions
	int get_capacity()const;
	int get_consumtion()const;
};