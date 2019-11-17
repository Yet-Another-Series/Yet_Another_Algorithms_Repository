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

template<typename T>
class Queue {
    Node<T> *fron;
    Node<T> *rear;
    int size;
    
    
    public :
    
    
    Queue() {
        
        this->fron = NULL;
        this->rear = NULL;
        this->size = 0;
        
    }
    
    void enqueue(T data) {
        Node<T> *temp = new Node<T>(data);
        if(this->size == 0){
            this->fron = this->rear = temp;
            this->size++;
        }else{
            this->rear->next = temp;
            this->rear = temp;
            this->size++;
        }
        
    }
    
    int getSize() {
        
        return this->size;
        
    }
    
    bool isEmpty() {
        return this->size == 0;
        
    }
    
    T dequeue() {
        // Return 0 if queue is empty
        if(this->size == 0){
            return 0;
        }
        Node<T> *temp = this->fron;
        T data = temp->data;
        this->fron = this->fron->next;
        delete temp;
        this->size--;
        return data;
        
    }
    
    T front()  {
        // Return 0 if queue is empty
        if(size == 0){
            return 0;
        }else{
            return this->fron->data;
        }
    }
};

int main() {
    
    Queue<int> q;
    
    int choice;
    cin >> choice;
    int input;
    
    while (choice !=-1) {
        if(choice == 1) {
            cin >> input;
            q.enqueue(input);
        }
        else if(choice == 2) {
            int ans = q.dequeue();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 3) {
            int ans = q.front();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 4) {
            cout << q.getSize() << endl;
        }
        else if(choice == 5) {
            if(q.isEmpty()) {
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }
        cin >> choice;
    }
    
}
