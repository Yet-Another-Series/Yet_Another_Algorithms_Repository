'''
Original by Ashish Ohri
Modified by Tarun M
Stacks
The following operations are performed by the stack in this module
Function name           Description                                     Return type
Push(Key)               adds key to the collection of stack             None
KeyTop()                returns most recently added key                 String
KeyPop()                removes and returns most recently added key     String
IsEmpty()               tells whether the stack is empty                Boolean
Disp()                  displays the stack                              List
'''

class Stack:
    top=None
    def __init__(self,value):
        self.data=value
        self.next=None

def Push(Key):
    node=Stack(Key)
    if IsEmpty():
        Stack.top=node
    else:
        node.next=Stack.top
        Stack.top=node

def KeyTop():
    if IsEmpty():
        return "Underflow"
    
    return Stack.top.data

def KeyPop():
    if IsEmpty():
        return "Underflow"
    
    _=Stack.top
    Stack.top=Stack.top.next
    return _.data

def IsEmpty():
    return Stack.top is None

def Disp():
    if IsEmpty():
        print(None)
    else:
        temp=Stack.top
        while temp is not None:
            print(temp.data)
            temp=temp.next

''' Menu driven stack implementation '''


while True:
    print('->Menu \n 1.Push \n 2.KeyTop \n 3.KeyPop \n 4.Empty \n 5.Disp \n and 6. Quit')
    x=input('Enter your choice...')
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
    elif x=='6':
        break
    else:
        print("Incorrect choice...")
