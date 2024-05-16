#include <stdio.h>
#include "circuit.h"

circuit::circuit()
{
	winner = nullptr;
	for (int i = 0; i < nr_cars_max; i++)
		competitors[i] = nullptr;
}

void circuit::SetLength(int length)
{
	this->length_circuit = length;
}

void circuit::SetWeather(int cond)
{
	this->condition = cond;
}

void circuit::AddCar(car* new_participant)
{
	if (competitor_index < nr_cars_max)
		competitors[competitor_index++] = new_participant;
	else
		printf("error: too many competitors.\n");
}

//-----------------------------------------------------------------------------

void circuit::Race() //sort
{
	bool swaped = false;
	for (int i = 0; i < competitor_index - 1; i++) // last i elements are already in place
	{
		swaped = 0;
		for (int j = 0; j < competitor_index - i - 1; j++)
		{
			if (competitors[j]->speed(this->condition) > competitors[j + 1]->speed(this->condition))
			{
				swaped = true;
				car* temp = competitors[j];
				competitors[j] = competitors[j + 1];
				competitors[j + 1] = temp;
			}
		}

		if (swaped == false)
			break;
	}
}

void circuit::ShowFinalRanks()const //sorted
{
	int position = 1;
	for (int i = 0; i < competitor_index; i++)
	{
		int possible_kilometers_driven = 0;
		possible_kilometers_driven  = competitors[i]->get_capacity();
		possible_kilometers_driven *= competitors[i]->get_consumtion();
		possible_kilometers_driven /= 100;

		if (possible_kilometers_driven >= this->length_circuit) //who finished
			printf("%s is on place: %d, speed: %f.\n", competitors[i]->name, position++, competitors[i]->speed(this->condition));
	}
	printf("\n");
}

void circuit::ShowWhoDidNotFinish()const
{
	bool everyone_finished = true;
	for (int i = 0; i < competitor_index; i++)
	{
		int possible_kilometers_driven = 0;
		possible_kilometers_driven = competitors[i]->get_capacity();
		possible_kilometers_driven *= competitors[i]->get_consumtion();
		possible_kilometers_driven /= 100;
		if (possible_kilometers_driven < this->length_circuit) //oposite operation of the previous call
		{
			printf("%s did not finish.\n", competitors[i]->name);
			everyone_finished = false;
		}
	}

	if (everyone_finished) printf("everyone has arrived at the finish line!\n");
}