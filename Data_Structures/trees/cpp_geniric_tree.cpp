#include <iostream>
using namespace std;
#include <vector>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};


#include <queue>


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
int countOfNodes(TreeNode<int>* root) {
    
    int c=0;
    for(int i=0;i<root->children.size();i++){
        c+=countOfNodes(root->children[i]);
        
    }
    return 1+c;
    
}
int height(TreeNode<int>* root) {
   
    int c=0;
    for(int i=0;i<root->children.size();i++){
        int x= height(root->children[i]);
        if(x>c)
            c=x;
    }
    
    return 1+c;

}
void printLevelWise(TreeNode<int>* root) {
   
    queue <TreeNode<int>*> q;
    if(q.empty())
        q.push(root);
    
      while (q.empty() == false) 
    { 
       TreeNode<int> *x=q.front();
       cout<<x->data<<":";
          
        q.pop();
          int ii=0;
          int s=x->children.size();
           for( ii=0;ii<s;ii++){
              cout<<(x->children[ii]->data);
               if(ii==s-1)
                   break;
               cout<<",";
          }
          cout<<endl;
          for(int i=0;i<x->children.size();i++){
              q.push(x->children[i]);
          }
  
       
    }
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout<<"count of Nodes  ";
    cout << countOfNodes(root) << endl;
    cout<<"height  ";
    cout<<height(root)<<endl;
}
