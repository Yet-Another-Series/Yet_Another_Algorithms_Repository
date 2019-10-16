#include<bits/stdc++.h>
using namespace std;

int lis(int arr[], int n) {

		if(n==1)
            return 1;
     int dp[n];
     
     dp[0]=1;
     // dp[i] value tells the longest increasing subsequence ending at value of index i
     
     for(int i=1;i<n;i++)
     {
         dp[i]=1;
         for(int j=0;j<i;j++)
         {
             if(arr[j]<arr[i])
             {
                 dp[i]=max(dp[i],1+dp[j]);
             }
         }
     }
     
    int res=0; //res is the length of longest increasing subsequence
    
	for(int i=0;i<n;i++)
    {
        res=max(res,dp[i]);
    }
    
    return res;
}

int main()
{
	int n ;
	cin>>n ;  // number of array elements 
	int arr[n] ;
	for(int i=0; i<n ; i++)		cin>>arr[i] ;
	
	int res = lis(arr,n) ;
	cout<<"longest increasing subsequence is of length "<<res<<endl ;
	return 0 ;
}
 
