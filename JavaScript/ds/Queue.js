class Queue {
  constructor() {
    this.items = [];
  }

  size() {
    return this.items.length;
  }

  enqueue(element) {
    this.items.push(element);
  }

  dequeue() {
    if (this.isEmpty()) throw Error("Underflow");

    return this.items.shift();
  }

  front() {
    if (this.isEmpty()) throw Error("No elements in  the queue");

    return this.items[0];
  }

  isEmpty() {
    return this.items.length === 0;
  }

  iterate(callback = null) {
    if (callback === null) {
      let str = "";
      for (let i of this.items) {
        str += i + " ";
      }
      str.trim();
      return str;
    }

    const iterated = [];
    for (let i of this.items) {
      iterated.push(callback(i));
    }

    return iterated;
  }
}

// implementation
let arr = [10, 20, 30, 40, 50];
let queue = new Queue();

console.log("Empty size:", queue.size()); // Returns 0

console.log("Is empty?", queue.isEmpty()); // Returns true

try {
  console.log(queue.dequeue()); // Will throw an error
} catch (err) {
  console.error("Error for attemtping to dequeue empty queue:", err.message);
}

// Add items in the queue
for (let i of arr) {
  queue.enqueue(i);
}

console.log("Added values:", queue.iterate()); // Displays all elements in the queue.

console.log("Front:", queue.front()); // Returns 10
console.log("Dequeue:", queue.dequeue()); // Removes 10 from the queue.
console.log("New Front:", queue.front()); // Returns 20

console.log(
  "Iterate with callback:",
  queue.iterate((element) => element / 10)
); // Maps the queue and returns an array.
