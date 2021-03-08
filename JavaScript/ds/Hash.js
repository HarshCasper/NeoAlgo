/*

A JavaScript program for creating a well known data structure "Hash Table". A hash table (often called a hash map) is a data structure 
that maps keys to values. Hash tables combine lookup, insert, and delete operations in an efficient way. Hash tables can perform in constant time.
In the worst-case scenario, the performance of hash tables can be as low as O(n).

In this program, user can provide a choice to perform operations on a Hash Table. It is created using a ES6 class syntax. 
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

class HashTable {
  constructor(size) {
    // Set Hash Table size
    this.data = new Array(size);
  }

  // Generate a location using simple hash logic
  _hash(key) {
    let hash = 0;
    for (let i = 0; i < key.length; i++) {
      // Location mapping
      hash = (hash + key.charCodeAt(i) + i) % this.data.length;
    }

    return hash;
  }

  // Set the location of item in hash
  set(key, value) {
    let address = this._hash(key);
    if (!this.data[address]) {
      this.data[address] = [];
    }

    // Insert item at the desired location with [key, value] pair
    this.data[address].push([key, value]);
    return this.data;
  }

  // Get the location of item in hash table
  get(key) {
    let address = this._hash(key);
    const currentBucket = this.data[address];
    // Item at the location is not found , return undefined
    if (!currentBucket) return undefined;

    if (currentBucket.length) {
      for (let i = 0; i < currentBucket.length; i++) {
        if (currentBucket[i][0] === key) {
          return {
            data: [currentBucket[i][0], currentBucket[i][1]],
            location: address,
          };
        }
      }
    }
    return undefined;
  }

  // Delete item
  deleteItem(value) {
    let item = this.get(value);

    // Item is not present in hash table
    if (item === undefined)
      return console.log("Can't delete, no such item found");

    // Delete item present at that location from hash table
    delete this.data[item.location];
    return console.log("Deleted", item.data[0]);
  }

  // Display all items
  keys() {
    const keysArray = [];
    for (let i = 0; i < this.data.length; i++) {
      if (this.data[i]) keysArray.push(this.data[i][0][0]);
    }

    return keysArray;
  }
}

// Instantiating the HashTable
const myHashTable = new HashTable(100);

// Insert item in Hash Table
myHashTable.set("grapes", 1000); // Output - [['grapes', 1000]]
myHashTable.set("apple", 100); // Output - [['apple', 100], ['grapes', 1000]]
myHashTable.set("oranges", 50); // Output - [['apple', 100], ['grapes', 1000], ['oranges', 50]]

myHashTable.deleteItem("apple"); // Output - [['grapes', 1000], ['oranges', 50]]
myHashTable.deleteItem("fruits"); // Output - Can't delete, no such item found

let choice = 0;
let value, index;

// Asking user input for performing operations on Hash Table
do {
  console.log("\nWelcome to the Hash Table");
  console.log("Follow the instructions to get in the show");
  console.log("0. To exit without doing anything".yellow);
  console.log("1. Display all elements of the Hash Table".display);
  console.log("2. Insert element in the Hash Table".insert);
  console.log("3. Find element in Hash Table".display);
  console.log("4. Delete element from Hash Table".delete);

  choice = +prompt("Enter your choice - ");

  switch (choice) {
    case 0:
      console.log("Hmm, matter of choice!\n".rainbow);
      return;

    case 1:
      console.log("Hash Table - ", myHashTable.keys());
      break;

    case 2:
      value = prompt("Enter Value ( first value )  to Insert element - ");
      index = +prompt("Enter amount ( second value) to Insert element - ");

      if (index <= 0)
        return console.log("You know this is wrong, Bbye!\n".wrong);

      myHashTable.set(value, index);
      console.log("After Insertion Hash Table - ", myHashTable.keys());
      break;

    case 3:
      if (myHashTable.data.length === 0) {
        return console.log("Hash Table in empty".wrong);
      }

      value = prompt("Enter Value to find the element - ");
      let result = myHashTable.get(value);

      if (!result) console.log("Element not found");
      else console.log("Element ", result);
      break;

    case 4:
      if (myHashTable.data.length === 0) {
        return console.log(
          "404, you can't remove anything from empty hash table".wrong
        );
      }

      value = prompt("Enter Value to delete - ");
      myHashTable.deleteItem(value);
      console.log("After Deletion Hash Table - ", myHashTable.keys());
      break;

    default:
      console.log("You know this is wrong, Bbye!\n".wrong);
      return;
  }
} while (choice !== 0);
