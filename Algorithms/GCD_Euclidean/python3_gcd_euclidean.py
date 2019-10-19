# Python program to demonstrate Basic Euclidean Algorithm 
  
  
# Function to return gcd of a and b 
def gcd(a, b):  
    if a == 0 : 
        return b  
      
    return gcd(b%a, a) 
  
a = int(input('Enter first number: '))
b = int(input('Enter second number: '))
print("gcd(", a , "," , b, ") = ", gcd(a, b)) 