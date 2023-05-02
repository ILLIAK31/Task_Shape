#pragma once

#include "Shape.hpp"

class Tree : public Shape
{
public:
	Tree() = default;
	void AddTree(Shape* obj, vector<vector<string>>& Shape, int& Size_Forest);
	~Tree();
};