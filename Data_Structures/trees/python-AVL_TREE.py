#AVL Tree (Adelson Velsky and Landis Tree)
#it is a binary search tree in which all levels is completely fill except last level
#self balancing Tree
#insertion,deletion and searching operation is performed in O(h) time
#h-> height of AVL Tree
#insertion and deletion operation program

class TreeNode(object):
    def __init__(self,val):
        self.val   = val
        self.left  = None
        self.right = None
        self.height = 1

class AVL_Tree(object):

    #function for insertion of new node in avl tree
    def insert(self,root,val):
        if root is None:
            return TreeNode(val)
        elif val <root.val :
            root.left = self.insert(root.left,val)
        elif val >= root.val :
            root.right = self.insert(root.right,val)

        #update the height of ancestor node
        root.height = 1+max(self.height(root.left) , self.height(root.right))

        balance = self.getBalance(root)
        # if the node is unbalanced then try out 4 possibilities

        # left left case - 1
        if balance > 1 and val < root.left.val:
            return self.rightRotate(root)

        #right right case - 2
        if balance < -1 and val >root.right.val:
            return self.leftRotate(root)

        #left right case - 3
        if balance>1 and val >root.left.val:
            root.left = self.leftRotat(root.left)
            return self.rightRotate(root)

        #right left case - 4
        if balance<-1 and val < root.right.val:
            root.right  = self.rightRotate(root.right)
            return self.leftRotate(root)

        return root

    #function to perform deletion from avl tree 
    def deleteNode(self,root,val): 
        if not root:
            return root 
        elif val<root.val:
            root.left = self.deleteNode(root.left,val)
        elif val>root.val: 
            root.right = self.deleteNode(root.right,val) 
        else:
            if root.left is None and root.right is None:
                root = None 
                return root 
            if root.left is None:
                temp = root.right
                #root = None 
                return temp 
            
            if root.right is None:
                temp = root.left 
                #root = None 
                return temp 
            #if both the child are present 
            temp = self.getMinValueNode(root.right)
            root.val = temp.val 
            root.right = self.deleteNode(root.right,temp.val) 
            
        #if tree is only one node simply return it 
        #if root is None:
        #   return 
        
        
        #step - 2 update the  height of ancestor 
        root.height = 1 + max(self.height(root.left),self.height(root.right))
        
        balance = self.getBalance(root)
        
        #case - 1 
        if balance>1 and self.getBalance(root.left)>=0:
            return self.rightRotate(root) 
        if balance<-1 and self.getBalance(root.right)<=0:
            return self.leftRotate(root) 
        if balance>1 and self.getBalance(root.left)<0:
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root) 
        if balance<-1 and self.getBalance(root.right)>0:
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)
        return root    
            
    def getMinValueNode(self,root):
        current = root 
        while current.left is not None:
            current = current.left 
        return current    
            
        

    #function for performing left rotation in avl tree
    def leftRotate(self,z):
        y = z.right
        T2 = y.left

        #perform rotation
        y.left = z
        z.right = T2

        #update heights
        z.height =  1+max(self.height(z.left),self.height(z.right))
        y.height =  1+max(self.height(y.left),self.height(y.right))

        return y
        
    #function for performing right rotation in avl tree
    def rightRotate(self,z):
        y = z.left
        T2 = y.right
        #perform rotation
        y.right = z
        z.left = T2
        #update height
        z.height = 1+max(self.height(z.left),self.height(z.right))
        y.height = 1+max(self.height(y.left),self.height(y.right))

        return y

    #function for calculating height 
    def height(self,root):
        if not root:
            return 0
        return root.height

    #function to calculate balance factor
    def getBalance(self,root):
        if not root:
            return 0
        return self.height(root.left) - self.height(root.right)

    #function to perform preOrder traversal
    def preOrder(self,root):
        if root is None:
            return
        print(root.val,end=' ')
        self.preOrder(root.left)
        self.preOrder(root.right)
    
    
    
    
    
#Driver Code
tree = AVL_Tree()
root = None
root  = tree.insert(root,10)
root  = tree.insert(root,20)
root  = tree.insert(root,30)
root  = tree.insert(root,40)
root  = tree.insert(root,50)
root  = tree.insert(root,25)
#preOrder Traversal
print("PreOrder traversal of the  constructed AVL tree is: ")
tree.preOrder(root)
print()

# Delete 
key = 30
root = tree.deleteNode(root, key) 
  
# Preorder Traversal 
print("Preorder Traversal after deletion -") 
tree.preOrder(root) 
print() 
