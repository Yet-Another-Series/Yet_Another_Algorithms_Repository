# This code is contributed by Bhavya Jain 
# Modified by Tarun M

def computeSubArray(pat, M, lps): 
	len = 0  

	lps[0] = 0 
	i = 1

	for i in range(1,M):
		if pat[i]== pat[len]: 
			len += 1
			lps[i] = len
		else: 
			if len != 0: 
				len = lps[len-1]  
        i -= 1
			else: 
				lps[i] = 0

def KMPSearch(pattern, txt): 
	M = len(pattern) 
	N = len(txt) 
  lps = [0]*M 
	j = 0 

	computeSubArray(pattern, M, lps) 

	i = 0  
	while i < N: 
		if pattern[j] == txt[i]: 
			i += 1
			j += 1

		if j == M: 
			print "Found pattern at index " + str(i-j) 
			j = lps[j-1] 

		# mismatch after j matches 
		elif i < N and pattern[j] != txt[i]: 
			# Do not match lps[0..lps[j-1]] characters, 
			# they will match anyway 
			if j != 0: 
				j = lps[j-1] 
			else: 
				i += 1


if __name__ == '__main__':
  txt = input("Enter the complete string...")
  substring = input("Enter the substring to be searched using the KMP alogrithm...")
  KMPSearch(substring, txt) 

