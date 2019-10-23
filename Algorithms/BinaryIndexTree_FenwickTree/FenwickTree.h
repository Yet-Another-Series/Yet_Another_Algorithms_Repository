#include <iostream> 
using namespace std; 

int getSum(int fenwickTree[], int index) 
{ 
	int sum = 0;
	index = index + 1; 
	while (index>0) 
	{ 
		sum += fenwickTree[index]; 
		index -= index & (-index); 
	} 
	return sum; 
} 

void updateFenwickTree(int fenwickTree[], int n, int index, int val) 
{ 
	index = index + 1; 
	while (index <= n) 
	{ 
	fenwickTree[index] += val; 
	index += index & (-index); 
	} 
} 

int *constructfenwickTree(int arr[], int n) 
{ 
	int *fenwickTree = new int[n+1]; 
	for (int i=1; i<=n; i++) 
		fenwickTree[i] = 0; 
	for (int i=0; i<n; i++) 
		updateFenwickTree(fenwickTree, n, i, arr[i]); 
	return fenwickTree; 
} 

int main() 
{ 
  	cout << "Enter the size of Fenwick Tree\n";
  	int sizeOfFenwickTree, indexForSum;
  	cin >> sizeOfFenwickTree;
	int freq[100];
	for(int i=0; i<sizeOfFenwickTree; i++){
		cin >> freq[i];
	}
  	cout << "Enter the index upto which sum is to be calculated\n";
  	cin >> indexForSum; 
	int n = sizeof(freq)/sizeof(freq[0]); 
	int *fenwickTree = constructfenwickTree(freq, n); 
  	cout << "Below is the constructed Binary Tree\n";
  	for (int i=1; i<=n; i++) 
		 cout << fenwickTree[i] << " ";
	cout << "\nSum of elements for the given index is: "
		<< getSum(fenwickTree, indexForSum);

	return 0; 
}