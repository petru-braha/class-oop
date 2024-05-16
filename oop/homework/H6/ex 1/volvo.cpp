#include "volvo.h"
float volvo::speed(int condition)
{
	this->fuel_capacity = 100;
	this->fuel_consumption = 100;
	strcpy(this->name, "volvo car");
	float speed_volvo = 150;
	switch (condition)
	{
	case 0: //sunny
		return speed_volvo;
		break;
	case 1: //rainny
		return speed_volvo * 5 / 6;
		break;
	case 2: //snowy
		return speed_volvo * 4 / 6;
		break;
	default:
		break;
	}
	return 0;
}