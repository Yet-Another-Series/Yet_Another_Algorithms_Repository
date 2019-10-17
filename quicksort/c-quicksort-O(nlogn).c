#include<stdio.h> 

/*
    Utility function to swap 2 elements.

    Parameters:
    int *a  : Pointer to the first element
    int *b  : Pointer to the second element
*/

void swap(int* a, int* b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 


/*  Considers the last element to be the pivot, and sorts the array
    placing all elements smaller than the pivot on the right of the pivot
    and placing all elements greater than the pivot on the right of the pivot.

    Parameters:
    int arr[]   : Array Input
    int low     : Lower Index to start from
    int high    : Higher Index to end at

    Return Value:
    Index of the pivot element
*/

int partition (int arr[], int low, int high) { 
    // Set pivot to be the last element
    int pivot = arr[high];

    // Get Index of the smallest element
    int i = (low - 1); 
  
    for (int j = low; j <= high- 1; j++) {

        // If current element is smaller than the pivot 
        if (arr[j] < pivot) {
            // Incremenet index of the smaller element 
            i++; 
            swap(&arr[i], &arr[j]); 
        }
    }
    // Last swap to place the pivot element in the correct (sorted) position
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

  
/*  Main Quicksort function to sort the array; recursively elements 
    to the left and right of the Partitioning Index (Pivot)

    Parameters:
    int arr[]   : Array Input
    int low     : Lower Index to start from
    int high    : Higher Index to end at
*/

void quickSort(int arr[], int low, int high) { 
    if (low < high) {
        // pi = Partitioning Index (Pivot)
        // arr[pi] is in the correct (sorted) position
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before the Partitioning Index
        quickSort(arr, low, pi - 1); 
        // Separately sort elements after the Partitioning Index
        quickSort(arr, pi + 1, high); 
    } 
} 
  
/* Utility function to print an array */
void printArray(int arr[], int size)  {
    for (int i=0; i < size; i++) { 
        printf("%d ", arr[i]); 
    }
    printf("\n"); 
} 
  
/* Driver Program */
int main() {
    int arr[] = {41, 93, 27, 4, 10, 15, 33, 50}; 

    // int n = Size of the array
    int n = sizeof(arr)/sizeof(arr[0]); 

    printf("Array before Sorting:\n"); 
    printArray(arr, n);

    quickSort(arr, 0, n-1); 

    printf("\nArray after sorting using Quicksort:\n"); 
    printArray(arr, n); 
    
    return 0; 
} 
