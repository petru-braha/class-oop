#include "car.h"
car::car()
{
	fuel_capacity = 0;
	fuel_consumption = 0;
}

int car::get_capacity()const
{
	return this->fuel_capacity;
}

int car::get_consumtion()const
{
	return this->fuel_consumption;
}