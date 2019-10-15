/*
    Bubble sort
    author : Sameer Saini
 */

import java.util.Scanner;

public class BubbleSort {
    static Scanner in = new Scanner(System.in);
    public static void main(String args[]){
        int a[];
        a = new int[11];
        System.out.print("enter values: ");
        for(int i=0;i<10;++i){
            a[i] = in.nextInt();
        }
        for(int i=0;i<10;++i){
            for (int j = 0; j < (10 - i); ++j)  {
                if(a[j]>a[j+1]){
                    a[j] = a[j] + a[j + 1];
                    a[j + 1] = a[j] - a[j + 1];
                    a[j] = a[j] - a[j + 1];
                }
            }
           //System.out.print(a[i]+" ");
        }
        System.out.println("\n sorted array:  ");
        for(int i=0;i<11;++i){
            System.out.print(a[i]+" ");
        }
    }
}
