#include<bits/stdc++.h>
using namespace std ;

int dp[1000][1000] ;

int eggprob(int e,int k)
{
    if(k==0 || k==1)    return k ;
    if(e==1)    return k ;
    if(dp[e][k]!=-1)    return dp[e][k] ;
    int res=INT_MAX ;
    for(int i=1;i<=k;i++)
    {
        int a = eggprob(e-1,i-1) ;
        int b = eggprob(e,k-i) ;
        res = min(res,1+max(a,b)) ;
    }
    return dp[e][k]=res ;
}


int main() {
	
	    int n,k ;
	    // n is the number of eggs and k is the number of floors
	    cin>>n>>k ;
	    memset(dp,-1,sizeof(dp)) ;
	    cout<<"minimum eggs needed to find critical floor are "<< ;
	    cout<<eggprob(n,k)<<endl ;
	    
	return 0;
}
