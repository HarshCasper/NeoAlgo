/*

A stack is a data structure that follows the Last in, First out principle (i.e.​ the last added elements are removed first).
Generally, a stack is implemented using an array but a linked list approach can be used. Below is the implementation of a stack using a linked list ( Singly Linked List ).

In this program, the user can provide a choice to perform operations on a stack. It is created using an ES6 class syntax. 
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

// Creating a Stack class to perform operations
class Stack {
  constructor() {
    this.top = null;
    this.bottom = null;
    this.length = 0;
  }

  // Push element into the stack
  push(value) {
    const newNode = new Node(value);
    if (this.length === 0) {
      this.top = newNode;
      this.bottom = newNode;
      this.length++;

      return this;
    }

    const holdingPointer = this.top;
    this.top = newNode;
    this.top.next = holdingPointer;
    this.length++;
    return this;
  }

  // Get topmost element of stack
  peek() {
    if (this.length === 0) return console.log("Nothing to look for");
    return console.log(this.top.value);
  }

  // Check whether the stack is empty or not
  isEmpty() {
    if (this.length === 0) return console.log("Yes, it's Empty here");
    return console.log("There is something inside, not void for sure");
  }

  // Pop element form the stack
  pop() {
    if (!this.top) return console.log("Nothing to pop");
    let pop = this.top.value;

    if (this.top === this.bottom) {
      this.bottom = null;
      this.top = null;
      this.length--;
      return console.log("Popped out", pop);
    }

    this.top = this.top.next;
    this.length--;
    return console.log("Popped out", pop);
  }

  // Reverse the stack
  reverse() {
    if (!this.top.next) {
      return this.top;
    }

    let top = this.top;
    this.bottom = this.top;
    let nextNode = top.next;

    while (nextNode) {
      const temp = nextNode.next;
      nextNode.next = top;
      top = nextNode;
      nextNode = temp;
    }

    this.top.next = null;
    this.top = top;

    return this;
  }

  // Display all the elements of stack
  printStackElements() {
    let currentNode = this.top;
    let data = [];

    while (currentNode) {
      data.push(currentNode.value);
      currentNode = currentNode.next;
    }

    return console.log("Stack Elements", data);
  }
}

// Instantiating the Stack class
const myStack = new Stack();

let choice = 0;
let value;

// Asking user input for performing operations on Stack
do {
  console.log("\nWelcome to the Stack Linked List Show");
  console.log("Follow the instructions to get in the show");
  console.log("0. To exit without doing anything".yellow);
  console.log("1. Display the stack".display);
  console.log("2. Push element into the stack".insert);
  console.log("3. Get top element of the stack".display);
  console.log("4. Check whether the stack in empty or not".insert);
  console.log("5. Pop element from the stack".delete);
  console.log("6. Reverse the stack".display);

  choice = +prompt("Enter your choice - ");

  switch (choice) {
    case 0:
      console.log("Hmm, matter of choice!\n".rainbow);
      return;

    case 1:
      myStack.printStackElements();
      break;

    case 2:
      value = prompt("Enter element to push into the stack - ");
      myStack.push(value);
      myStack.printStackElements();
      break;

    case 3:
      myStack.peek();
      break;

    case 4:
      myStack.isEmpty();
      break;

    case 5:
      myStack.pop();
      myStack.printStackElements();
      break;
    
    case 6:
      if (myStack.length === 0) {
        console.log("Stack is empty");
      } else {
        myStack.reverse();
        myStack.printStackElements();
      }
  
      break;

    default:
      console.log("You know this is wrong, Bbye!\n".wrong);
      return;
  }
} while (choice !== 0);

// Sample I/O of the above program -

/*

> node StackLinkedList

Welcome to the Stack Linked List Show
Follow the instructions to get in the show
0. To exit without doing anything
1. Display the stack
2. Push element in stack
3. Get top element of stack
4. Check whether stack in empty or not
5. Pop element from stack
6. Reverse the stack
Enter your choice - 1
Stack Elements []

Welcome to the Stack Linked List Show
Follow the instructions to get in the show
0. To exit without doing anything
1. Display the stack
2. Push element in stack
3. Get top element of stack
4. Check whether stack in empty or not
5. Pop element from stack
6. Reverse the stack
Enter your choice - 2
Enter element to push into the stack - Google
Stack Elements [ 'Google' ]

Welcome to the Stack Linked List Show
Follow the instructions to get in the show
0. To exit without doing anything
1. Display the stack
2. Push element in stack
3. Get top element of stack
4. Check whether stack in empty or not
5. Pop element from stack
6. Reverse the stack
Enter your choice - 2
Enter element to push into the stack - YouTube
Stack Elements [ 'Google', 'YouTube' ]

Welcome to the Stack Linked List Show
Follow the instructions to get in the show
0. To exit without doing anything
1. Display the stack
2. Push element in stack
3. Get top element of stack
4. Check whether stack in empty or not
5. Pop element from stack
6. Reverse the stack
Enter your choice - 6
Stack Elements [ 'YouTube', 'Google' ]

*/


