﻿#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Shape.hpp"
#include "Tree.hpp"
#include "Rectangle.hpp"
#include "RT.hpp"
#include "Border.hpp"

void PrintForest(vector<Shape*>& objs, vector<vector<string>>& Shape, int& Size_Forest);

int main()
{
    int Height, Width, menu_num, X, Y, size_forest , size_of_obj = 0 , xb , yb , h ,w;
	string Color , ColorB , Position , border;
	char Symbol;
	cout << "To create forest give size of it (Size must be bigger than 0): ";
	vector<Shape*> objs;
	cin >> size_forest;
	cout << "Size of forest gona be " << size_forest << "x" << 2 * size_forest << endl;
	vector<vector<string> > forest(size_forest, vector<string>(2 * size_forest));
	for (int i = 0; i < size_forest; ++i)
	{
		for (int j = 0; j < 2 * size_forest; ++j)
		{
			forest[i][j] = "0";
		}
	}
	do
	{
		cout << endl << "Menu :" << endl << "1. Add tree to forest" << endl << "2. Add rectangle to forest" << endl << "3. Add rectangular triangle to forest" << endl << "4. Print forest" << endl << "5. Exit" << endl << "Enter number : ";
		cin >> menu_num;
		if (menu_num == 1)
		{
			cout << endl << "Enter color (Red , Blue , Green , Yellow , Purple , White) : ";
			cin >> Color;
			if ((Color != "Red") && (Color != "Blue") && (Color != "Green") && (Color != "Yellow") && (Color != "Purple") && (Color != "White"))
			{
				cout << endl << "Wrong color" << endl;
				break;
			}
			cout << "Enter symbol : ";
			cin >> Symbol;
			cout << "Enter height : ";
			cin >> Height;
			cout << "Enter X ( From " << "1 to " << 2 * size_forest << " ) : ";
			cin >> X;
			if (size_forest == 1)
				cout << "Enter Y (Only 1 can be Y) : ";
			else
				cout << "Enter Y ( From " << "1 to " << size_forest << " ) : ";
			cin >> Y;
			Shape* obj = new Shape(size_of_obj,Color,Symbol,Height,X,Y);
			Tree* obj2 = new Tree();
			objs.push_back(obj);
			obj2->AddTree(obj,forest,size_forest);
			delete obj2;
			obj2 = NULL;
		}
		else if (menu_num == 2)
		{
			cout << endl << "Enter color (Red , Blue , Green , Yellow , Purple , White) : ";
			cin >> Color;
			if ((Color != "Red") && (Color != "Blue") && (Color != "Green") && (Color != "Yellow") && (Color != "Purple") && (Color != "White"))
			{
				cout << endl << "Wrong color" << endl;
				break;
			}
			cout << "Enter symbol : ";
			cin >> Symbol;
			cout << "Enter height : ";
			cin >> Height;
			cout << "Enter width : ";
			cin >> Width;
			cout << "Enter X ( From " << "1 to " << 2 * size_forest << " ) : ";
			cin >> X;
			if (size_forest == 1)
				cout << "Enter Y (Only 1 can be Y) : ";
			else
				cout << "Enter Y ( From " << "1 to " << size_forest << " ) : ";
			cin >> Y;
			cout << "Do you want border for rectangle ?" << endl << "Yes or No : ";
			cin >> border;
			if (border == "Yes")
			{
				Shape* obj = new Shape(size_of_obj, Color, Symbol, Height, Width, X, Y);
				Rectangle* obj3 = new Rectangle();
				objs.push_back(obj);
				obj3->AddRectangle(obj, forest, size_forest);
				cout << "Enter x for border : ";
				cin >> xb;
				cout << "Enter y for border : ";
				cin >> yb;
				cout << "Enter hight of border : ";
				cin >> h;
				cout << "Enter width of border : ";
				cin >> w;
				cout << "Enter color of border (Red , Blue , Green , Yellow , Purple , White) : ";
				cin >> ColorB;
				if (!(((h + yb + 2) < Height) && ((w + xb + 2) < Width)))
					break;
				Shape* obj6 = new Shape(size_of_obj, ColorB, Symbol, h, w, xb , yb,2);
				Border* obj5 = new Border();
				objs.push_back(obj6);
				obj5->AddRectangle2(obj,obj6, forest, size_forest);
				delete obj5;
				obj5 = NULL;
				delete obj3;
				obj3 = NULL;
			}
			else
			{
				Shape* obj = new Shape(size_of_obj, Color, Symbol, Height, Width, X, Y);
				Rectangle* obj3 = new Rectangle();
				objs.push_back(obj);
				obj3->AddRectangle(obj, forest, size_forest);
				delete obj3;
				obj3 = NULL;
			}
		}
		else if (menu_num == 3)
		{
			cout << endl << "Enter color (Red , Blue , Green , Yellow , Purple , White) : ";
			cin >> Color;
			if ((Color != "Red") && (Color != "Blue") && (Color != "Green") && (Color != "Yellow") && (Color != "Purple") && (Color != "White"))
			{
				cout << endl << "Wrong color" << endl;
				break;
			}
			cout << "Enter symbol : ";
			cin >> Symbol;
			cout << "Enter height : ";
			cin >> Height;
			cout << "Enter X ( From " << "1 to " << 2 * size_forest << " ) : ";
			cin >> X;
			if (size_forest == 1)
				cout << "Enter Y (Only 1 can be Y) : ";
			else
				cout << "Enter Y ( From " << "1 to " << size_forest << " ) : ";
			cin >> Y;
			cout << "Enter postition of object (LT,RT,LD,RD) . Where L is left , R is right , T is top , D is down . \nEnter : ";
			cin >> Position;
			Shape* obj = new Shape(size_of_obj, Color, Symbol, Height, X, Y ,Position);
			RT* obj4 = new RT();
			objs.push_back(obj);
			obj4->AddRT(obj,forest,size_forest);
			delete obj4;
			obj4 = NULL;
		}
		else if (menu_num == 4)
			PrintForest(objs,forest,size_forest);
		else if (menu_num == 5)
		{
			cout << "Objects were deleted" << endl;
			break;
		}
		else
		{
			cout << "Wrong number" << endl << "Objects were deleted" << endl;
			break;
		}
	} while (true);
	objs.clear();
	forest.clear();
	cout << endl << "Forest was deleted" << endl;
}

void PrintForest(vector<Shape*>& objs, vector<vector<string>>& Shape, int& Size_Forest)
{
	int index;
	for (int i = 0; i < Size_Forest; ++i)
	{
		for (int j = 0; j < 2 * Size_Forest; ++j)
		{
			if (Shape[i][j] == "0")
				cout << ' ';
			else
			{
				index = stoi(Shape[i][j]);
				cout << "\033[1;" << objs[index - 1]->GetColor() << objs[index - 1]->GetSymbol() << "\033[0m";
			}
		}
		cout << endl;
	}
}