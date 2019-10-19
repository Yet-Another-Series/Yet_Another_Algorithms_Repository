// Java program to demonstrate working of extended 
// Euclidean Algorithm 
  
import java.util.*; 
import java.lang.*; 
  
class Java_gcd_euclidean
{ 
    // extended Euclidean Algorithm 
    public static int gcd(int a, int b) 
    { 
        if (a == 0) 
            return b; 
          
        return gcd(b%a, a); 
    } 
  
// Driver Program 
    public static void main(String[] args) 
    { 
        System.out.println("Enter two numbers: ");
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        Scanner sc2 = new Scanner(System.in);
        int b = sc.nextInt();
        int g = gcd(a, b); 
        System.out.println("GCD(" + a +  " , " + b+ ") = " + g); 
    } 
}