#include <bits/stdc++.h>

using namespace std;

int main()
{
	int l,n,t,h,flag=0,mid=0,s;
	vector<int> a;
	cin>>t;
	while(t--)
	{
		cin>>s;
		a.push_back(s);
	}
	cin>>n;
	l=0;
	h=a.size()-1;

	while(l<h)
	{
		mid=(l+h)/2;
		if(a[mid]>n) {h=mid-1;}		//If element is smaller than a[mid] then it mush be present at left of mid 
		else if(a[mid]<n) {l=mid+1;}	//If element is greater than a[mid] then it must be present at right of mid
		else {flag=1; break;}		//If element is found at mid
	}
	if(flag==1)
        cout<<mid;

	return 0;
}
