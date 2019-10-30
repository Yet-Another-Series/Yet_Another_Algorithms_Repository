import java.math.*;
import java.util.*;
import java.io.*;

public class java_ArrayList<E>
{
	public static void main(String[] args) {
		java_ArrayList<Integer> list = new java_ArrayList<>();
		int[] ary = {1,5,3,6,2,3,4,5,8,6,1};
		for(int k : ary) list.add(k);
		System.out.println(list.toString());
	}


	private int DEFAULT_CAPACITY = 10;

    Object[] elementData;

    private int size, capacity;

    public java_ArrayList() {
    	this.elementData = new Object[DEFAULT_CAPACITY];
    	capacity = DEFAULT_CAPACITY;
    }

    public java_ArrayList(int initialCapacity) {
        if (initialCapacity > 0) {
            this.elementData = new Object[initialCapacity];
            capacity = initialCapacity;
        } else {
            throw new IllegalArgumentException("Illegal Capacity: "+
                                               initialCapacity);
        }
    }


    private void grow() {
        // overflow-conscious code
        int oldSize = capacity,	
        	newSize = oldSize << 1;
        Object[] elementDataCopy = new Object[newSize];
        for(int i = 0; i < oldSize; i++) 
        	elementDataCopy[i] = elementData[i];
        elementData = elementDataCopy;
        capacity = newSize;
    }


    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }



    public E get(int index) {
        return (E) elementData[index];
    }

    public void set(int index, E element) {
        while(index >= size) grow();
        elementData[index] = element;
    }

    public boolean add(E e) {
    	if(size + 1 <= capacity) grow();
        elementData[size++] = e;
        return true;
    }

    public void add(int index, E element) {
    	while(index >= size) grow();
    	for(int i = size - 1; i > index; i--) elementData[i] = elementData[i - 1];
    	elementData[index] = element;
    	size++;
    }

    public E remove(int index) {
        if(index >= size) return null;

        E oldValue = get(index);

        for(int i = index; i < size - 1; i++) elementData[i] = elementData[i + 1];
        elementData[--size] = null; // clear to let GC do its work

        return oldValue;
    }

    public void clear() {
        // clear to let GC do its work
        for (int i = 0; i < size; i++)
            elementData[i] = null;

        size = 0;
    }

    public String toString() {
    	return Arrays.toString(Arrays.copyOfRange(elementData, 0, size));
    }

}
