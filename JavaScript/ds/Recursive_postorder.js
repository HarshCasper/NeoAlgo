/*
In postorder traversal , the root node is visited in the end,that is , first visit
the left sub-tree , then the right sub-tree , and lastly the root .
Postorder traversal is Defined as
* Traverse the left sub-tree of the root R in postorder
* Traverse the right sub-tree of the root R in postorder
* Visit the root node R
*/

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BinarySearchTree {
    constructor() {
        this.root = null;
    }
    //insert function inserts a new node into the binary search tree
    insert(value) {
        var New = new Node(value);
        if (this.root === null) {
            this.root = New;
            return this;
        }
        let curr = this.root;
        let prev = null;
        while (curr) {
            if (value < curr.data) {
                prev = curr;
                curr = curr.left;
            }
            else if (value > curr.data) {
                prev = curr;
                curr = curr.right;
            }
        }
        if (prev.data > value) {
            prev.left = New;
            return this;
        }
        else {
            prev.right = New;
            return this;
        }

    }

    recursive_postorder(node) {
        if (node !== null) {
            this.recursive_postorder(node.left);
            this.recursive_postorder(node.right);
            console.log(node.data);
        }
    }
}

/*
install readline-sync module to get user input 
To install use the command : npm install readline-sync
*/
const readline = require("readline-sync");
console.log("Enter the number of nodes to insert");
let n = Number(readline.question());

let b = new BinarySearchTree();
console.log("Enter the values of nodes to insert\n")
for (let i = 0; i < n; i++) {
    console.log("Enter the value for node " + (i + 1));
    b.insert(Number(readline.question()));
}
let root = b.root;
console.log("The postorder traversal for the binary search tree ")
b.recursive_postorder(root);

/*
Sample I/O :

Enter the number of nodes to insert
5
Enter the values of nodes to insert

Enter the value for node 1
4
Enter the value for node 2
2
Enter the value for node 3
5
Enter the value for node 4
3
Enter the value for node 5
1
The postorder traversal for the binary search tree
1
3
2
5
4

Time complexity : O(n)
Space complexity : O(n)
*/
