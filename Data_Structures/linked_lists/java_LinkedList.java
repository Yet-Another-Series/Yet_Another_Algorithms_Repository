import java.io.*;
import java.util.*;

public class java_LinkedList<E>
{

	static public void main(String[] args) {
		int[] ary = {1,2,3,4,5,9,8,7,6};
		int n = ary.length;
		java_LinkedList<Integer> list = new java_LinkedList<>();
		for(int i = n - 1; i >= 0; i--) list.add(ary[i]);
		list.print();
	}


	int size = 0;

	Node<E> first, last;

	public java_LinkedList() {

	}

	public E getFirst() {
		if(first == null) throw new NullPointerException(); 
		return first.elem;
	}

	public E getLast() {
		if(last == null) throw new NullPointerException(); 
		return last.elem;
	}

	public int size() {
		return size;
	}

	public boolean isEmpty() {
		return size == 0;
	}

	public void addFirst(E e) {
		Node<E> f = first;
		Node<E> newNode = new Node<>(null, e, f);
		first = newNode;
		if(f == null) last = newNode;
		else f.prev = newNode;
		size++;
	}

	public E removeFirst() {
		if(first == null) throw new NullPointerException(); 
		E elem = first.elem;
		first = first.next;
		size--;
		return elem;
	}


	public void add(E e) {
		addLast(e);
	}

	public void addLast(E e) {
		Node<E> l = last;
		Node<E> newNode = new Node(l, e, null);
		last = newNode;
		if(l == null) first = newNode;
		else l.next = newNode;
		size++;
	}


	public E removeLast() {
		if(last == null) throw new NullPointerException(); 
		E elem = last.elem;
		last = last.prev;
		size--;
		return elem;
	}

	public void print() {
		Node<E> node = first;
		while(node != null) {
			System.out.println(node.elem);
			node = node.next;
		}		
	}


	private class Node<E> 
	{
		E elem;
		Node<E> prev, next;
		Node(Node prev, E elem, Node next) {
			this.elem = elem;
			this.prev = prev;
			this.next = next;
		}
	}
}