#pragma once
#include <iostream>

using namespace std;

#include "Border.hpp"

Border::Border(string Color, int X, int Y, int H, int W) : x(X), y(Y), h(H), w(W)
{
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
}

void Border::AddRectangle(Shape* obj, vector<vector<string>>& Shape, int& Size_Forest)
{
	int X = (obj->x) - 1, Y = (obj->y) - 1;


	//if((x<(obj->width-2))||(y<(obj->height)||())

	for (int y2 = 0; y2 < (obj->height); ++y2, ++y)
	{
		for (int x2 = 0; x2 < (obj->width); ++x2, ++x)
		{
			if (((obj->tab[y2][x2]) == "0") && (Shape[y][x] != "0"))
			{
				if ((x + 1) >= (2 * Size_Forest))
					break;
				continue;
			}
			Shape[y][x] = obj->tab[y2][x2];
			if ((x + 1) >= (2 * Size_Forest))
				break;
		}
		x = (obj->x) - 1;
		if ((y + 1) >= Size_Forest)
			break;
	}
}

string Border::GetColor()
{
	return this->color;
}

char Border::GetSymbol()
{
	return this->symbol;
}