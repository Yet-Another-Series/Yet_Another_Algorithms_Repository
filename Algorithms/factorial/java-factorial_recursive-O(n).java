import java.util.Scanner;

public class Main
{
  public static int recursiveFact(int a){
  
  if(a==0){ return 1; }
  else {
  int result = recursiveFact(a-1)*a;
  return result;}
  
  }
  
	public static void main(String[] args) 
	{
	    Scanner sc = new Scanner(System.in);
	    int pr=1;
	    
		  System.out.print("Please input an Integer number: ");
		
      int inp = sc.nextInt();
      int result = recursiveFact(inp);
 
		  System.out.println("The factorial of the given number is: "+result);

	}
}
