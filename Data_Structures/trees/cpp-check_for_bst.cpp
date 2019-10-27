bool isBST(Node* root) {
/*
    static Node* prev=NULL;
    
    if(root){
    if(!isBST(root->left))
    {
        return false;
    }
    if(prev!=NULL && root->data<=prev->data)
    {
        return false;
    }
    prev=root;
    return isBST(root->right);}
    return true;*/
    
    
    static Node *prev = NULL;
     
    // traverse the tree in inorder fashion and keep track of prev node
    if (root)
    {
        if (!isBST(root->left))
          return false;
 
        // Allows only distinct valued nodes 
        if (prev != NULL && root->data <= prev->data){
            prev=NULL;
        
          return false;}
 
        prev = root;
 
        return isBST(root->right);
    }
 
    return true;
}
