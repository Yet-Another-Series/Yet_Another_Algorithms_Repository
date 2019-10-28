import java.util.*;
import java.io.*;

/**
Implements a max heap with integer elements
*/
public class java_Integer_PriorityQueue {

	int[] ary;

	int defaultCapacity = 10, size = 0, capacity;

	public static void main(String[] args) {
		java_Integer_PriorityQueue q = new java_Integer_PriorityQueue();
		int[] ary = {3,5,2,1,4,67,35,25};
		for(int k : ary) { 
			q.offer(k);
			System.out.println(q.toString());
		}
		while(!q.isEmpty()) {
			System.out.println(q.poll());
		}
	}


	public java_Integer_PriorityQueue() {
		this.ary = new int[defaultCapacity];
		capacity = defaultCapacity;
	}

	public java_Integer_PriorityQueue(int initialCapacity) {
		if(initialCapacity < 1) throw new IllegalArgumentException();
		this.ary = new int[initialCapacity];
		capacity = initialCapacity;
	}

	public int size() {return size;}

	public boolean isEmpty() {
		return size == 0;
	}

	private void grow() {
		// doubles ary size
		int nextCap = capacity << 1;
		int[] copy = new int[nextCap];
		for(int i = 0; i < capacity; i++)
			copy[i] = ary[i];
		ary = copy;
		capacity = nextCap;
	}

	public void offer(int element) {
		insert(element);
	}

	public String toString() {
		return Arrays.toString(Arrays.copyOfRange(ary, 0, size));
	}

	public void insert(int element) {
		if(size + 1 == capacity) grow();
		ary[size] = element;
		siftUp(size, element);
		size++;
	}

	public int poll() {
		int res = ary[0];
		ary[0] = ary[size - 1];
		size--;
		siftDown();
		return res;
	}

	private void siftUp(int k, int val) {
		while(k > 0) {
			int parent = (k - 1) / 2;
			if(ary[parent] > val) break;
			ary[k] = ary[parent];
			k = parent;
		}
		ary[k] = val;
	}


	private void siftDown() {
		int k = 0, val = ary[0];
		while(k < size / 2) {
			int c1 = k * 2 + 1,
				c2 = k * 2 + 2,
				v1 = ary[c1],
				v2 = ary[c2],
				c = v1 > v2 ? c1 : c2,
				v = v1 > v2 ? v1 : v2;
			if(val >= ary[c]) break;
			ary[k] = v;
			k = c;
		}
		ary[k] = val;
	}
}