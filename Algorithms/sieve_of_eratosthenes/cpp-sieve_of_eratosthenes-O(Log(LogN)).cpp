#include<iostream>
using namespace std;

void sieve_of_eratosthenes(int n){
	bool* check = new bool[n+1];
    for (int i = 2; i <= n; i++) check[i] = true;
    for (int i = 2; i <= n; i++){
        if (check[i]){
            cout << i << " ";
            int j = 2;
            while ( i*j <= n ){
                check[i*j] = false;
                j++;
            }
        }
    }
}


int main(){
	int n;
	cin >> n;
	sieve_of_eratosthenes(n);
	cout << endl;
}
		
