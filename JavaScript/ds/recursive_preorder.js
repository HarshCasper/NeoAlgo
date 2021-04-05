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

const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin , output: process.stdout });

const getLine = (function () {
    const getLineGen = (async function* () {
        for await (const line of rl) {
            yield line;
        }
    })();
    return async () => ((await getLineGen.next()).value);
})();

const main =  async()=>{
    console.log("Enter the number of nodes to insert");
    let n = Number(await getLine());
    let b = new BinarySearchTree();
    console.log("Enter the values of nodes to insert\n")
    for (let i = 0; i < n; i++) {
        console.log("Enter the value for node " + (i + 1));
        b.insert(Number(await getLine()));
    }
    let root = b.root;
    console.log("The preorder traversal for the binary search tree ")
    b.recursive_preorder(root);    
    process.exit(0);
}

main();
/*
Sample I/O:
Enter the number of nodes to insert
5
Enter the values of nodes to insert
Enter the value for node 1
4
Enter the value for node 2
3
Enter the value for node 3
5
Enter the value for node 4
1
Enter the value for node 5
2
The preorder traversal for the binary search tree
4
3
1
2
5
Time complexity : O(n)
Space complexity : O(n)
*/
