
package queueimplemetation;

/**
 *
 * @author Salman Ahmad
 */
public class QueueImplemetation {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Queue queue=new Queue();
        for (int i=0;i<10;i++){
            queue.add(i);
        }
        int value=queue.elementAt(5);
        if(value!=-1){
            System.out.println("Value at index 5 is: "+String.valueOf(value));
        }
        System.out.println("Before removing ");
        for (int i=0;i<queue.size();i++){
            System.out.println("Value at index "+String.valueOf(i)+" is: "+String.valueOf(queue.elementAt(i)));
        }
        System.out.println("After removing ");
        queue.remove();
        for (int i=0;i<queue.size();i++){
            System.out.println("Value at index "+String.valueOf(i)+" is: "+String.valueOf(queue.elementAt(i)));
        }

    }
    
}
