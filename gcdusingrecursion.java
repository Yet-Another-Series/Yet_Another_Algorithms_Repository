import java.util.*;
 
class mr11
{
 public static void main(String args[])
 {
     int n1,n2,answer=1;
 Scanner sc = new Scanner(System.in);
     System.out.println("Enter 1st no");
     n1=sc.nextInt();
     System.out.println("Enter 2nd no");
     n2=sc.nextInt();    	
 
 answer=gcd(n1,n2);
   System.out.println("GCD("+n1+","+n2+") = "+answer);
 }
 
 static int gcd(int a, int b)
 {
     if(a==0)
         return b;
     else
         return gcd(b%a,a);
 }
}