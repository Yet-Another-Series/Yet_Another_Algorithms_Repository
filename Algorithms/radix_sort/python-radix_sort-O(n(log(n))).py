def countingSort(arr, base): 
	n = len(arr) 
	# Output array which will contain sorted elements
	final = [0] * (n) 

	# Frequency of all digits from 0-9 is set to 0 
	frequency = [0] * (10) 

	# The frequency of each digit is stored in the frequency array
	for i in range(0, n): 
		index = int(arr[i]/base) 
		frequency[(index)%10] += 1

	# This step is used to get the respective positions 
	# of the elements in the sorted array
	for i in range(1,10): 
		frequency[i] += frequency[i-1] 

	# Sorting the elements by placing them at their respective positions
	# as suggested by the frequency array
	i = n-1
	while i>=0: 
		index = int(arr[i]/base) 
		final[ frequency[ (index)%10 ] - 1] = arr[i] 
		frequency[ (index)%10 ] -= 1
		i -= 1

	# Copying the sorted elements into the original array
	i = 0
	for i in range(0,len(arr)): 
		arr[i] = final[i] 

def radixSort(arr): 
	maximum = max(arr) 
	# Counting sort will be performed for every digit from the least
	# significant bit to the most significant bit

	# base is 10^i where i is the digit
	base = 1
	while maximum/base > 0: 
		countingSort(arr,base) 
		base *= 10

# Entering the elements of the array to be sorted
arr = list(map(int,input().split())) 
radixSort(arr) 

# Displaying the sorted elements
for i in arr: 
	print(i,end=" ")