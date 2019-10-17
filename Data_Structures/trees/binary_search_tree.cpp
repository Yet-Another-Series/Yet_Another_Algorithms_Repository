#include<bits/stdc++.h>
using namespace std;
struct node{
    node *left = NULL;
    node *right = NULL;
    int data; 
};
node* getnewnode(int d)
{
    node *tmp = new node();
    tmp->data = d;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
node* Insert(node *root, int d)
{
    if(root == NULL)
    {
        root = getnewnode(d);
    }
    else if(d<=root->data)
    {
        root->left = Insert(root->left,d);        
    }
    else
    {
        root->right = Insert(root->right,d);
    }
    return root;
}
bool search(node *root,int d)
{
    if(root==NULL)return false;
    else if(root->data==d)return true;
    else if(d>root->data)
        return search(root->right,d);  
    else 
        return search(root->left,d);
}
int height(node* root)
{
    if(root==NULL)return -1;
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
}
void lvl(node* root)
{   
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node *current = q.front();
        if(current->left!=NULL)q.push(current->left);
        if(current->right!=NULL)q.push(current->right);
        cout<<current->data<<" ";
        q.pop();
    }
}
void preorder(node* root)
{
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root)
{
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);    
}
void postorder(node* root)
{
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
// bool isSubtreeLesser(node *root,int data)
// {
//     if(root==NULL)return true;
//     if(root->data<=data && isSubtreeLesser(root->left,data) && isSubtreeLesser(root->right,data))return true;
//     else return false;
// }
// bool isSubtreeGreater(node *root,int data)
// {
//     if(root==NULL)return true;
//     if(root->data>data && isSubtreeGreater(root->left,data) && isSubtreeGreater(root->right,data))return true;
//     else return false;
// }
bool isBinarySearchTree(node *root, int minValue, int maxValue)
{
    if(root==NULL) return true;
    if( root->data>minValue && root->data<maxValue && isBinarySearchTree(root->left,minValue,root->data) && isBinarySearchTree(root->right,root->data,maxValue))
        return true;
    return false;    
}
node* Findmin(node* root)
{
    if(root==NULL) return root;
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
node* delet(node *root,int data)
{
    if(root=NULL)return root;
    else if(data < root->data) root->left = delet(root->left,data);
    else if(data > root->data) root->right = delet(root->right,data);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
            // return root;
        }
        else if(root->left = NULL)
        {
            node *tmp = root;
            root = root->right;
            delete tmp;
            // return root;
        }
        else if(root->right == NULL)
        {
            node *tmp = root;
            root = root->left;
            delete tmp;
            // return root;
        }
        else
        {
            node* tmp = Findmin(root->right);
            root->data = tmp->data;
            root->right = delet(root->right,tmp->data);
        }
    }
    return root;
}
int main()
{
    node *root=NULL;
    root = Insert(root,15);
    root = Insert(root,34);
    root = Insert(root,12);
    root = Insert(root,11);
    bool k = search(root,24);
    int m = height(root);
    lvl(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    cout<<isBinarySearchTree(root,INT_MIN,INT_MAX)<<endl;
    root=delet(root,12);
    cout<<endl;
    postorder(root);
    return 0;
}