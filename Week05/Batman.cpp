#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
    int size = 0;
    cin >> size;
    char c = '#';

    int field = 3 * size + 1;
    char space = ' ';
    int mid = size / 2;

    for (int row = 0; row < ((size - 1) + size/2); row++)
    {
        for (int col = 0; col < field; col++)
        {
            if (row == 0 && col <= size - 1 ||                                                                  //top left wing
                row == 0 && col >= 2 * size && col < field - 1 ||                                               //top right wing
                row - col <= 0 && row <= mid && col <= size - 1 ||                                              //rest of left wing
                row + col <= field - 2 && row <= mid && col >= 2 * size ||                                      //rest of right wing
                row == mid - 1 && col == size + (mid - 1) ||                                                    //left ear
                row == mid - 1 && col == size + mid + 1 ||                                                      //right ear
                row >= mid && row <= mid + mid - 2 && size / 2 <= col && col <= field - mid - 2 ||              //body
                row >= 2 * mid - 1 && row < 3 * mid - 1 && col - row >= 3 && col + row <= 2 * size + (size - 4))//tail
            {
                cout << c;
            }
            else
            {
                cout << space;
            }
        }
        cout << endl;
    }
	return 0;
}
