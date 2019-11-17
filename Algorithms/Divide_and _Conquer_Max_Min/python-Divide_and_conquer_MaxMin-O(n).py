def max_min(li, left, right): 
  global count 
  if (left == right): 
    return li[left],li[left]     
  elif (right-left == 1): 
    return max(li[left],li[right]), min(li[left],li[right]) 
  else: 
    mid = int((left + right) / 2)      
    max1,min1 = max_min(li, left, mid)      	
    max2,min2 = max_min(li, mid+1, right)     	
    return max(max1,max2),min(min1,min2) 
     
li = [5,1,3,4,6,2] 
maxi,mini = max_min(li, 0, len(li)-1) 
print(maxi) 
print(mini) 

