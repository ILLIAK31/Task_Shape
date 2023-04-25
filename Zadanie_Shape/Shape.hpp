#pragma once
#include <vector>
class Shape
{
private:
	friend class Tree;
	friend class Rectangle;
	friend class RT;
	//friend void AddTree(Tree* obj2, Shape* obj, vector<vector<string>>& Shape);
	//friend string GetColor(Shape* obj);
	string color;
	char symbol;
	int height ,width;
	int x , y;
	string** tab;
	string position;
	int size_of_forest;
public:
	Shape() = default;
	Shape(int& Size_Of_Obj,string Color, char Symbol, int Height, int X, int Y);
	Shape(int& Size_Of_Obj, string Color, char Symbol, int Height, int Width , int X, int Y);
	Shape(int& Size_Of_Obj, string Color, char Symbol, int Height, int X, int Y,string Position);
	string GetColor();
	char GetSymbol();
	~Shape();
};