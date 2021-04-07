/* This program prints pre-order traversal of a tree. In pre-order,
the traversal is done as : (root, left, right). */

package main

import (
	"fmt"
)

// Structure of a node in the tree
type Node struct {
	/* Every node has a data, pointer to its
	left child and also right child.*/
	data int
	left *Node
	right *Node
}

/* This function prints thre pre-order traversal of
the tree recursively.*/
func pre_order(root *Node) {

	// If we reach the end, return
	if(root == nil) {
		return
	}

	// Print the data
	fmt.Print(root.data, " ")

	// Call the function for left half
	pre_order(root.left)
	// Then, call for the right half
	pre_order(root.right)
}

// This function creates a new node
func new_node(value int) *Node {
	// It takes data to be stored as parameter
	return &Node{value, nil, nil}
}

func main() {

	// Declaring the root node
	var root *Node
	// Initializing the root node
	root = new_node(1)

	// Forming the rest of the tree
	root.left = new_node(2)
	root.right = new_node(3)

	root.left.left = new_node(4)
	root.left.right = new_node(5)

	root.right.left = new_node(6)
	root.right.right = new_node(7)

	fmt.Print("Pre-order traversal of the tree is: ")
	pre_order(root)
	fmt.Print("\n")
}

/* 

The tree considered in the above example is -

		1
		/\
	       /  \
	      /    \
	     2      3
	    /\	    /\
	   /  \    /  \
	  4    5  6    7

	  Output - 

	  Pre-order traversal of the tree is: 1 2 4 5 3 6 7 

*/
