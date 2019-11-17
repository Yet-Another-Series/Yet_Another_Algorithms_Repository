#include <stdio.h>
#include <stdlib.h>
 
#define SIZE 8
 
void display(int a[],const int size);
void shellsort(int a[], const int size);
 
int main()
{
    int a[SIZE] = {5,6,3,1,7,8,2,4};
 
    printf("--- C Shell Sort Demonstration --- \n");
 
    printf("Array before sorting:\n");
    display(a,SIZE);
 
    shellsort(a,SIZE);
 
    printf("Array after sorting:\n");
    display(a,SIZE);
 
    return 0;
}
 
void shellsort(int a[], const int size)
{
  int i, j, inc, tmp;
 
  inc = 3;
  while (inc > 0)
  {
    for (i=0; i < size; i++)
    {
      j = i;
      tmp = a[i];
      while ((j >= inc) && (a[j-inc] > tmp))
      {
        a[j] = a[j - inc];
        j = j - inc;
      }
      a[j] = tmp;
    }
    if (inc/2 != 0)
      inc = inc/2;
    else if (inc == 1)
      inc = 0;
    else
      inc = 1;
  }
}
 
void display(int a[],const int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d ",a[i]);
 
    printf("\n");
}
