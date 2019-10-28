from random import *
sudoku=[]
l=[0,0,0,0,0,0,0,0,0]
for i in range(9):
    sudoku.append(l.copy())
global s 
s=list(sudoku)
block={}
r,c=-1,-1
block_num=0
def fillblock1():
    global s
    List=[1,2,3,4,5,6,7,8,9]
    for i in range(3):
        for j in range(3):
            a=choice(List)
            s[i][j]=a
            List.remove(a)
#fillblock1()
def getemptypos():
    for i in range(9):
        for j in range(9):
            if s[i][j]==0:
                return i,j
    return -1,-1
def canbeadded(ele,r,c):
    row=[]
    column=[]
    for i in range(9):
        row.append(s[r][i])
        column.append(s[i][c])
    if r<3:
        if c<3:
            B=[]
            for i in range(3):
                for j in range(3):
                    B.append(s[i][j])
        elif c<6:
            B=[]
            for i in range(3):
                for j in range(3,6):
                    B.append(s[i][j])
        else:
            B=[]
            for i in range(3):
                for j in range(6,9):
                    B.append(s[i][j])
    elif r<6:
        if c<3:
            B=[]
            for i in range(3,6):
                for j in range(3):
                    B.append(s[i][j])
        elif c<6:
            B=[]
            for i in range(3,6):
                for j in range(3,6):
                    B.append(s[i][j])
        else:
            B=[]
            for i in range(3,6):
                for j in range(6,9):
                    B.append(s[i][j])
    else:
        if c<3:
            B=[]
            for i in range(6,9):
                for j in range(3):
                    B.append(s[i][j])
        elif c<6:
            B=[]
            for i in range(6,9):
                for j in range(3,6):
                    B.append(s[i][j])
        else:
            B=[]
            for i in range(6,9):
                for j in range(6,9):
                    B.append(s[i][j])
    return ele not in row and ele not in column and ele not in B
def solvable(s):
    r,c=getemptypos()
    if r==-1 and c==-1:
        return True
    for i in range(1,10):
        if canbeadded(i,r,c):
            s[r][c]=i
            if solvable(s):
                return True
            s[r][c]=0
    return False
solvable(s)
for i in range(9):
    print(s[i])








