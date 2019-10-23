#include <stdio.h>

// This macro defines the maximum array size (in element count).
#define MAX_LENGTH          123456

// This macro defines the maximum gap sequence length (in element count).
#define MAX_GAPS_LENGTH     123

// This macro defines element data type.
#define ELEMENT             unsigned long long int

ELEMENT arr[MAX_LENGTH];
ELEMENT arr_gaps[MAX_GAPS_LENGTH];

ELEMENT gap_sequence(ELEMENT *dest, ELEMENT dest_size, ELEMENT n) {
    // For demonstration purposes, the following gap sequence is hard-coded:
    //
    //   4^k + 3 * 2^(k-1) + 1, prefixed with 1
    //
    // Credit: Sedgewick, 1982
    // Worst-case complexity: O(n^(4/3))

    ELEMENT k = 0;
    if (n > k) {
        dest[k] = 1;
    }

    for (k = 1; k < dest_size; ++k) {
        // Use exponentiation trick: 4^k = (2^2)^k = 2^(2k) = 1 << (2k)
        dest[k] = (1 << (2 * k))
            + 3 * (1 << (k - 1))
            + 1;

        if (dest[k] >= n) {
            break;
        }
    }

    // Return size of produced array.
    return k;
}

void gappedInsertSort(ELEMENT *A, ELEMENT gap, ELEMENT N) {
    ELEMENT i, j, temp;

    // The first gap elements A[0..(gap-1)] are already in gapped order.
    // Keep adding one more element until the whole array is sorted.
    for (i = gap; i < N; ++i) {
        // Save A[i] and make a hole at the position i.
        temp = A[i];

        // Shift earlier gap-sorted elements up until the correct location for
        // A[i] is found.
        for (j = i; j >= gap && A[j - gap] > temp; j -= gap) {
            A[j] = A[j - gap];
        }

        // Put temp (the original A[i]) in its correct location.
        A[j] = temp;
    }
}

void shellSort(ELEMENT *A, ELEMENT N, ELEMENT* gaps) {
    if (N == 0) {
        // Trivial case.
        return;
    }

    // Manufacture a gap sequence of elements strictly lower than N.
    ELEMENT n_gaps = gap_sequence(gaps, MAX_GAPS_LENGTH, N);

    // Enumerate the gap sequence in reverse (largest to smallest element).
    for (ELEMENT gap_idx = 0; gap_idx < n_gaps; ++gap_idx) {
        const ELEMENT gap = gaps[n_gaps - gap_idx - 1];

        // For each gap, perform an insert sort.
        gappedInsertSort(A, gap, N);
    }
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
    shellSort(arr, N, arr_gaps);

    // Print the sorted array.
    printf("\nSorted array : ");
    for (ELEMENT i = 0; i < N; ++i) {
        printf("%llu ", arr[i]);
    }
    printf("\n");

    return 0;
}

