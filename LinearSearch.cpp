#include<bits/stdc++.h>
using namespace std;

int LSearch(int a[], int n, int val)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==val)
        return i;
    }
    return -1;
}

int main()
{
    int n;
    cout<<"\n Size : ";
    cin>>n;
    
    cout<<"\n Enter values in array : ";
    int a[n],i,x;
    for(i=0;i<n;i++)
    cin>>a[i];
    
    cout<<"\n Enter value to Search : ";
    cin>>x;
    
    int res=LSearch(a,n,x);
    
    (res==-1)?cout<<"\n Value not found":cout<<"\n Value found at index "<<res;
    
    return 0;
}
