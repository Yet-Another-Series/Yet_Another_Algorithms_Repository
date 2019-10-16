#include<iostream>
using namespace std ;
int main()
{
int n;
cout<<"enter size of array";
cin>> n;
int a[n];
for( int i = 0 ; i < n ; i++ ){
cin>> a[i];
cout<<" ";
}

int max1 = a[0] ,max2 = a[0];

for(int i =1 ; i < n ; i++ )
{
if(max1 < a[i])
{
  max2 = max1;
  max1 = a[i];
}
else if(max2 < a[i])
{
  max2 = a[i];
}
}

cout<< "second max element "<<max2;
return 0;
}
