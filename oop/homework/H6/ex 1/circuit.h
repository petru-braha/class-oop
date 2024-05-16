#pragma once
#include "weather.h"
#include "bmw.h"
#include "fiat.h"
#include "seat.h"
#include "volvo.h"
#include "rangerover.h"
#define nr_cars_max 10

class circuit
{
	//car competitors[nr_cars_max];
	car* winner, * competitors[nr_cars_max];
	int competitor_index = 0;
	int condition = -1;
	int length_circuit = -1;
public:
	circuit();
	void SetLength(int length);
	void SetWeather(int cond);
	
	void AddCar(car* new_participant);

	void Race();
	void ShowFinalRanks()const;
	void ShowWhoDidNotFinish()const;
};