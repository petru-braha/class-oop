#include <iostream>
#pragma warning(disable:4996)

class lab3_class//sigleton: global data structure ex: system files
{
    int x, y;
    lab3_class(int x, int y) : x(x), y(y) { std::cout << "("; }//exclusive constructor
    static lab3_class* inst;
public:
    int computation()const
    {
        return x + y;
    }
    static lab3_class* create(int x, int y);
    static void deconstruct();
    ~lab3_class() { std::cout << ")"; }
};
lab3_class* lab3_class::inst = 0; //no initialisation in class => create
lab3_class* lab3_class::create(int x = 0, int y = 0)
{
    if (inst == 0)
        inst = new lab3_class(x, y);
    return inst;
}
void lab3_class::deconstruct()
{
    delete(inst);
}

class B
{
    int x;
    char str[100];
public:
    B(int value, const char* point_array);  //regular constructor
    B(const B& inst);                       //the copy constructor
    void print()const { std::cout << "element values: " << this->x << ' ' << this->str; }
    ~B() { std::cout << "]"; }
};
B::B(int value, const char* point_array)
{
    this->x = value;
    strcpy(this->str, point_array);
    std::cout << "[";
}
B::B(const B& inst) 
{
    //inst. //acces only to the members and NOT methods without const at the end
    this->x = inst.x;
    strcpy(str, inst.str);
    std::cout << "[";
}

void lab3_constructors_main()
{
    //explicit distructor - static variables
    //implicit distructor is called at return by default
    //part of the class just by the binding, the location is far away: static
    std::cout << "lab3_class: " << lab3_class::create(1, 2)->computation() << ' ' << lab3_class::create()->computation();
    lab3_class::deconstruct(); std::cout << '\n';

    B b1(5, "abc");
    B b2(10, "xyz");
    B b3(b1);
    B b4 = b2;

    B* bb = (B*)malloc(sizeof(B));
    new(bb)B(7, "bcde");
    bb->print();
    bb->~B();
}

//----------------------------------------------------------------------------------------------------

class exemple_constructor
{
    int x;
public:
    exemple_constructor(int value) : x(value){}//not a default constructor
};
class copy_ex_cnst
{
    exemple_constructor Jesus;
    int a = 0, b = 0;
    char name[40] = "j", job[69] = "j";
    float inch_penis = 10.50;

public:
    copy_ex_cnst(char value) :Jesus(value){} //explicit cuz: 1. no default constructor for exemple_constructor 2. it would work if no constructors for the first class
    copy_ex_cnst() : Jesus(100) {}

    //constructor calls constructor == delegation -> the original one
    copy_ex_cnst(int x, int y) : Jesus(x* y) {}
    copy_ex_cnst(int copy): copy_ex_cnst(copy, copy){} 

    //copy_ex_cnst(...); 
    //copy_ex_cnst A = { 1, 2, "Rares", "santier", 13.01 };
};
class hello_vvv
{
    int a[100];
public:
    hello_vvv() : a{ 1, 2, 3, 4, 5, 6 } {};
};
class wewew
{
    int* x;
public:
    wewew(int count) : x(new int[count] {1, 2, 3, 5}) { }
    void print(int index)const { std::cout << this->x[index]; }
    /*in main:
    wewew d(3);
    d.print(3);
    wewew return_init_list();*/
};

//----------------------------------------------------------------------------------------------------

