#include <stdio.h>

int linearSearch(int arr[], int n, int value)
{
	for (int i = 0; i < n; ++i)
		if (arr[i] == value)
			return 1;
	return 0;
}

int main()
{
	int arr[] = {3, -12, 29432, 0, 42, 9, -23, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	int value;
	scanf("%d", &value);
	if (linearSearch(arr, n, value))
		printf("%d is present in the array.\n", value);
	else
		printf("%d isn't present in the array.\n", value);

	return 0;
}
