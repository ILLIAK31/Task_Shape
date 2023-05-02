#pragma once

#include "Rectangle.hpp"

class Border : public Rectangle
{
public:
	Border() = default;
	string GetColor();
	char GetSymbol();
	void AddRectangle2(Shape* obj2,Shape* obj, vector<vector<string>>& Shape, int& Size_Forest);
	~Border();
};