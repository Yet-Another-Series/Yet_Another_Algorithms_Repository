/*
Program to print all prime numbers <= n using sieve of Eratosthenes 
*/

#include <bits/stdc++.h> 
using namespace std; 
  
void SieveOfEratosthenes(int n) { 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    int prime[n+1]; 
    memset(prime, true, (n+1)*sizeof(int)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == 1) 
        { 
            // Update all multiples of p 
            for (int i=p*2; i<=n; i += p) 
                prime[i] = 0; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          cout << p << " "; 
} 
  
int main() { 
    int n;
    cout << "Enter the number: ";
    cin>>n;
    cout << "Primes smaller than or equal to " << n << <<" are:\n";
    SieveOfEratosthenes(n); 
    return 0; 
}
