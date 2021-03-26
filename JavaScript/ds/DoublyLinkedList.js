/*

A doubly linked list is a linked data structure that consists of a set of sequentially linked records called nodes. Each node contains three fields: two link fields (references to the previous and to the next node in the sequence of nodes) and one data field. 
The beginning and ending nodes' previous and next links, respectively, point to some kind of terminator, typically a sentinel node or null, to facilitate traversal of the list.

Below, is the implementation of doubly linked list. In this program, user can provide a choice to perform operations on a Doubly Linked List. It is created using a ES6 class syntax. 
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
  constructor(value, next = null, prev = null) {
    this.value = value, 
    this.next = next, 
    this.prev = prev
  }
}

// Creating Doubly Linked List class to perform operations 
class DoublyLinkedList {
  constructor(value) {
    this.head = {
      value: value,
      prev: null,
      next: null,
    };

    this.tail = this.head;
    this.length = 1;
  }

   // Looping to a given index in doubly Linked List
  traverseToIndex(index) {
    let counter = 1;
    let currentNode = this.head;

    while (counter !== index) {
      currentNode = currentNode.next;
      counter++;
    }

    return currentNode;
  }

  // Case : The very "first node" insertion in doubly linked list
  firstNode(value) {
    let newNode = new Node(value);

    this.head = newNode;
    this.head.next = null;
    this.head.prev = null;
    this.tail = this.head;

    this.length++;
    return this;
  }

  // Appending (at the end) node in doubly linked list
  append(value) {
    if (!this.head) return this.firstNode(value);
    const newNode = new Node(value);

    this.tail.next = newNode;
    newNode.prev = this.tail;

    this.tail = newNode;
    this.length++;
    return this;
  }

  // Prepending ( at the beginning ) of doubly linked list
  prepend(value) {
    if (!this.head) return this.firstNode(value);
    const newNode = new Node(value);

    this.head.prev = newNode;
    newNode.next = this.head;
    this.head = newNode;
    this.length++;

    return this;
  }

  // Inserting node at a given position in doubly linked list
  insert(index, value) {
    if (index === 1) return this.prepend(value);
    if (index > this.length) return this.append(value);

    const newNode = new Node(value);
    if (index === this.length) {
      newNode.prev = this.tail.prev;
      this.tail.prev.next = newNode;
      this.tail.prev = newNode;
      newNode.next = this.tail;
      this.length++;

      return this;
    }

    let currentNode = this.traverseToIndex(index - 1);

    newNode.next = currentNode.next;
    currentNode.next.prev = newNode;
    newNode.prev = currentNode;
    currentNode.next = newNode;

    this.length++;
    return this;
  }

  // Removing the element node form doubly linked list
  remove(index) {
    if (this.length === 1) { // If length of doublyLL is one
      this.head = null;
      this.tail = this.head;
    } else if (index === 1) { // If entered position is one 
      this.head = this.head.next;
      this.head.prev = null;
    } else if (index === this.length) { // If entered postion is equal to the length of doublyLL
      this.tail = this.tail.prev;
      this.tail.next = null;
    } else { // for the rest of cases
      //Traverse to that particular index of element 
      let currentNode = this.traverseToIndex(index - 1);
      currentNode.next.next.prev = currentNode;
      currentNode.next = currentNode.next.next;
    }

    this.length--;
    return this;
  }

  // Displaying all the nodes of doubly linked list
  printList() {
    let array = [];
    let currentNode = this.head;

    while (currentNode !== null) {
      array.push(currentNode.value);
      currentNode = currentNode.next;
    }

    return array;
  }

}

// Instantiating the doubly Linked List class
const myDoublyLinkedList = new DoublyLinkedList(22);

let choice = 0;
let value, index;

// Asking user input for performing operations on doubly Linked List
do {
  console.log("\nWelcome to the Doubly Linked List Show");
  console.log("Follow the instructions to get in the show");
  console.log("0. To exit without doing anything".yellow);
  console.log("1. Display the Doubly Linked List".display);
  console.log("2. Append element in the Doubly Linked List".insert);
  console.log("3. Prepend element in the Doubly Linked List".insert);
  console.log("4. Insert anywhere in between the Doubly Linked List".insert);
  console.log("5. Delete element from Doubly Linked List".delete);

  choice = +prompt("Enter your choice - ");

  switch (choice) {
    case 0:
      console.log("Hmm, matter of choice!\n".rainbow);
      return;

    case 1:
      console.log("Doubly Linked List - ", myDoublyLinkedList.printList());
      break;

    case 2:
      value = +prompt("Enter Value to Append element - ");
      myDoublyLinkedList.append(value);
      console.log(
        "After Append Doubly Linked List - ",
        myDoublyLinkedList.printList()
      );
      break;

    case 3:
      value = +prompt("Enter Value to Prepend element - ");
      myDoublyLinkedList.prepend(value);
      console.log(
        "After Prepend Doubly Linked List - ",
        myDoublyLinkedList.printList()
      );
      break;

    case 4:
      value = +prompt("Enter Value to Insert element - ");
      index = +prompt("Enter Position to Insert element - ");

      if (index <= 0)
        return console.log("You know this is wrong, Bbye!\n".wrong);
      
      myDoublyLinkedList.insert(index, value);
      console.log(
        "After Insertion Doubly Linked List - ",
        myDoublyLinkedList.printList()
      );
      break;

    case 5:
      if (myDoublyLinkedList.length === 0) {
        return console.log("404, you can't remove anything from void".wrong);
      }
  
      index = +prompt("Enter position of element - ");
      if (index <= 0 || index > myDoublyLinkedList.length)
        return console.log("You know this is wrong, Bbye!\n".wrong);
  
      myDoublyLinkedList.remove(index);
      console.log( "After Deletion Doubly Linked List - ", myDoublyLinkedList.printList());
      break;

    default:
      console.log("You know this is wrong, Bbye!\n".wrong);
      return;
  }
} while (choice !== 0);


// Sample I/O of the above program -

/*

> node DoublyLinkedList

Welcome to the Doubly Linked List Show
Follow the instructions to get in the show
0. To exit without doing anything
1. Display the Doubly Linked List
2. Append element in the Doubly Linked List
3. Prepend element in the Doubly Linked List
4. Insert anywhere in between the Doubly Linked List
5. Delete element from Doubly Linked List
Enter your choice - 1
Doubly Linked List -  [ 22 ]

Welcome to the Doubly Linked List Show
Follow the instructions to get in the show
0. To exit without doing anything
1. Display the Doubly Linked List
2. Append element in the Doubly Linked List
3. Prepend element in the Doubly Linked List
4. Insert anywhere in between the Doubly Linked List
5. Delete element from Doubly Linked List
Enter your choice - 3
Enter Value to Prepend element - 23
After Prepend Doubly Linked List -  [ 23, 22 ]

Welcome to the Doubly Linked List Show
Follow the instructions to get in the show
0. To exit without doing anything
1. Display the Doubly Linked List
2. Append element in the Doubly Linked List
3. Prepend element in the Doubly Linked List
4. Insert anywhere in between the Doubly Linked List
5. Delete element from Doubly Linked List
Enter your choice - 5
Enter position of element - 2
After Deletion Doubly Linked List -  [ 23 ]

*/

