#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int> &arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		int indexOfMin = i;
		for (int j = i + 1; j < arr.size(); ++j)
			if (arr[j] < arr[indexOfMin])
				indexOfMin = j;
		swap(arr[i], arr[indexOfMin]);
	}
}

int main()
{
	vector<int> arr {23, -3, 3, 144, 0, 32, -243, 3};
	selection_sort(arr);
	for (auto &e : arr)
		cout << e << ' ';
	cout << '\n';

	return 0;
}
