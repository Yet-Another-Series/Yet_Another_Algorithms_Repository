def fact(n):
    if(n==0):
        return(1)
    else:
        f=n*fact(n-1)
        return(f) 

num=int(input("Enter a number:"))
print(fact(num))
