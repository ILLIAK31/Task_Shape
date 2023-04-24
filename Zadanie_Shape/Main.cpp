#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Shape.hpp"
#include "Tree.hpp"
#include "Rectangle.hpp"

vector<Shape*> objs;

void PrintForest(vector<Shape*>& objs,vector<vector<string>>& Shape, int& Size_Forest)
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

int main()
{
	vector<Shape*> objs;
    int Height, Width, menu_num, X, Y, size_forest , size_of_obj = 0;
	string Color;
	char Symbol;
	cout << "To create forest give size of it (Size must be bigger than 0): ";
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
		cout << endl << "Menu :" << endl << "1. Add tree to forest" << endl << "2. Add rectangle to forest" << endl << "3. Print forest" << endl << "4. Exit" << endl << "Enter number : ";
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
			Shape* obj = new Shape(size_of_obj, Color, Symbol, Height, Width, X, Y);
			Rectangle* obj3 = new Rectangle();
			objs.push_back(obj);
			obj3->AddRectangle(obj, forest, size_forest);
		}
		else if (menu_num == 3)
		{
			PrintForest(objs,forest,size_forest);
		}
		else if (menu_num == 4)
		{
			break;
		}
		else
		{
			cout << "Wrong number" << endl;
			break;
		}
	} while (true);
}
