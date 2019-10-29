
#include <stdio.h> 
#include <string.h> 
  
// To return value of a char. For example, 2 is 
// returned for '2'.  10 is returned for 'A', 11 
// for 'B' 
int val(char c) 
{ 
    if (c >= '0' && c <= '9') 
        return (int)c - '0'; 
    else
        return (int)c - 'A' + 10; 
} 
  
// Function to convert a number from given base 'b' 
// to decimal 
int toDeci(char *str, int base) 
{ 
    int len = strlen(str); 
    int power = 1; // Initialize power of base 
    int num = 0;  // Initialize result 
    int i; 
  
    // Decimal equivalent is str[len-1]*1 + 
    // str[len-1]*base + str[len-1]*(base^2) + ... 
    for (i = len - 1; i >= 0; i--) 
    { 
        // A digit in input number must be 
        // less than number's base 
        if (val(str[i]) >= base) 
        { 
           printf("Invalid Number"); 
           return -1; 
        } 
  
        num += val(str[i]) * power; 
        power = power * base; 
    } 
  
    return num; 
} 
  
// Driver code 
int main() 
{ 
    char str[] = "11A"; 
    int base = 16; 
    printf("Decimal equivalent of %s in base %d is "
           " %d\n", str, base, toDeci(str, base)); 
    return 0; 
}

