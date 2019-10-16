#include <stdio.h>
#define MAX 100005

long long int arr[MAX];

long long int binarySearch(long long int A[], long long int N, long long int ele) {
    long long int beg, mid, end, flag = -1;
    beg = 0;
    end = N - 1;
    while(beg <= end) {
        mid = (beg + end) / 2;
        if(A[mid] == ele) {
            flag = mid;
            break;
        } else if(A[mid] < ele) {
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return flag;
}

int main() {
    long long int N, S;
    printf("\nEnter number of elements of array: ");
    scanf("%lld", &N);
    printf("\nEnter elements of array: ");
    for(long long int i = 0 ; i < N ; i++) {
        scanf("%lld", &arr[i]);
    }
    printf("\nEnter number of searches: ");
    scanf("%lld", &S);
    while(S) {
        long long int T;
        printf("\nEnter element to search for: ");
        scanf("%lld", &T);
        long long int f = -1;
        f = binarySearch(arr, N, T);
        if(f == -1) {
            printf("%lld not found!", T);
        } else {
            printf("%lld found at index %lld", T, f);
        }
        S--;
    }
    return 0;
}
