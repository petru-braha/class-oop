#include "rangerover.h"
float rangerover::speed(int condition)
{
	this->fuel_capacity = 200;
	this->fuel_consumption = 150;
	strcpy(this->name, "rangerover car");
	float speed_rangerover = 120;
	switch (condition)
	{
	case 0: //sunny
		return speed_rangerover;
		break;
	case 1: //rainny
		return speed_rangerover * 5 / 6;
		break;
	case 2: //snowy
		return speed_rangerover * 4 / 6;
		break;
	default:
		break;
	}
	return 0;
}