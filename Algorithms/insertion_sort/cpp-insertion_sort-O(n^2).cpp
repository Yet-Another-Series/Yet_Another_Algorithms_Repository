/* Insertion Sort 
    Time complexity- O(n^2)
    Auxillary space- O(1)*/
#include<iostream>
using namespace std;

void insertion_sort(int arr[],int n)
{   int i,j,key;
    for(i=0;i<n;i++)
    {   key=arr[i];
        j=i-1;
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while(j>=0 && arr[j]>key)
        {   arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void printArray(int arr[],int n)
{   for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{   int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of array : ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"The array is : ";
    printArray(a,n);
    insertion_sort(a,n);
    cout<<"\nThe sorted array is : ";
    printArray(a,n);
    return 0;
}
