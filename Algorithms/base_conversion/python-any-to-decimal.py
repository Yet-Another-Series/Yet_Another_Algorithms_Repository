# Python program to convert a 
# number from any base to decimal 

# To return value of a char. 
# For example, 2 is returned 
# for '2'. 10 is returned for 'A', 
# 11 for 'B' 
def val(c): 
	if c >= '0' and c <= '9': 
		return ord(c) - ord('0') 
	else: 
		return ord(c) - ord('A') + 10; 

# Function to convert a number 
# from given base 'b' to decimal 
def toDeci(str,base): 
	llen = len(str) 
	power = 1 #Initialize power of base 
	num = 0	 #Initialize result 

	# Decimal equivalent is str[len-1]*1 + 
	# str[len-1]*base + str[len-1]*(base^2) + ... 
	for i in range(llen - 1, -1, -1): 
		
		# A digit in input number must 
		# be less than number's base 
		if val(str[i]) >= base: 
			print('Invalid Number') 
			return -1
		num += val(str[i]) * power 
		power = power * base 
	return num 
	
# Driver code 
strr = "11A"
base = 16
print('Decimal equivalent of', strr, 
			'in base', base, 'is', 
				toDeci(strr, base)) 

