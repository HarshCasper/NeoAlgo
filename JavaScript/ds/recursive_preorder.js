/*
In Preorder traversal , the root is visited first , then the let sub-tree in preorder
fashion, and then the right subtree in preorder fashion.The traversal is defined as 
* Visit the root node R
*Traverse the left sub-tree of R in preorder
*Traverse the right sub-tree of R in preorder
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

    recursive_preorder(node) {
        if (node !== null) {
            console.log(node.data);
            this.recursive_preorder(node.left);
            this.recursive_preorder(node.right);
        }
    }
}

let b = new BinarySearchTree();
let arr = [5, 1, 4, 3, 2]; // elements to be inserted into the binary search tree
for (let i = 0; i < arr.length; i++) {
    b.insert(arr[i]);//inserting the elements to the binary search tree
}

let root = b.root;
console.log("The preorder traversal for the binary search tree ")
b.recursive_preorder(root);

