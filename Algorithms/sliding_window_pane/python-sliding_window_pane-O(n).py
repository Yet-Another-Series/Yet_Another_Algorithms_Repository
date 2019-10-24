def maxSum(num_list, n, k):
    if n < k:
        print("Invalid")
        return -1

    max_sum = 0
    for i in range(k):
        max_sum += num_list[i]

    window_sum = max_sum
    for i in range(k,n):
        window_sum += num_list[i] - num_list[i - k]
        max_sum = max(max_sum, window_sum)
    return max_sum


if __name__ ==  '__main__':
    num_list = [1, 4, 2, 10, 2, 3, 1, 0, 20]
    k = 4
    n = len(num_list)
    print(maxSum(num_list, n, k))
