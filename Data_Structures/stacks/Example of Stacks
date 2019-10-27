#include<iostream>
using namespace std;

/*
 * The policy of a Stack is Last In First Out. Add first and delete last
*/

class Box{
public:
  int value = 0;
  Box *next;

  Box()
  {
    value = 0;
    next = NULL;
  }
};

class Stack{
public:
  Box *head;

  Stack()
  {
    head = NULL;
  }

  void push(int x)
  {
    if(head == NULL)
    {
      head = new Box;
      head->value = x;
    }
    else
    {
      Box *helper = new Box;
      helper->value = x;
      helper->next = head;
      head = helper;
    }

  }

  void pop()
  {
    if(head == NULL)
    {
      cout<<"Empty Stack: Nothing To Remove"<<endl;
    }
    else
    {
      Box *remover;
      remover = head;
      head = head->next;
      cout<<"Deleting: "<<remover->value<<endl;
      cout<<"Value Deleted"<<endl;
      delete remover;
    }

  }

  void displayContents()
  {
    if(head == NULL)
    {
      cout<<"No Contents In Stack"<<endl;
    }
    else
    {
      Box *print;
      print = head;
      while(print != NULL)
      {
        cout<<print->value<<endl;
        print = print->next;
      }
    }

  }
};

int main()
{
  Stack S;
  int choice, value;

while(1)
{
  cout<<"Press 1 to Add To Stack"<<endl;
  cout<<"Press 2 to Delete From Stack"<<endl;
  cout<<"Press 3 to Print Contents"<<endl;
  cin>>choice;
  switch(choice)
  {
    case 1 :  cout<<endl;
              cout<<"Input a integer"<<endl;
              cin>>value;
              S.push(value);
              cout<<endl;
              break;

    case 2 :  cout<<endl;
              S.pop();
              cout<<endl;
              break;

    case 3 :  cout<<endl;
              cout<<"Here are all the values in the Stack"<<endl;
              S.displayContents();
              cout<<endl;
              break;
  }
}
  return 1;
}
