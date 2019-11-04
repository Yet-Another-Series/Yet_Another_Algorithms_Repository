/*
 * Heap Sort
 * Worst Case O(nlogn)
 * Average Case O(nlogn)
 */
#include<stdio.h>

void Heapify(int arr[], int n, int i)
{
    int temp, largest, l, r;
    largest=i;
    l=2*i + 1;
    r=2*i + 2;
    if (l<n && arr[l]>arr[largest])
        largest=l;
    if (r<n && arr[r]>arr[largest])
        largest=r;
    if (largest!=i)
    {
        temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        Heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    int i,temp;
    for (i=n/2-1; i>=0; i--)
        Heapify(arr, n, i);
    for (i=n-1; i>=0; i--)
    {
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        Heapify(arr, i, 0);
    }
}

int main()
{
    int i,n,arr[18];
    
    /*
     * Enter By User
     */
    printf("Enter array length:");
    scanf("%d",&n);
    printf("Enter array element:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    /*
     * Print I/P Array
     */
    printf("Given array is \n");
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);

    heapsort(arr, n);

    /*
     * Print O/P Array
     */
    printf("\nSorted array is \n");
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
}
