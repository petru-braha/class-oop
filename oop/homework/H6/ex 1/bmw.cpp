#include "bmw.h"
float bmw::speed(int condition)
{
	this->fuel_capacity = 100;
	this->fuel_consumption = 140;
	strcpy(this->name, "bmw car");
	float speed_bmw = 200;
	switch (condition)
	{
	case 0: //sunny
		return speed_bmw;
		break;
	case 1: //rainny
		return speed_bmw * 5 / 6;
		break;
	case 2: //snowy
		return speed_bmw * 4 / 6;
		break;
	default:
		break;
	}
	return 0;
}