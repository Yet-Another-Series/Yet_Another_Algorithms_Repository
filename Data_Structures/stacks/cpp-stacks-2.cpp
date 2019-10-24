#include<iostream>
using namespace std;

template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

template <typename T>
class Stack {
    Node<T> *head;
    int size;		// number of elements prsent in stack
    
    public :
    
    Stack() {
        this->head = NULL;
        this->size = 0;
    }
    
    int getSize() {
        return this->size;
    }
    
    bool isEmpty() {   
        return this->size==0;
    }
    
    void push(T element) {
        Node<T> *temp = new Node<T>(element);
        temp->next = this->head;
        this->head = temp;
        this->size++;
        
    }
    
    T pop() {
        // Return 0 if stack is empty.
        if(this->size == 0){
            return 0;
        }
        Node<T> *temp = head;
        int data = temp->data;
        head = head->next;
        delete temp;
        this->size--;
        return data;
        
    }
    
    T top() {
        // Return 0 if stack is empty.
        if(this->size == 0){
            return 0;
        }
        return this->head->data;
        
    }

int main() {
        
        Stack<int> st;
        
        int choice;
        cin >> choice;
        int input;
        
        while (choice !=-1) {
            if(choice == 1) {
                cin >> input;
                st.push(input);
            }
            else if(choice == 2) {
                int ans = st.pop();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }
            else if(choice == 3) {
                int ans = st.top();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }
            else if(choice == 4) {
                cout << st.getSize() << endl;
            }
            else if(choice == 5) {
		if(st.isEmpty()){
                	cout << "true" << endl;
		}else{
			cout << "false" << endl;
		}
            }
            cin >> choice;
        }
    
    }
