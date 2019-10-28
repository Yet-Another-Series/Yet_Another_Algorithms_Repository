#include < iostream >

int GCD(int A, int B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}

int main( ) {
int g=GCD(16, 10);
cout << ”The GCD of 16 and 10 is ” << g << endl;
return 0;   
}
