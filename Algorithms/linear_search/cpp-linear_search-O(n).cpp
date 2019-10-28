#include <bits/stdc++.h>
#include <iostream.h>
using namespace std;

int linear_search(int arr[], int len,int key)
{
	for(int i=0;i<len;i++)
	{
		if(arr[i]==key)
		{
			return i+1;
		}
	}
	return -1;
}	
int main()
{
	int n,key;
	cin>>n>>key;
	int A[n];
	cout<<"Enter the elements : "<<endl;
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}
	int res=linear_search(A,n,key)
	if(res!=-1)
		cout<<"Found at position "<<res;
	else
		cout<<"Not Found"<<endl;
	return 0;
}
