#include <iostream>
class person
{
private:
    int age;
    static short int skin_colors;

public:
    static char hobby;
    void setAge(int value);
    person(); //the same name + constructor will call itself when we declare person p

protected:
    int Bible = 0;
};
void person::setAge(int value)
{
    this->age = value;
}
person::person()
{
    std::cout << "s-a nascut Mesia!\n";
    this->age = 0;
}
short int person::skin_colors;
char person::hobby;