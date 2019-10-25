def kadane(array):
  array.sort()
  max_current = array[0]
  max_global = array[0]
  
  for i in range(1,len(array)):
    max_current = max([array[i], max_current + array[i]])
    if max_current > max_global:
      max_global = max_current
  return max_global

array = [2,3,15,-3,458]
print("Max sum is", kadane(array))