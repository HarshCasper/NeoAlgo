/*

Brain.js is a GPU accelerated library of neural networks written in JavaScript for browsers and Node.js. It is simple, fast and easy to use.
It provides multiple neural network implementations as different neural nets can be trained to do different things well.

Below is the simple example of neural network with BrainJS.

*/

const brain = require("brain.js"); // the brain JS library
const prompt = require("prompt-sync")({ sigint: true }); // A sync prompt for node.
const network = new brain.NeuralNetwork(); // Create a neural network

// Train network with sample input & output
network.train([
  { input: [0, 0, 0], output: [0] },
  { input: [0, 0, 1], output: [0] },
  { input: [0, 1, 1], output: [0] },
  { input: [1, 0, 1], output: [1] },
  { input: [1, 1, 1], output: [1] },
]);

let result;

// Take user input
console.log("Command-line input any 1/0");
let data1 = +prompt(" data1: ");
checkInput(data1);
let data2 = +prompt(" data2: ");
checkInput(data2);
let data3 = +prompt(" data3: ");
checkInput(data3);

// Run the neural network over the given input data
const output = network.run([data1, data2, data3]);
if (output > 0.85) {
  result = 1;
} else {
  result = 0;
}

console.log(`Prob: ${output}`);
console.log(`Approx Result: ${result}`);

// check for validating user input
function checkInput(input) {
  if (input !== 0 && input !== 1) {
    console.log(" That's wrong");
    process.exit(1);
  }
}

/*

> node neuralNetwork

Command-line input any 1/0
 data1: 0
 data2: 1
 data3: 0
Prob: 0.050605230033397675
Approx Result: 0

Command-line input any 1/0
 data1: 1
 data2: 1
 data3: 0
Prob: 0.913151741027832
Approx Result: 1

*/

