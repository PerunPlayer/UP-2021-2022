#include "stdafx.h"
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

int moveHero(int princess, int hero, char castle[]);

int main()
{
	int rooms = 0;
	cin >> rooms;

	char castle[MAX_SIZE];
	cin >> castle;

	int cleopatra = -1, arthur = -1, dagonet = -1;
	for (size_t i = 0; i < rooms; i++)
	{
		if (castle[i] == 'C')
		{
			cleopatra = i;
		}
		else if(castle[i] == 'A')
		{
			arthur = i;
		}
		else if (castle[i] == 'D')
		{
			dagonet = i;
		}
	}

	if (dagonet == -1 || arthur == -1 || cleopatra == -1)
	{
		cout << "Wrong castle!" << endl;
		return 0;
	}

	int dagonetPoints = 0, arthurPoints = 0;
	if (abs(cleopatra - arthur) < abs(cleopatra - dagonet))
	{
		arthurPoints = moveHero(cleopatra, arthur, castle);
		if (arthurPoints == -1)
		{
			cout << "Dagonet wins Cleopatra's heart because Arthur was eaten by the dragon Valyrian." << endl;
			return 0;
		}
		dagonetPoints = moveHero(cleopatra, dagonet, castle);
		if (dagonetPoints == -1)
		{
			cout << "Arthur wins Cleopatra's heart because Dagonet was eaten by the dragon Valyrian." << endl;
			return 0;
		}
	}
	else
	{
		dagonetPoints = moveHero(cleopatra, dagonet, castle);
		if (dagonetPoints == -1)
		{
			cout << "Arthur wins Cleopatra's heart because Dagonet was eaten by the dragon Valyrian." << endl;
			return 0;
		}
		arthurPoints = moveHero(cleopatra, arthur, castle);
		if (arthurPoints == -1)
		{
			cout << "Dagonet wins Cleopatra's heart because Arthur was eaten by the dragon Valyrian." << endl;
			return 0;
		}
	}

	if (arthurPoints > dagonetPoints)
	{
		cout << "Arthur wins Cleopatra's heart with " << arthurPoints << " points." << endl;
	}
	else if (dagonetPoints > arthurPoints)
	{
		cout << "Dagonet wins Cleopatra's heart with " << dagonetPoints << " points." << endl;
	}
	else if (dagonetPoints == arthurPoints)
	{
		cout << "The castle is big enough for the three of them and so they all lived happily ever after!" << endl;
	}

	return 0;
}

int moveHero(int princess, int hero, char castle[])
{
	int points = 0;
	int rooms = abs(princess - hero);
	if (princess < hero)
	{
		for (size_t i = hero; i > princess; i--)
		{
			switch (castle[i])
			{
			case 'V': points = -1; return points;
			case '~': points += 18; break;
			case '%': points += 24; break;
			case '#': points += 35; break;
			default: break;
			}
			castle[i] = '.';
		}
	}
	else
	{
		for (size_t i = hero; i < princess; i++)
		{
			switch (castle[i])
			{
			case 'V': points = -1; return points;
			case '~': points += 18; break;
			case '%': points += 24; break;
			case '#': points += 35; break;
			default: break;
			}
			castle[i] = '.';
		}
	}

	return points;
}
