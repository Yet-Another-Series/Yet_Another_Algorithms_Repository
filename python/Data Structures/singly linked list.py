'''
SINGLY LINKED LIST
The linked list contains the following functions:

    FUNCTION                DESCRIPTION
    PushFront(Key)          add Key to the starting of the linked list
    TopFront()              return front(starting) element (node)
    PopFront()              remove front element
    PushBack(Key)           add Key to the ending of the linked list
    TopBack()               return last item of the linked list
    PopBack()               remove and return the last item of the linked list
    Find(Key)               returns boolean (true or false) for whether the key is present in the linked list
    Erase(Key)              remove Key from the list
    Empty()                 returns boolean (true or false) for whether the list is empty
    AddBefore(Node,Key)     adds Key before Node
    AddAfter(Node,Key)      adds Key after Node
    Disp()                  display the linked list
'''

class Node_Item: # initializes a key value as a node
    start=None
    def __init__(self,Key):
        self.value=Key
        self.Next=None

def PushFront(Key):
    node=Node_Item(Key) # creates a node (an object instance of Node_Item class)
    if Empty():
        Node_Item.start=node
    else:
        node.Next=Node_Item.start
        Node_Item.start=node

def TopFront():
    if Empty():
        return None
    return Node_Item.start.value

def PopFront():
    if Empty():
        return None
    else:
        _=Node_Item.start
        Node_Item.start=Node_Item.start.Next
        return _.value

def PushBack(Key):
    node=Node_Item(Key)
    if Empty():
        Node_Item.start=node
    else:
        temp_node=Node_Item.start
        while temp_node.Next!=None:
            temp_node=temp_node.Next
        temp_node.Next=node

def TopBack():
    if Empty():
        return None
    else:
        temp_node=Node_Item.start
        while temp_node.Next!=None:
            temp_node=temp_node.Next
        return temp_node.value

def PopBack():
    if Empty():
        return None
    elif Node_Item.start.Next==None:
        _=Node_Item.start
        Node_Item.start=None
        return _.value
    else:
        prev_node=Node_Item.start
        temp_node=Node_Item.start.Next
        while temp_node.Next!=None:
            prev_node=temp_node
            temp_node=temp_node.Next
        prev_node.Next=temp_node.Next
        return temp_node.value

def Find(Key):
    if Empty():
        return False
    else:
        temp_node=Node_Item.start
        while temp_node!=None:
            if temp_node.value==Key:
                return True
            temp_node=temp_node.Next
        return False

def Erase(Key):
    if Empty():
        print('Underflow')
    elif Node_Item.start.value==Key:
        Node_Item.start=Node_Item.start.Next
    else:
        prev_node=Node_Item.start
        temp_node=prev_node.Next
        while temp_node!=None:
            if temp_node.value==Key:
                prev_node.Next=temp_node.Next
                break
            temp_node=temp_node.Next
        else:
            print('No such key value found')

def Empty():
    if Node_Item.start==None:
        return True
    return False

def AddBefore(Node_val,Key):
    node=Node_Item(Key)
    if Empty():
        print('Underflow')
    elif Node_Item.start.value==Node_val:
        node.Next=Node_Item.start
        Node_Item.start=node
    elif Node_Item.start.Next==None:
        print('No such node value')
    else:
        prev_node=Node_Item.start
        temp_node=Node_Item.start.Next
        while temp_node!=None:
            if temp_node.value==Node_val:
                prev_node.Next=node
                node.Next=temp_node
                break
            prev_node=temp_node
            temp_node=temp_node.Next
        else:
            print('No such node value')
def AddAfter(Node_val,Key):
    node=Node_Item(Key)
    if Empty():
        print('Underflow')
    else:
        temp_node=Node_Item.start
        while temp_node!=None:
            if temp_node.value==Node_val:
                node.Next=temp_node.Next
                temp_node.Next=node
                break
        else:
            print('No such node value')
def Disp():
    if Node_Item.start==None:
        print(None)
    else:
        temp_node=Node_Item.start
        while temp_node!=None:
            print(temp_node.value,end=' ')
            temp_node=temp_node.Next
        print()

'''
This program is implemented through a menu driven loop
Note that all values of the keys (nodes) are taken to be integer
'''
while True:
    n=input('1.PushFront(Key)\n2.TopFront()\n3.PopFront()\n4.PushBack(Key)\n5.TopBack()\n6.PopBack()\
    \n7.Find(Key)\n8.Erase(Key)\n9.Empty()\n10.AddBefore(Node,Key)\n11.AddAfter(Node,Key)\n12.Disp\nand any other key to exit ')
    if n=='1':
        PushFront(int(input('Key: ')))
    elif n=='2':
        print(TopFront())
    elif n=='3':
        print(PopFront())
    elif n=='4':
        PushBack(int(input('Key: ')))
    elif n=='5':
        print(TopBack())
    elif n=='6':
        print(PopBack())
    elif n=='7':
        print("present=",Find(int(input('Key: '))))
    elif n=='8':
        Erase(int(input('Key:')))
    elif n=='9':
        print(Empty())
    elif n=='10':
        AddBefore(int(input('Value of node (before which the key is to be added): ')),int(input('Key: ')))
    elif n=='11':
        AddAfter(int(input('Value of node (after which the key is to be added): ')),int(input('Key: ')))
    elif n=='12':
        Disp()
    else:
        break
    input('Press any key to continue')
