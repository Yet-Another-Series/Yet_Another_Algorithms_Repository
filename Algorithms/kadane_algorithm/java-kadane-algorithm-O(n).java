import java.lang.Math;
import java.util.Scanner;

class KadaneAlgorithm {
    /**
     * Kadane Algorithm
     * @param array an array of integers
     * @return the largest possible sum of a contiguous subarray of the input array
     */
    public static int kadane(int[] array){
        int maxSoFar = array[0];
        int currentMax = array[0];
        for (int i=1; i<array.length; i++){
            currentMax = Math.max(array[i], currentMax + array[i]);
            maxSoFar = Math.max(maxSoFar, currentMax);
        }
        return maxSoFar;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter array of Integers, separated by \" \" (space).");

        // read stdin
        String input = sc.nextLine();

        // parse
        String[] strArr = input.split(" ");
        int[] numArray = new int[strArr.length];
        for (int i = 0; i < numArray.length; i++) {
            numArray[i] = Integer.parseInt(strArr[i]);
        }

        // run Kadane algorithm
        int maxSubArraySum = kadane(numArray);

        System.out.println("The largest possible sum of a contiguous subarray of the input array equals " + maxSubArraySum);
    }
}