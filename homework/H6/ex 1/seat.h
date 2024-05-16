#pragma once
#include "car.h"
class seat : public car
{
public:
	float speed(int condition) override;
};