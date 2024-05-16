#include <cstring>
#define max_char 100
class Number
{
	char x[max_char], b;
public:
	Number(const char* value, int base);
	Number(const int base_ten_digit);
	~Number(){}
	Number() : b(10) { strcpy_s(x, "0\0"); };

	Number(Number& to_be_copied);
	Number(Number&& to_be_moved) noexcept;

	//result has biggest base out of operands (except for the relation and index operators)

	friend Number operator +  (Number m, Number n); //first parameter of a friend should be a reference
	friend Number operator -  (Number m, Number n);
	int operator []    (int index);

	bool operator <    (Number m);
	bool operator <=   (Number m);
	bool operator >    (Number m);
	bool operator >=   (Number m);
	bool operator ==   (Number m);
	bool operator !=   (Number m);
	
	Number& operator = (const Number m); //always w a reference
	Number& operator = (int number);
	Number& operator = (const char number[]);

	friend void operator -- (Number& m); //prefix: remove the first digit
	friend void operator -- (Number& m, int value); //postix: remove last

	void SwitchBase(int newBase);
	void Print()const;
	int  GetDigitsCount()const;
	int  GetBase()const;
};