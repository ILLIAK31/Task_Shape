#pragma once
#include <vector>
class Shape
{
private:
	friend class Tree;
	friend void AddTree(Tree* obj2, Shape* obj, vector<vector<string>>& Shape);
	friend string GetColor(Shape* obj);
	string color;
	char symbol;
	int height ,width;
	int x , y;
	int** tab;
	string position;
	int size_of_forest;
public:
	Shape() = default;
	Shape(int& Size_Forest,string Color, char Symbol, int Height, int X, int Y);
	void PrintForest(vector<vector<string>>& Shape, int& Size_Forest);
	string GetColor(Shape* obj);
	char GetSymbol(Shape* obj);
	~Shape();
};