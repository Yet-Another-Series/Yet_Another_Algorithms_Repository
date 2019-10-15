#include <stdio.h>
/***
Array should be sorted
***/


int binary_search(int *arr, int from, int to, int key)
{
  if(from > to)
  {
    return -1;
  }
  int mid = (from + to) / 2;
  if(arr[mid] == key)
  {
    return mid;
   }
   if(arr[mid] > key)
    return binary_search(arr, from, mid, key);
   else if(arr[mid] < key)
    return binary_search(arr, mide + 1, to, key);
}

