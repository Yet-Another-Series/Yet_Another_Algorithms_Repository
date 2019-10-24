#include<stdio.h>

void sieve_of_eratosthenes(int n){
	int* check = malloc( (n+1)* sizeof(int) );
    for (int i = 2; i <= n; i++) check[i] = 1;
    for (int i = 2; i <= n; i++){
        if (check[i]){
            printf("%d ", i);
            int j = 2;
            while ( i*j <= n ){
                check[i*j] = 0;
                j++;
            }
        }
    }
}

int main()
{
	long int inp,pr;
	pr=1;
	
	printf("Please enter an Integer Number ");
	scanf("%ld",&inp);
	
	sieve_of_eratosthenes(inp);
	printf("\n");

	return 0;
}
