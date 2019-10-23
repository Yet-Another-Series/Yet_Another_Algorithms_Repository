//Fibonacci Series using Recursion 
#include<bits/stdc++.h> 
using namespace std; 
  
int fib(int n) 
{ 
    if (n <= 1) 
        return n; 
    return fib(n-1) + fib(n-2); 
} 
  
int main () 
{ 
    int n;
    cout << "Enter the index of fibonacci series term you want to calculate: " ;
    cin >> n;
    cout << "nth term of fibonacci series is: "
    cout << fib(n); 
    getchar(); 
    return 0; 
} 
