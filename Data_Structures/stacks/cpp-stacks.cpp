
/*
 * c++-stacks.cpp
 *
 *  Created on: 12 de out de 2019
 *      Author: Luana Brasil Teixeira
 */
#include<iostream>
#include<stack>

using namespace std;

//Function to show stack's elements

void showstack(stack <int> stackExample) {

	//empty(): returns if the stack is empty
	//top(): shows the top element
	//pop(): removes the top element

	/*While the stack isn't empty, print the top element and remove it.
	This way we can print all the elements one by one.*/

    while (!stackExample.empty())
    {
        cout << '\t' << stackExample.top();
        stackExample.pop();
    }

}

//Main

int main () {


	//Declaring a stack

	stack <int> stackExample;

    //push(): adds an element to the top of the stack

    stackExample.push(10);
    stackExample.push(30);
    stackExample.push(20);
    stackExample.push(5);
    stackExample.push(1);

    cout << "The stack is : ";
    showstack(stackExample);
    cout << "\n";

    //size(): returns the size of the stack

    cout << "size: " << stackExample.size() << "\n";
    cout << "top element: " << stackExample.top() << "\n";


    //Removing the top element

    cout << "pop: ";
    stackExample.pop();
    showstack(stackExample);
    cout << "\n";

    return 0;
}

#include<iostream>
#include<assert.h>
using namespace std;
class Stack
{
	private:
		int *stk;
		int top,size;
	public:
		Stack();
		Stack(int);
		void push(int);
		int pop();
		void display();
};
Stack::Stack()
{
	top=size=0;
	stk=NULL;
}
Stack::Stack(int s)
{
	size=s;
	top=0;
	stk=new int[size];
	assert(stk!=NULL);
}
void Stack::push(int d)
{
	if(top==size)
		cout<<"\nStack is full!\n";
	else
	{
		stk[top++]=d;
	}
}
int Stack::pop()
{
	if(top==0)
	{
		cout<<"\nStack is empty!\n";
		return -1;
	}
	else
		return stk[--top];
}

void Stack::display(){
	cout<<"\nElements in stack:\n";
	for(int i = top-1; i >= 0; i--){
		cout<<stk[i]<<endl;
	}
}

int main()
{
	int stackSize;
	cout<<"Enter stack size: ";
	cin>>stackSize;
	Stack s1(stackSize);
	
	while(true){
		cout<<"\nEnter your choice:\n";
		cout<<"1.Push\n";
		cout<<"2.Pop\n";
		cout<<"3.Display\n";
		cout<<"4.Exit\n";
		int choice = 0;
		cin>>choice;
		if(choice==1){
			int num = 0;
			cout<<"\nEnter a number: ";
			cin>>num;
			s1.push(num);
		}else if(choice==2){
			int popNum = s1.pop();
			if(popNum != -1){
				cout<<"\nPopped elements is: ";
				cout<<popNum<<endl;
			}
			
		}else if(choice==3){
			s1.display();
		}else if(choice==4){
			break;
		}
	}
}