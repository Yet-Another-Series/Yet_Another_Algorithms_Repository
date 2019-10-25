package main;

import java.lang.Math;

public class LinearSearch {
	
	/***
	 * Function to find 
	 * @param array
	 * @param waldo
	 * @return
	 */
	public static int linear_search(int[] array, int waldo) {
		System.out.println("Searching for: " + waldo + "\n");
		
		for (int i = 0; i < array.length; i ++) 
			if (array[i] == waldo)
				return i;

		
		return -1;
	}
	
	public static void main (String[] args) {
		int[] array = {74, 23, 57, 86, 40, 33, 17, 69};
		
		int waldo = (int) (Math.random() * 100 + 1),
				index = linear_search(array, waldo);
		
		if(index > -1)
			System.out.println(waldo + " is at index " + index);
		else 
			System.out.println(waldo + " cannot be found");
		
		
		
		return;
	}
}
