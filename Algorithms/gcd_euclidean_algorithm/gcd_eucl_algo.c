#include<stdio.h>
long long int gcd(long long int a, long long int b) {
    return gcd(b,a%b);
}
int main() {
    long long int a=0,b=0, c=0;
    printf("Enter the 2 natural numbers(>=1)\n");
    scanf(" %lld %lld",&a,&b);
    c = gcd(a,b);
    printf("GCD of %lld & %lld = %lld\n",a,b,gcd(a,b));
}
