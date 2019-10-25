#include <stdio.h>

void heap(int [], int, int); // turns data into a heap
void sort(int [], int); // sorts data by heap
void print(int [], int); // prints everything
void swap(int [], int, int); // switches two integers given the array index

int main() {
    int array[] = {74, 23, 57, 86, 40, 33, 17, 69};
    int n = sizeof(array) / sizeof(array[0]);


    sort(array, n);

    printf("Sorted array\n",
            "------------");
    print(array, n);

    return 0;
}

/***
 * Swaps two integers
 * @param array list of integers where swapping is taking place
 * @param i1 index of first integer to be swapped
 * @param i2 index of second integer to be swapped
 */
void swap(int array[], int i1, int i2)
{
    int temp = array[i1];
    array[i1] = array[i2];
    array[i2] = temp;
}

/***
 * Turns the data into a heap
 * @param array the list of data being heaped
 * @param n the number of items in the array
 * @param i the largest integer
 */
void heap(int array[], int n, int i) {
    int largest = i,
            l = 2 * i + 1,
            r = 2 * i + 2;

    if ((l < n) && (array[l] > array[largest]))
        largest = l;

    if ((r < n) && (array[r] > array[largest]))
        largest = r;

    if (largest != i){
        swap(array, i , largest);
        heap(array, n, largest);
    }
}

/***
 * Performs the heap sort on the array
 * @param array the list of integers being sorted
 * @param n the number of integers in the array
 */
void sort(int array[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(array, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(array, 0, i);

        heap(array, i , 0);
    }
}

/***
 * Prints the array
 * @param array the list of integers being printed
 * @param n the number of indices
 */
void print(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);

    printf("\n\n");
}