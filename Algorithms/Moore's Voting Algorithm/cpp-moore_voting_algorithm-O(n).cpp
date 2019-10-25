/*
The code below finds the majority element which in this case,
is the element that occurs > N/3 times, where N is the total
number of elements in the vector
*/

#include <bits/stdc++.h>
using namespace std;

int repeatedNumber(const vector<int> &A) {

    int maj_1 = INT_MAX;
    int maj_2 = INT_MAX;
    int count_1 = 0;
    int count_2 = 0;
    for ( int i = 1; i < A.size(); i++ )
    {
        if ( A[i] == maj_1 )
            count_1++;
        else if ( A[i] == maj_2 )
            count_2++;
        else if ( count_1 == 0 )
        {
            count_1 = 1;
            maj_1 = A[i];
        }
        else if ( count_2 == 0 )
        {
            count_2 = 1;
            maj_2 = A[i];
        }
        else
        {
            count_1--;
            count_2--;
        }
    }
    int req = A.size() / 3;
    count_1 = 0;
    for ( int i = 0; i < A.size(); i++ )
    {
        if ( maj_1 == A[i] )
            count_1++;
    }
    count_2 = 0;
    for ( int i = 0; i < A.size(); i++ )
    {
        if ( maj_2 == A[i] )
            count_2++;
    }
    
    if ( count_1 > req )
        return maj_1;
    if ( count_2 > req )
        return maj_2;
    return -1;
}

int main(){
	int n; //number of elements in the vector
	cin >> n;
	vector<int> A(n);
	for ( int i = 0; i < n; i++ )
		cin >> A[i];
	int result = repeatedNumber(A);
	cout << result;
}
