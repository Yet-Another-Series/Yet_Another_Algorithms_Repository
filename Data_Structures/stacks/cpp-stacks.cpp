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
