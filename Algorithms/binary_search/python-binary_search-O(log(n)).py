def binary_search(list_, val, asc=1):
	'''
	list_: sorted list with unique values
	val: value to search
	asc: asc==1 list is sorted in ascending order
 
	Searches for a given element in a list sorted in ascending order. For searching in a list sorted in descending order, pass the argument value for asc as '0'.
	'''
	
	lo = 0
	hi = (len(list_)-1)
	
	while (lo <= hi):
		mid = int(lo + (hi-lo)/2)
		#print("mid", mid)
		if (list_[mid] == val):
			return mid
		elif (list_[mid] > val):
			if (asc == 1): # increasing
				hi = mid-1
			else :
				lo = mid+1			
		elif (list_[mid] < val):
			if (asc == 1): # increasing
				lo = mid+1
			else :
				hi = mid-1
	return -1


a = [14,15,16,17,18,19]
a_= [19,18,17,16,15,14]

print(binary_search(a, 16))
print(binary_search(a, 19))
print(binary_search(a, 18))
print(binary_search(a, 11))

print(binary_search(a_, 16, 0))
print(binary_search(a_, 19, 0))
print(binary_search(a_, 18, 0))
print(binary_search(a_, 11, 0))
