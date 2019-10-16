# O(n) implementation
# sliding window pane
# finding sum of a subarray of size k

import sys

INT_MIN = -99999

def maxSum(arr, N, k):

    #N must be greater than k
    if not (N>k):
        print("array size less than subarray size. Error")
        return -1;
    

    maxSum = INT_MIN
    windowSum = 0

    for i in range(k):
        windowSum += arr[i]

    # finding sum of other windows by sliding 
    # windows by adding last element and removing first

    for i in range(N-k):
        windowSum = windowSum - arr[i] + arr[i+k]
        maxSum = max(windowSum, maxSum)


    return maxSum




arr = [10,20,4,5,23,78,67,21]
k = 4
N = len(arr)
print(maxSum(arr, N, k))


