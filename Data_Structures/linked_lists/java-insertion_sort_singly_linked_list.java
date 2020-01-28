//Insertion Sort Singly Linked List 
class LLInsertionSort 
{ 
    node head; 
    node sorted; 

    // Linked List Node
    class node 
    { 
        int val; 
        node next; 

        public node(int val) 
        { 
            this.val = val; 
        } 
    } 

    void insert(int val) 
    { 
        node newnode = new node(val); 
        newnode.next = head; 
        head = newnode; 
    } 

    // function to sort a singly linked list using insertion sort 
    void insertionSort(node headref) 
    { 
        sorted = null; 
        node current = headref; 
        while (current != null) 
        { 
            node next = current.next; 
            sortedInsert(current); 
            current = next; 
        } 
        head = sorted; 
    } 

    // Function to insert a given node in a sorted linked list 
    void sortedInsert(node newnode) 
    { 
        if (sorted == null || sorted.val >= newnode.val) 
        { 
            newnode.next = sorted; 
            sorted = newnode; 
        } 
        else
        { 
            node current = sorted; 
            while (current.next != null && current.next.val < newnode.val) 
            { 
                current = current.next; 
            } 
            newnode.next = current.next; 
            current.next = newnode; 
        } 
    } 

    // Function to print linked list
    void print(node head) 
    { 
        while (head != null) 
        { 
            System.out.print(head.val + " "); 
            head = head.next; 
        } 
    } 
    
    public static void main(String[] args) 
    { 
        LLInsertionSort list = new LLInsertionSort(); 

        list.insert(7); 
        list.insert(22); 
        list.insert(9); 
        list.insert(32); 

        System.out.println("Linked List before Sorting.."); 
        list.print(list.head); 
        list.insertionSort(list.head); 
        System.out.println("\nLinkedList After sorting"); 
        list.print(list.head); 
    } 
} 
