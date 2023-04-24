#include <iostream>
#include <string>

using namespace std;

#include "Shape.hpp"

Shape::Shape(int& Size_Of_Obj, string Color, char Symbol, int Height, int X, int Y)
{
	++Size_Of_Obj;
	if (Color == "Red")
		color = "31m";
	else if (Color == "Blue")
		color = "34m";
	else if (Color == "Green")
		color = "32m";
	else if (Color == "Yellow")
		color = "33m";
	else if (Color == "Purple")
		color = "35m";
	else if (Color == "White")
		color = "37m";
	symbol = Symbol;
	height = Height;
	x = X;
	y = Y;
	string s = to_string(Size_Of_Obj);
	tab = new string* [height];
	for (int j = 0; j < height; j++)
	{
		tab[j] = new string[2 * height - 1];
		for (int i = 0; i < 2 * height - 1; i++)
			tab[j][i] = "0";
	}
	for (int j = 0; j < height; j++)
		for (int i = height - j - 1; i < height + j; i++)
			tab[j][i] = s;
}

Shape::~Shape()
{
	for (int j = 0; j < height; j++)
		delete tab[j];
	delete tab;
}

string Shape::GetColor()
{
	return this->color;
}

char Shape::GetSymbol()
{
	return this->symbol;
}