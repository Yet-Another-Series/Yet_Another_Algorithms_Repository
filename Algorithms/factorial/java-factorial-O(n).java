import java.util.Scanner;

public class Main
{
	public static void main(String[] args) 
	{
	    Scanner sc = new Scanner(System.in);
	    int pr=1;
	    
		  System.out.print("Please input an Integer number: ");
		
      int inp = sc.nextInt();
      for(int i=1;i<=inp;i++)
      {
          pr*=i;
      }
		
		  System.out.println("The factorial of the given number is: "+pr);

	}
}
