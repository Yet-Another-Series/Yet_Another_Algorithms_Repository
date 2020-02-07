import java.util.Arrays;
import java.util.Scanner;

class BubbleSort {

  public static void main(String[] args) {
    int[] numArr = parseStrToIntArr(readLine());
    sort(numArr);
    System.out.println(Arrays.toString(numArr));
  }

  private static String readLine(){
    Scanner sc = new Scanner(System.in);
    System.out.println("Please enter array of Integers, separated by \" \".");
    return sc.nextLine();
  }

  private static int[] parseStrToIntArr(String input){
    String[] strArr = input.split(" ");
    int[] numArr = new int[strArr.length];

    for (int i = 0; i < numArr.length; i++) {
      numArr[i] = Integer.parseInt(strArr[i]);
    }

    return numArr;
  }

  private static boolean isSmallerThanPrevious(int[] arr, int index){
    return (arr[index] < arr[index - 1]);
  }

  private static void swapWithPrevius(int[] arr, int index){
    int prevNum = arr[index - 1];
    arr[index - 1] = arr[index];
    arr[index] = prevNum;
  }

  private static void sort(int[] arr){
    boolean needSorting = true;

    while (needSorting) {

      boolean swapPerformed = false;

      // start at 1st index, look backwards
      for (int i = 1; i < arr.length; i++) {

        if (isSmallerThanPrevious(arr, i)) {
          swapWithPrevius(arr, i);
          swapPerformed = true;
        }

      }

      if (!swapPerformed) {
        needSorting = false;
      }

    }

  }

}
