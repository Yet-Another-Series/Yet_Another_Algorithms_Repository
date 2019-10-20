public class BubbleSorting{
	
	static void bubbleSort(int[] arr) {
		for(int i=0;i< arr.length-1;i++) {
			for(int j=i+1;j< arr.length;j++) {
				if(arr[i] > arr[j]) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	public static void main(String args[]) {
		int[] array = new int[]{10,11,5,7,6,8};
		
		System.out.println("Printing array elements before sorting");
		for(int i=0;i < array.length;i++) {
			System.out.print(array[i] + " ");
		}
		System.out.println();
		bubbleSort(array);
		System.out.println("Printing array elements after sorting");
		for(int i=0;i < array.length;i++) {
			System.out.print(array[i] + " ");
		}
	}
}
