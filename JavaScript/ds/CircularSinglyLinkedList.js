/*

In a circular Singly linked list, the last node of the list contains a pointer to the first node of the list.
We can have circular singly linked list as well as circular doubly linked list.
We traverse a circular singly linked list until we reach the same node where we started. 
The circular singly liked list has no beginning and no ending. There is no null value present in the next part of any of the nodes.

In this program, user can provide a choice to perform operations on a Circular Singly Linked List. It is created using a ES6 class syntax. 
prompt & colors are node packages for taking user input and displaying text in different colors respectively. 

*/

const prompt = require("prompt-sync")({ sigint: true });
const colors = require("colors");

// Setting the color schema
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

// Creating Circular Singly Linked List class to perform operations
class CircularLinkedList {
  constructor(value) {
    this.head = null;
    this.tail = this.head;
    this.length = 0;
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

  // Handling the very first node of Linked List
  firstNode(value) {
    let newNode = new Node(value);

    this.head = newNode;
    this.head.next = this.head;
    this.tail = this.head;

    this.length++;
    return this;
  }

  // Appending ( at the end ) node in Linked List
  append(value) {
    if (!this.head) return this.firstNode(value);
    let newNode = new Node(value);

    this.tail.next = newNode;
    newNode.next = this.head;
    this.tail = newNode;

    this.length++;
    return this;
  }

  // Prepending ( at the beginning ) of Linked List
  prepend(value) {
    if (!this.head) return this.firstNode(value);
    let newNode = new Node(value);

    newNode.next = this.head;
    this.head = newNode;
    this.tail.next = this.head;

    this.length++;
    return this;
  }

  // Inserting node at a given position in Linked List
  insert(index, value) {
    if (index === 1) return this.prepend(value);
    else if (index > this.length) return this.append(value);
    else {
      let newNode = new Node(value);
      let previousNode = this.traverseToIndex(index - 1);

      newNode.next = previousNode.next;
      previousNode.next = newNode;
    }

    this.length++;
    return this;
  }

  // Delete a node from circular SLL
  remove(index) {
    if (index === 1) {
      this.tail.next = this.head.next;
      this.head = this.head.next;
      this.length--;
      return this;
    } else {
      let previousNode = this.traverseToIndex(index - 1); // traverse to that node
      if (index === this.length) {
        previousNode.next = this.head;
        this.length--;
        return this;
      }

      previousNode.next = previousNode.next.next;
      this.length--;
      return this;
    }
  }

  // Reverse circular singly linked list
  reverse() {
    if (!this.head.next) return;

    let first = this.head;
    this.tail = this.head;
    let second = first.next;

    while (second !== this.head) {
      const temp = second.next;
      second.next = first;
      first = second;
      second = temp;
    }

    // Update head node
    this.head.next = first;
    this.head = first;
  }

  // Displaying all the nodes of Linked List
  printList() {
    let currentNode = this.head;
    let data = [];

    while (currentNode.next !== this.head) {
      data.push(currentNode.value);
      currentNode = currentNode.next;
    }

    data.push(currentNode.value);
    return data;
  }
}

// Instantiating the Circular Singly Linked List class
const myCircularLinkedList = new CircularLinkedList();

let choice = 0;
let value, index;

// Asking user input for performing operations on Linked List
do {
  console.log("\nWelcome to the Circular Singly Linked List Show");
  console.log("Follow the instructions to get in the show");
  console.log("0. To exit without doing anything".yellow);
  console.log("1. Display the Circular Singly Linked List".display);
  console.log("2. Append element in the Circular Singly Linked List".insert);
  console.log("3. Prepend element in the Circular Singly Linked List".insert);
  console.log("4. Insert anywhere in between the Circular Singly Linked List".insert);
  console.log("5. Delete element from the Circular Singly Linked List".delete);
  console.log("6. Reverse the Circular Singly Linked List".display);


  choice = +prompt("Enter your choice - ");

  switch (choice) {
    case 0:
      console.log("Hmm, matter of choice!\n".rainbow);
      return;

    case 1:
      if (myCircularLinkedList.length === 0) console.log("Empty LL []");
      else console.log("Linked List - ", myCircularLinkedList.printList());
      break;

    case 2:
      value = +prompt("Enter Value to Append element - ");
      myCircularLinkedList.append(value);
      console.log("After Append Linked List - ", myCircularLinkedList.printList());
      break;

    case 3:
      value = +prompt("Enter Value to Prepend element - ");
      myCircularLinkedList.prepend(value);
      console.log("After Prepend Linked List - ", myCircularLinkedList.printList());
      break;

    case 4:
      value = +prompt("Enter Value to Insert element - ");
      index = +prompt("Enter Position to Insert element - ");

      if (index <= 0)
        return console.log("You know this is wrong, Bbye!\n".wrong);
      myCircularLinkedList.insert(index, value);
      console.log("After Insertion Linked List - ", myCircularLinkedList.printList());
      break;

    case 5:
      if (myCircularLinkedList.length === 0) {
        return console.log("404, you can't remove anything from void".wrong);
      }
  
      index = +prompt("Enter position of element - ");
      if (index <= 0 || index > myCircularLinkedList.length)
        return console.log("You know this is wrong, Bbye!\n".wrong);
  
      myCircularLinkedList.remove(index);
      console.log("After Deletion Linked List - ", myCircularLinkedList.printList());
      break;
    
    case 6:
      if (myCircularLinkedList.length === 0) {
        return console.log("500, you can't reverse empty CSLL".wrong);
      }
  
      myCircularLinkedList.reverse();
      console.log("Reversed Circular Linked List - ", myCircularLinkedList.printList());
      break;

    default:
      console.log("You know this is wrong, Bbye!\n".wrong);
      return;
  }
} while (choice !== 0);

/*

> node CircularSinglyLinkedList

Welcome to the Linked List Show
Follow the instructions to get in the show
0. To exit without doing anything
1. Display the Linked List
2. Append element in the Linked List
3. Prepend element in the Linked List
4. Insert anywhere in between the Linked List
5. Delete element from the Circular Singly Linked List
6. Reverse the Circular Singly Linked List
Enter your choice - 2
Enter Value to Append element - 21
After Append Linked List -  [ 21 ]

4. Insert anywhere in between the Linked List
Enter your choice - 4
Enter Value to Insert element - 12
Enter Position to Insert element - 1
After Insertion Linked List -  [ 12, 21 ]

3. Prepend element in the Linked List
Enter your choice - 3
Enter Value to Prepend element - 90
After Prepend Linked List -  [ 90, 12, 21 ]

5. Delete element from the Circular Singly Linked List
Enter your choice - 5 
Enter position of element - 2
After Deletion Linked List - [90, 21]

6. Reverse the Circular Singly Linked List
Enter your choice - 6
Reversed Circular Linked List - [21, 90]

*/

