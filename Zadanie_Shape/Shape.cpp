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

Shape::Shape(int& Size_Of_Obj, string Color, char Symbol, int Height, int Width, int X, int Y)
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
	width = Width;
	x = X;
	y = Y;
	string s = to_string(Size_Of_Obj);
	tab = new string * [height];
	for (int j = 0; j < height; j++)
	{
		tab[j] = new string[width];
		for (int i = 0; i < width; i++)
			tab[j][i] = s;
	}
}

Shape::Shape(int& Size_Of_Obj, string Color, char Symbol, int Height, int X, int Y, string Position)
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
	position = Position;
	string s = to_string(Size_Of_Obj);
	tab = new string * [height];
	for (int j = 0; j < height; j++)
	{
		tab[j] = new string[height];
		for (int i = 0; i < height; i++)
			tab[j][i] = "0";
	}
	int height2;
	if (position == "RD")
	{
		height2 = height;
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < height2; i++)
				tab[j][i] = s;
			--height2;
		}
	}
	else if (position == "RT")
	{
		height2 = 1;
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < height2; i++)
				tab[j][i] = s;
			++height2;
		}
	}
	else if (position == "LT")
	{
		height2 = height-2;
		for (int j = 0; j < height; j++)
		{
			for (int i = height-1; i > height2; i--)
				tab[j][i] = s;
			--height2;
		}
	}
	else
	{
		height2 = 0;
		for (int j = 0; j < height; j++)
		{
			for (int i = height - 1; i >= height2; i--)
				tab[j][i] = s;
			++height2;
		}
	}
}

Shape::Shape(int& Size_Of_Obj, string Color, char Symbol, int Height, int Width, int X, int Y, int Type) :symbol(Symbol), height(Height), width(Width), x(X), y(Y)
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

	string s = to_string(Size_Of_Obj);
	int index_x = 0, index_y = 0;
	tab = new string * [Height+2];
	for (int j = 0; j < Height+2; j++)
	{
		tab[j] = new string[Width+2];
		for (int i = 0; i < Width + 2; i++)
		{
			if ((index_y == 0) || (index_y == (Height + 1)))
				tab[j][i] = s;
			else
			{
				if ((index_x == 0) || (index_x == (Width + 1)))
					tab[j][i] = s;
				else
					tab[j][i] = "0";
			}
			++index_x;
		}
		++index_y;
		index_x = 0;
	}
}

string Shape::GetColor()
{
	return this->color;
}

char Shape::GetSymbol()
{
	return this->symbol;
}

Shape::~Shape()
{
	for (int j = 0; j < height; j++)
		delete tab[j];
	delete [] tab;
}