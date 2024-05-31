#include "H6_classes_extra.h"
JsonValue::~JsonValue(){}
void iden_prt(std::ostream& out, int x)
{
	for (int i = 0; i < x; i++)
		out << "\t";
}

//---------------------------------------------------------------------------------

void NullValue::print(std::ostream& out, int identation) const
{
	out << "null";
}

void NumberValue::print(std::ostream& out, int identation) const
{
	out << this->value;
}

void BoolValue::print(std::ostream& out, int identation) const
{
	if (this->value)
		out << "true";
	else
		out << "false";
}

StringValue::StringValue(const char* name)
{
	this->value = new char[str];
	strcpy(this->value, name);
}

void StringValue::print(std::ostream& out, int identation) const
{
	out << '"' << this->value << '"';
}

//---------------------------------------------------------------------------------

ArrayValue::ArrayValue()
{
	this->size = 0;
	for (size_t i = 0; i < arr; i++)
		this->elements[i] = nullptr;
}

void ArrayValue::add(JsonValue* pointer_element)
{
	if(this->size < arr)
		this->elements[this->size++] = pointer_element;
}

// only called inside an object
void ArrayValue::print(std::ostream& out, int identation) const
{
	out << "[\n";
	identation++;

	for (size_t i = 0; i < this->size; i++)
	{
		iden_prt(out, identation);
		this->elements[i]->print(out, identation);
		if (i < this->size - 1)
			out << ",";
		out << "\n";
	}

	identation--;
	iden_prt(out, identation);
	out << "]"; // without comma => it can be the last element from an object
}

ArrayValue::~ArrayValue()
{
	for (size_t i = 0; i < size; i++)
		delete this->elements[i];
}

//---------------------------------------------------------------------------------

void ObjectValue::add(const char* name, JsonValue* pointer_element)
{
	this->elements[this->size].name = new char[str];
	strcpy(this->elements[this->size].name, name);
	this->elements[this->size].value = pointer_element;
	this->size++;
}

void ObjectValue::print(std::ostream& out, int identation) const
{
	out << "{\n";
	identation++;

	for (size_t i = 0; i < this->size; i++)
	{
		iden_prt(out, identation);
		
		out << '"' << this->elements[i].name << '"' << ": ";
		this->elements[i].value->print(out, identation);
		
		if (i < this->size - 1)
			out << ",";
		out << "\n";
	}
	
	identation--;
	iden_prt(out, identation);
	out << "}";
}

bool is_object(JsonValue* obj)
{
	return obj->container;
}

#include <iostream>
ObjectValue::operator unsigned() const
{
	// the global object will not be counted;
	// the local objects will be counted as well as its children;

	unsigned sum = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		auto pointer = this->elements[i].value;
		sum += (unsigned)(*pointer);
		if (is_object(pointer))
			sum++;
	}

	return sum;
}

ObjectValue::~ObjectValue()
{
	for (size_t i = 0; i < this->size; i++)
	{
		delete[]this->elements[i].name;
		delete this->elements[i].value;
	}
}

#include <iostream>
#include <fstream>
std::ostream& standard_VS_file()
{
	char decision = 'N';
	std::cout << "\nchoose: file output / standard output (Y/N) : ";
	std::cin >> decision;
	if (decision == 'N')
		return std::cout;
	if (decision != 'Y')
		return std::cout;

	char file_name[50];
	std::cout << "type the name of the file (if needed with its path) : ";
	std::cin>>file_name;
	static std::ofstream file(file_name);
	return file;
}

// bool, null, nr, string - print right after the name
