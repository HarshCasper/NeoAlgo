/* This program prints post order traversal of a tree. In post order,
the traversal is done as : (left, right, root). */

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



/* This function prints thre post order traversal of
the tree recursively.*/
func post_order(root *Node) {

	// If we reach the end, return
	if(root == nil) {
		return
	}
	// Call the function for left half
	post_order(root.left)
	// Then, call for the right half
	post_order(root.right)

	// Print the data
	fmt.Print(root.data, " ")
}

// This function creates a new node
func new_node(value int) *Node {
	// It takes data to be stored as parameter
	return &Node{value, nil, nil}
}

// This function forms the tree using the user input
func form_tree(array []int) *Node {

	/* The user input is considered as level
	order traversal of the tree. This function
	returns pointer to the root of the tree.*/

	// This array contains all nodes in the tree
	a := make([]*Node , len(array))
	for i := 0; i < len(array); i++ {
		a[i] = new_node(array[i])
	}

	// Below are some base cases for 1, 2, 3, 4 nodes

	// If there is only one node return the node
	if(len(array) == 1) {
		return a[0]
	}

	// If there are two nodes
	a[0].left = a[1]
	if(len(array) == 2) {
		// Point the second node to first and return
		return a[0]
	}

	// If there are three nodes
	a[0].right = a[2]
	if(len(array) == 3) {
		// Make a binary tree and return root node
		return a[0]
	}

	// If there are four nodes
	if(len(array) == 4) {
		a[1].left = a[3]
		return a[0]
	}

	// If there are more than four nodes
	for i := 1; i < len(array); i++ {

		// Point  each node to its left and right child
		a[i].left = a[2*i + 1]
		a[i].right = a[2*i + 2]

		// If we reach the end, return root node
		if(2*i + 2 == len(array) - 1) {
			return a[0]
		}
	}
	// Return root node
	return a[0]
}

func main() {

	// Take number of nodes in the tree as input from the user
	fmt.Print("Enter the number of nodes in the tree: ")
	var n int
	fmt.Scan(&n)

	// Take the value of nodes as input
	fmt.Print("Enter the value of nodes of tree in level order traversal manner: ")
	array := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&array[i])
	}

	// Call the function and form the tree
	var root *Node = form_tree(array)

	// Call the post order function and print it
	fmt.Print("\nPost order traversal of the tree is: ")
	post_order(root)
	fmt.Print("\n")
}

/*
Sample I/O:

Enter the number of nodes in the tree: 11
Enter the value of nodes of tree in level order traversal manner: 1 2 3 4 5 6 7 8 9 10 11

Post order traversal of the tree is: 8 9 4 10 11 5 2 6 7 3 1

*/
