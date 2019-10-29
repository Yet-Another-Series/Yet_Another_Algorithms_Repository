//Insertion Sort Singly Linked List 
#include<iostream>
using namespace std;

// Linked List Node
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 

// Function to insert a given node in a sorted linked list 
void sortedInsert(struct Node** head_ref, struct Node* new_node) 
{ 
    struct Node* current; 
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) 
    { 
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    } 
    else
    { 
        current = *head_ref; 
        while (current->next!=NULL && 
               current->next->data < new_node->data) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 

// function to sort a singly linked list using insertion sort
void insertionSort(struct Node **head_ref) 
{ 
    struct Node *sorted = NULL; 
    struct Node *current = *head_ref; 
    while (current != NULL) 
    { 
        struct Node *next = current->next; 
        sortedInsert(&sorted, current); 
        current = next; 
    } 
    *head_ref = sorted; 
} 

void print(struct Node *head) 
{ 
    struct Node *temp = head; 
    while(temp != NULL) 
    { 
        printf("%d  ", temp->data); 
        temp = temp->next; 
    } 
} 

void insert_new(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = new Node; 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 

int main()
{    
    struct Node *head = NULL; 
    insert_new(&head, 6); 
    insert_new(&head, 21); 
    insert_new(&head, 5); 
    insert_new(&head, 4); 
    insert_new(&head, 23); 
    insert_new(&head, 18); 


    cout<<"The original linked list is : ";
    print(head);
    insertionSort(&head); 
    cout<<"\nThe sorted linked list is : ";
    print(head);
    return 0;
}
