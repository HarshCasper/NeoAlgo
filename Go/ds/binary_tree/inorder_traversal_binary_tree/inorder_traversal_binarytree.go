package main

import (
	"fmt"
	"os"
)

// Node defines the structure of a particular node in binary tree
type Node struct {
	data  int
	left  *Node
	right *Node
}

// NewNode creates a node and returns it's pointer
func NewNode(data int) *Node {
	return &Node{
		data: data,
	}
}

// CreateTree creates a new tree from level order array
func (root *Node) CreateTree(arr []int, pos, size int) *Node {
	var r *Node // nill by default
	if pos < size {

		r = NewNode(arr[pos])

		// fill left subtree
		r.left = r.CreateTree(arr, pos*2+1, size)

		// fill right subtree
		r.right = r.CreateTree(arr, pos*2+2, size)
	}
	return r
}

// InorderTraversal prints the Inorder traversal of tree
func (root *Node) InorderTraversal() {
	// Inorder Traversal : Left -> Root -> Right
	if root != nil {
		root.left.InorderTraversal()
		fmt.Printf("%v ", root.data)
		root.right.InorderTraversal()

	}
}

// Driver Code
func main() {
	// taking size of tree
	var size int
	fmt.Println("Enter size of the tree: ")
	_, err := fmt.Scanf("%d\n", &size)
	// exit on invalid size
	if err != nil {
		println("Invalid size")
		os.Exit(-1)
	}

	// allocating memory for array
	arr := make([]int, size)
	fmt.Println("Enter values in level order fashion: ")

	// Taking inpur
	for i := 0; i < size; i++ {
		_, err = fmt.Scanf("%d", &arr[i])

		if err != nil {
			println("Invalid argument")
			os.Exit(-1)
		}
	}

	// declaring root
	var root *Node

	// creating the tree
	root = root.CreateTree(arr, 0, size)

	// Calling InorderTraversal
	root.InorderTraversal()
}

/*
Sample input:
Enter size of the tree:
6
Enter values in level order fashion:
5 6 7 3 10 9

Example Input Tree

			  5
		    /   \
		  6      7
		 / \    /
		3  10  9

Output
3 6 10 5 9 7
*/
