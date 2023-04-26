#pragma once
#include <vector>
class Shape
{
private:
	friend class Tree;
	friend class Rectangle;
	friend class RT;
	friend class Border;
	string color ;
	char symbol;
	int height ,width ;
	int x , y ;
	string** tab;
	string position;
	int size_of_forest;
public:
	Shape() = default;
	Shape(int& Size_Of_Obj,string Color, char Symbol, int Height, int X, int Y);
	Shape(int& Size_Of_Obj, string Color, char Symbol, int Height, int Width , int X, int Y);
	Shape(int& Size_Of_Obj, string Color, char Symbol, int Height, int X, int Y,string Position);
	Shape(int& Size_Of_Obj, string Color, char Symbol, int Height, int Width ,int X, int Y,int Type);
	virtual string GetColor();
	virtual char GetSymbol();
	virtual ~Shape();
};