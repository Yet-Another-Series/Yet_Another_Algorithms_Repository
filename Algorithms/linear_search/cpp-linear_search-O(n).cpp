#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,key;
	cin>>n>>key;
	int A[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}
	int i;
	for (i = 0; i < n; ++i)
	{
		if(A[i]==key)
			break;
	}
	if(i==n)
		cout<<"Not Found"<<endl;
	else
		cout<<"Found"<<endl;
	
}