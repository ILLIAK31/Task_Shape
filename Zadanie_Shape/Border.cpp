#pragma once
#include <iostream>
#include <string>

using namespace std;

#include "Border.hpp"

void Border::AddRectangle2(Shape* obj2 , Shape* obj, vector<vector<string>>& Shape, int& Size_Forest)
{

	int x = ((obj->x)+(obj2->x)) - 2, y = ((obj->y)+(obj2->y)) - 2;
	for (int y2 = 0; y2 < (obj->height+2); ++y2, ++y)
	{
		for (int x2 = 0; x2 < (obj->width+2); ++x2, ++x)
		{
			if (((obj->tab[y2][x2]) == "0") && (Shape[y][x] != "0"))
			{
				if ((x + 1) >= (2 * Size_Forest))
					break;
				Shape[y][x] = obj->tab[y2][x2];
				continue;
			}
			Shape[y][x] = obj->tab[y2][x2];
			if ((x + 1) >= (2 * Size_Forest))
				break;
		}
		x = ((obj->x) + (obj2->x)) - 2;
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