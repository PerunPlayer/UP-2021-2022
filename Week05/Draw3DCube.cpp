#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
//3d cube
	int N = 0;
	cin >> N;
	int field = N * 2 - 1;
	int mid = N - 1;

	for (size_t row = 0; row <= field; row++)
	{
		for (size_t col = 0; col <= field; col++)
		{
			if (row == 0 && col <= mid ||
				row == N - 1 && col <= mid ||
				row == (field - 1) && col >= mid && col <= (field - 1) ||
				row <= mid && col == 0 ||
				row <= mid && col == mid ||
				col - row == mid && col <= (field - 1) ||
				row > mid && row <= (field - 1) && col == (field - 1) ||
				(row - col == mid) && row <= (field - 1)  ||
				col - row == 0 && col > mid && col <= (field - 1))
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
