#include "fiat.h"
float fiat::speed(int condition)
{
	this->fuel_capacity = 50;
	this->fuel_consumption = 100;
	strcpy(this->name, "fiat car");
	float speed_fiat = 130;
	switch (condition)
	{
	case 0: //sunny
		return speed_fiat;
		break;
	case 1: //rainny
		return speed_fiat * 5 / 6;
		break;
	case 2: //snowy
		return speed_fiat * 4 / 6;
		break;
	default:
		break;
	}
	return 0;
}