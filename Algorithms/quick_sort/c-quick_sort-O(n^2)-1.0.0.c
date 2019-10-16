/*
 * Quick Sort
 * Worst Case O(n^2)
 * Average Case O(nlogn)
 */
#include<stdio.h>

int partition(int arr[], int p, int r)
{
    int pivot,temp,j,i;
    pivot=arr[r];
    j=p-1;
    for(i=p;i<=r-1;i++)
    {
        if(arr[i]<=pivot)
        {
            j++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[j+1];
    arr[j+1]=arr[r];
    arr[r]=temp;
    return (j+1);
}

void quicksort(int arr[],int p, int r)
{
    int q;
    if(p<r)
    {
        q=partition(arr, p, r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
    }
}

int main()
{
    int arr[18],i,n;

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

    quicksort(arr,0,n-1);

    /*
     * Print O/P Array
     */
    printf("\nSorted array is \n");
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
}
