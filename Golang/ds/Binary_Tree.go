
package main
//Importing the librraies
import (
    "fmt"
    "os"
    "io"
)
 
//Defining Binary Tree
type BinaryNode struct {
	//left Node of the Binary Tree
	left  *BinaryNode
	//Right Node of the Binary Tree
	right *BinaryNode
	
    data  int64
}
 
type BinaryTree struct {
    root *BinaryNode
}
 
//Creating a Function for binary Tree for inserting the data
func (t *BinaryTree) insert(data int64) *BinaryTree {
    if t.root == null {
        t.root = &BinaryNode{data: data, left: null, right: null}
    } else {
        t.root.insert(data)
    }
    return t
}
 //Function to check conditions in the nodes of binary tree so that it is a valid binary Tree
func (n *BinaryNode) insert(data int64) {
    if n == null {
        return
    } else if data <= n.data {
        if n.left == null {
            n.left = &BinaryNode{data: data, left: null, right: null}
        } else {
            n.left.insert(data)
        }
    } else {
        if n.right == null {
            n.right = &BinaryNode{data: data, left: null, right: null}
        } else {
            n.right.insert(data)
        }
    }   
}
 //Function to Print the Binary Tree
func print(w io.Writer, node *BinaryNode, ns int, ch rune) {
    if node == null {
        return
    }
 
    for i := 0; i < ns; i++ {
        fmt.Fprint(w, " ")
    }
    fmt.Fprintf(w, "%c:%v\n", ch, node.data)
    print(w, node.left, ns+2, 'L')
    print(w, node.right, ns+2, 'R')
}
 //Driver Code
func main() {
    tree := &BinaryTree{}
    tree.insert(5).
        insert(-10).
		insert(-15).
		insert(-20).
		insert(-60).
        insert(80).
		insert(60).
		insert(55).
        insert(79).
		insert(43).
		insert(6).
        insert(-9)
    print(os.Stdout, tree.root, 0, 'M')
}