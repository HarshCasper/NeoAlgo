/*

A graph is a pictorial representation of a set of objects where some pairs of objects are connected by links.
The interconnected objects are represented by points termed as vertices (vertex), and the links that connect the vertices are called edges.

Below is the program of Graph implementation with dynamic inputs of edges & vertex.
prompt & colors are the side libraries to take user input & provide a colorful terminal interface respectively.

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

// Creating the Graph class to create graph
class Graph {
  constructor() {
    this.numberOfNodes = 0;
    this.adjacentList = {};
  }

  // Add vertex of graphs
  addVertex(node) {
    this.adjacentList[node] = [];
    this.numberOfNodes++;
  }

  // Add edges of graph
  addEdge(node1, node2) {
    this.adjacentList[node1].push(node2);
    this.adjacentList[node2].push(node1);
  }

  // Create connections and display
  showConnections() {
    const allNodes = Object.keys(this.adjacentList);
    for (let node of allNodes) {
      let nodeConnections = this.adjacentList[node];
      let connections = "";
      let vertex;
      for (vertex of nodeConnections) {
        connections += vertex + " ";
      }

      // Display node connection
      console.log(node + " --> " + connections);
    }
  }
}

// Instantiating the Graph class
const myGraph = new Graph();

let choice = 0;
let value;

// Asking user input for performing operations on Graph
do {
  console.log("\nWelcome to the Graph Show");
  console.log("Follow the instructions to get in the show");
  console.log("0. To exit without doing anything".yellow);
  console.log("1. Show Graph Connections".display);
  console.log("2. Add Vertex".insert);
  console.log("3. Add Edge".display);

  choice = +prompt("Enter your choice - ");

  switch (choice) {
    case 0:
      console.log("Hmm, matter of choice!\n".rainbow);
      return;

    case 1:
      if (myGraph.numberOfNodes === 0)
        console.log("Graph is empty. No vertex or edges.".display);
      else myGraph.showConnections();
      break;

    case 2:
      value = prompt("Enter element to add as vertex in Graph - ");
      myGraph.addVertex(value);
      break;

    case 3:
      let pair1 = prompt("Enter first edge - ");
      let pair2 = prompt("Enter first edge - ");

      // Check if entered pairs are available or not as vertex
      if (myGraph.adjacentList[pair1] && myGraph.adjacentList[pair2])
        myGraph.addEdge(pair1, pair2);
      else console.log("Wrong edge. Add proper vertex first.".wrong);
      break;

    default:
      console.log("You know this is wrong, Bbye!\n".wrong);
      return;
  }
} while (choice !== 0);

/*

> node Graph

Welcome to the Graph Show
Follow the instructions to get in the show
0. To exit without doing anything
1. Show Graph Connections
2. Add Vertex
3. Add Edge
Enter your choice - 2
Enter element to add as vertex in Graph - 5

... Add vertex [3,7]

Enter your choice - 3
Enter first edge - 5
Enter first edge - 7

Enter your choice - 3
Enter first edge - 3
Enter first edge - 5

Enter your choice - 1
3 --> 5 
5 --> 7 3 
7 --> 5 

*/

