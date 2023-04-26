#pragma once

#include "Rectangle.hpp"

class Border : public Rectangle
{
private:
	int x, y , h , w;
	string color ;
	char symbol;
public:
	Border() = default;
	Border(string Color, int X, int Y, int H, int W);
	string GetColor();
	char GetSymbol();
	void AddRectangle2(Shape* obj, vector<vector<string>>& Shape, int& Size_Forest, int& Size_Of_Obj);
};