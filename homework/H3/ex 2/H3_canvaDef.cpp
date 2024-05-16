#include <iostream>
#include <cstring>
#include <cmath>
#include "H3_canva.h"

Canvas::Canvas(int width, int height)
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			matrix[i][j] = ' ';
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int center_x = x + ray, center_y = y + ray, dist = 0;
	for (int i = x; i <= x + 2 * ray; i++)
		for (int j = y; j <= y + 2 * ray; j++)
		{
			dist = (i - center_x) * (i - center_x) + (j - center_y) * (j - center_y);
			if (dist <= ray * ray)
				matrix[j][i] = ch;
			if (dist <= (ray - 1) * (ray - 1))
				matrix[j][i] = ' ';
		}
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int center_x = x + ray;
	int center_y = y + ray;
	int dist;

	for (int i = x; i <= x + 2 * ray; i++)
		for (int j = y; j <= y + 2 * ray; j++)
		{
			dist = (i - center_x) * (i - center_x) + (j - center_y) * (j - center_y);
			if (dist <= (ray - 1) * (ray - 1))
				matrix[j][i] = ch;
		}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
	{
		matrix[i][left] = ch;
		matrix[i][right] = ch;
	}
	for (int i = left; i <= right; i++)
	{
		matrix[top][i] = ch;
		matrix[bottom][i] = ch;
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i < bottom; i++)
		for (int j = left + 1; j < right; j++)
			matrix[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	matrix[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int distance_x = abs(x2 - x1), distance_y = abs(y2 - y1) * -1;
	int error = distance_x + distance_y, temp = 0;
	int x1_lower_than_x2 = 0, y1_lower_than_y2 = 0;

	if (x1 < x2)
		x1_lower_than_x2 = 1;
	else
		x1_lower_than_x2 = -1;

	if (y1 < y2)
		y1_lower_than_y2 = 1;
	else
		y1_lower_than_y2 = -1;

	while (1)
	{
		matrix[y1][x1] = ch;
		if (x1 == x2 && y1 == y2)
			break;
		temp = 2 * error;
		if (temp >= distance_y)
		{
			if (x1 == x2)
				break;
			error = error + distance_y;
			x1 = x1 + x1_lower_than_x2;
		}
		if (temp <= distance_x)
		{
			if (y1 == y2)
				break;
			error = error + distance_x;
			y1 = y1 + y1_lower_than_y2;
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << '\n';
	}
}
void Canvas::Clear()
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			matrix[i][j] = ' ';
}