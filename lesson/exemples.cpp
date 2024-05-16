#include <iostream>

//change the variable by its address
int function(int& a);
//in the actual call: function(a)

class test
{
	int x=0;
public:
	int& getx();
	const void printx() const { std::cout << x << '\n'; }
};

int& test::getx() { return x; }

int x2 = 0; int& second_test() { return x2; }

int& thir_test(int x) { return x; }

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void methods()
{
	test one;
	one.getx() += 10;
	one.printx(); //why 1?????

	second_test()+=11;
	std::cout << second_test() << ' ' << x2 << '\n';

	std::cout << ++thir_test(31);
}

class Date
{
private:
	const mutable int* x;
	int y, z, t;
	//const mutable int r3 = 0;
public:
	const int& GetX() const;

	void modifyY(Date* date1)const { date1->y = 1; }
	//void modify_r3() const { r3 = 2; }
	//void print_r3() const { std::cout << r3; }
};
const int& Date::GetX() const
{
	x = &y;
	return *x;
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void trick()
{
	Date d;
	int x = d.GetX();
	x++;

	//d.modify_r3();
	//d.print_r3();
}

class understand_00
{
	int x, y;
public:
	void init_number();
	int getx();
	int gety();
	friend class understand_01; //all methods from 01 can access these info
};

class understand_01
{
	int number;
	char name[20];
public:
	int  friend double0();
	void friend understand_00::init_number();
};

int double0()
{
	return 0;
}

void initialization_lists()
{
	int x = 5;
	x = { 5 };
	int v[] = { 100 }; //v[2] = 7; won't compile
}