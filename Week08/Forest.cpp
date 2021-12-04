#include <iostream>

using namespace std;

const int MAX_SIZE = 50;

int countNeighbours(char forest[][MAX_SIZE], int currRow, int currCol, int rows, int cols);
void printForest(char forest[][MAX_SIZE], int rows, int cols);

int main()
{
	int rows, cols, years;
	char forest[MAX_SIZE][MAX_SIZE], lastForest[MAX_SIZE][MAX_SIZE];

	cout << "Enter rows: ";
	cin >> rows;
	cout << "Enter cols: ";
	cin >> cols;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cin >> forest[i][j];
		}
	}

	cout << "Enter years: ";
	cin >> years;

	if (years >= 10)
	{
		int decades = years / 10;
		for (int decade = 0; decade < decades; decade++)
		{
			for (size_t i = 0; i < rows; i++)
			{
				for (size_t j = 0; j < cols; j++)
				{
					lastForest[i][j] = forest[i][j]; //update backup forest
				}
			}
			for (size_t i = 0; i < rows; i++)
			{
				for (size_t j = 0; j < cols; j++)
				{
					if (forest[i][j] >= '1' && forest[i][j] <= '3')
					{
						forest[i][j]++;
					}
					else if (forest[i][j] == '4')
					{
						int neighbours = countNeighbours(lastForest, i, j, rows, cols); //check before changes
						if (neighbours >= 3)
						{
							forest[i][j]--;
						}
					}
				}
			}
			cout << "Decade " << decade << endl;
			printForest(forest, rows, cols);
		}
	}

	return 0;
}

int countNeighbours(char forest[][MAX_SIZE], int currRow, int currCol, int rows, int cols)
{
	int count = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			//check borders
			if ((currRow == 0 && i == -1) ||
				(currRow == rows && i == 1) ||
				(currCol == 0 && j == -1) ||
				(currCol == cols && j == 1))
			{
				continue;
			}
			if (i == 0 && j == 0) //don't count current position
			{
				continue;
			}
			if (forest[i + currRow][j + currCol] == '4')
			{
				count++;
			}
		}
	}

	return count;
}

void printForest(char forest[][MAX_SIZE], int rows, int cols)
{
	cout << "----------------\n";
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << forest[i][j] << " ";
		}
		cout << endl;
	}
	cout << "----------------\n";
}
