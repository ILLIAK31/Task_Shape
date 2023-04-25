#pragma once

#include "Rectangle.hpp"

class Border : public Rectangle
{
private:
	int x, y , h , w;
public:
	Border() = default;
	void AddRectangle(Shape* obj, vector<vector<string>>& Shape, int& Size_Forest);
};