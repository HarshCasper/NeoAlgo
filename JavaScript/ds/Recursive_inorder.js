/*
In inorder traversal,before visiting the root node, the left sub-tree of the root node
is visited,then the root node after the visit of the root node the right sub-tree of the
root node is visited. Visiting both the sub-trees is in the same fashion as the tree itself.
The traversal is defines as 
* Traverse the left sub-tree of the root node R in inorder
* Visit the root node R
* Traverse the right sub-tree of the root node R in inorder
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

    recursive_inorder(node) {
        if (node !== null) {
            this.recursive_inorder(node.left);
            console.log(node.data);
            this.recursive_inorder(node.right);
        }
    }
}

let b = new BinarySearchTree();
let arr = [5, 1, 4, 3, 2]; // elements to be inserted into the binary search tree
for (let i = 0; i < arr.length; i++) {
    b.insert(arr[i]);//inserting the elements to the binary search tree
}

let root = b.root;
console.log("The inorder traversal for the binary search tree ")
b.recursive_inorder(root);

