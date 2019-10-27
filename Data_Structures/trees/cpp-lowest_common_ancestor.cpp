Node* LCA(Node *root, int n1, int n2)
{
    Node* cur=root;
    Node* pre=root;
    while(cur)
    {
        pre=cur;
        if(n1>cur->data && n2>cur->data)
        {
            cur=cur->right;
        }
        else if(n1<cur->data && n2<cur->data)
        {
            cur=cur->left;
        }
        else
        return pre;
        
    }
    return cur;
}
