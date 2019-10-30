#include<stdio.h>

int recFibonacci(int n)
{
    if(n==0)
    {   printf("-----------\n\n");
        printf("%d. 0\n",n);
        return 0;
    }
    else
    {
        if(n==1)
        {
            printf("%d. 1\n",n);
            return 1;
        }
        else
        {
            int result = recFibonacci(n-2) + recFibonacci(n-1);
            printf("%d. %d\n",n,result);
            return result;
        }
    }
}


int main()
{
    int n;

    printf("Insert the number of elements: \n");
    scanf("%ld",&n);

    n = recFibonacci(n);

    printf("--- %d ---",n);
}


