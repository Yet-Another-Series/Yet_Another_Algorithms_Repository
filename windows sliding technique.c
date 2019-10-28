#include<stdio.h>
#include<stdlib.h>
int max_sum(int arr[],int n,int k)
{
int maxsum=0;
for(int i=0;i<n-k+1;i++)
{
  int current=0;
  for(int j=0;j<k;j++)
  {
  current=current+a[i+j];
  }
  maxsum=max(maxsum,current);
}
return maxsum
}
int max(int a,int b)
{
return (a>b)?a:b;
}
int main()
{
int a[];
int n;
int k;
printf("enter the length u want");
scanf("%d",&n);
printf("enter the numbers");
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter the count f numbersof sum u want");
scanf("%d",&k);
int cout=max_sum(arr,n,k);
printf("%d",cout);
}
