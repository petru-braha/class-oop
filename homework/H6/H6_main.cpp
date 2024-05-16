#include "ex 1/circuit.h"

int weather::sun = 0;
int weather::rain = 1;
int weather::snow = 2;

int H6_cars_main()
{
	circuit c;
	c.SetLength(100);
	c.SetWeather(weather::rain);
	c.AddCar(new volvo());
	c.AddCar(new bmw());
	c.AddCar(new seat());
	c.AddCar(new fiat());
	c.AddCar(new rangerover());
	
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}


