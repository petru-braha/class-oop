#include "H2_studentFct.h"
int compare_name(student one, student two)
{
	char temp = (char)strcmp(one.getName(), two.getName());
	if (temp > 0)
		return 1;
	if (temp < 0)
		return -1;
	return 0;
}

int compare_MTH(student one, student two)
{
	float temp = one.getMTH() - two.getMTH();
	if (temp > 0)
		return 1;
	if (temp < 0)
		return -1;
	return 0;
}

int compare_ENG(student one, student two)
{
	float temp = one.getENG() - two.getENG();
	if (temp > 0)
		return 1;
	if (temp < 0)
		return -1;
	return 0;
}

int compare_HST(student one, student two)
{
	float temp = one.getHST() - two.getHST();
	if (temp > 0)
		return 1;
	if (temp < 0)
		return -1;
	return 0;
}

int compare_AVG(student one, student two)
{
	float temp = one.average_grade() - two.average_grade();
	if (temp > 0)
		return 1;
	if (temp < 0)
		return -1;
	return 0;
}