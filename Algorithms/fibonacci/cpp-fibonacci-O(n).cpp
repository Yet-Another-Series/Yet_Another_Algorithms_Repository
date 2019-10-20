#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a=0,b=1,sum;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            cout<<a<<" ";
        }
        else if(i==1)
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

