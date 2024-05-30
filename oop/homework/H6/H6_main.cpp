#include "ex 1/circuit.h"

int weather::sun = 0;
int weather::rain = 1;
int weather::snow = 2;

int H6_cars_main()
{
	circuit c;
	c.SetLength(100);
	c.SetWeather(weather::rain);
	c.AddCar(new volvo());
	c.AddCar(new bmw());
	c.AddCar(new seat());
	c.AddCar(new fiat());
	c.AddCar(new rangerover());
	
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "extra/H6_classes_extra.h"

int H6_extra_main() {
    ArrayValue* cacat = new ArrayValue();
    delete cacat;
    auto array_numbers = new ArrayValue();
    array_numbers->add(new NumberValue(5));
    array_numbers->add(new NumberValue(10));
    array_numbers->add(new NumberValue(15));

    auto array_strings = new ArrayValue();
    array_strings->add(new StringValue("abc"));
    array_strings->add(new StringValue("def"));
    array_strings->add(new StringValue("ghi"));

    auto subobject = new ObjectValue();
    subobject->add("email", new StringValue("t@gmail.com"));
    subobject->add("name", new StringValue("T"));
    subobject->add("online", new BoolValue(true));

    auto object = new ObjectValue();
    object->add("n", new NullValue());
    object->add("array_numbers", array_numbers);
    object->add("array_strings", array_strings);
    object->add("info", subobject);

    std::cout << "Top node has " << (unsigned)*object << " subnodes\n";
    
    // the command line added: 
    object->print(standard_VS_file(), 0);
    delete object;
    return 0;
}

/* OUTPUT:
* an object opens with {}
* an simple type just with []

{
    "n": null,
    "array_numbers": [
        5,
        10,
        15
    ],
    "array_strings": [
        "abc",
        "def",
        "ghi"
    ],
    "info": {
        "email": "t@gmail.com",
        "name": "T",
        "online": true
    }
}

*/