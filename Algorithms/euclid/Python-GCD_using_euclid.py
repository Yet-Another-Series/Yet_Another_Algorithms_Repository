# -*- coding: utf-8 -*-
"""
Created on Tue Oct 12 15:17:20 2019

@author: Kaushal Agarwal
"""

def GCD(A,B):
    if B==0:
        return A 
    else:
        return GCD(B,A%B) 
#Driver Code     
if __name__ =="__main__":
    print("GCD of 10 and 15 is",GCD(10,15))
    print("GCD of 12 and 15 is",GCD(12,15))
    print("GCD of 8 and   9 is",GCD(8,9))
    print("GCD of 91 and 69 is",GCD(91,65))
    
        
