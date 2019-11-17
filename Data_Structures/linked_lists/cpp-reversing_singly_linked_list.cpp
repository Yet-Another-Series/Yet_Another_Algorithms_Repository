//Reversing a Singly Linked List 
#include<iostream>
using namespace std;

class Node      //Link list node
{public:    
    int data;
    Node* next;
};
Node* reverse(Node* head)   //Function to reverse the linked list
{   Node* current,*prev,*next;
    current=head;
    prev=NULL;
    while(current!=NULL)
    {   
        next=current->next;     // Store next 
        current->next=prev;     // Reverse current node's pointer 
        prev=current;           //move pointers one point ahead
        current=next;
    }
    head=prev;
    return head;
}
void print(Node* head)
{   Node* temp=head;
    while(temp!=NULL)
    {   cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{   Node* head=new Node();  // creating three new nodes
    Node* second=new Node();//and making head,second and third
    Node* third=new Node();// to point over there
    
    head->data=3;   //assigning data and linking to next node
    head->next=second;
    
    second->data=5;
    second->next=third;
    
    third->data=7;
    third->next=NULL;
    cout<<"The original linked list is : ";
    print(head);
    head=reverse(head); 
    cout<<"\nThe reversed linked list is : ";
    print(head);
    return 0;
}
