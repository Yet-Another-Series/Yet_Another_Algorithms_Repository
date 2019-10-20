import java.util.Arrays;

public class Anagram{
	
	public static boolean checkAnagram(String s1,String s2) {
		char[] charArray1 = s1.toCharArray();
		char[] charArray2 = s2.toCharArray();
		
		Arrays.parallelSort(charArray1);
		Arrays.parallelSort(charArray2);
		
		for(int  i=0;i<s1.length();i++) {
			if(charArray1[i] !=  charArray2[i])
				return false;
		}
		return true;
	}
	public static void main(String args[]) {
		boolean isAnagram = checkAnagram("hello","elloh");
		if(isAnagram == true)
			System.out.println("The Strings are Anagram");
		else
			System.out.println("The Strings are not Anagram");
	}
}
