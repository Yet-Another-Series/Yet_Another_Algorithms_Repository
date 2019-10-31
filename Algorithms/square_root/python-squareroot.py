#this uses Newton's method to calculate the square root

def square_root(n):
	guess = 1
	while not (abs(guess*guess - n) < 0.001):
		guess = (guess + (n/guess)) / 2.0
	return guess


#test
print(square_root(16))

