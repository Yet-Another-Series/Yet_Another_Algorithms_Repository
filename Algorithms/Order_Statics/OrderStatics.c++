#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int partition(int a[],int l,int r)
{
    int ele=a[r];
    int i=l;
    
    for(int j=l;j<=r-1;j++)
    {
        if(a[j]<=ele)
        {
           swap(&a[j],&a[i]);
           i++;
        }
    }
    swap(&a[i],&a[r]);
    
    return i;
}

int getRandomPivot(int a[],int l,int r)
{
      int n=r-l+1;
      int pivot=rand()%n;
      swap(&a[l+pivot],&a[r]);
      return partition(a,l,r);
}
int getEle(int a[],int l,int r,int k)
{
    if(k>0 && k<=r-l+1)
    {
        int pivot=getRandomPivot(a,l,r);
        
        if(k-1==pivot-l)
        return a[pivot];
        
        else if(k-1<pivot-l)  //element is  on left side
        return getEle(a,l,pivot-1,k);
        
        else 
        return getEle(a,pivot+1,r,l+k-pivot-1);
    }
    
    return INT_MAX;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cin>>k;
	    
	    int ans=getEle(a,0,n-1,k);
	    cout<<ans<<endl;
	    
	}
	return 0;
}