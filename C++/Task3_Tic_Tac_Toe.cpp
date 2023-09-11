#include <iostream>
using namespace std;

/********************** Task3-Tic Tac Toe **************************/
//Global Variables
char player = 'X'; char grid[3][3]; bool continueGame = true;

//Functions Definitions
void initializeGrid()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
			grid[i][j] = ' ';
	}
}
void displayGrid()
{
	cout << " -------------  " << endl;
	for (int i = 0; i < 3; ++i)
	{
		cout << " | ";
		for (int j = 0; j < 3; ++j)
			cout << grid[i][j] << " | ";
		cout <<endl<< " -------------  " << endl;
	}
}
void switchPlayer()
{
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}
void playerMove()
{
	bool inputWrong = false;int row, column;
	do {
		cout << "Enter the row: ";
		cin >> row;
		cout << "Enter the column: ";
		cin >> column;
		if (row > 2 || row < 0)
		{
			cout << "INVALID ROW!! "<<endl;inputWrong = true;
		}
		else if (column > 2 || column < 0)
		{
			cout << "INVALID COLUMN!! "<<endl;inputWrong = true;
		}
		else if (grid[row][column] != ' ')
		{
			inputWrong = true;
		}
	} while (inputWrong);

	if (player == 'X')
		grid[row][column] = 'X';
	else
		grid[row][column] = 'O';
}
bool checkWin(char symbol)
{
	//check rows
	for (int i = 0; i < 3; ++i)
	{
		if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2]== symbol)
		{
			return true;
		}
	}

	//check columns
	for (int i = 0; i < 3; ++i)
	{
		if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol)
		{
			return true;
		}
	}

	//check diagonals
	if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol)
	{
		return true;
	}
	if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol)
	{
		return true;
	}

	return false;
}
bool checkDraw()
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (grid[i][j] == ' ') {
				return false; // Empty cell found, game is not a draw
			}
		}
	}
	return true; //No empty cells, A draw!!
}
void playAgain()
{
	bool endFunc = false;
	do {
		cout << "Do you want to Play Again??" << endl;
		cout << "	Write Y => Yes	N => No	" << endl;
		char userResponse;
		cin >> userResponse;
		userResponse=toupper(userResponse);
		if (userResponse == 'Y')
		{
			continueGame = true; initializeGrid();
		}
		else if (userResponse == 'N')
		{
			continueGame = false;
			cout << "See You Soon!!" << endl;
		}
		else
		{
			cout << "Invalid Input" << endl; endFunc = true;
		}
	} while (endFunc);
}
void displayResult()
{
	if (checkWin(player))
	{
		cout << "Congratulations!! Winner is Player " << player << endl; playAgain();
	}
	else if (checkDraw())
	{
		cout << "	DRAW!!	" << endl; playAgain();
	}
	return;
}

//Main Program
int main(void)
{
	initializeGrid();
	do
	{
		displayGrid();
		playerMove();
		displayResult();
		switchPlayer();
	} while (continueGame);
	system("pause>0");
}