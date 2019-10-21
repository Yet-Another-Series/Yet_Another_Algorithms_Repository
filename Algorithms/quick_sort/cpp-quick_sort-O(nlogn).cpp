/* Quick Sort: Merge and sort algorithm
                Worst case O(n^2)
                Average Case O(nlogn)
*/
#include<iostream>
using namespace std;

void swap(int *a,int *b)
{   int t=*a;
    *a=*b;
    *b=t;
}
//Function to divide the array with starting index 'l' and end index 'h' into two subarrays in accordance with the pivot
int partition(int arr[],int l,int h)
{   int pivot=arr[h];
    int pIn=l;
    for(int i=l;i<h;i++)
    {   if(arr[i]<pivot)
        {   swap(&arr[i],&arr[pIn]);
            pIn++;
        }
    }
    swap(&arr[pIn],&arr[h]);
    return pIn;
}
//recursive fnction for sorting algorithm
void quick_sort(int arr[],int l,int h)
{   if(l<h)
    {   int pIndex=partition(arr,l,h);
        quick_sort(arr,l,pIndex-1);
        quick_sort(arr,pIndex+1,h);
    }
}
//Function to print the array
void print_array(int arr[],int len)
{   for(int i=0;i<len;i++)
        cout<<arr[i]<<" ";
}

int main()
{   int n;
    cout<<"Enter array length : ";
    cin>>n;
    int a[n+1];
    cout<<"Enter array element :";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Given array is: ";
    print_array(a,n);
    cout<<endl;
    quick_sort(a,0,n-1);
    cout<<"Sorted array is : ";
    print_array(a,n);
    return 0;
}
