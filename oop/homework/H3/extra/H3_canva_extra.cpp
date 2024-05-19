#include <cstdarg>
#include <stdio.h>
#include "H3_canva_extra.h"

Canvas_extra::Canvas_extra(int lines, int columns)
{
	this->clear();
	this->max_line = lines;
	this->max_column = columns;
	this->canva_matrix = new char*[lines];
	for (int i = 0; i < lines; i++)
		this->canva_matrix[i] = new char[columns] {0};
}

void Canvas_extra::set_pixel(int x, int y, char value)
{
	this->canva_matrix[x][y] = value;
}

// tuples of x, y, value
void Canvas_extra::set_pixels(int count, ...)
{
	va_list argumetns;
	va_start(argumetns, count);
	while (count)
	{
		int x = va_arg(argumetns, int); 
		int y = va_arg(argumetns, int); 
		char val = va_arg(argumetns, char);
		this->set_pixel(x, y, val);
		count--;
	}
	
	va_end(argumetns);
}

void Canvas_extra::clear()
{
	for (int i = 0; i < this->max_line; i++)
		for (int j = 0; j < this->max_column; j++)
			this->canva_matrix[i][j] = 0;
}

void Canvas_extra::print() const
{
	for (int i = 0; i < this->max_line; i++)
	{
		for (int j = 0; j < this->max_column; j++)
			printf("%c", this->canva_matrix[i][j]);
		printf("\n");
	}
}

Canvas_extra::~Canvas_extra()
{
	for (int i = 0; i < this->max_line; i++)
		delete this->canva_matrix[i];
	delete[] this->canva_matrix;
}	