/**
 * Nodes are the "elements" of a linked list.
 * They are represented as objects here to include the "next node" property
 */
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

/**
 * With nodes defined, we can create a LinkedList class
 * that will use nodes to instantiate LinkedList objects.
 */
class LinkedList {
  // TODO: Re-implement the constructor to receive an array, and then convert it to a LinkedList.
  constructor(head = null) {
    this.head = head;
  }

  size() {
    let count = 0;
    let node = this.head;
    while (node) {
      count++;
      node = node.next;
    }
    return count;
  }

  clear() {
    this.head = null;
  }

  getLast() {
    let lastNode = this.head;
    if (lastNode) {
      while (lastNode.next) {
        lastNode = lastNode.next;
      }
    }
    return lastNode;
  }

  getFirst() {
    return this.head;
  }
}

// Just a simple implementation of the Linked List

// First, we define the values.
const arr = [0, 1, 2, 3, 4];

// Second, we create the nodes.
const firstNode = new Node(arr[0]);
const secondNode = new Node(arr[1]);
const thirdNode = new Node(arr[2]);
const fourthNode = new Node(arr[3]);
const fifthNode = new Node(arr[4]);

// Third, we establish the linking between nodes.
firstNode.next = secondNode;
secondNode.next = thirdNode;
thirdNode.next = fourthNode;
fourthNode.next = fifthNode;

// Fourth, we instantiate a LinkedList only using the first node (head).
const linkedList = new LinkedList(firstNode);

// Calling some Linked List methods.
console.log("After populating the linked list:");
console.log("First node: ", linkedList.getFirst());
console.log("Last node: ", linkedList.getLast());
console.log("List size: ", linkedList.size());

// Clearing linked list
console.log("\nAfter clearing the list:");
linkedList.clear();
console.log("First node: ", linkedList.getFirst());
console.log("Last node: ", linkedList.getLast());
console.log("List size: ", linkedList.size());

/**
 * This is just a simple implementation. My challenge for you now,
 * is to implement the LinkedList constructor in such way, that when
 * you pass an array as argument, it will automate the node creation
 * and linking. Good luck!
 */
