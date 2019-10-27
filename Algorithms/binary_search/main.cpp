#include <iostream>
using namespace std;
class TreeNode {
public:
    int value;
    TreeNode *right;
    TreeNode *left;

    TreeNode(){
        value = 0;
        right = left = NULL;
    }
};
class BST {
public:
    TreeNode *root;
    BST() {
        root = NULL;
    }
    //Functions that a BST must perform
    // 1. Search for a value
    void searchBST(int key, TreeNode *start) {
        //check to see if you found it (anchor value)
        if (start == NULL) {
            cout << "Could not find it" << endl;
            return;
        } else if (key == start->value) {
            cout << "Found it! " << endl;
            if (start->left != NULL && start->right != NULL) {
                cout << "Node has 2 children" << endl;
            } else if (start->left != NULL) {
                cout << "Node has 1 child" << endl;
            } else if (start->right != NULL) {
                cout << "Node has 1 child" << endl;
            } else {
                cout << "Node has no children" << endl;
            }
            return;
        } else {
            if (key > start->value) {
                searchBST(key, start->right);
            } else {
                searchBST(key, start->left);
            }
        }
    }
    // 2. Add new values to the tree
    void addNodeBST(int key) {
        // you can't use recursion for this
        TreeNode *slow, *fast;
        slow = fast = root;
        // want fast to fall off the tree
        // Step 1: Search for Key
        if (root == NULL) {
            root = new TreeNode;
            root->value = key;
            return;
        } else {
            //use "fast" to go look for this 'key'
            // if "fast" falls off the tree, then this value does not exist
            //at this point, 'slow' to point to the parent of the new node
            //start by searching for this value
            //If you find it, don't add it. Just write a comment
            //If you don't find it. add it where you should have found it
            while (fast != NULL) {
                if (fast->value == key) {
                    cout << "Duplicate" << endl; //This is when you don't want duplicates
                    return;
                } else if (key > fast->value) {
                    slow = fast;
                    fast = fast->right;
                } else {
                    slow = fast;
                    fast = fast->left;
                }
            } //fast should have fallen off the tree
            //slow happens to be at the node which will become the new parent
            TreeNode *temp = new TreeNode;
            temp->value = key;

            if (key > slow->value) {
                slow->right = temp;
            } else {
                slow->left = temp;
            }
        }
    }

    // Step 4. Ways to display the content of the tree
    // In order trasnversal: must go to every value and print them out
    //Left->current-> right
    // Left, center, and right
    // With our example it would be 10,12,13,15,17,18,23
    void inorder(TreeNode *start) {
        if (start == NULL) {
            return;
        }
        else {
            inorder(start->left);
            cout << start->value << " " << endl;
            inorder(start->right);
        }
    }

    //PreOrder Transveral:
    //Current Node->Left node->Right node
    //15 12 10 13 18 17 23
    void preorder(TreeNode *start) {
        if (start == NULL) {
            return;
        }
        else {
            cout << start->value << " " << endl;
            preorder(start->left);
            preorder(start->right);
        }
    }

    //Post Order:
    //Left->Right->Center
    //Prefixes are with Root
    // pre->Root first
    //Post->Root last
    void postorder(TreeNode *start) {
        if (start == NULL) {
        }
        else {
            postorder(start->left);
            postorder(start->right);
            cout << start->value << " " << endl;
        }
    }

    /*int minValRSubTree(TreeNode *start) {
        int value;
        TreeNode *temp = start;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp->value;
    } */


    int maxValLSubTree(TreeNode *start) {
        int value;
        TreeNode *temp2 = start;
        while (temp2->right != NULL) {
            temp2 = temp2->right;
        }
        return temp2->value;
    }


    //Code will print the following: 10 13 12 17 23 18 15
    // 3. Delete values from the tree
    void deleteNodeBST(int key, TreeNode *fast, TreeNode *slow) {
//CASE I: has no child
        //finds the value
        if (fast == NULL) {
            cout << "Could not find it" << endl;
        }
            //CASE I: NO children
        else if (key == fast->value) {
            if (fast->left == NULL && fast->right == NULL) {
                //before you delete fast you have to determine which thing you are deleting
                if (slow->left == fast) {
                    delete fast;  //is the child to the left?
                    slow->left = NULL;
                } else if (slow->right == fast) { //or is it to the right?
                    delete fast;
                    slow->right = NULL;
                }
            }
//CASE II: has one child
                // see if fast is to the right of slow

            else if (fast->left == NULL && fast->right != NULL) {
                if (slow->left == fast) {
                    slow->left = fast->right;
                    delete fast;
                } else if (slow->right == fast) {
                    slow->right = fast->right;
                    delete fast;
                }
            } else if (fast->left != NULL && fast->right == NULL) {
                if (slow->left == fast) {
                    slow->left = fast->left;
                    delete fast;
                } else if (slow->right == fast) {
                    slow->right = fast->left;
                    delete fast;
                }
            }

                //CASE III: has two children:
                // Look at the max in the left or the min for the right side
                // You don't need both of them, but you can
                /*else if (fast->left !=NULL && fast->right !=NULL){
                    int replace = minValRSubTree(fast->right);
                    deleteNodeBST(replace, fast->right);
                    fast->value = replace;
                }*/
            else if (fast->left != NULL && fast->right != NULL) {
                int replace = maxValLSubTree(fast->left);
                deleteNodeBST(replace, fast->left, fast);
                fast->value = replace;
            }
        } else {
            if (key > fast->value) {
                deleteNodeBST(key, fast->right, fast);
            } else if (key < fast->value) {
                deleteNodeBST(key, fast->left, fast);
            }
        }
    }
};

    int main() {
        BST myTree;
        int choice, value;
        while (1) {
            cout << "Press 1 to add BST" << endl;
            cout << "Press 2 to search BST" << endl;
            cout << "Press 3 to delete" << endl;
            cout << "Press 4 to infix" << endl;
            cout << "Press 5 for prefix" << endl;
            cout << "Press 6 to postfix" << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Add what? " << endl;
                    cin >> value;
                    myTree.addNodeBST(value);
                    break;
                case 2:
                    cout << "What are you searching for " << endl;
                    cin >> value;
                    myTree.searchBST(value, myTree.root);
                    break;
                case 3:
                    int value;
                    cout << "What value would you like to delete " << endl;
                    cin >> value;
                    myTree.deleteNodeBST(value, myTree.root, myTree.root);
                    break;
                case 4:
                    myTree.inorder(myTree.root);
                    break;
                case 5:
                    myTree.preorder(myTree.root);
                    break;
                case 6:
                    myTree.postorder(myTree.root);
                    break;
            }
        }
    }