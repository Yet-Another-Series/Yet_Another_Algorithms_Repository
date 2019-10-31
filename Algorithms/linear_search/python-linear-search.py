def lns(A, x):
  for index in range(len(A)):
    if A[index] == x:
      return f"{x} is found in index {index}"
  return f"{x} is not found"

A =[1,9,3,-1,5,19,-14,2,3,5,7]

x = int(input("Number to find: "))

print(lns(A, x))