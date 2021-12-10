#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

void reverse(int* arr);
void swap(int& first, int &second);
int* findNum(int arr[], int toFind);
void merge(int arr[], int length1, int arr2[], int length2);
void printArr(int arr[], int length);
int* minSumArr(int arr[], int arr2[]);

int main()
{
	int arr[MAX_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//TASK 3
	//int arr2[MAX_SIZE] = { 9, 8, 7, 7, 4, 3, 1, 1, 0, 5 }; //min
	//int* minPointer = nullptr;
	//minPointer = minSumArr(arr, arr2);
	//cout << *minPointer; //9

	//TASK 2
	/*int arr2[MAX_SIZE] = { -1, 0, 5, 5, 7, 10, 11, 56};
	int length1 = 10, length2 = 8;

	merge(arr, length1, arr2, length2);*/

	//TASK 1
	/*int* found = findNum(arr, 11);
	if (!found)
	{
		cout << "Not found" << endl;
	}*/

	//TASK 0
	/*reverse(arr);

	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;*/
}

void reverse(int* arr)
{
	for (size_t i = 0; i < MAX_SIZE / 2; i++)
	{
		swap(arr[i], arr[MAX_SIZE - i - 1]);
	}
}

void swap(int& first, int& second)
{
	int x = first;
	first = second;
	second = x;
}

int* findNum(int arr[], int toFind)
{
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		if (arr[i] == toFind)
		{
			return &arr[i]; /*return arr + i;*/
		}
	}
	return nullptr;
}

void merge(int first[], int length1, int second[], int length2)
{
	int result[2 * MAX_SIZE];

	int k = 0, i = 0, j = 0;
	while (k < length1 + length2)
	{
		if (i == length1)
		{
			result[k] = second[j];
			k++;
			j++;
		}
		else if (j == length2)
		{
			result[k] = first[i];
			k++;
			i++;
		}
		else if (first[i] <= second[j])
		{
			result[k] = first[i]; //result[k++] = first[i++];
			i++;
			k++;
		}
		else if (first[i] > second[j])
		{
			result[k] = second[j];
			j++;
			k++;
		}
	}

	printArr(result, k);
}

void printArr(int arr[], int length)
{
	for (size_t i = 0; i < length - 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << arr[length - 1] << endl;
}

int* minSumArr(int first[], int second[])
{
	if (first == nullptr)
	{
		if (second == nullptr)
		{
			return nullptr;
		}
		return second;
	}
	else if(second == nullptr)
	{
		return first;
	}

	int sum1 = 0, sum2 = 0;
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		sum1 += first[i];
	}
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		sum2 += second[i];
	}

	if (sum1 <= sum2)
	{
		return first;
	}
	return second;
}
