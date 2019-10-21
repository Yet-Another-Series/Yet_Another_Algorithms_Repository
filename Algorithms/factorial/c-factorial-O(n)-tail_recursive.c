#include <stdio.h>

/*Products are computed before the recursive call. In this way a smart compiler can avoid to maintain the functions in the stack*/
unsigned long recursive_fact_tr(int n, unsigned long f){
    if(n == 0)
    	return f;
    else
        return recursive_fact_tr(n-1,n*f);
}

void main()
{
	int n;
	scanf("%d", &n);
	
    unsigned long res = recursive_fact_tr(n,1);

	printf("%ld\n", res);
}