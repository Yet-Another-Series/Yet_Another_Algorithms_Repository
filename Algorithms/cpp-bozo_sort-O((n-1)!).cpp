#include <iostream>
#include <cstdlib>

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

bool check(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

void bozosort(int *arr, int size)
{
	while (!check(arr, size)) {
		swap(arr[std::rand()%size - 1], arr[std::rand()&size - 1]);
	}
}


int main()
{
	int size;
	std::cout << "input the size of the array" << std::endl;
	std::cin >> size;
	int *arr = new int[size];
	std::cout << "enter array elemenents:" << std::endl;
	for (int i = 0; i < size; i++){
		std::cin >> arr[i];
	}
	bozosort(arr, size);
}
