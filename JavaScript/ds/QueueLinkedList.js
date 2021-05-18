/*

A queue is a linear data structure that follows the First in, First out principle (i.e.​ the first added elements are removed first).
Generally, a queue is implemented using Linked List but other approach can be used i.e using array ( which has high time complexity ) or using stack.
Below is the implementation of a queue using a linked list ( Singly Linked List ).

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

// Creating a Queue class to perform operations
class Queue {
  constructor() {
    this.first = null;
    this.last = null;
    this.length = 0;
  }

  // Get the first element of Queue
  peek() {
    if (this.length === 0) return console.log("Empty Queue");
    return console.log(this.first.value);
  }

  // Insert an element in the Queue
  enqueue(value) {
    const newNode = new Node(value);
    if (this.length === 0) {
      this.first = newNode;
      this.last = newNode;
    } else {
      this.last.next = newNode;
      this.last = newNode;
    }

    this.length++;
    return this;
  }

  // Delete an element from the Queue
  dequeue() {
    if (!this.first) return console.log("Queue is already empty");
    if (this.first === this.last) {
      this.first = null;
      this.last = null;
    } else {
      this.first = this.first.next;
    }

    this.length--;
    return this;
  }

  // Check whether the Queue is empty or not
  isEmpty() {
    if (this.length === 0) return console.log("Into the Void here");
    return console.log("There is something deep inside it");
  }

  // Print all the elements of Queue
  printList() {
    let currentNode = this.first;
    let queueItems = [];

    while (currentNode) {
      queueItems.push(currentNode.value);
      currentNode = currentNode.next;
    }

    return console.log("Queue", queueItems);
  }
}

// Instantiating the Queue class
const myQueue = new Queue();

let choice = 0;
let value;

// Asking user input for performing operations on Queue
do {
  console.log("\nWelcome to the Queue Linked List Show");
  console.log("Follow the instructions to get in the show");
  console.log("0. To exit without doing anything".yellow);
  console.log("1. Display the queue".display);
  console.log("2. Insert element in queue".insert);
  console.log("3. Get first element of queue".display);
  console.log("4. Check whether queue in empty or not".insert);
  console.log("5. Delete element from queue".delete);

  choice = +prompt("Enter your choice - ");

  switch (choice) {
    case 0:
      console.log("Hmm, matter of choice!\n".rainbow);
      return;

    case 1:
      myQueue.printList();
      break;

    case 2:
      value = prompt("Enter element to insert into the queue - ");
      myQueue.enqueue(value);
      myQueue.printList();
      break;

    case 3:
      myQueue.peek();
      break;

    case 4:
      myQueue.isEmpty();
      break;

    case 5:
      myQueue.dequeue();
      myQueue.printList();
      break;

    default:
      console.log("You know this is wrong, Bbye!\n".wrong);
      return;
  }
} while (choice !== 0);

// Sample I/O of the above program -

/*

> node QueueLinkedList

Welcome to the Queue Linked List Show
Follow the instructions to get in the show
0. To exit without doing anything
1. Display the queue
2. Insert element in queue
3. Get first element of queue
4. Check whether queue in empty or not
5. Delete element from queue
Enter your choice - 1
Queue []

Welcome to the Queue Linked List Show
Follow the instructions to get in the show
0. To exit without doing anything
1. Display the queue
2. Insert element in queue
3. Get first element of queue
4. Check whether queue in empty or not
5. Delete element from queue
Enter your choice - 2
Enter element to insert into the queue - 4
Queue [ '4' ]

*/


