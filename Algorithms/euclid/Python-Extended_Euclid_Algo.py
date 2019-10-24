# -*- coding: utf-8 -*-
"""
Created on Tue Oct 12 14:07:09 2019

@author: Kaushal Agarwal
"""

#extended Euclid theorem
#input A B
#output GCD , x, y

def extendedEuclid(A,B,x,y,d):
    if B==0:
        d[0] = A
        x[0] = 1
        y[0] = 0
    else:
        extendedEuclid(B,A%B,x,y,d)
        x[0],y[0] = y[0], x[0] - (A//B)*y[0]


def main():
    d = [0];x = [0];y = [0]
    extendedEuclid(16,10,x,y,d)
    print(x[0],y[0],d[0])

main()
