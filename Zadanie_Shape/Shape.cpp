#include <iostream>
#include <string>

using namespace std;

#include "Shape.hpp"

Shape::Shape(int& Size_Forest, string Color, char Symbol, int Height, int X, int Y)
{
	++Size_Forest;
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
	tab = new int* [height];
	for (int j = 0; j < height; j++)
	{
		tab[j] = new int[2 * height - 1];
		for (int i = 0; i < 2 * height - 1; i++)
			tab[j][i] = 0;
	}
	for (int j = 0; j < height; j++)
		for (int i = height - j - 1; i < height + j; i++)
			tab[j][i] = Size_Forest;
}

Shape::~Shape()
{
	for (int j = 0; j < height; j++)
		delete tab[j];
	delete tab;
}

void Shape::PrintForest(vector<vector<string>>& Shape, int& Size_Forest, vector<Shape*> objs)
{
	int index;
	for (int i = 0; i < Size_Forest; ++i)
	{
		for (int j = 0; j < 2 * Size_Forest; ++j)
		{
			if (Shape[i][j] == "0")
				cout << ' ';
			else if ((Shape[i][j]).size() == 1)
			{
				index = stoi(Shape[i][j]);
				//cout << "\033[1;" << wektor[index - 1]->color << wektor[index - 1]->symbol << "\033[0m";
			}
			else
			{
				index = int((Shape[i][j])[2]);
				//cout << "\033[1;" << wektor[index - 1]->color << wektor[index - 1]->symbol << "\033[0m";
			}
		}
		cout << endl;
	}
}

string Shape::GetColor(Shape* obj)
{
	return obj->color;
}

char Shape::GetSymbol(Shape* obj)
{
	return obj->symbol;
}