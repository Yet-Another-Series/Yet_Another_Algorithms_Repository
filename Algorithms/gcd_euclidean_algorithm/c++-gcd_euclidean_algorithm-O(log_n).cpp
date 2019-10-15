#include <iostream>
#include <string>

//using recursion
int gcd(int num1, int num2) 
{ 
    if (num1 == 0) 
        return num2;
	
    return gcd(num1%num2, num1); 
} 
  
int main() 
{ 
	//test:
    int a = 10;
	int b = 20; 
    printf("gcd of (%d, %d) is %d", a, b, gcd(a, b)); 
    
    return 0; 
} 