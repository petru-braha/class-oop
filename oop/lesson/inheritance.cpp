#include <iostream>
#pragma warning(disable: 26495) //error for uninitialised values
class base
{
	int a, b, c;
public:
	int public_value_base = 9;
	void set_a_b_c(int value){}
	        
	        void function_same_name1(){}
	virtual void function_same_name2(){}

protected:
	char* d;
};
class derived : public virtual base
{
	int x;
public:
	void set_x(const char* je) {}
	void set_d() {} //if it was private => no compile
	void function_same_name1() {}
	virtual void function_same_name2() {}
};
class derived2 : private base
{
	int y;
public:
	void set_y(const char* je){}
};
//class derived3 : public virtual base, private virtual derived \
the order of constructor calls: base, derived, derived3

void inheret_main_ex1()
{
	derived obj;
	obj.set_a_b_c(10);
	obj.public_value_base = 10;
	obj.function_same_name1();	// derived hides base

	base* aaa = &obj;
	aaa->function_same_name1(); // aaa's
	aaa->function_same_name2(); // obj's / derived overrides base's fct
}

class Figure 
{
public: 
	virtual void Draw() { printf("Figure"); }
};
class Circle : public Figure 
{
public: 
	void Draw() { printf("Circle"); }
};
class Square : public Figure 
{
public: 
	void Draw() { printf("Square"); }
};

//void inheret_main_ex2();