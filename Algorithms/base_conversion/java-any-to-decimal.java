// Java program to convert 
// a number from any base 
// to decimal 
import java.io.*; 

class ABC
{ 
// To return value of a char. 
// For example, 2 is returned 
// for '2'. 10 is returned 
// for 'A', 11 for 'B' 
static int val(char c) 
{ 
	if (c >= '0' && c <= '9') 
		return (int)c - '0'; 
	else
		return (int)c - 'A' + 10; 
} 

// Function to convert a 
// number from given base 
// 'b' to decimal 
static int toDeci(String str, 
				int base) 
{ 
	int len = str.length(); 
	int power = 1; // Initialize 
				// power of base 
	int num = 0; // Initialize result 
	int i; 

	// Decimal equivalent is 
	// str[len-1]*1 + str[len-1] * 
	// base + str[len-1]*(base^2) + ... 
	for (i = len - 1; i >= 0; i--) 
	{ 
		// A digit in input number 
		// must be less than 
		// number's base 
		if (val(str.charAt(i)) >= base) 
		{ 
		System.out.println("Invalid Number"); 
		return -1; 
		} 

		num += val(str.charAt(i)) * power; 
		power = power * base; 
	} 

	return num; 
} 

// Driver code 
public static void main (String[] args) 
{ 
	String str = "11A"; 
	int base = 16; 
	System.out.println("Decimal equivalent of "+ 
						str + " in base "+ base + 
									" is "+ " "+ 
							toDeci(str, base)); 
} 
} 

