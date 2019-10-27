struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; 
// Method that prints the bottom view.
void bottom(Node* root, int level, map<int,int> &m)
{
    if(root==NULL)
    return;
    m[level]=root->data;
    bottom(root->left,level-1,m);
    bottom(root->right,level+1,m);
    
}
void bottomView(Node *root)
{
    map<int,int> m;
    
    bottom(root,0,m);
    map<int,int> :: iterator itr;
    for(itr=m.begin();itr!=m.end();itr++)
    {
        cout<<itr->second<<" ";
    }
}
