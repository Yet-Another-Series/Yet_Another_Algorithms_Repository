/* C++ program to print largest contiguous array sum 
Time complexity- O(n) */
#include<iostream> 
#include<climits> 
using namespace std; 

int maxSubArraySum(int a[], int size) 
{ 
	int max_so_far = INT_MIN, max_ending_here = 0; 

	for (int i = 0; i < size; i++) 
	{ 
		max_ending_here = max_ending_here + a[i]; 
		if (max_so_far < max_ending_here) 
			max_so_far = max_ending_here; 

		if (max_ending_here < 0) 
			max_ending_here = 0; 
	} 
	return max_so_far; 
} 

int main() 
{ 
	int n;
	cout<<"Enter the size of array: ";
	cin>>n;
	int a[n];
	cout<<"Enter the array: ";
	for(int i=0;i<n;i++)
	    cin>>a[i];
	cout<<"The entered array are : ";
	for(int i=0;i<n;i++)
	    cout<<a[i]<<" ";
	int max_sum = maxSubArraySum(a, n); 
	cout << "\nMaximum contiguous sum is " << max_sum; 
	return 0; 
} 
