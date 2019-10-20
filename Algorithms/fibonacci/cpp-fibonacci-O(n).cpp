#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter how many fibonacci number you want to see:";
    cin>>n;
    int a=0,b=1,sum;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            cout<<a<<" ";
        }
        else if(i==2)
        {
            cout<<b<<" ";
        }
        else
            {
                sum=a+b;
                a=b;
                b=sum;
                cout<<sum<<" ";
            }
    }
    return 0;

}

