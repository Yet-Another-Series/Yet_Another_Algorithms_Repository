void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
} */
// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i=l;
    int j=m+1;
    int newarr[r-l+1];
    int k=0;
    while(i<=m && j<=r)
    {
        if(arr[i]<arr[j])
        {
          newarr[k++]=arr[i++];
        }
        else
        newarr[k++]=arr[j++];
    }
    while(i<=m)
    {
        newarr[k++]=arr[i++];
    }
    while(j<=r)
    {
        newarr[k++]=arr[j++];
    }
    for(int i=l,j=0;i<=r; i++,j++)
    {
        arr[i]=newarr[j];
    }
}
