#include <bits/stdc++.h> 

using namespace std;

int main()
{
	int l,n,t,h,flag=0,mid=0,s;
	vector<int> a;
	cin>>t; // input length of the array
	while(t--)
	{
		cin>>s;
		a.push_back(s);// storing sorted arrray in vector a
	}
	cin>>n;// input integer to find
	l=0;
	h=a.size()-1;

	while(l<h)
	{
		mid=(l+h)/2;// defining middle index
		if(a[mid]>n) {h=mid-1;}// integer greater than integer at the midddle index 
		else if(a[mid]<n) {l=mid+1;}// integer less than integer at the midddle index
		else {flag=1; break;}// index of integer found
	}
	if(flag==1)
        cout<<mid;

	return 0;
}
