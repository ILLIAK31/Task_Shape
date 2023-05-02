#include <iostream>

using namespace std;

#include "Tree.hpp"

void Tree::AddTree(Shape* obj, vector<vector<string>>& Shape, int& Size_Forest)
{
	int x = (obj->x) - 1, y = (obj->y) - 1;
	for (int y2 = 0; y2 < (obj->height); ++y2, ++y)
	{
		for (int x2 = 0; x2 < ((2 * (obj->height)) - 1); ++x2, ++x)
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

Tree::~Tree(){}
