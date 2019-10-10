'''
Queues
The following operations are performed by the stack in this module

Function name           Description

Enqueue(Key)            adds key to the queue
KeyFront()              returns the oldest added key
Dequeue()               removes and returns the oldest added key
Empty()                 returns boolean value True or False on whether the queue is empty
Disp()                  displays the queue

'''

class Queue:
    front=None
    back=None
    def __init__(self,value):
        self.data=value
        self.next=None

def Enqueue(Key):
    node=Queue(Key)
    if Empty():
        Queue.front=node
        Queue.back=node
    else:
        if Queue.front.next==None:
            Queue.front.next=node
        else:
            Queue.back.next=node
        Queue.back=node

def KeyFront():
    if Empty():
        return "Underflow"
    else:
        return Queue.front.data

def Dequeue():
    if Empty():
        return "Underflow"
    else:
        if Queue.front.next==None:
            Queue.back=None
        _=Queue.front
        Queue.front=Queue.front.next
        return _.data
def Empty():
    return Queue.front==None
def Disp():
    if Empty():
        print(None)
    else:
        temp=Queue.front
        while temp!=None:
            print(temp.data)
            temp=temp.next

''' Menu driven queue implementation '''

while True:
    x=input('Enter\n1.Enqueue\n2.KeyFront\n3.Dequeue\n4.Empty\n5.Disp\nand any other key to exit')
    if x=='1':
        Enqueue(int(input('Enter value to be pushed')))
    elif x=='2':
        print(KeyFront())
    elif x=='3':
        print(Dequeue())
    elif x=='4':
        print(Empty())
    elif x=='5':
        Disp()
    else:
        break
