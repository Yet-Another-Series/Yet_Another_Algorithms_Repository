
public class Main {
    public static void main(String[] args){
        int a = 1;
        int b = 1;
        int n = 5;
        int i = 2;
        int result = 0;

        if (n <= 1) {
            result = 1;
        } else {
            while (i <= n) {
                result = a + b;
                a = b;
                b = result;
                i++;
            }
        }
        System.out.println(result);
    }
}
