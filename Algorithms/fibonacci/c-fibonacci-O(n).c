#include<stdio.h>

int main()
{
	long int inp,pr;
	pr=1;
	
	printf("Please enter an Integer Number ");
	scanf("%ld",&inp);
	
	if (inp == 0) printf("0\n");
	else if (inp == 1) printf("0\n1\n");
	else{
		printf("0\n1\n");
		int a = 0, b = 1, i, tmp;
		
		for (i = 2; i <= inp; i++){
			tmp = a+b;
			printf("%d\n", tmp);
			a = b;
			b = tmp;
		}
	}

	return 0;
}
