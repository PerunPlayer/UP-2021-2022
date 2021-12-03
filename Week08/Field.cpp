#include <iostream>

const int ARRAY_SIZE = 50;

void enterField(char arr[ARRAY_SIZE][ARRAY_SIZE], const int rows, const int columns);
void printField(const char arr[ARRAY_SIZE][ARRAY_SIZE], const int rows, const int columns);
void modifyField(char arr[ARRAY_SIZE][ARRAY_SIZE], const int rows, const int columns, int years);


int main()
{
	char field[ARRAY_SIZE][ARRAY_SIZE];
	int rowWidth, rowHeight, years;

	std::cin >> rowHeight >> rowWidth >> years;

	enterField(field, rowWidth, rowHeight);
	
	std::cout << std::endl;

	printField(field, rowWidth, rowHeight);

	modifyField(field, rowWidth, rowHeight, years);
	printField(field, rowWidth, rowHeight);
}

void enterField(char arr[ARRAY_SIZE][ARRAY_SIZE], const int rows, const int columns)
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			std::cin >> arr[row][column];
		}
	}
}

void printField(const char arr[ARRAY_SIZE][ARRAY_SIZE], const int rows, const int columns)
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			std::cout << arr[row][column] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void modifyField(char arr[ARRAY_SIZE][ARRAY_SIZE], const int rows, const int columns, int years)
{
	int amountOfFours = 0;

	while (years >= 10)
	{
		for (int row = 0; row < rows; row++)
		{
			for (int column = 0; column < columns; column++)
			{
				if (arr[row][column] >= '1' && arr[row][column] <= '3')
				{
					arr[row][column]++;
				}	
				else if (arr[row][column] == '4')
				{
					if (row == 0)
					{
						if (column == 0)
						{
							if (arr[row][column + 1] == '4') amountOfFours++;
							if (arr[row + 1][column] == '4') amountOfFours++;
							if (arr[row + 1][column + 1] == '4') amountOfFours++;
						}
						else if (column == columns - 1)
						{
							if (arr[row][column - 1] == '4') amountOfFours++;
							if (arr[row + 1][column] == '4') amountOfFours++;
							if (arr[row + 1][column - 1] == '4') amountOfFours++;
						}
						else
						{
							if (arr[row][column - 1] == '4') amountOfFours++;
							if (arr[row][column + 1] == '4') amountOfFours++;
							if (arr[row + 1][column - 1] == '4') amountOfFours++;
							if (arr[row + 1][column] == '4') amountOfFours++;
							if (arr[row + 1][column + 1] == '4') amountOfFours++;
						}
					}
					else if (row == rows - 1)
					{
						if (column == 0)
						{
							if (arr[row][column + 1] == '4') amountOfFours++;
							if (arr[row - 1][column] == '4') amountOfFours++;
							if (arr[row - 1][column + 1] == '4') amountOfFours++;
						}
						else if (column == columns - 1)
						{
							if (arr[row][column - 1] == '4') amountOfFours++;
							if (arr[row - 1][column] == '4') amountOfFours++;
							if (arr[row - 1][column - 1] == '4') amountOfFours++;
						}
						else
						{
							if (arr[row][column - 1] == '4') amountOfFours++;
							if (arr[row][column + 1] == '4') amountOfFours++;
							if (arr[row - 1][column - 1] == '4') amountOfFours++;
							if (arr[row - 1][column] == '4') amountOfFours++;
							if (arr[row - 1][column + 1] == '4') amountOfFours++;
						}
					}
					else
					{
						if (arr[row][column + 1] == '4') amountOfFours++;
						if (arr[row][column - 1] == '4') amountOfFours++;
						if (arr[row - 1][column] == '4') amountOfFours++;
						if (arr[row - 1][column + 1] == '4') amountOfFours++;
						if (arr[row - 1][column - 1] == '4') amountOfFours++;
						if (arr[row + 1][column] == '4') amountOfFours++;
						if (arr[row + 1][column + 1] == '4') amountOfFours++;
						if (arr[row + 1][column - 1] == '4') amountOfFours++;
					}
				}

				if (amountOfFours >= 3) arr[row][column]--;

				amountOfFours = 0;
			}
		}

		years -= 10;
	}
}