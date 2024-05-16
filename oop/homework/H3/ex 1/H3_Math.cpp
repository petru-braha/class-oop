#include <cstring>
#include <cstdarg>
#include "H3_Math.h"
int convert_char(char* nr);
char* convert_int(int nr);

int Math::Add(int x, int y)
{
	return x + y;
}
int Math::Add(int x, int y, int z)
{
	return x + y + z;
}
int Math::Add(double x, double y)
{
	return (int)(x + y);
}
int Math::Add(double x, double y, double z)
{
	return (int)(x + y + z);
}
int Math::Mul(int x, int y)
{
	return x * y;
}
int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}
int Math::Mul(double x, double y)
{
	return (int)(x * y);
}
int Math::Mul(double x, double y, double z)
{
	return (int)(x * y * z);
}
int Math::Add(int count, ...)
{
	int rez = 0;
	va_list argumetns;
	va_start(argumetns, count);
	for (; count > 0; count--)
		rez = rez + (int)va_arg(argumetns, int);
	
	va_end(argumetns);
	return rez;
}
char* Add(const char* a, const char* b)
{
	int sum;
	if (a == nullptr || b == nullptr)
	{
		return nullptr;
	}
	else
	{
		sum = convert_char((char*)a) + convert_char((char*)b);
	}
	return convert_int(sum);
}