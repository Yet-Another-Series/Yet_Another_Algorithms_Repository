import java.io.*;
public class Main
{
	public static void main(String[] args)throws Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int A[] = {21, 25, 76, 33, 10, 60, 45,103, 44, 331};
		System.out.println("Enter the number to be searched.");
		int x = Integer.parseInt(br.readLine());
		int flag = 0;
		for(int i = 0; i < 10; i++)
		{
		    if(A[i] == x)
		    {
		        System.out.println("Your number is found at position " + (i + 1));
		        flag = 1;
		        break;
		    }
		}
		if(flag == 0)
		{
		    System.out.println("Number not found");
		}
	}
}
