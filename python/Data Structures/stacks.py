'''
Stacks
The following operations are performed by the stack in this module

Function name           Description

Push(Key)               adds key to the collection of stack
KeyTop()                returns most recently added key
KeyPop()                removes and returns most recently added key
Empty()                 returns boolean value True or False on whether the stack is empty
Disp()                  displays the stack

'''

class Stack:
    top=None
    def __init__(self,value):
        self.data=value
        self.next=None

def Push(Key):
    node=Stack(Key)
    if Empty():
        Stack.top=node
    else:
        node.next=Stack.top
        Stack.top=node

def KeyTop():
    if Empty():
        return "Underflow"
    else:
        return Stack.top.data

def KeyPop():
    if Empty():
        return "Underflow"
    else:
        _=Stack.top
        Stack.top=Stack.top.next
        return _.data

def Empty():
    return Stack.top==None

def Disp():
    if Empty():
        print(None)
    else:
        temp=Stack.top
        while temp!=None:
            print(temp.data)
            temp=temp.next

''' Menu driven stack implementation '''

while True:
    x=input('Enter\n1.Push\n2.KeyTop\n3.KeyPop\n4.Empty\n5.Disp\nand any other key to exit')
    if x=='1':
        Push(int(input('Enter value to be pushed')))
    elif x=='2':
        print(KeyTop())
    elif x=='3':
        print(KeyPop())
    elif x=='4':
        print(Empty())
    elif x=='5':
        Disp()
    else:
        break