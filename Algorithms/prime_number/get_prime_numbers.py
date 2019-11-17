"""
Prime Numbers between 2 numbers a and b (Using Sieve of Eratosthenes)
a. Sieve of Eratosthenes is an ancient method for finding prime numbers
b. starting from lowest element(curr) in sieve remove element if item%curr==0
"""
def primes(end,start=0):
	sieve = [2]+list(range(3,end+1,2))
	i=1
	while i<len(sieve):
		index = i+1
		while index < len(sieve):
			if sieve[index]%sieve[i] == 0:
				sieve.pop(index)
			index+=1
		i+=1
	i=0
	while sieve[i] < start:
		i+=1
	return sieve[i:]
  
if __name__ == '__main__':
  print(primes(30,start=10))
