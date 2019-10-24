import java.util.Scanner;

public class FibonacciSeries {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the limit:");
        int number = sc.nextInt();

        int a = 0;
        int b = 0;
        int c = 1;

        for(int i = 0; i <= number; i++) {
            a = b;
            b = c;
            c = a + b;
            System.out.println(a + "");
        }

    }

}
