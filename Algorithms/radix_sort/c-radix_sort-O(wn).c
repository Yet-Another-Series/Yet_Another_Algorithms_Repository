#include <stdio.h>

// This macro defines the maximum array size (in element count).
#define MAX_LENGTH      123456

// This macro defines element data type.
#define ELEMENT         unsigned long long int

// This macro defines element bit (binary digit) count.
#define ELEMENT_DIGITS  64

ELEMENT arr[MAX_LENGTH];
ELEMENT arr_aux[MAX_LENGTH];

void swap(ELEMENT **a, ELEMENT **b) {
    ELEMENT *tmp = *a;
    *a = *b;
    *b = tmp;
}

ELEMENT* radixSort(ELEMENT *A, ELEMENT *B, ELEMENT N) {
    ELEMENT mask = 1;

    // Iterate from the least significant bit to the most significant bit.
    // Update the bit mask as we go.
    for (int digit = 0; digit < ELEMENT_DIGITS; ++digit, mask <<= 1) {
        // In each cycle, we copy array from A to B.
        // Keep track of the next free-to-insert position.
        ELEMENT *next_free = B;

        // Scan source array two times: first for 0, then for 1.
        // Move items with the matching digits into their corresponding bucket.
        for (ELEMENT i = 0; i < N; ++i) {
            if ((A[i] & mask) == 0) {
                *next_free++ = A[i];
            }
        }

        for (ELEMENT i = 0; i < N; ++i) {
            if ((A[i] & mask) > 0) {
                *next_free++ = A[i];
            }
        }

        // At this point, the target array becomes the new source array.
        swap(&A, &B);
    }

    // Return whichever of the two arrays becomes source at the end.
    return A;
}

int main() {
    // Read array size.
    ELEMENT N;
    int f = 0;
    printf("Enter number of elements of array : ");
    f = scanf("%llu", &N);
    if (!f)
        return 1; // I/O error.
    if (N > MAX_LENGTH)
        return 2; // Entered size is too large and will not fit in RAM.

    // Read array contents.
    printf("\nEnter elements of array : ");
    for (ELEMENT i = 0; i < N; ++i) {
        f = scanf("%llu", &arr[i]);
        if (!f)
            return 3; // I/O error.
    }

    // Sort the array.
    const ELEMENT* arr_out = radixSort(arr, arr_aux, N);

    // Print the sorted array.
    printf("\nSorted array : ");
    for (ELEMENT i = 0; i < N; ++i) {
        printf("%llu ", arr_out[i]);
    }
    printf("\n");

    return 0;
}

