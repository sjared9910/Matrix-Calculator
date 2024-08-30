#include "menu_header.h"

//defines arrow keys
#define KEY_UP 72
#define KEY_DOWN 80

using namespace std;

//Shows menu of matrix operations
void ShowMenu()
{
	cout << "   Matrix Menu" << endl;
	cout << "-----------------------------" << endl;
	cout << "   Addition" << endl;
	cout << "   Subtraction" << endl;
	cout << "   Multiplication" << endl;
	cout << "   Power" << endl;
	cout << "   Transpose" << endl;
	cout << "   Determinant" << endl;
	cout << "   Inverse" << endl;
	cout << "   About" << endl;
	cout << "   Quit" << endl;
	cout << endl;
}

//Moves the cursor to a location in the terminal based on inputted 
//x and y coordinates
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//Function that applies functionality to the main menu of the calculator
//Allows the arrow keys to navigate through the various functions of
//the calculator and make the navigation circular to prevent offscreen
int menu_move(int counter)
{
	//display menu and take key input
	ShowMenu();
	gotoxy(0, counter + 1);
	cout << "->";
	char key = _getch();

	//loop to allow menu navigation
	while (key != '\r')
	{
		system("cls");
		ShowMenu();
		gotoxy(0, counter + 1);
		cout << "->";

		key = _getch();

		//moves arrow selector up one space or loops down to last option
		if (key == KEY_UP)
		{
			if (counter == 1)
			{
				counter = 9;
			}
			else
			{
				counter--;
			}
		}
		//moves arrow selector down one space or loops to first option
		if (key == KEY_DOWN)
		{
			if (counter == 9)
			{
				counter = 1;
			}
			else
			{
				counter++;
			}
		}
	}
	system("cls");
	return counter + 1;
}
//Matrix addition selected from main menu, performs matrix addition
void add_update()
{
	system("cls");
	while (true)
	{
		addition();
		cout << "Press enter to continue" << endl;
		if (_getch() == '\r')
		{
			break;
		}
	}
	system("cls");
	return;
}
//Matrix subtraction selected from main menu, performs subtraction
void sub_update()
{
	system("cls");
	while (true)
	{
		subtraction();
		cout << "Press enter to continue" << endl;
		if (_getch() == '\r')
		{
			break;
		}
	}
	system("cls");
	return;
}
//Matrix multiplication selected from main menu, performs multiplication
void mul_update()
{
	system("cls");
	while (true)
	{
		multiplication();
		cout << "Press enter to continue" << endl;
		if (_getch() == '\r')
		{
			break;
		}
	}
	system("cls");
	return;
}
//Matrix power selected from main menu, performs power of a matrix
void pow_update()
{
	system("cls");
	while (true)
	{
		power();
		cout << "Press enter to continue" << endl;
		if (_getch() == '\r')
		{
			break;
		}
	}
	system("cls");
	return;
}
//Matrix transpose choosen from main menu, performs transpose
void trans_update()
{
	system("cls");
	while (true)
	{
		trans();
		cout << "Press enter to continue" << endl;
		if (_getch() == '\r')
		{
			break;
		}
	}
	system("cls");
	return;
}
//Matrix determinate choosen from main menu, calculates determinate
void det_update()
{
	system("cls");
	while (true)
	{
		determ();
		cout << "Press enter to continue" << endl;
		if (_getch() == '\r')
		{
			break;
		}
	}
	system("cls");
	return;
}
//Matrix inverse choosen from main menu, calculates inverse
void inverse_update()
{
	system("cls");
	while (true)
	{
		inverse();
		cout << "Press enter to continue" << endl;
		if (_getch() == '\r')
		{
			break;
		}
	}
	system("cls");
	return;
}
//Displays the about section of the calculator
void about_update()
{
	system("cls");
	while (true)
	{
		cout << "Matrix calculator that can do multiple operations." << endl;
		cout << "Choose from addition, subtraction, multiplication," << endl;
		cout << "matrix power, transpose matrix, determinant, and inverse." << endl;
		cout << endl;
		cout << "Press enter to continue" << endl;

		if (_getch() == '\r')
		{
			break;
		}
	}
	system("cls");
	return;
}

