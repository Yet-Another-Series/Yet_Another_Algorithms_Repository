#include <stdio.h>
#define MAX 100005

long long int arr[MAX];

int bubbleSort(long long int A[], long long int N) {
    int flag = 1;
    for(long long int i = 0 ; i < N ; i++) {
        if(A[i] > A[i + 1]) {
            flag = 0;
            long long int temp;
            temp = A[i];
            A[i] = A[i + 1];
            A[i + 1] = temp;
        }
    }
    return flag;
}

int main() {
    long long int N;
    int f = 0;
    printf("\nEnter number of elements of array : ");
    f = scanf("%lld", &N);
    if(!f)
        return -1;
    printf("\nEnter elements of array : ");
    for(long long int i = 0 ; i < N ; i++) {
        f = scanf("%lld", &arr[i]);
        if(!f)
            return -1;
    }
    int sorted = 0;
    while(!sorted) {
        sorted = bubbleSort(arr, N - 1);
    }
    printf("\nSorted array : ");
    for(long long int i = 0 ; i < N ; i++) {
        printf("%lld ", arr[i]);
    }
    return 0;
}
