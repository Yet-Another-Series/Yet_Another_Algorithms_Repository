#include<iostream>
using namespace std;
int euclid(int a,int b)
{
  while(a!=b)
  {
    if (a>b)
    a=a-b;
    else
    b=b-a;
  }
  return a;
}
int main()
{
  int x,y;
  cout<<"Enter two numbers";
  cin>>x>>y;
  cout<<endl;
  cout<<"GCD is "<<euclid(x,y);
  return 0;
}
