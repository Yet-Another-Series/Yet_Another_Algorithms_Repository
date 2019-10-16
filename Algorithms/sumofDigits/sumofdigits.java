import java.util.Scanner;

class Solution
{
    public static void main(String[] args) {
        System.out.println("Enter the number till you want to sum");
        Scanner obj=new Scanner(System.in);
        int a=obj.nextInt();
        int sum=0;
        for(int i=1;i<a;i++){
            sum+=i;
        }
        System.out.println(sum);
    }
}