#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;

void fib(int);

int main()
{
	int element;
	cin >> element;
	switch (element)
	{
	case 1: cout << "Element 1 = 1"; break;
	case 2: cout << "Element 2 = 1"; break;
	default: fib(element);
		break;
	}

	return 0;
}

void fib(int element)
{
	int buff1 = 1, buff2 = 1;
	int result = 0;
	for (size_t i = 0; i < element - 2; i++)
	{
		result = buff1 + buff2;
		cout << "Element " << i + 3 << " = " << result << endl;
		buff1 = buff2;
		buff2 = result;
	}
}
