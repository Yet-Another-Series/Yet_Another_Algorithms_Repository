/*Fibonacci series using dynamic programming
    Time complexity- O(n)
    Space complexity- O(n)*/

#include<iostream>
using namespace std;

int fib(int n)
{   //Declaring an array to store fibonacci numbers
    int f[n+2];
    f[0]=0;
    f[1]=1;
    for(int i=2;i<=n;i++)
        f[i]=f[i-1]+f[i-2];
    return f[n];
}

int main()
{   int n;
    cout<<"Enter the number of terms in the series : ";
    cin>>n;
    cout<<"The series is : ";
    for(int i=0;i<n;i++)
       cout<<fib(i)<<" ";
    return 0;
}
