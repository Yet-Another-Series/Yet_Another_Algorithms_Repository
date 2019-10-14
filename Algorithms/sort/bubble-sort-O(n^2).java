import java.util.Arrays;
import java.util.Scanner;

class BubbleSort {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Please enter array of Integers, separated by \" \".");

    // read stdin
    String input = sc.nextLine();

    // parse
    String[] strArr = input.split(" ");
    int[] numArr = new int[strArr.length];
    for (int i = 0; i < numArr.length; i++) {
      numArr[i] = Integer.parseInt(strArr[i]);
    }

    // run Bubble Sort algorithm
    boolean needSorting = true;
    while (needSorting) {
      boolean swapPerformed = false;

      // start at 1st index, look backwards
      for (int i = 1; i < numArr.length; i++) {
        if (numArr[i] < numArr[i - 1]) {
          // swap needed

          // store previous int
          int prevNum = numArr[i - 1];

          numArr[i - 1] = numArr[i];
          numArr[i] = prevNum;

          swapPerformed = true;
        }
      }

      if (!swapPerformed) {
        needSorting = false;
      }
    }

    System.out.println(Arrays.toString(numArr));
  }
}