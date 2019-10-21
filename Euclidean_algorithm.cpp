#include<bits/stdc++.h>
using namespace std;
//this function will return gcd of two number;
int gcd(int a, int b)
{
	if(a == 0)			//if 'a' is 0 then it will return 'b'; 
		return b;
	return gcd(b % a, a);	//else if will return gcd(b % a, a);
}
int main()
{
	cout << gcd(10, 15) << endl;
	cout << gcd(36, 60) << endl;
	cout << gcd(15, 37) << endl;
	return 0;
}
