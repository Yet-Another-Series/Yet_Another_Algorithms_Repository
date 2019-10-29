// Java Program to convert decimal to any given base 
import java.lang.*; 
import java.io.*; 
import java.util.*; 

class ABC
{ 
	
// To return char for a value. For 
// example '2' is returned for 2. 
// 'A' is returned for 10. 'B' for 11 
static char reVal(int num) 
{ 
	if (num >= 0 && num <= 9) 
		return (char)(num + 48); 
	else
		return (char)(num - 10 + 65); 
} 

// Function to convert a given decimal number 
// to a base 'base' and 
static String fromDeci(int base1, int inputNum) 
{ 
	String s = ""; 

	// Convert input number is given 
	// base by repeatedly dividing it 
	// by base and taking remainder 
	while (inputNum > 0) 
	{ 
		s += reVal(inputNum % base1); 
		inputNum /= base1; 
	} 
	StringBuilder ix = new StringBuilder(); 

		// append a string into StringBuilder input1 
		ix.append(s); 

	// Reverse the result 
	return new String(ix.reverse()); 
} 

// Driver code 
public static void main (String[] args) 
{ 
	int inputNum = 282, base1 = 16; 
	System.out.println("Equivalent of " + inputNum + 
							" in base "+base1+" is " + 
							fromDeci(base1, inputNum)); 
} 
} 

