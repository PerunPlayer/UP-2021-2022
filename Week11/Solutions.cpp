#include <iostream>

using namespace std;

int* cutArr(const int* arr, int size);
int* resize(const int* arr, int size, int newSize);
char* copyArray(const char* arr, int length);
char* convertIntToChar(int number);

int main()
{
	//TASK 4
	/*int number;
	cin >> number;

	char* text = convertIntToChar(number);
	cout << text;

	delete[] text;*/

	//TASK 3
	/*char arr[] = "UP-to e lesno";
	char* copy = copyArray(arr, 6);

	delete[] copy;*/

	//TASK 2
	/*int arr[] = { 1, 2, 3, 4, 5, 42 };
	int* newArr = resize(arr, 6, 8);

	cout << "New arr: ";
	for (size_t i = 0; i < 8; i++)
	{
		cout << newArr[i] << " ";
	}
	delete[] newArr;*/

	//TASK 1
	/*int teachersCount, marksCount;
	cout << "Enter number of teachers: ";
	cin >> teachersCount;
	cout << "Enter number of marks per teacher: ";
	cin >> marksCount;

	double** marks = new double* [teachersCount];
	for (size_t i = 0; i < teachersCount; i++)
	{
		cout << "Enter " << marksCount << " marks: ";
		marks[i] = new double[marksCount];
		for (size_t j = 0; j < marksCount; j++)
		{
			cin >> marks[i][j];
		}
	}

	for (size_t i = 0; i < teachersCount; i++)
	{
		for (size_t j = 0; j < marksCount; j++)
		{
			cout << marks[i][j] << " ";
		}
		cout << endl;
	}*/

	//TASK 0
	/*int arr[] = { 1, 2, 3, 4, 5, 42 };

	int* halfArr = cutArr(arr, 6);
	delete[] halfArr;*/

	return 0;
}

int* cutArr(const int* arr, int size)
{
	int newSize = size / 2;
	int* halfArr = new int[newSize];

	for (size_t i = 0; i < newSize; i++)
	{
		halfArr[i] = arr[i];
	}

	return halfArr;
}

int* resize(const int* arr, int size, int newSize)
{
	int* newArr = new int[newSize];
	int iterations = min(size, newSize);
	for (size_t i = 0; i < iterations; i++)
	{
		newArr[i] = arr[i];
	}
	if (newSize == max(size, newSize))
	{
		for (size_t i = size; i < newSize; i++)
		{
			newArr[i] = 0;
		}
	}

	return newArr;
}

char* copyArray(const char* arr, int length)
{
	char* copy = new char[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		copy[i] = arr[i];
	}
	copy[length] = '\0';

	return copy;
}

char* convertIntToChar(int number)
{
	int digitCount = 0, numberCopy = number;
	while (numberCopy)
	{
		numberCopy /= 10;
		digitCount++;
	}
	if (!digitCount)
	{
		char* text = new char[2];
		text[0] = '0';
		text[1] = '\0';
		return text;
	}

	char* text = new char[digitCount + 1];
	for (int i = digitCount - 1; i >= 0; i--)
	{
		text[i] = number % 10 + '0';
		number /= 10;
	}
	text[digitCount] = '\0';

	return text;
}
