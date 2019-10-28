import java.util.*;
import java.lang.*;
import java.io.*;

public class SlidingWindow {

    public static int maximumSum(int[] elementList, int n, int k ){

        if( n < k ){
            System.out.println("Invalid");
            return -1;
        }

        int maxSum = 0;
        int windowSum = 0;

        for( int i = 0; i < k; i++) {
            maxSum += elementList[i];
        }

        windowSum = maxSum;

        for( int j = k; j < n; j++) {
            windowSum += elementList[j] - elementList[j - k];
            maxSum = Math.max(maxSum, windowSum);
        }

        return maxSum;

    }

    public static void main (String[] args) {

        int[] elements = {1, 4, 2, 10, 2, 3, 1, 0, 20};
        int k = 4;
        int n = elements.length;
        System.out.println(maximumSum(elements, n, k));
        
    }
}
