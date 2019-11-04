def binary_search(arr, l, r, x):
	"""	Function to search number in a list in logn time"""
	while l <= r:
		mid = (l + r) // 2

		# Check if x is present at mid
		if arr[mid] == x:
			return mid

		# If x is greater, ignore left half
		elif arr[mid] < x:
			l = mid + 1

		# If x is smaller, ignore right half
		else:
			r = mid - 1

	# If we reach here, then the element
	# was not present
	return -1

arr = list(map(int, input("Enter the sorted array: ").split()))
x = int(input("Enter the number to search: "))

# Function call
result = binary_search(arr, 0, len(arr) - 1, x)

if result != -1:
	print("Element is present at position {}".format(result + 1))
else:
	print("Element is not present in array")
