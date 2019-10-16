package com.jagjit.Hactoberfest;

public class EggDrop {

	private static int eggDrop(int totalEggs, int totalFloors) {

		int[][] dp = new int[totalFloors + 1][totalEggs + 1];

		int step = 0; // Initialize the step = 0;

		while (dp[step][totalEggs] < totalFloors) { // if current step is less than total step
			++step;
			
			//start with the egg 1 and go on when it is equal to totalEggs
			for (int j = 1; j <= totalEggs; ++j)
//				if egg break, we can use (j-1) eggs and (step-1) 
//				if egg isn't broken, we can use k eggs and (step-1) step
				dp[step][j] = dp[step - 1][j - 1] + dp[step - 1][j] + 1;
		}

		return step;
	}

	public static void main(String[] args) {

		int totalEggs = 2, totalFloors = 10;
		System.out.println("Minimum number of trials in worst case with " + totalEggs + "  " + "eggs and " + totalFloors
				+ " floors is " + eggDrop(totalEggs, totalFloors));

	}

}
