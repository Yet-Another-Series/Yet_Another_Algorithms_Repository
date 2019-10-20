/**Author : Vivek Bhardwaj
  *Written for : Yet_Another_Algorithms_Repository
**/

/**IMPLEMENTATION OF QUEUE CLASS IN CPP
  *INSPIRED BY QUEUE CLASS PROVIDED BY STL
**/

#include<iostream>
using namespace std;


/**Node structure created for linked list implementation of queue.
  *The structure consists of template ,thus queue can be made for diffrent datatypes
**/ 
template<class A>
struct Node{
    A data;
    Node * link;
};

template<class A>
class queue{
    private :
        Node<A> * front_ptr;                    //front_ptr points to the Node in front of queue
        Node<A> * back_ptr;                     //back_ptr points to the Node in back of queue
        long long size;                         //size stores the no. of elements currently in queue

    public :

    /** Constructor which assigns values to the private variables
    **/
        queue(){
            front_ptr=nullptr;
            back_ptr=nullptr;
            size=0;
        }
    /** Push function for the queue 
     *  it creates a node and inserts it in end of the linked list
    **/
        void push(A x){
            Node<A> *temp=new Node<A>;
            temp->data=x;
            temp->link=nullptr;
            //if condition for the situation when there ins no node in the linked list i.e. queue is empty
            if(size==0){
                front_ptr=temp;
                back_ptr=temp;
            }
            else{
                back_ptr->link=temp;
                back_ptr=temp;
            }
            size++;
        }

        /** Pop function for the queue 
        *  it deletes the node in the beginning of the linked list
        **/
        void pop(){

            //if condition to prevent popping when list(or queue) is empty.
            if(size==0){
                cout<<"Queue is empty ,No elements to pop!"<<endl;
                return;
            }
            Node<A> *temp=front_ptr;
            front_ptr=temp->link;
            delete temp;
            size--;
        }


        /** Front functions returns the data in front of queue
        **/
        A front(){
            return front_ptr->data;
        }

        /** Empty function checks if the queue is empty or not
         *  returns true if queue is empty.
        **/
        bool empty(){
            return size==0;
        }
        
};

/*int main(){
    queue<int> q;
    for(int i=0;i<5;i++) q.push(i);
    for(int i=0;i<5;i++){
         cout<<q.front()<<" ";
         q.pop();
    }

    q.push(5);q.push(2);q.push(1);q.push(9);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}*/
