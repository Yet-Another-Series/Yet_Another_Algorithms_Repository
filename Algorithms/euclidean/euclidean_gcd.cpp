#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find gcd of a and b 
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 

    return gcd(b % a, a); 
} 
  
int main() 
{ 
    int n;
    cin>>n;

    while(n--)
    {
       int a, b,c;
       cin>>a>>b>>c;
       int ans=0;
       while(b>0 && c>=2)
       {
        
         b--; 
         c-=2;
         ans+=3;
       }
       
       while(a>0 && b>=2)
       {
        
         b-=2; 
         a--;
         ans+=3;
       }


       cout<<ans<<endl;

    }

    
    return 0; 
} 