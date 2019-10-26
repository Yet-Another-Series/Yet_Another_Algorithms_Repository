#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
};

node* createNode(int data)
{
    node *newNode = new node();
    (*newNode).val = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node *insert(node *root, int val)
{
    if(root==NULL)
    {
        root = createNode(val);
    }
    else if((root->val)>=val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

node* findmin(struct node* root)
{
  if(root->left==NULL)
  return root;
  else return findmin(root->left);
}
node *deleteKey(node * root, int key)
{
    if(root==NULL)
    {
        return root;
    }
    else if(root->val == key)
    {
        if(root->left == NULL and root->right == NULL)
        {
            delete(root);
            return NULL;
        }
        else if(root->left==NULL)
        {
            node *temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node* temp = root->left;
            delete(root);
            return temp;
        }
        else
        {
            node *temp = findmin(root->right);
            temp->val = root->val;
            root->right = deleteKey(root->right, key );
            return root;
        }
    }
    else if(root->val>key)
    {
        root->left = deleteKey(root->left, key);
        return root;
    }
    else if(root->val<key)
    {
        root->left = deleteKey(root->right, key);  
        return root;
    }
}

void inorder(node *root)
{
    if(root==NULL)
    return;
    else
    {
        inorder(root->left);
        cout << root->val << endl;
        inorder(root->right);
    }
}

void preorder(node *root)
{
    if(root==NULL)
    return;
    else
    {
        cout << root->val << endl;
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if(root==NULL)
    return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << endl;
    }
}

bool search(node *root, int key)
{
    if(root==NULL)
    return false;
    else if(root->val == key)
    {
        return true;
    }
    else if(root->val>key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->left, key);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    node *bst;
    bst = insert(bst, 15);
    bst = insert(bst, 6);
    bst = insert(bst, 18);
    bst = insert(bst, 3);
    bst = insert(bst, 7);
    bst = insert(bst, 13);
    bst = insert(bst, 9);
    bst = insert(bst, 2);
    bst = insert(bst, 4);
    bst = insert(bst, 17);
    bst = insert(bst, 20);
    inorder(bst);
    return 0;
}