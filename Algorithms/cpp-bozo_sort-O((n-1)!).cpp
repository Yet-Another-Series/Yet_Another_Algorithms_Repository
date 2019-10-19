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
	int *p = arr;
	for (int i = 0; i < size - 1; i++)
	{
		if (p[i] > p[i + 1]) {
			return false;
		}
	}
	return true;
}

void bozosort(int *arr, int size)
{
	while (!check(arr, size)) {
		swap(arr[std::rand()%size], arr[std::rand()%size]);
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
	return 0;
}
