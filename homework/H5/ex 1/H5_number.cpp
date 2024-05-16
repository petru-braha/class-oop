#pragma warning(disable:4244)
#include <stdio.h>
#include "H5_number.h"
char new_nr[300]; //patch for the function convert_int(int nr);

//------------------------------------------------------------------

int convert_char(char* nr)
{
	int p = 1, index = 0, result = 0;
	while (nr[index])
		index++;
	index--;
	while (index)
	{
		result = result + (nr[index] - '0') * p;
		p *= 10;
		index--;
	}

	if (nr[index] == '-')
		return -1 * result;
	return result + (nr[index] - '0') * p;
}
char* convert_int(int nr)
{
	int p = 10, digit = 0, index = 0;

	if (nr < 0)
	{
		new_nr[0] = '-';
		index = 1;
		nr *= -1;
	}
	while (p <= nr / 10)
		p *= 10;

	while (nr)
	{
		digit = nr / p;
		new_nr[index++] = digit + '0';
		nr = nr % p;
		p /= 10;
	}
	new_nr[index] = '\0';
	return new_nr;
}
void ten_B(char* nr, int B)
{
	int p = 1; int decimal_nr = convert_char(nr), result = 0;
	bool first_exe = 1;
	while (decimal_nr || first_exe)
	{
		int digit = decimal_nr % B;
		result += digit * p;
		p *= 10;
		decimal_nr /= B;
		first_exe = 0;
	}
	nr = convert_int(result);
}
void B_ten(char* nr, int B)
{
	int index = 0;
	while (nr[index])
		index++;
	int how_many = index;
	index--;

	int p = 1, result = 0;
	while (index >= 0)
	{
		int digit = nr[index] - '0';
		result += digit * p;
		p *= B;
		index--;
	}
	nr = convert_int(result);
}


Number::Number(const char* value, int base)
{
	strcpy_s(x, value); 
	b = base;
}
Number::Number(const int base_ten_digit)
{
	strcpy_s(this->x, convert_int(base_ten_digit));
	this->b = 10;
}
Number::Number(Number& to_be_copied)
{
	strcpy_s(this->x, to_be_copied.x);
	this->b = to_be_copied.b;
}
Number::Number(Number&& to_be_moved) noexcept
{
	strcpy_s(this->x, to_be_moved.x);
	this->b = to_be_moved.b;

	strcpy_s(to_be_moved.x, "\0");
	to_be_moved.b = 10;
}

//------------------------------------------------------------------

void Number::SwitchBase(int newBase)
{
	if (this->b == 10)
	{
		if (newBase != 10)
			ten_B(this->x, newBase);
	}
	else
	{
		if (newBase == 10)
			B_ten(this->x, newBase);
		else
		{
			B_ten(this->x, this->b);
			ten_B(this->x, newBase);
		}
	}
	this->b = newBase;
}

void Number::Print()const
{
	printf("%s wrote in base: %d\n", this->x, this->b);
}

int Number::GetDigitsCount()const 
{
	int i = 0;
	for (i; this->x[i]; i++);
	return i;
}

int Number::GetBase()const
{
	return (int)this->b;
}

//------------------------------------------------------------------

Number operator +  (Number m, Number n)
{
	Number result;
	Number copyNr_smallerBase;
	bool first_is_greater = 1;
	if (m.b > n.b)
	{
		result.b = m.b;
		copyNr_smallerBase.b = n.b;
		strcpy_s(copyNr_smallerBase.x, n.x);
	}
	else
	{
		first_is_greater = 0;
		result.b = n.b;
		copyNr_smallerBase.b = m.b;
		strcpy_s(copyNr_smallerBase.x, m.x);
	}

	copyNr_smallerBase.SwitchBase(result.b);//upgrade
	int temp = convert_char(copyNr_smallerBase.x);
	if (first_is_greater)
		temp += convert_char(m.x);
	else
		temp += convert_char(n.x);
	strcpy_s(result.x, convert_int(temp));
	return result;
}
Number operator -  (Number m, Number n)
{
	Number result;
	Number copyNr_smallerBase;
	bool first_is_greater = 1;
	if (m.b > n.b)
	{
		result.b = m.b;
		copyNr_smallerBase.b = n.b;
		strcpy_s(copyNr_smallerBase.x, n.x);
	}
	else
	{
		first_is_greater = 0;
		result.b = n.b;
		copyNr_smallerBase.b = m.b;
		strcpy_s(copyNr_smallerBase.x, m.x);
	}

	copyNr_smallerBase.SwitchBase(result.b);//upgrade
	int temp = convert_char(copyNr_smallerBase.x);
	if (first_is_greater)
		temp = convert_char(m.x) - temp;
	else
		temp -= convert_char(n.x);
	strcpy_s(result.x, convert_int(temp));
	return result;
}
int Number::operator []    (int index)
{
	return (int)(this->x[index]);
}
bool Number::operator <    (Number m)
{
	if (b == m.b)
		return convert_char(x) < convert_char(m.x);
	m.SwitchBase(b);
	return convert_char(x) < convert_char(m.x);
}
bool Number::operator <=   (Number m)
{
	if (b == m.b)
		return convert_char(x) <= convert_char(m.x);
	m.SwitchBase(b);
	return convert_char(x) <= convert_char(m.x);
}
bool Number::operator >    (Number m)
{
	if (b == m.b)
		return convert_char(x) > convert_char(m.x);
	m.SwitchBase(b);
	return convert_char(x) > convert_char(m.x);
}
bool Number::operator >=   (Number m)
{
	if (b == m.b)
		return convert_char(x) >= convert_char(m.x);
	m.SwitchBase(b);
	return convert_char(x) >= convert_char(m.x);
}
bool Number::operator ==   (Number m)
{
	if (b == m.b)
		return convert_char(x) == convert_char(m.x);
	m.SwitchBase(b);
	return convert_char(x)== convert_char(m.x);
}
bool Number::operator !=   (Number m)
{
	if (b == m.b)
		return convert_char(x) != convert_char(m.x);
	m.SwitchBase(b);
	return convert_char(x) != convert_char(m.x);
}

Number& Number::operator = (const Number m)
{
	strcpy_s(x, m.x);
	b = m.b;
	return (*this);
}
Number& Number::operator = (int number)
{
	strcpy_s(x, convert_int(number));
	b = 10;
	return (*this);
}
Number& Number::operator = (const char number[])
{
	strcpy_s(x, number);
	b = 10;
	return (*this);
}

void operator -- (Number& m)
{
	strcpy_s(m.x, m.x + 1);
}

#pragma warning(disable:6386)
void operator -- (Number& m, int value)
{
	int i = 0;
	for (; m.x[i]; i++);
	
	m.x[i-1] = '\0';
}