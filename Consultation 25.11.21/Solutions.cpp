#include "stdafx.h"
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

//Task 1
void checkEGN();
//Task 2
void printNumbers();
//Task 3
void findBigger();
//Task 4
void findSubstring();
//Task 5
void checkAmicablePairs();

int main()
{
  //checkEGN();
  //printNumbers();
  //findBigger();
  //findSubstring();
  //checkAmicablePairs();

	return 0;
}


//Task 1
void checkEGN()
{
  long long egn = 0;
	cin >> egn;

	short year, month, date, count = 0;
	long long copyOfEGN = egn;
	while (copyOfEGN)
	{
		copyOfEGN /= 10;
		count++;
	}

	if (count < 7)
	{
		cout << "Error";
		return 0;
	}

	if (((count == 8) || (count == 7)) && (egn / 10000000) < 3)
	{
		year = 1900;
		month = (egn / 1000000) % 100;
	}
	else if ((count == 8) && (egn / 10000000) >= 3)
	{
		year = 2000;
		month = ((egn / 1000000) % 100) - 40;
	}
	else if (count == 9)
	{
		year = 2000 + (egn / 100000000);
		month = ((egn / 1000000) % 100) - 40;
	}
	else
	{
		year = 1900 + (egn / 100000000);
		month = (egn / 1000000) % 100;
	}

	date = (egn / 10000) % 100;
	cout << "Date of birth: " << date << "." << month << "." << year << endl;
	if (((egn % 100) / 10) % 2 == 0)
	{
		cout << "Sex: male" << endl;
	}
	else
	{
		cout << "Sex: female" << endl;
	}
}

//Task 2
void printNumbers()
{
  unsigned short a = 0, b = 0;
	cin >> a >> b;

	for (size_t i = a; i < b; i++)
	{
		if (i < 10)
		{
			switch (i)
			{
			case 1: cout << "I, "; break;
			case 2: cout << "II, "; break;
			case 3: cout << "III, "; break;
			case 4: cout << "IV, "; break;
			case 5: cout << "V, "; break;
			case 6: cout << "VI, "; break;
			case 7: cout << "VII, "; break;
			case 8: cout << "VIII, "; break;
			case 9: cout << "IX, "; break;
			default: break;
			}
		}
		else
		{
			cout << i * i << ", ";
		}

	}
	cout << b * b << endl;
}

//Task 3
void findBigger()
{
  int arr[MAX_SIZE] = { 0 };
	int length = 0;

	cin >> length;
	for (size_t i = 0; i < length; i++)
	{
		cin >> arr[i];
	}

	for (size_t i = 0; i < length; i++)
	{
		int bigger = -1;

		for (int j = i; j >= 0; j--)
		{
			if (arr[i] < arr[j])
			{
				bigger = arr[j];
				break;
			}
		}
		cout << arr[i] << " -> " << bigger << ", ";
	}
}

//Task 4
void findSubstring()
{
  char wholeStr[MAX_SIZE];
	char part[MAX_SIZE];

	cin >> wholeStr;
	cin >> part;

	int counter = 0;
	for (size_t i = 0; part[i] != '\0'; i++)
	{
		counter++;
	}

	bool isFound = true;
	int foundCount = 0;
	for (size_t i = 0; wholeStr[i] != '\0'; i++)
	{
		for (size_t j = 0; j < counter; j++)
		{
			if (wholeStr[i + j] != part[j])
			{
				isFound = false;
			}
		}
		if (isFound)
		{
			foundCount++;
		}
		isFound = true;
	}

	cout << "Second word is found " << foundCount << " times in the first." << endl;
}

//Task 5
void checkAmicablePairs()
{
  int number = 0;
	cin >> number;

	int arr[MAX_SIZE] = { 0 };
	for (size_t i = 0; i < number * 2; i++)
	{
		cin >> arr[i];
	}

	for (size_t i = 0; i < number * 2; i += 2)
	{
		int sum = 0;
		for (size_t j = 1; j <= arr[i] / 2; j++)
		{
			if ((arr[i] % j) == 0)
			{
				sum += j;
			}
		}
		if (sum == arr[i + 1])
		{
			sum = 0;
			for (size_t j = 1; j <= arr[i + 1] / 2; j++)
			{
				if ((arr[i + 1] % j) == 0)
				{
					sum += j;
				}
			}
			if (sum = arr[i])
			{
				cout << "Are Amicable pairs" << endl;
			}
			else
			{
				cout << "Are NOT Amicable pairs" << endl;
			}
		}
		else
		{
			cout << "Are NOT Amicable pairs" << endl;
		}
	}
}
