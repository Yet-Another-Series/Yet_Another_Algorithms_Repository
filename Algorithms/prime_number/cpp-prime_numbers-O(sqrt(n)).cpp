// Prime numbers between 2 numbers a and b.
#include <iostream>
#include <cmath>
using namespace std;

int is_number_prime(int number)
{
	int i;
	for (i = 2; i <= sqrt(number); ++i)
	{
		if (number % i == 0)
			return 0;
	}
	return 1;
}

int prime(int start, int end)
{
	int i;
	for (i = start; i != end; ++i)
	{
		if (is_number_prime(i) == 1)
			cout << i << " ";
	}

	return i;
}

int main()
{
	// start = a, end = b
	int start, end;
	start = 2;
	end = 100;

	prime(start, end);

	return 0;
}
