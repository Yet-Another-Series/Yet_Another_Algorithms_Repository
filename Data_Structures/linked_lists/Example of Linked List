#include<iostream>
using namespace std;

/*
 * Partner: Ryan Henley
 * I pledge my honor that I have abided  by the Stevens Honor System X Justin John
 * Can add anywhere and can delete anywhere
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

class LinkList{
public:
  Box *head;
  int count;

  LinkList()
  {
    count = 0;
    head = NULL;
  }

  void insertAtHead(int x)
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
    count++;
  }

  void insertAtPosition(int position, int x)
  {
    if(position>0 && position <= count + 1)
    {
      Box *helper = new Box;
      helper->value = x;

      if(position == 1)
      {
        helper->next = head;
        head = helper;
      }
      else if(position == count+1)
      {
        Box *anotherH = this->head;
        for(int i = 1;i<count;i++)
        {
          anotherH = anotherH->next;
        }
        anotherH->next = helper;
      }
      else
      {
        Box *anotherH = head;
        for(int i = 1;i < position-1;i++)
        {
          anotherH = anotherH->next;
        }
        helper->next = anotherH->next;
        anotherH->next = helper;
      }
      count++;
    }
    else
    {
      cout<<"Invalid Position: Can Not Insert"<<endl;
    }

  }

  void removeFromPosition(int position)
  {
    if(position > 0 && position <= count)
    {
      if(position == 1)
      {
        Box *remover;
        remover = head;
        head = head->next;
        cout<<"Deleting: "<<remover->value<<endl;
        cout<<"Value Deleted"<<endl;
        delete remover;
      }
      else if(position == count)
      {
        Box *replacer, *remover;
        replacer = remover = head;
        while(remover->next != NULL)
        {
          replacer = remover;
          remover = remover->next;
        }
        replacer->next = NULL;
        cout<<"Deleting: "<<remover->value<<endl;
        cout<<"Value Deleted"<<endl;
        delete remover;
      }
      else
      {
        Box *rembefore, *remafter;
        rembefore = remafter = head;
        for(int i = 1;i < position;i++)
        {
          rembefore = remafter;
          remafter = remafter->next;
        }
        rembefore->next = remafter->next;
        cout<<"Deleting: "<<remafter->value<<endl;
        cout<<"Value Deleted"<<endl;
        delete remafter;
      }
      count--;
    }
    else
    {
      cout<<"Invalid Position: Can Not Delete"<<endl;
    }
  }

  void Display()
  {
    if(head == NULL)
    {
      cout<< "No Content In Link List"<<endl;
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
  LinkList ll;
  int choice, position, value;

  while(1)
  {
    cout<<"Press 1 to Add to Linked List"<<endl;
    cout<<"Press 2 to Add at Specific Position"<<endl;
    cout<<"Press 3 to Delete from Linked List"<<endl;
    cout<<"Press 4 to Print Contents"<<endl;
    cout<<"Press 5 to Print Number of Counts"<<endl;
    cin>>choice;

    switch(choice)
    {
      case 1 :  cout<<endl;
                cout<<"Input a Value"<<endl;
                cin>>value;
                cout<<endl;
                ll.insertAtHead(value);
                cout<<endl;
                break;

      case 2 :  cout<<endl;
                cout<<"Input a Position"<<endl;
                cin>>position;
                cout<<endl;
                cout<<"Input a Value"<<endl;
                cin>>value;
                cout<<endl;
                ll.insertAtPosition(position,value);
                cout<<endl;
                break;

      case 3 :  cout<<endl;
                cout<<"Input a Position"<<endl;
                cin>>position;
                cout<<endl;
                ll.removeFromPosition(position);
                cout<<endl;
                break;

      case 4 :  cout<<endl;
                cout<<"Here are all the values in the Stack"<<endl;
                ll.Display();
                cout<<endl;
                break;

      case 5 :  cout<<endl;
                cout<<"Here is the count of the Linkedlist (count)"<<endl;
                cout<<ll.count<<endl;
                cout<<endl;
                break;
    }
  }

  return 1;
}
