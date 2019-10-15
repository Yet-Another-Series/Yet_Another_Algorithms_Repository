#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;


 struct node
     {
         int value;
         node* next;
     };
node* first=NULL;
node* last=NULL;



void Enqueue(int val)
    {
        node* temp=new node();
        temp->value=val;
        temp->next=NULL;
        if(first==NULL&&last==NULL)
        {
            first=temp;
            last=temp;
        }
        else
        {
            last->next=temp;
            last=temp;
        }
    }


bool IsEmpty()
{
    if(first==NULL)
        return true;
    else
        return false;
}


void Dequeue()
{
    if(IsEmpty()==true)
        cout<<"Underflow!\n";
    else if(first==last)
    {
        first=NULL;
        last=NULL;
    }
    else
    {
        node* temp=first;
        first=first->next;
        delete temp;
    }
}



void Front()
{
     if(IsEmpty()==true)
        cout<<"Underflow!\n";
        else
            {

        cout<<first->value<<endl;
            }
}



void Display()
{
    if(IsEmpty()==true)
        cout<<"Underflow!\n";
    else
        {

            node* temp=first;
            while(temp!=NULL)
            {
                cout<<temp->value;
                cout<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
}


int main()
{

    int x=0,value;
    bool a;
    while(x!=6)
    {
        cout<<"1. Enqueue\n2. Dequeue\n3. Check empty\n4. Show front\n5. Display queue\n6. Exit\nEnter your choice:";
        cin>>x;
        switch(x)
        {
            case 1: cout<<"Value to enqueue:";
                    cin>>value;
                    Enqueue(value);
                    break;
            case 2 : Dequeue();
                     break;
            case 3: a=IsEmpty();
                    if(a==true)
                        cout<<"Queue is empty\n";
                    else
                        cout<<"Queue is not empty\n";
                    getch();
                    break;
            case 4: Front();
                    getch();
                    break;
            case 5: Display();
                    getch();
                    break;
            case 6: exit(0);
        }
    }
return 0;
}
