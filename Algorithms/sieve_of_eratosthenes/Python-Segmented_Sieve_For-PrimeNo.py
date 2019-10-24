#this program is an efficient version of sieve eratosthenes program to calculate all prime numbers in range[1,N]
#time complexity is O(NloglogN)
#space complexity is O(sqrt(N))

import math
import copy
def sieveOfEratosthenes(n):
    prime =[True]*(n+1)
    for i in range(4,n+1,2):
        prime[i] = False
    p = 3
    while p*p<(n+1):
        if prime[p]:
            for i in range(p*p,n+1,p):
                prime[i] = False
        p+=2 
    res = []
    for i in range(2,n+1):
        if prime[i]:
            res.append(i)
    return res
    
def segmentedSieve(n):
    limit = int(math.sqrt(n))+1
    prime = sieveOfEratosthenes(limit)
    res = copy.deepcopy(prime)

    low = limit 
    high = limit*2 
    while low<n:
        if high>n:
            high=n
        mark = [True]*(high - low +1)
            
        for i in range(len(prime)):
            lowLimit = int(low//prime[i])*prime[i]
            if lowLimit<low:
                lowLimit +=prime[i]
            for j in range(lowLimit,high+1,prime[i]):
                mark[j - low]=False
        
        for i in range(low,high+1):
            if mark[i-low]==True:
                res.append(i)
        low = low+limit 
        high = high +limit
    return res            
                    
            
    
    
    
#N = int(input())
#for testing purpose taking N=10**5
N = 10**5
#printing only first 100 terms for testing purpose
print(segmentedSieve(N)[:100])
