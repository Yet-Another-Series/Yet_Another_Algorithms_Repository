#include<bits/stdc++.h>
using namespace std;

int LSearch(int a[],int s,int x)
{
  for(int i=0;i<s;i++)
  {
    if(a[i]==x)
    return i;
  }
  
  return -1;
}

int main()
{
  int n,k;
  cout<<"\n Enter size : ";
  cin>>n;
  int a[n];
  cout<<"\n Enter elements in array : ";
  for(int i=0;i<n;i++)
  cin>>a[i];
  
  cout<<"\n Enter element to search for : ";
  cin>>k;
  
  int res=LSearch(a,n,k);
  
  (res==-1)?cout<<"\n Element not found":cout<<"\n Elemet found at index "<<res;
  
  return 0;
}
