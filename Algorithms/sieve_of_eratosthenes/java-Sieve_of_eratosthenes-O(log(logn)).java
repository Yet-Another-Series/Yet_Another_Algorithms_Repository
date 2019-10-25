/**********************************************************************************
 * Name: Maxwell Ding
 * NetID: m_d339
 * HW: #1 (Part 2)
 * Due Date: 7 / 16 / 2019
 **********************************************************************************/
package primeNumbers;

import java.io.*;
import java.util.*;

public class Primes {
	
	private ArrayList<Integer> primes;
	private int upperBound;
	private String fileName;
	
	/***
	 * Constructor for the Primes class
	 */
	public Primes() {
		primes = new ArrayList<Integer>();
		upperBound = -1;
		fileName = "";
	}
	
	/***
	 * Generates an ArrayList of integers from 2 to the upperBound
	 * @param upperBound the highest integer that can be used
	 * @param fileName the name of the text file to hold all prime numbers up to the upper bound
	 */
	public void createList(int upperBound, String fileName) {
		for(int x = 2; x <= upperBound; x++)
			primes.add(x);
		
		this.upperBound = upperBound;
		this.fileName = fileName + ".txt";
		 System.out.println(primes.toString());
	}
	
	/***
	 * Uses Euler's sieve to determine all primes from 2 to the upper bound
	 */
	public void findPrimes() {
		int base = 2, factor = base * base;

		for(int x = 2; x < this.upperBound; x++) {
			base = x;
			factor = base * base;
			primes.remove(new Integer(factor));
			
			while(factor <= this.upperBound) {
				base++;
				factor = base * x;
				primes.remove(new Integer(factor));	
			}	
		}		
		System.out.println(primes.toString());
	}
	
	/***
	 * Outputs the upper bound and the ArrayList of primes to a text file
	 * @throws IOException error either by accessing file or stream output
	 */
	public void printPrimes() throws IOException{
		File txtFile = new File(this.fileName);
		FileWriter fWriter = new FileWriter(txtFile);
		
		BufferedWriter buffWriter = new BufferedWriter(fWriter);
		try {
		
			buffWriter.write("Upper Bound:    " + upperBound );
			buffWriter.newLine();
			buffWriter.newLine();
			buffWriter.write(primes.toString());
			buffWriter.close();
		}
		catch (IOException ioe) {
			ioe.printStackTrace();
		}
	}
	
	public static void main (String args[]) throws IOException  {
		
		if( args.length <= 2) {
			System.out.println("Invalid number of arguments");
			return;
		}
		
		int upperBound = Integer.parseInt(args[0]);
		String fileName = args[1];
		
		Primes primeHunter = new Primes();
		
		primeHunter.createList(upperBound, fileName);
		primeHunter.findPrimes();
		primeHunter.printPrimes();
	}
}
