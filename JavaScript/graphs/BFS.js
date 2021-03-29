/* BFS visits the neighbor vertices before visiting the child vertices,
 and a queue is used in the search process */


/* Function to implement BFS in JS. */

const BFS = (node) => {
    // Create a Queue and add our initial node in it
    let q = new Queue(this.nodes.length);
    let explored = new Set();
    q.enqueue(node);
 
    // Mark the first node as explored explored.
    add(node);
 
    // We'll continue till our queue gets empty
    while (!q.isEmpty()) {
       let t = q.dequeue();
 
       // Log every element that comes out of the Queue
       console.log(t);
 
       // 1. In the edges object, we search for nodes this node is directly connected to.
       // 2. We filter out the nodes that have already been explored.
       // 3. Then we mark each unexplored node as explored and add it to the queue.
       this.edges[t]
       .filter(n => !explored.has(n))
       .forEach(n => {
          explored.add(n);
          q.enqueue(n);
       });
    }
 }


 /*

Example


let g = new Graph();
g.addNode("A");
g.addNode("B");
g.addNode("C");
g.addNode("D");
g.addNode("E");
g.addNode("F");
g.addNode("G");

g.addEdge("A", "C");
g.addEdge("A", "B");
g.addEdge("A", "D");
g.addEdge("D", "E");
g.addEdge("E", "F");
g.addEdge("B", "G");

g.BFS("A");


Output

This will give the output −

A
C
B
D
G
E
F


 */