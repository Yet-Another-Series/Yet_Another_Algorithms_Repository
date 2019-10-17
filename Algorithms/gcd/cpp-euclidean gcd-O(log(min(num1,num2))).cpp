#include <bits/stdc++.h> 
using namespace std; 
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b,a%b); 
} 
  
// Driver Code 
int main() 
{ 
    int a,b;
    cout <<"Enter two numbers\n";
    cin>>a>>b;
    cout << "GCD(" << a << ", "<< b << ") = " << gcd(a, b)<<endl; 
    return 0; 
}