#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

void insertion_sort(int* arr)
{
	int i, j, key;
	for (i = 1; i < MAX_SIZE; ++i) {
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; --j)
			arr[j + 1] = arr[j];

		arr[j + 1] = key;
	}
}

int main()
{
	int arr[MAX_SIZE] = {7, 2, 1, 10, 9, 4, 5, 3, 6, 8};

	insertion_sort(arr);

	for (int i = 0; i < MAX_SIZE; ++i)
		cout << arr[i] << endl;
}
