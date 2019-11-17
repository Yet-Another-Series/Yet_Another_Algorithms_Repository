#include<iostream>
using namespace std;

class factorial
{
	int num;
	int pr;
	public: factorial()
	{
		num = 0;
		pr=1;
	}

	void input()
	{
		cout<<"Please input an Integer number "<<endl;
		cin>>num;
	}
	
	void calculate()
	{
		for(int i=1;i<=num;i++)
		{
			pr*=i;
		}
	}

	void display()
	{
		cout<<"The factorial of the given number is: "<<pr<<endl;
	}
};


int main()
{
	factorial ob;
	ob.input();
	ob.calculate();
	ob.display();
}
		
