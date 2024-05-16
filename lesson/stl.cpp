#include <stdio.h>
#pragma warning(disable:4302)
#pragma warning(disable:4244)

int   add(int x, char y) { return x + y; }
float add(char x, int y) { return (float)x + (float)y; }

void display_cast()
{
	//imagine that int is the name of a class
	int a = 100;
	char b = reinterpret_cast<char> (&a);
	//b = char((void*)(&a));

	//fails int j = add(100, 11); 
	int j = static_cast<int(*) (int, char)> (add)(100, 11);

	const int xx = 1;
	*const_cast<int*>(&xx) = 2; //at the end will be two: it is on stack => write permissions
	//BUT! whenever x is used its value will be replaced w const 1 
	//not the same for class exe
}

void display_macro()
{

#define print\
	if(x == 1)\
	std::cout<<x;

#define sum(type)\
type add_##type(type x, type y) { return (x) + (y); } // concat

	//double roar = add_double(1.2f, 1.3f);

	volatile int xxx = 5;
	printf("%d", xxx); //here when optimisations are created... x is not allocated, will just print 5 if no other operation uses xxx

}

//literals
int operator "" _ma_pis_3(unsigned long long value)
{
	return 3;
}

void operator "" _reverse(const char* input, size_t size_string)
{
	printf("%s\n", input);
}

void display_literals()
{
	int test_1 = 30_ma_pis_3;
	"c++ test in mata"_reverse;
}

//templates
template <class jet>
jet difference(jet x, jet y) { return x + y; }

template <class T1, class T2, class T3>
T1 se_introduce(T2 x, T2 y, T3 z) { return (T1)x; }

void display()
{
	int a = difference<int>(10, 10);
	int b = se_introduce<int, int, float>(10, 10, 1.2f);
	//slide 103
}