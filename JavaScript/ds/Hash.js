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
    console.log(this.data);
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
    console.log("item", item);

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

const myHashTable = new HashTable(100);

myHashTable.set("grapes", 1000);
let found = myHashTable.get("grapes");
console.log("Found", found);

myHashTable.set("apple", 100);
found = myHashTable.get("apple");
console.log("Found", found);

myHashTable.set("oranges", 50);
found = myHashTable.get("oranges");
console.log("Found", found);

let keys = myHashTable.keys();
console.log(keys);

myHashTable.deleteItem("apple");
keys = myHashTable.keys();
console.log(keys);

myHashTable.deleteItem("fruits");
console.log(myHashTable);
