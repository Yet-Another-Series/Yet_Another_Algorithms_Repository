#include<iostream.h>
#include<conio.h>
int rear=-1,front=-1;
int a[21],op,n,c,b;
void insertqueue(int r);
void deletequeue();
void displayqueue();
void main()
{
	clrscr();

	cout<<"\nEnter the max size:";
	cin>>n;
	//front=n;
	do
	{
	cout<<"\n1.insert 2.delete 3. display ";
	cout<<"\nEnter your option:";
	cin>>op;

	switch(op)
	{
		case 1: cout<<"\nEnter element to be inserted:";
			cin>>b;
			insertqueue(b);
			break;
		case 2: ++front;
			deletequeue();
			break;
		case 3: displayqueue();
			break;

	}
	cout<<"\nDo you want to continue? press 1:";
	cin>>c;
	}while(c==1);
	getch();
}
	void insertqueue(int e)
	{
	  int item=e;
	  if(rear>=n)
	  {	cout<<"\nqueue is full:";
	  }
	  else
	  {
		rear=rear+1;
		a[rear]=item;
	  }
	}
	void deletequeue()
	{
		if(front==-1)
		{
			cout<<"\nqueue is empty ";
		}
		else
		{
		       //	front=front+1;
			int item=a[front];
			cout<<"\ndeleted item :"<<item;
		}
	}
	void displayqueue()
	{
		if(front==-1&&rear==-1)
		{
			cout<<"\nqueue is empty";
		}
		else
		{
			cout<<"\nElements in the queue are:";
			for(int i=front+1;i<=rear;i++)
			{
				cout<<a[i];
				cout<<"\t";
			}
		}
	}






