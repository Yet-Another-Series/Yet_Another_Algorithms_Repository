def maxSum(arr, n, k): 
	max_sum = INT_MIN ; 
	for i in range(n - k + 1): 
		current_sum = 0; 
		for j in range(k): 
			current_sum = current_sum + arr[i + j]; 
		max_sum = max(current_sum, max_sum ); 

	return max_sum; 

k = 4
n = int(input())
arr=[for x in input().split()]
print(maxSum(arr, n, k))

