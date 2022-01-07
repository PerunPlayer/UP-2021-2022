#include <iostream>

using namespace std;

int ackermann(int, int);
void getDecreasing(int lists[][3], int size, int arrays);
bool isDecreasing(int lists[][3], int i, int size, int iterator);
bool searchMaze(int startRow, int startCol, int endRow, int endCol);
bool outOfBounds(int row, int col);

const int SIZE = 5;

bool maze[SIZE][SIZE] = { {1, 1, 0, 0, 0},
						              {0, 1, 1, 1, 0},
						              {0, 1, 0, 1, 0},
						              {0, 1, 0, 1, 0},
						              {1, 1, 0, 1, 1} };

int main()
{
  //TASK 2
	/*bool isItPossible = false;
	isItPossible = searchMaze(0, 0, SIZE - 1, SIZE - 1);
	cout << isItPossible << endl;*/


  //TASK 1
	/*int lists[5][3] = { {5, 4, 3},
						{4, 5, 8},
						{3, 1, 0},
						{6, 7, 5},
						{8, 5, 90} };

	getDecreasing(lists, 3, 5);
	for (int i = 0; i < 5; i++)
	{
		if (lists[i][0] == lists[i][1]) //skipping empty arrays
		{
			continue;
		}
		for (int j = 0; j < 3; j++)
		{
			cout << lists[i][j] << " ";
		}
		cout << endl;
	}*/

  //TASK 0
	/*int first, second;
	cin >> first >> second;
	cout << "Result: " << ackermann(first, second);*/

	return 0;
}

int ackermann(int first, int second)
{
	if (!first)
	{
		return second + 1;
	}
	if (!second)
	{
		return ackermann(first - 1, 1);
	}

	return ackermann(first - 1, ackermann(first, second - 1));


	return 0;
}

void getDecreasing(int lists[][3], int size, int arrays)
{
	for (int i = 0; i < arrays; i++)
	{
		if (!isDecreasing(lists, i, size, 0))
		{
			for (int j = 0; j < size; j++)
			{
				lists[i][j] = 0;
			}
		}
	}
}

bool isDecreasing(int lists[][3], int i, int size, int iterator)
{
	if (iterator + 1 == size)
	{
		return true;
	}

	return lists[i][iterator] > lists[i][iterator + 1] && isDecreasing(lists, i, size, ++iterator);
}

bool searchMaze(int startRow, int startCol, int endRow, int endCol)
{
	if ((startRow == endRow) && (startCol == endCol))
	{
		return true;
	}
	if (maze[startRow][startCol] == 0 || maze[endRow][endCol] == 0)
	{
		return false;
	}

	bool left = false, right = false, up = false, down = false;

	maze[startRow][startCol] = 0;
	if (outOfBounds(startRow + 1, startCol) && maze[startRow + 1][startCol] == 1)
	{
		down = searchMaze(startRow + 1, startCol, endRow, endCol);
	}
	if (outOfBounds(startRow - 1, startCol) && maze[startRow - 1][startCol] == 1)
	{
		up = searchMaze(startRow - 1, startCol, endRow, endCol);
	}
	if (outOfBounds(startRow, startCol + 1) && maze[startRow][startCol + 1] == 1)
	{
		right = searchMaze(startRow, startCol + 1, endRow, endCol);
	}
	if (outOfBounds(startRow, startCol - 1) && maze[startRow][startCol - 1] == 1)
	{
		left = searchMaze(startRow, startCol - 1, endRow, endCol);
	}
	maze[startRow][startCol] = 1;

	return left || right || up || down;
}

bool outOfBounds(int row, int col)
{
	if (row < 0 || col < 0 || row >= SIZE || col >= SIZE)
	{
		return false;
	}
	return true;
}
