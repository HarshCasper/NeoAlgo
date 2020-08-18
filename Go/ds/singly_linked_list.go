/*
	==============================================================
		 Implementing Singly Linked List  data structure
	==============================================================
*/

package main

import (
	"fmt"
)

// Node it is user-defined data type used to store data and the address of next node
type Node struct {
	next *Node
	data int
}

// List it is user-defined data type used to represent the linked list
type List struct {
	head *Node
	tail *Node
	size int
}

// initList(): it will initalize the List's fields for first time
func (list *List) initList() {
	list.head = nil
	list.tail = nil
	list.size = 1
}

// isEmpty(): if the head of list is not poiting any node then it will return true otherwise false
func (list *List) isEmpty() bool {
	return list.head == nil
}

// insertAtFront(): if the list is empty then it will assign the same value to head and tail of linked list
// otherwise it will insert node before the head in linked list
func (list *List) insertAtFront() {
	var value int
	fmt.Println("enter the value of element:")
	fmt.Scanf("%d", &value)
	var node Node
	node.data = value
	if list.isEmpty() {
		list.head = &node
		list.tail = &node
		list.size = 0
	} else {
		node.next = list.head
		list.head = &node
		list.size++
	}
	fmt.Println("value added successfully at the front of the linked list")
}

// insertAtEnd(): if the list is empty then it will assign the same value to head and tail of linked list
// otherwise it will insert node after the tail in linked list
func (list *List) insertAtEnd() {
	var value int
	fmt.Println("enter the value of element:")
	fmt.Scanf("%d", &value)
	var node Node
	node.data = value
	if list.isEmpty() {
		list.head = &node
		list.tail = &node
		list.size = 0
	} else {
		list.tail.next = &node
		list.tail = &node
		list.size++
	}
	fmt.Println("value added successfully at the end of the linked list")
}

// insertAtGivenPosition(): if the list is empty then it will assign the same value to head and tail of linked list
// otherwise it will insert node at the given psition in linked list
func (list *List) insertAtGivenPosition() {
	var position int
	var value int
	var node Node

	fmt.Println("enter the position for element")
	fmt.Scanf("%d", &position)
	fmt.Println("enter the value of element:")
	fmt.Scanf("%d", &value)
	node.data = value
	if list.isEmpty() {
		list.head = &node
		list.tail = &node
		list.size = 0
	} else {
		temp := list.head
		if position < 2 {
			node.next = list.head
			list.head = &node
		} else {
			for i := 0; i < position-2; i++ {
				temp = temp.next
			}
			node.next = temp.next
			temp.next = &node
		}
		list.size++

	}
	fmt.Printf("value added successfully at position: %d of the linked\n", position)
}

// length(): will print the total number of node available at a time
func (list *List) length() {
	if list.isEmpty() {
		fmt.Println("Linked List is empty")
	} else {
		fmt.Printf("the number of avialbale node in Linked List is %d\n", list.size)
	}
}

// print(): it will travers through linked list and prints the data of each node
func (list *List) print() {
	if list.isEmpty() {
		fmt.Println("Linked List is empty")
	} else {
		temp := list.head
		fmt.Println("the current state of linked list is:")
		for i := 0; i <= list.size; i++ {
			fmt.Printf("%d ", temp.data)
			temp = temp.next
		}
		fmt.Println()
	}

}

func main() {
	var linkList List
	linkList.initList() // initalizing the linkList for first time

	linkList.insertAtFront()
	linkList.insertAtFront()
	linkList.insertAtEnd()
	linkList.insertAtEnd()
	linkList.insertAtGivenPosition()
	linkList.print()
	linkList.length()
}

/*
	input/output sample

	enter the value of element:
	1
	value added successfully at the front of the linked list
	enter the value of element:
	2
	value added successfully at the front of the linked list
	enter the value of element:
	3
	value added successfully at the end of the linked list
	enter the value of element:
	4
	value added successfully at the end of the linked list
	enter the position for element
	2
	enter the value of element:
	6
	value added successfully at position: 2 of the linked
	the current state of linked list is:
	2 6 1 3 4
	the number of avialbale node in Linked List is 5

*/
