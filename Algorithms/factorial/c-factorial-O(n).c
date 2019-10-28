#include<stdio.h>

int main()
{
	long int inp,pr;
	pr=1;
	
	printf("Please enter an Integer Number ");
	scanf("%ld",&inp);
	
	int i=0;
	
	for (i=1;i<=inp;i++)
	{
		pr*=i;
	}

	printf("The factorial of the number is: %ld \n",pr);

	return 0;
}
