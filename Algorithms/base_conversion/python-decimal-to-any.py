# Python3 Program to convert decimal to 
# any given base 

# To return char for a value. For example 
# '2' is returned for 2. 'A' is returned 
# for 10. 'B' for 11 
def reVal(num): 

	if (num >= 0 and num <= 9): 
		return chr(num + ord('0')); 
	else: 
		return chr(num - 10 + ord('A')); 

# Utility function to reverse a string 
def strev(str): 

	len = len(str); 
	for i in range(int(len / 2)): 
		temp = str[i]; 
		str[i] = str[len - i - 1]; 
		str[len - i - 1] = temp; 

# Function to convert a given decimal 
# number to a base 'base' and 
def fromDeci(res, base, inputNum): 

	index = 0; # Initialize index of result 

	# Convert input number is given base 
	# by repeatedly dividing it by base 
	# and taking remainder 
	while (inputNum > 0): 
		res+= reVal(inputNum % base); 
		inputNum = int(inputNum / base); 

	# Reverse the result 
	res = res[::-1]; 

	return res; 

# Driver Code 
inputNum = 282; 
base = 16; 
res = ""; 
print("Equivalent of", inputNum, "in base", 
	base, "is", fromDeci(res, base, inputNum)); 

