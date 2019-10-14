def bubble_sort(arr):
    """Function to sort a list using bubble sort method"""
    n = len(arr)

    # Traverse through all array elements
    for i in range(n):

        # Last i elements are already in place
        for j in range(0, n - i - 1):

            # traverse the array from 0 to n-i-1
            # Swap if the element found is greater
            # than the next element
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return(arr)

arr = list(map(int, input("Enter the unsorted list: ").split()))

# Function call
result = bubble_sort(arr)

print("Sorted List: {}".format(result))
