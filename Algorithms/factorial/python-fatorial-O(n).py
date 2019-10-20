# -*- coding: utf-8 -*-

def fatorial(n):
    if n <= 1:
        return 1
    else:
        return n * fatorial(n - 1)

print(fatorial(20))