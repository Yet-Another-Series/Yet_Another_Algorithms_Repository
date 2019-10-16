#include<stdio.h> 

// function that find maximum of two numbers 
int max(int a, int b) { 
	return (a > b)? a : b; 
} 

int knapsack(int W, int w[], int V[], int n) 
{
	if (n == 0 || W == 0) 
		return 0; 
	// If weight of the nth item is larger than capacity(W) of Knapsack 
	if (w[n-1] > W) 
		return knapsack(W, w, V, n-1); 
	// Return max(nth item included, nth item not included) 
	else 
		return max( V[n-1] + knapsack(W-w[n-1], w, V, n-1), knapsack(W, w, V, n-1) ); 
} 

// Driver program to test above function 
int main() 
{
	int w[] = {5, 4, 6, 3};  
	int V[] = {10, 40, 30, 50};    
	int  W = 10; 
	int n = 4;
	int Max;

	printf("Details : \n");
	printf("Value\\Profit\tWeight\t\n");
	for (int i = 0; i < n; i++) 
	{ 
		printf("%d\t\t%d\n",V[i],w[i]);
	}

	printf("\n");
	Max = knapsack(W, w, V, n); 
	printf("Maximum profit = %d", Max); 
	return 0; 
} 
