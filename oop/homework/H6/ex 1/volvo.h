#pragma once
#include "car.h"
class volvo : public car
{
public:
	float speed(int condition) override;
};