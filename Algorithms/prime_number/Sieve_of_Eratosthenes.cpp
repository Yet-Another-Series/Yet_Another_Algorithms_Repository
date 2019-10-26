#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 10;
    int sum = 0;
    int A[n + 1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Initialize/Mark all values of the array as the indexes
    /*Starting from the first prime number '2' we mark(put 0) 
    in the array value on those numbers
    that are multiples of the prime number and >= to the square of it*/
    for(int i = 2; i * i <= n; i++)
    {
        if(A[i] != 0)
        {
            for(int j = i * i; j <= n; j = j + i)
            {
                A[j] = 0;
            }
        }
    }//Pick the next unmarked number from the array
    cout << "Prime numbers till number 10 are: " << endl;
    for(int k = 2; k <= n; k++ )
    {
        if(A[k] != 0)
        {
            cout << A[k] << " ";
        }
    }

    return 0;
}
