# FIBONACCI SEQUENCE
n=int(input())
a=0
b=1


for i in range(0,n):
    if i==0:
        print(a,end=' ')
    elif i==1:
        print(b,end=' ')
    else:
        s=a+b
        a=b
        b=s
        print(s,end=' ')