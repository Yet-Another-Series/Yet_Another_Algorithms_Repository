n = int(input("Factorial Number: "))
mem = {}

def fact(n):
	if n in mem:
		return mem[n]
	if n == 0:
		return 1
	mem[n] = fact(n-1)*n
	return mem[n]
print(fact(n))
