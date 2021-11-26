#include "stdafx.h"
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

int main()
{
	int rows, cols;
	char field[MAX_SIZE][MAX_SIZE];
	cin >> rows >> cols;

	for (size_t i = 0; i < rows; i++)
	{
		cin >> field[i];
	}

	short xDir, yDir;
	short currX = 0, currY = 0;
	int countAt = 0, countX = 0, countAnd = 0;

	do
	{
		switch (field[currX][currY])
		{
		case 'X': countX++; break;
		case '&': countAnd++; break;
		case '@': countAt++; break;
		default: cout << "Invalid input" << endl;
			break;
		}
    
		cin >> xDir >> yDir; //(1,0)-надясно, (0,1)-нагоре, (-1,0)-наляво, (0,-1)-надолу
		if ((xDir == 1) && (yDir == 0) && currY < cols - 1)
		{
			currY++;
		}
		else if ((xDir == 0) && (yDir == 1) && currX > 0)
		{
			currX--;
		}
		else if ((xDir == -1) && (yDir == 0) && currY > 0)
		{
			currY--;
		}
		else if ((xDir == 0) && (yDir == -1) && currX < rows - 1)
		{
			currX++;
		}
		else
		{
			cout << "Wrong directions. Try again!" << endl;
		}
	} while ((xDir != 0) || (yDir != 0));

	cout << "Count of X: " << countX << endl;
	cout << "Count of &: " << countAnd << endl;
	cout << "Count of @: " << countAt << endl;

	return 0;
}
