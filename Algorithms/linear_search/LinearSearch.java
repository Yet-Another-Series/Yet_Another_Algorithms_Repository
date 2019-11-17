
public class LinearSearch {

	int linearSearch(int arr[],int x) {
		for (int i = 0; i < arr.length; i++) {
			if(arr[i]==x) {
				return i;
			}
		}
		return -1;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinearSearch linearSearch = new LinearSearch();
		int arr[] = {20,65,98,1,4,6,8,1,205,2};
		int x = 1;
		int result = linearSearch.linearSearch(arr, x);
		if(result==-1) {
			System.out.println("Element not present");
		}
		else {
			System.out.println("Element found at index " + result);
		}
	}

}
