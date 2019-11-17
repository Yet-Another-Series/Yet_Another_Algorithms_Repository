#include<iostream>
using namespace std;

struct node        //Create a new struct
{
  int val;
  node* next;
};

int main()
{
	node* n;
	node* t;
	node* s;

	n = new node;// It basically creates a new node and makes n point there
	n->val=10;    // set the value to the newly created Node1
	t=n;         // Point the temp 't' to Node1
	s=n;	     // Point the start 's' to the Node1

	n= new node; // Creates a new Node2 and makes n to point there, notice t still points to Node1
	n->val = 2;  // Set value to the Node2
	t->next = n; // As t still points to Node1, we change the value 'next' of Node1 to address of Node2
	t = n;	     // Makes t point to Node2

	n = new node;
	n->val = 3;
	t->next = n;
	n->next = NULL;

	node* access = s->next; //access now points to Node 2

	cout<<"The value at node 1 is "<<s->val<<endl;
	cout<<"The address stored in node 1 is "<<s->next<<endl;
	cout<<"The value in node 2 is "<< access->val<<endl;
	access = access->next;
	cout<<"The value in node 3 is "<<access->val<<endl;


	return 0;
}
