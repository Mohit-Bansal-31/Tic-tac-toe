// Mohit Bansal
// 5/03/2023 && 6/03/2023
// My First Project
// Hope you will like it.
//  Let's learn how to make a tic-tac-toe game at medium level difficulty
#include <iostream>
using namespace std;
char matrix[3][3];
char check();	 // check after each move
void init();	 // intialize the matrix with spaces
void computer(); // computer's move
void you();		 // Your move
void display();	 // display the matrix
void bansal(int s);
int q = 1;
int main()
{
	char done = ' ';
	char w[80];
	char ch = '0';
	cout << "This is a simple Tic-Tac-Toe game.\n"
		 << endl
		 << "You will be playing against Computer(Single Player).\n"
		 << endl
		 << "Here, the upper leftmost block is in row 1, column 1 and the bottom rightmost block is row 3,column 3.\n"
		 << endl;
	for (;;)
	{
		init();
		cout << "You will have Cross Symbol(X) and Computer will have Nought Symbol(O).\n" << endl;
		do
		{
			display();
			you();
			done = check();
			if (done != ' ')
				break;
			computer();
			done = check();
		} while (done == ' ');
		display();
		if (done == 'X')
			cout << "\nCongratulations for this time!" << endl
				 << "But I won't let you win the next time.\n"
				 << endl;
		if (done == 'O')
			cout << "\nSee I won!!" << endl
				 << "It takes more than this to beat me.\n"
				 << endl;
		if (done == 'd')
			cout << "\nWell played! Guess this time we have to settle for a draw.\n"
				 << endl;
		while (ch != 'Y' && ch != 'N')
		{
			fflush(stdin);
			cout << "Do you want to play again:" << endl;
			cout << "(Y)es\t\t(N)o" << endl;
			gets(w);
			ch = toupper(*w);
		}
		if (ch == 'N')
		{
			cout << "Thank You for Playing.";
			break;
		}
		if (ch == 'Y')
			continue;
	}
}
void init()
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			matrix[i][j] = ' ';
	}
}
void display()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		cout << "| " << matrix[i][0] << " | " << matrix[i][1] << " | " << matrix[i][2] << " |" << endl;
		if (i != 2)
			cout << "|---|---|---|" << endl;
	}
	cout << endl;
}
void you()
{
	int x, y;
	cout << "Enter the row of block you want to fill:";
	cin >> x;
	cout << "\nEnter the column of block you want to fill:";
	cin >> y;
	--x, --y;
	if (matrix[x][y] != ' ')
	{
		cout << "\nInvalid Input!Try again.\n"
			 << endl;
		you();
	}
	else
		matrix[x][y] = 'X';
}
char check()
{
	int i, j, r = 0;
	// checking rows
	for (i = 0; i < 3; i++)
	{
		if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
			return matrix[i][0];
	}
	// checking columns
	for (i = 0; i < 3; i++)
	{
		if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
			return matrix[0][i];
	}
	// checking diagonals
	if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2])
		return matrix[0][0];
	if (matrix[1][1] == matrix[0][2] && matrix[1][1] == matrix[2][0])
		return matrix[1][1];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			if (matrix[i][j] == ' ')
				r++;
	}
	if (r == 0)
		return 'd';
	else
		return ' ';
}
void bansal(int m)
{
	int mohit[3][3];
	int i, j, sumr = 0, sumc = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (matrix[i][j] == 'X')
				mohit[i][j] = 2;
			if (matrix[i][j] == 'O')
				mohit[i][j] = 8;
			if (matrix[i][j] == ' ')
				mohit[i][j] = 0;
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sumr = 0;
			sumc = 0;
			if (mohit[0][0] + mohit[1][1] + mohit[2][2] == m)
			{
				if (mohit[0][0] == 0)
				{
					matrix[0][0] = 'O';
					q++;
					break;
				}
				if (mohit[2][2] == 0)
				{
					matrix[2][2] = 'O';
					q++;
					break;
				}
			}
			if (mohit[0][2] + mohit[1][1] + mohit[2][0] == m)
			{
				if (mohit[0][2] == 0)
				{
					matrix[0][2] = 'O';
					q++;
					break;
				}
				if (mohit[2][0] == 0)
				{
					matrix[2][0] = 'O';
					q++;
					break;
				}
			}
			if (mohit[i][j] == 0)
			{
				sumr = mohit[i][0] + mohit[i][1] + mohit[i][2];
				sumc = mohit[0][j] + mohit[1][j] + mohit[2][j];
				if (sumr == m || sumc == m)
				{
					matrix[i][j] = 'O';
					q++;
					break;
				}
			}
		}
		if (q > 1)
			break;
	}
}
void computer()
{
	if (matrix[1][1] == ' ')
	{
		matrix[1][1] = 'O';
	}
	else
	{
		bansal(16);
		if (q == 1)
			bansal(4);
		if (q == 1)
			bansal(2);
		if (q == 1)
			bansal(8);
		if (q == 1)
			bansal(0);
		if (q == 1)
			bansal(10);
	}
	q = 1;
	cout << "Here's my response:" << endl;
}
