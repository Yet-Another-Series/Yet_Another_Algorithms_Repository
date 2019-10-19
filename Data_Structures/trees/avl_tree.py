class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.left_height = 0
        self.right_height = 0

    def set_left(self, node):
        self.left = node
        self.left_height = max(node.left_height, node.right_height)+1 if node else 0

    def set_right(self, node):
        self.right = node
        self.right_height = max(node.left_height, node.right_height)+1 if node else 0

    def rotate_left(self):
        b = self.right
        self.set_right(b.left)
        b.set_left(self)
        return b
        
    def rotate_right(self):
        a = self.left
        self.set_left(a.right)
        a.set_right(self)
        return a

    def factor(self):
        return self.right_height - self.left_height

def add_node(root, node):
    if root is None: return node

    if node.key < root.key:
        root.set_left(add_node(root.left, node))
        if root.factor() < -1:
            if root.left.factor() > 0:
                root.set_left(root.left.rotate_left())
            return root.rotate_right()
    else:
        root.set_right(add_node(root.right, node))
        if root.factor() > 1:
            if root.right.factor() < 0:
                root.set_right(root.right.rotate_right())
            return root.rotate_left()
    
    return root

def print_tree(root, parent = 0, index = 0):
    if root is None: return index
    
    print ('{}[label="{} ({})"]'.format(index, root.key, root.factor()))
    if parent!=index:
        print ('{}->{}'.format(parent, index))
    
    lindex = print_tree(root.left, index, index+1)
    return print_tree(root.right, index, lindex)
    

import random
tree = None

for word in random.sample(range(10000), 16):
    tree = add_node(tree, Node(word))

print ('digraph{')
print_tree(tree)
print ('}')