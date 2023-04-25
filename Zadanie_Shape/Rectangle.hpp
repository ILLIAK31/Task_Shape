#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
	Rectangle() = default;
	virtual void AddRectangle(Shape* obj, vector<vector<string>>& Shape, int& Size_Forest);
};
