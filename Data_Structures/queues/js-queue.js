class Queue {
  constructor(...elements) {
    // State to hold the queue elements
    this._elements = [];
    // Init the queue using the initial arguments
    this.enqueue(...elements);
  }
  /**
   * @function enqueue
   * @param  {any} elements: the items to enqueue
   */
  enqueue(...elements) {
    this._elements = [...this._elements, ...elements];
  }
  /**
   * @function dequeue
   * @return {any}, Dequeues an item and returns it. If the queue is empty, returns null
   */
  dequeue() {
    return this.empty() ? null :this._elements.shift();
  }
  /**
   * @function keyFront
   * @return {any} ,Returns the first element in the queue. If the queue is empty, returns null
   */
  keyFront() {
    return this.empty() ? null : this._elements[0];
  }
  /**
   * @function empty
   * @return {Boolean}, true if the queue is empty, and false otherwise
   */
  empty() {
    return this._elements.length === 0;
  }
  /**
   * @function disp
   * @return {None} Displays the elements in the queue
   */
  disp() {
    console.log(this._elements);
  }
  /**
   * @function getLength
   * @return {Number} Returns the number of elements in the queue
   */
  getLength() {
    return this._elements.length;
  }
}