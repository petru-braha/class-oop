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
	for (int i = 0; i < identation; i++)
		printf("\t");
	printf("null,\n");
}

void NumberValue::print(std::ostream& out, int identation) const
{
	for (int i = 0; i < identation; i++)
		out << "\t";
	out << this->value << ",\n";
}

void BoolValue::print(std::ostream& out, int identation) const
{
	for (int i = 0; i < identation; i++)
		out << "\t";
	if (this->value)
		out << "true";
	else
		out << "false";
	out << ",\n";
}

StringValue::StringValue(const char* name)
{
	this->value = new char[str];
	strcpy(this->value, name);
}

void StringValue::print(std::ostream& out, int identation) const
{
	for (int i = 0; i < identation; i++)
		out << "\t";
	out << this->value << ",\n";
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

void ArrayValue::print(std::ostream& out, int identation) const
{
	for (int i = 0; i < identation; i++)
		out << "\t";
	for (size_t i = 0; i < this->size; i++)
	{
		this->elements[i]->print(out, identation);
		if (i < this->size - 1)
			out << ",";
		out << "\n";
	}
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

// DE IMPLEMENTAT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void ObjectValue::print(std::ostream& out, int identation) const
{
	out << "{\n";
	for (size_t i = 0; i < this->size; i++)
	{
		iden_prt(out, identation);
		out << this->elements[i].name;
		this->elements[i].value->print(out, identation + 1);
	}

	out << "}";
}

ObjectValue::operator unsigned() const
{
	// the global object will not be counted;
	// the local objects will be counted as well as its children;

	unsigned sum = 1;
	for (size_t i = 0; i < this->size; i++)
	{
		sum += (unsigned)*this->elements[i].value;
	}

	return sum;
}

ObjectValue::~ObjectValue()
{
	for (size_t i = 0; i < this->size; i++)
	{
		delete[]this->elements[i].name;
		delete this->elements[i].name;
	}
}


#include <iostream>
#include <fstream>
std::ostream& standard_VS_file()
{
	char decision = false;
	std::cout << "choose: file output / standard output (Y/N) : ";
	std::cin >> decision;
	if (decision == 'N')
		return std::cout;
	if (decision != 'Y')
		return std::cout;

	char file_name[50];
	std::cout << "type the name of the file (if needed with its path) : ";
	std::cin.getline(file_name, 50);
	static std::ofstream file(file_name);
	return file;
}
