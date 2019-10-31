#include <iostream> 
using namespace std; 
void sentinelSearch(int arr[], int n, int x) 
{ 
  
    int last = arr[n - 1]; 
  
    
    arr[n - 1] = x; 
    int i = 0; 
  
    while (arr[i] != x) 
        i++; 
  
   
    arr[n - 1] = last; 
  
    if ((i < n - 1) || (x == arr[n - 1])) 
        cout << x << " is present at index " << i; 
    else
        cout << "Not found"; 
} 
  
// main function
int main() 
{ 
    int arr[] = { 10, 20, 75, 30, 60, 50, 110, 100, 70 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 75; 
  
    sentinelSearch(arr, n, x); 
  
    return 0; 
} 