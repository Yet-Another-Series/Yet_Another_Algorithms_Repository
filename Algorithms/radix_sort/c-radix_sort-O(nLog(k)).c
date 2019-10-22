// C-Program to Implement Radix Sort Algorithm
/*Constraints:
            1 ≤ n ≤ 10^9
            0 ≤ arr[i] ≤ 10^9

  Time Complexity = O((n+b)*Log b(k)).
                    where,
                        k is the range of the elements i.e. 1 ≤ element ≤ k,
                        b is the base for representing numbers (here b=10),
                        n is the number of inputs.*/

#include <stdio.h>
#include <stdlib.h>

//implicit declaration of functions
void Radix_Sort(int *arr,int n);
void Count_Sort(int *arr,int n,int exp);
int max_int(int *arr,int n);

//Main function to get input and implement Radix Sort
int main(void)
{
    int i,n;
    printf("Enter the number of elements(n) you want to sort: ");
    scanf("%d",&n);
    //Dynamic declaration of array
    int *arr=(int*)calloc(n,sizeof(int));
    if(n<=0)
    {
        printf("Please enter a number greater than 0\n");
        return 0;
    }
    printf("\nEnter %d positive elements -:\n\n",n);
    //Accepting n elements to be sorted
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    Radix_Sort(arr,n);
    printf("\n The sorted array is -:\n\t\t");
    //Printing Sorted array
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}

//Function to get maximum value in an array of size n
int max_in(int *arr,int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    {
        max= (max>arr[i]) ? max : arr[i];
    }
    return max;
}

//Function to implement Radix Sort
void Radix_Sort(int *arr,int n)
{
    int k,exp=1;
    k=max_in(arr,n);
    //Doing Count Sort for every digit
    while(k!=0)
    {
        k=k/10;
        Count_Sort(arr,n,exp);
        exp*=10;
    }
}

//Function to implement Count Sort
void Count_Sort(int *arr,int n,int exp)
{
    int counter[10]={0};
    //Declaring temp_arr to store elements in actual order
    int temp_arr[n];
    int i;
    //Counting number of occurrences
    for(i=0;i<n;i++)
    {
        counter[ (arr[i]/exp)%10 ]++;
    }
    //Now Counter stores actual position of each digit
    for(int j=1;j<10;j++)
    {
        counter[j]+=counter[j-1];
    }
    //Using basic concept of Count Sorting Algorithm
    for(i=n-1;i>=0;i--)
    {
        temp_arr[ counter[( arr[i]/exp)%10 ] -1 ]=arr[i];
        counter[ (arr[i]/exp)%10 ]--;
    }
    //Copying temp_arr to actual arr to update arr
    for(i=0;i<n;i++)
    {
        arr[i]=temp_arr[i];
    }
}
