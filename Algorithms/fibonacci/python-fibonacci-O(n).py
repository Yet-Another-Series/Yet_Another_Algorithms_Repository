#FIBBONACI USING DP

def fibonacci(n):  
    a=[0,1]
    if(n==1):
        return [1]
    else:
        for i in range(2,n):
            a.append(a[i-1]+a[i-2])
        return a

n=int(input())
if n==0:
    print(n)
else:
    x=(fibonacci(n))
    print(*x)
