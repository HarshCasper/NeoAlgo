/*

A queue is a linear data structure that follows the First in, First out principle (i.e.​ the first added elements are removed first).
Generally, a queue is implemented using Linked List but other approach can be used i.e using two stacks.
Below is the implementation of a queue using a Two Stacks.

In this program, the user can provide a choice to perform operations on a Queue. It is created using an ES6 class syntax. 
prompt & colors are node packages for taking user input and displaying text in different colors respectively. 

*/

const prompt = require("prompt-sync")({ sigint: true });
const colors = require("colors");

// Setting the Color schema
colors.setTheme({
  display: "green",
  insert: "white",
  delete: "red",
  leave: "yellow",
  end: "rainbow",
  wrong: "america",
});

// Creating the node class to create nodes
class Node {
  constructor(value, next = null) {
    this.value = value;
    this.next = next;
  }
}

// Creating stack class
class Stack {
  constructor() {
    this.first = null;
    this.last = null;
    this.length = 0;
  }

  // Add element at the end operation in stack
  push(value, decode) {
    let newNode;
    if (decode) newNode = value;
    else newNode = new Node(value);

    if (this.length === 0) {
      this.first = newNode;
      this.last = newNode;
    } else {
      const temp = this.first;
      this.first = newNode;
      this.first.next = temp;
    }

    this.length++;
    return this.length;
  }

  // Delete the very last element in the stack
  pop() {
    if (this.length === 0) return null;
    const temp = this.first;

    if (this.first === this.last) {
      this.first = null;
      this.last = null;
    } else {
      this.first = this.first.next;
    }

    temp.next = null;
    this.length--;
    return temp;
  }
}

// Creating a Queue class to perform operations
class Queue {
  constructor() {
    // Instantiating the First stack
    this.pushStack = new Stack();

    // Instantiating the Second stack
    this.popStack = new Stack();

    this.operation = false;
    this.queueItems = [];
    this.size = 0;
  }

  // Add element in queue
  enqueue(value) {
    // Pass teh given value to the first stack
    this.pushStack.push(value, false);
    this.size = this.pushStack.length + this.popStack.length;
    this.operation = false;
    return this;
  }

  // Delete element from queue
  dequeue() {
    if (this.popStack.length > 0) {
      this.size = this.pushStack.length + this.popStack.length - 1;
      this.operation = true;
      return this.popStack.pop();
    }

    while (this.pushStack.length > 0) {
      this.popStack.push(this.pushStack.pop(), true);
    }

    this.size = this.pushStack.length + this.popStack.length - 1;
    this.operation = true;
    return this.popStack.pop();
  }

  // Traversing the stacks 
  traverseStack(currentNode, type) {
    let tempArray = [];
    if (type === "pop") {
      while (currentNode) {
        tempArray.push(currentNode.value);
        currentNode = currentNode.next;
      }
    } else {
      while (currentNode) {
        tempArray.unshift(currentNode.value);
        currentNode = currentNode.next;
      }
    }

    return tempArray;
  }

  // Print Queue elements
  printItems() {
    let currentNode, tempArray;
    this.queueItems = [];

    // Check both the stacks to get all the elements together
    if (this.operation) {
      currentNode = this.popStack.first;
      this.queueItems = this.traverseStack(currentNode, "pop");

      tempArray = [];

      if (this.pushStack.length !== 0) {
        currentNode = this.pushStack.first;
        tempArray = this.traverseStack(currentNode, "push");
      }

      this.queueItems = [...this.queueItems, ...tempArray];
    } else {
      tempArray = [];
      if (this.popStack.length !== 0) {
        currentNode = this.popStack.first;
        tempArray = this.traverseStack(currentNode, "pop");
      }

      currentNode = this.pushStack.first;

      this.queueItems = this.traverseStack(currentNode, "push");
      this.queueItems = [...tempArray, ...this.queueItems];
    }

    return console.log("Queue - ", this.queueItems);
  }
}

// Instantiating the Queue class
const myQueue = new Queue();

let choice = 0;
let value;

// Asking user input for performing operations on Queue
do {
  console.log("\nWelcome to the Queue Stack Show");
  console.log("Follow the instructions to get in the show");
  console.log("0. To exit without doing anything".yellow);
  console.log("1. Display the queue".display);
  console.log("2. Insert element in queue".insert);
  console.log("3. Delete element from queue".delete);

  choice = +prompt("Enter your choice - ");

  switch (choice) {
    case 0:
      console.log("Hmm, matter of choice!\n".rainbow);
      return;

    case 1:
      myQueue.printItems();
      break;

    case 2:
      value = prompt("Enter element to insert into the queue - ");
      myQueue.enqueue(value);
      myQueue.printItems();
      break;

    case 3:
      myQueue.dequeue();
      myQueue.printItems();
      break;

    default:
      console.log("You know this is wrong, Bbye!\n".wrong);
      return;
  }
} while (choice !== 0);

// Sample I/O of the above program -

/*

> node QueueStack

Welcome to the Queue Stack Show
Follow the instructions to get in the show
0. To exit without doing anything
1. Display the queue
2. Insert element in queue
3. Delete element from queue
Enter your choice - 2
Enter element to insert into the queue - 12
Queue -  [ '12' ]

// Add few more elements using the same operation - 
// Queue -  [ '12', '55', '33', '22' ]

3. Delete element from queue
Enter your choice - 3
Queue - ['55', '33', '22']

*/

