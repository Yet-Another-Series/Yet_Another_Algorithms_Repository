#include<iostream>
using namespace std;
#define MAX 100 
int* BubbleSort(int *a,int n){
	int i,j,temp;
	for(i=1;i<n;++i)
	{
		for(j=0;j<(n-i);++j)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	}
	return a;
}
int main()
{
	int a[MAX],n,i;
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter the array elements: "; 
	
	for(i=0;i<n;++i)
		cin>>a[i];
		
	BubbleSort(a,n);
	
	cout<<"Array after bubble sort:";
	for(i=0;i<n;++i)
		cout<<" "<<a[i];
		
	return 0;
}
