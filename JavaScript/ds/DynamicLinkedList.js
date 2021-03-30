/*

A singly linked list is collection of nodes wherein each node has 2 parts: data and a pointer to the next node. 
The list terminates with a node pointing at null. Below is the program to add nodes dynamically in Singly Linked List.

In this program, user can provide a choice to perform operations on a Singly Linked List. It is created using a ES6 class syntax. 
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

// Creating Linked List class to perform operations 
class LinkedList {
  constructor(value) {
    this.head = {
      value: value,
      next: null,
    };

    this.tail = this.head;
    this.length = 1;
  }

 // Looping to a given index in Linked List
  traverseToIndex(index) {
    let counter = 1;
    let currentNode = this.head;

    while (counter !== index) {
      currentNode = currentNode.next;
      counter++;
    }

    return currentNode;
  }

// Appending (at the end) node in linked list
  append(value) {
    const newNode = new Node(value);

    this.tail.next = newNode;
    this.tail = newNode;
    this.length++;

    return this;
  }

// Prepending ( at the beginning ) of linked list
  prepend(value) {
    const newNode = new Node(value);

    newNode.next = this.head;
    this.head = newNode;
    this.length++;

    return this;
  }

// Inserting node at a given position in linked list
  insert(index, value) {
    if (index === 1) return this.prepend(value);
    else if (index > this.length) return this.append(value);
    else {
      const newNode = new Node(value);
      let currentNode = this.traverseToIndex(index - 1);

      newNode.next = currentNode.next;
      currentNode.next = newNode;
      this.length++;
    }
  }

// Removing the element node form linked list
  remove(index) {
    if (index === 1) {
      this.head = this.head.next;
      this.length--;
      return;
    }

    // Traversing to that particular node element
    let currentNode = this.traverseToIndex(index - 1);
    if (index === this.length) {
      currentNode.next = null;
      this.length--;
      return this;
    }

    currentNode.next = currentNode.next.next;
    this.length--;

    return this;
  }

// Reverse the linked list
  reverse() {
    if (!this.head.next) {
      return this.head;
    }

    let first = this.head;
    this.tail = this.head;
    let second = first.next;

    while (second) {
      const temp = second.next;
      second.next = first;
      first = second;
      second = temp;
    }

    this.head.next = null;
    this.head = first;

    return this;
  }

  // Sort the linked list using bubble sort algorithm in ascending order
  bubbleSort() {
    let firstNode, secondNode;
    firstNode = this.head;

    while (firstNode !== null) {
      secondNode = this.head;

      while (secondNode !== null) {
        if (firstNode.value < secondNode.value) {
          let temp = secondNode.value;
          secondNode.value = firstNode.value;
          firstNode.value = temp;
        }

        secondNode = secondNode.next;
      }

      firstNode = firstNode.next;
    }

    return this;
  }

// Displaying all the nodes of linked list
  printList() {
    const array = [];
    let currentNode = this.head;

    while (currentNode !== null) {
      array.push(currentNode.value);
      currentNode = currentNode.next;
    }

    return array;
  }
}

// Instantiating the Linked List class
const myLinkedList = new LinkedList(10);

let choice = 0;
let value, index;

// Asking user input for performing operations on Linked List
do {
  console.log("\nWelcome to the Linked List Show");
  console.log("Follow the instructions to get in the show");
  console.log("0. To exit without doing anything".yellow);
  console.log("1. Display the Linked List".display);
  console.log("2. Append element in the Linked List".insert);
  console.log("3. Prepend element in the Linked List".insert);
  console.log("4. Insert at any position in the Linked List".insert);
  console.log("5. Delete element from Linked List".delete);
  console.log("6. Reverse a Linked List".display);
  console.log("7. Sort the Linked List using Bubble Sort".insert);

  choice = +prompt("Enter your choice - ");

  switch (choice) {
    case 0:
      console.log("Hmm, matter of choice!\n".rainbow);
      return;

    case 1:
      console.log("Linked List - ", myLinkedList.printList());
      break;

    case 2:
      value = +prompt("Enter Value to Append element - ");
      myLinkedList.append(value);
      console.log("After Append Linked List - ", myLinkedList.printList());
      break;

    case 3:
      value = +prompt("Enter Value to Prepend element - ");
      myLinkedList.prepend(value);
      console.log("After Prepend Linked List - ", myLinkedList.printList());
      break;

    case 4:
      value = +prompt("Enter Value to Insert element - ");
      index = +prompt("Enter Position to Insert element - ");

      if (index <= 0)
        return console.log("You know this is wrong, Bbye!\n".wrong);
      myLinkedList.insert(index, value);
      console.log("After Insertion Linked List - ", myLinkedList.printList());
      break;
    
    case 5:
      if (myLinkedList.length === 0) {
        return console.log("404, you can't remove anything from void".wrong);
      }
  
      index = +prompt("Enter position of element - ");
      if (index <= 0 || index > myLinkedList.length)
        return console.log("You know this is wrong, Bbye!\n".wrong);
  
      myLinkedList.remove(index);
      console.log("After Deletion Linked List - ", myLinkedList.printList());
      break;
    
    case 6:
      if (myLinkedList.length === 0) {
        return console.log("Can't revert, Empty Linked List".wrong);
      }
  
      myLinkedList.reverse();
      console.log("Reversal of Linked List - ", myLinkedList.printList());
      break;
    
    case 7:
      if (myLinkedList.length === 0) {
        console.log("Linked List is Empty");
      } else {
        myLinkedList.bubbleSort();
        console.log("After sorting Linked List - ", myLinkedList.printList());
      }
  
      break;

    default:
      console.log("You know this is wrong, Bbye!\n".wrong);
      return;
  }
} while (choice !== 0);


// Sample I/O of the above program -

/*

Welcome to the Linked List Show
Follow the instructions to get in the show
0. To exit without doing anything
1. Display the Linked List
2. Append element in the Linked List
3. Prepend element in the Linked List
4. Insert anywhere in between the Linked List
5. Delete element from Linked List
6. Reverse a Linked List
7. Sort the Linked List using Bubble Sort
Enter your choice - 2
Enter Value to Append element - 43
After Append Linked List -  [10, 43]

0. To exit without doing anything
1. Display the Linked List
2. Append element in the Linked List
3. Prepend element in the Linked List
4. Insert anywhere in between the Linked List
5. Delete element from Linked List
6. Reverse a Linked List
7. Sort the Linked List using Bubble Sort
Enter your choice - 6
Reversal of Linked List -  [43, 10]

0. To exit without doing anything
1. Display the Linked List
2. Append element in the Linked List
3. Prepend element in the Linked List
4. Insert anywhere in between the Linked List
5. Reverse a Linked List
6. Delete element from Linked List
7. Sort the Linked List using Bubble Sort
Enter your choice - 7
After sorting -  [ 10, 43 ]

*/

