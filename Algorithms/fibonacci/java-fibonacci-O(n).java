
public class Fibonacci{
	
	public static void printFibonacci(int n) {
		int a = 0;
		int b = 1;
		for(int i=0;i < n;i++) {
			if(i == 0) 
				System.out.print(a+" ");
			else if(i == 1)
				System.out.print(b+" ");
			else {
				int c = a + b;
				System.out.print(c+" ");
				a = b;
				b = c;
			}
		}
	}
	public static void main(String args[]) {
		printFibonacci(10);
	}
}
