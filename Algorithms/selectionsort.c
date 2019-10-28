#include <stdio.h>
#include <stdlib.h>

void swap(int *m int *n)
{
  int t = *m;
  *m = *n;
  *n = t;
}

void sort(int a[],int n)
{
  int i,pos,j;
  for(i=0;i<n-1;i++)
  {
    pos = i;
    for(j=i+1;j<n;j++)
    {
      if(a[pos]>a[j]) pos=j;
    }
    if(pos!=i)
    {
      swap(&a[pos],&a[i]);
    }
  }
}

void disp(int a[],int n)
{
  for(int i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
}

int main(){
  int a[7] = {1,21,3,12,79,34,11};
  int n = sizeof(a)/sizeof(int);
  prinf("Enter num of elements");
  sort(a,n);
  disp(a,n);
}
