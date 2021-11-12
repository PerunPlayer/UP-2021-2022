#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int field = 3 * (n - 1) + n;
	bool flag = 1;
	if (n % 2 == 1)
	{
		flag = 0;
	}

	for (size_t row = 0; row < n; row++)
	{
		for (size_t col = 0; col < field; col++)
		{
			if (row == 0 && col >= n - 1 && (col <= 3 * n - 2) && (col % 2 == 0) && !flag ||
				row == 0 && col >= n - 1 && (col <= 3 * n - 2) && (col % 2 == 1) && flag ||
				col + row == n - 1 ||
				col + row == ((2 * n) + (n - 3)) ||
				col - row == n - 1 ||
				col - row == ((2 * n) + (n - 3)) ||
				row == n - 1 && col % 2 == 0)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