//Inputs matrix content into a vector. Takes num of cols and rows and forms a matrix based on inputted information.
Matrix InputMatrix()
{
	//takes num of rows and cols as inputes
	int col;
	cout << "Enter the number of columns: ";
	cin >> col;
	//input validation to ensure a number is inputted
	while (!cin.good())
	{
		cin.clear();
		cin.ignore(40, '\n');
		cout << "Not a number please try again" << endl;
		cout << "Enter the number of columns: ";
		cin >> col;
	}

	int row;
	cout << "Enter the number of rows: ";
	cin >> row;
	//input validation to ensure a number is inputted
	while (!cin.good())
	{
		cin.clear();
		cin.ignore(40, '\n');
		cout << "Not a number please try again" << endl;
		cout << "Enter the number of rows: ";
		cin >> row;
	}

	int num = 0;

	//vector for matrix content
	vector<int>Entry_Vector;

	//inputs content in matrix vector
	for (int i = 0; i < row * col; i++)
	{
		int enter = 0;
		cout << "Enter the " << num << " number column wise: ";
		cin >> enter;
		Entry_Vector.push_back(enter);
		num++;
	}
	cout << endl;

	//Creates matrix
	Matrix Test(Entry_Vector, row, col);

	cout << "inputted Matrix: " << endl;
	//outputs matrix content
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << Test.get(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;
	return Test;
}

//menu option for addition
void addition()
{
	//adds matrix A and B and displays result
	cout << "Addition " << endl;
	cout << "Enter first matrix: " << endl;
	Matrix A = InputMatrix();
	cout << "Enter second matrix: " << endl;
	Matrix B = InputMatrix();
	cout << "Result: " << endl;
	Matrix Result = A.add(B);
	Result.output();
}

//menu option for subtraction
void subtraction()
{
	cout << "Subtraction " << endl;
	//subtracts matrix B from A
	cout << "Enter first matrix: " << endl;
	Matrix A = InputMatrix();
	cout << "Enter second matrix: " << endl;
	Matrix B = InputMatrix();
	cout << "Result: " << endl;
	Matrix Result = A.sub(B);
	Result.output();
}

//menu option for multiplication
void multiplication()
{
	cout << "Multiplication" << endl;
	cout << "   Type C to multiply by a constant" << endl;
	cout << "   Type m to multiply by another matrix" << endl;
	int counter = 1;
	gotoxy(0, counter);
	cout << "->";
	char key = _getch();

	//Allows user to choose between multiplying by a constant or another matrix
	while (key != '\r')
	{
		system("cls");
		cout << "Multiplication" << endl;
		cout << "  Type C to multiply by a constant" << endl;
		cout << "  Type m to multiply by another matrix" << endl;
		gotoxy(0, counter);
		cout << "->";

		key = _getch();
		//Provides arrow key functionality to choose between the two options
		if (key == KEY_UP)
		{
			if (counter == 1)
			{
				counter = 2;
			}
			else
			{
				counter--;
			}
		}

		if (key == KEY_DOWN)
		{
			if (counter == 2)
			{
				counter = 1;
			}
			else
			{
				counter++;
			}
		}
	}
	//Multiply by constant
	if (counter == 1)
	{
		system("cls");
		//input constant
		int constant;
		cout << "Enter constant: ";
		cin >> constant;
		//input validation to ensure a number is inputted
		while (!cin.good())
		{
			cin.clear();
			cin.ignore(40, '\n');
			cout << "Not a constant please try again" << endl;
			cout << "Enter constant: ";
			cin >> constant;
		}
		//multiplies matrix by constant
		Matrix A = InputMatrix();
		Matrix Result = A.mult(constant);
		Result.output();
	}
	//Multiplying by another matrix
	else if (counter == 2)
	{
		system("cls");
		//multiplies matrix A x B
		Matrix A = InputMatrix();
		Matrix B = InputMatrix();
		Matrix Result = A.mult(B);
		Result.output();
	}
}

//menu option for power of a matrix
void power()
{
	//takes exponential input
	cout << "Power of a Matrix" << endl;
	int constant;
	cout << "Enter constant: ";
	cin >> constant;
	//input validation to ensure a number is inputted
	while (!cin.good())
	{
		cin.clear();
		cin.ignore(40, '\n');
		cout << "Not a constant please try again" << endl;
		cout << "Enter constant: ";
		cin >> constant;
	}
	//multiplies matrix to exponential
	cout << "Enter matrix: " << endl;
	Matrix A = InputMatrix();
	cout << "Result: " << endl;
	Matrix Result = A.power(constant);
	Result.output();
}

//menu option for transpose matrix
void trans()
{
	cout << "Transpose Matrix" << endl;
	//transpose matrix
	cout << "Enter matrix: " << endl;
	Matrix A = InputMatrix();
	cout << "Result: " << endl;
	A.trans(A);
}

//menu option for finding matrix determinant
void determ()
{
	cout << "Determinant" << endl;
	//takes size and finds determinant of matrix
	cout << "Enter matrix: " << endl;
	Matrix A = InputMatrix();
	int size = A.size(1);
	int d = A.determinant(A, size);
	//Matrix isn't a square
	if (d == -2147483648)
	{
		cout << "Not square matrix" << endl;
		cout << endl;
	}
	else
	{
		cout << "Determinant: " << d << endl;
		cout << endl;
	}
}

//menu option for matrix inverse
void inverse()
{
	cout << "Inverse Matrix" << endl;
	cout << "Enter matrix: " << endl;
	Matrix A = InputMatrix();
	cout << "Result: " << endl;
	Matrix Result = A.inverse(A);
}