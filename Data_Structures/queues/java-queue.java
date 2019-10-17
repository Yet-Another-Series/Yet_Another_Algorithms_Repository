package queue;

import java.io.IOException;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * Generic type Queue
 * @param <E> Generic type that the queue stores. 
 */
public class Queue <E> {
    
    private LinkedList<E> list; 
    
    Queue(){
        this.list = new LinkedList<>();
    }
    
    /**
    * This method insert a item on the end of the queue.
    * @param info is the item to be enqueued.
    */
    public void enqueue(E info){
        this.list.addLast(info);
    }
    
    /**
    * This method removes a item from the end of the queue.
    * @return the item removed
    * @throws java.io.IOException if the list is Empty.
    */
    public E dequeue() throws IOException{
        E aux;
        if(this.list.isEmpty()){
            throw new IOException("Empty List!");
        }
        aux = this.list.removeFirst();
        return aux;
    }
	
    /**
    * This method returns the first item of the queue,
    * but does not remove it.
    * @return the first item.
    */
    public E peek(){
        return this.list.getFirst();
    }
    
    /**
    * @return the size of the queue.
    */
    public long getSize() {
        return this.list.size();
    }
    
    @Override
    public String toString(){
        return this.list.toString();
    }
    
    /**
     * Just a demonstration of the methods.
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        long size;
        Scanner userInput = new Scanner(System.in);
        
        System.out.println("Insert the size of the queue:");
        size = userInput.nextLong();
        
        Queue queue = new Queue();
        
        for(long i = 0; i < size; i ++){
            queue.enqueue(i);
        }
        try{
        System.out.println(queue);
        System.out.println(queue.dequeue());
        System.out.println(queue);
        System.out.println(queue.peek());
        System.out.println(queue);
        }catch (IOException e){
            System.out.println(e);
        }

    }
}