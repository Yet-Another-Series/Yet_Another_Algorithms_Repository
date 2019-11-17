import org.jetbrains.annotations.NotNull;

import java.util.Arrays;

public class shellSort {
    public static void ShellSort(int[] a)
    {
        //break out of function if array is null
        if(a == null)
        {
            return;
        }
        int n = a.length;
        //start with a reasonable gap
        int gap = n/2;

        //keep going until there is no more gap
        while(gap > 0)
        {
        for(int i = gap; i < n;i++)
        {
            //add a[i] to the elements that have been gap sorted and save a[i] to temp
            //make the gap at i

            int temp = a[i];
            int j = i;

            //shift previously sorted elements forward until the correct position is found.
            while(j >= gap && a[j-gap] > temp)
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            //place temp in its correct location
            a[j] = temp;
        }
            //reduce our gap until we hit zero
            gap /= 2;
        }
        //print out the sorted array
        System.out.println(Arrays.toString(a));
    }
    public static void main(String[] args)
    {
        int[] test = {1,4,345,-3,0,73,50,8,2};
        shellSort.ShellSort(test);


    }

}
