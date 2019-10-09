a=input("enter no. 1")
b=raw_input("enter'+' to add, '-' to subtract, '*' to multiply, '/' to divide and '%' to find percentage")
c=input("enter no. 2")
if b == "+":
    res=a+c
elif b=="*":
    res = a*c
elif b=="-":
    res=a-c
elif b=="/":
    if c == 0:
        res = "not defined"
    else:
        res = a/c
elif b=="%":
    if c == 0:
        res = "not defined"
    else:
        res = a*100/c
else:
    res = "operator not defined"
print res