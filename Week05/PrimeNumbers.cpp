#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
//По въведено цяло число проверете дали то е просто.
//Изкарайте на стандартния изход подходящо съобщение.

  int p = 0, q = 0;
	cout << "Enter p: ";
	cin >> p;
	cout << "Enter q: ";
	cin >> q;

	cout << "Prime numbers between p & q: ";
	if(p > q) //swap
	{
		q ^= p;
		p ^= q;
		q ^= p;
	}

	bool flag = 1;
	for ( ; p < q; p++)
	{
		flag = 1;
		if (p <= 1)
		{
			continue;
		}
		for (size_t i = 2; i <= (p / 2); i++)
		{
			if (p % i == 0)
			{
				//cout << "N is not prime\n";
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			cout << p << ", ";
		}
	}

  return 0;
}
