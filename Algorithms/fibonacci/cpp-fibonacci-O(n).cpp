#include<iostream>
using namespace std;

class fibonacci
{
	long inp,sum,a,b;

	public: fibonacci()
	{
		
		inp = 0;
		sum = 1;
		a=0;
		b=1;
	}

	void input()
	{
		cout<<"Enter the number of terms you wanna' print upto"<<endl;
		cin>>inp;
	}
	
	void display()
	{
		cout<<a<<" "<<b;
		for (long i=0;i<inp;i++)
		{
			sum = a+b;
			cout<<" "<<sum;
			a=b;
			b=sum;
		}
		cout<<endl;
	}
};

int main()
{
	fibonacci ob;
	ob.input();
	ob.display();
}
