public class AnyClass {
	/**
	 * Previous: A list of elements have been initialized
	 * post: the elements are ordenated (in this case i'll use numbers)
	 */
	int[] list;
	
	public void SelectionSort() {
	for(int i= 0 ; i < list.length;i++) {
		//i'll create a module number to be our temporally minimum
		int minimum = 0;
		for(int j = i-- ; j < list.length; j++) {
			if(minimum > list[j]) {
				minimum = list[j];
				list[i] = list[j];
				
			}
		}
	}
	}

}
