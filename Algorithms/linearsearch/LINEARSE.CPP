#include<conio.h>
#include<iostream.h>
void main()
{
	 clrscr();
	 int a[11],n,i,k,flag=0;
	 cout<<"\nEnter the no.of elements:";
	 cin>>n;
	 cout<<"\nEnter the elements:";
	 for(i=0;i<n;i++)
	 {
		cin>>a[i];
	 }
	 cout<<"\nEnter the element to be searched:";
	 cin>>k;
	 for(i=0;i<n;i++)
	 {
		if(a[i]==k)
		{
			cout<<"\nElement found at position:"<<i+1;
			flag=1;
			break;
		}
	 }
	 if(flag==0)
	 {
		cout<<"\n Element not found...";
	 }
	 getch();
}