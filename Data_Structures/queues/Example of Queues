#include<iostream>
using namespace std;

/*
 * Queue follows the following policy:
 * First In and last out:
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

class Queue{
public:
  Box *head;

  Queue()
  {
    head = NULL;
  }

  void enqueue(int x)
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

  void dequeue()
  {
    if(head == NULL)
    {
      cout<<"Empty Queue: Nothing to Remove"<<endl;
    }
    else
    {
      Box *remover, *replace;
      remover = replace = head;
      while(remover->next != NULL)
      {
        replace = remover;
        remover = remover->next;
      }
      replace->next = NULL;
      cout<<"Deleting: "<<remover->value<<endl;
      cout<<"Value Deleted"<<endl;
      delete remover;
    }
  }

  void printContents()
  {
    if(head == NULL)
    {
      cout<<"No Contents in Queue"<<endl;
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
  Queue Q;
  int choice, value;

  while(1)
  {
    cout<<"Press a to Enqueue"<<endl;
    cout<<"Press b to Dequeue"<<endl;
    cout<<"Press c to Print Contents"<<endl;
    cin>>choice;

    switch(choice)
    {
      case a :  cout<<endl;
                cout<<"Input a integer"<<endl;
                cin>>value;
                Q.enqueue(value);
                cout<< endl;
                break;

      case b :  cout<<endl;
                Q.dequeue();
                cout<<endl;
                break;

      case c :  cout<<endl;
                cout<<"Here are all the values in the Queue"<<endl;
                Q.printContents();
                cout<<endl;
                break;
    }
  }
  return 1;
}
