#pragma once
#include "car.h"
class fiat : public car
{
public:
	float speed(int condition) override;
};