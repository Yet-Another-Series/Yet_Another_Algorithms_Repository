/* 
Queue_DataStructure implementation using dynamic memory allocation 

Methods : 
	Push(value) - Push value into the Queue
	Pop()       - Delete front element of Queue
	Front()     - Get the front element element
	isEmpty()   - Returns Boolean whether Queue is empty (true) or not (false)
*/

// Class for node with members for value and next node
class Node{
  constructor(v){
    this.val = v;
    this.nxt=null;
  }
}

// Class Queue
class Queue{
  constructor(){
    this.first=null;
    this.last=null;
  }

  // Add element from back
  push(n){
    var newElem = new Node(n);
    if(this.last){
      this.last.nxt = newElem;
      this.last = newElem
    }
    else{
      this.last=newElem;
      this.first=newElem;
    }
  }

  // Delete element from front
  pop(){
    if(this.first){
      this.first = this.first.nxt;
    }
    else
      throw new Error("Queue Empty!");
  }

  // Get front element
  front(){
    if(!this.isEmpty())
      return this.first.val;
    else
      throw new Error("Queue Empty!");
  }

  // Check if Queue is empty
  isEmpty(){
    return !(this.first);
  }

}



// Sample implementation : 



// Create a new Queue
var q = new Queue;

// Push 10, 20 and 30
q.push(10);
q.push(20);
q.push(30);
console.log(q.front()); // Print front element
q.push(40); // Insert 40
q.pop(); // Pop element
console.log(q.front()); // Print front element
// Pop elements
q.pop();
q.pop();
console.log(q.front()); // Print front element
q.pop(); // Pop element
