#pragma once

#include "Shape.hpp"

class RT : public Shape
{
public:
	RT() = default;
	void AddRT(Shape* obj, vector<vector<string>>& Shape, int& Size_Forest);
};