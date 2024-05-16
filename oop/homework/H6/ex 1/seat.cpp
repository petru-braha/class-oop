#include "seat.h"
float seat::speed(int condition)
{
	this->fuel_capacity = 80;
	this->fuel_consumption = 100;
	strcpy(this->name, "seat car");
	float speed_seat = 170;
	switch (condition)
	{
	case 0: //sunny
		return speed_seat;
		break;
	case 1: //rainny
		return speed_seat * 5 / 6;
		break;
	case 2: //snowy
		return speed_seat * 4 / 6;
		break;
	default:
		break;
	}
	return 0;
}