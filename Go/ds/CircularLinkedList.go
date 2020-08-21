package main

import "fmt"

// A linked list node
type node struct {
	data interface{}
	next *node
}

// A circular linked list
type circularLinkedList struct {
	head *node
	tail *node
	size int
}

// Inserts the given data to the head of the circular linked list
func (list *circularLinkedList) insert(value interface{}) {
	var temp = node{
		data: value,
	}

	if list.head == nil {
		list.head = &temp
		list.tail = &temp
		list.tail.next = list.head
	} else {
		list.tail.next = &temp
		list.tail = &temp
		list.tail.next = list.head
	}

	list.size++
}

// Prints the circular linked list
func (list *circularLinkedList) display() {
	var curr = list.head

	if list.head == nil {
		fmt.Println("Empty list")
	} else {
		fmt.Print("Nodes of Circular Linked List are: ")

		for curr.next != list.head {
			fmt.Print(curr.data)
			fmt.Print(" ")
			curr = curr.next
		}
		fmt.Print(curr.data)

		fmt.Println()
		fmt.Println(list.size)
	}
}

// Remove the node, if present, at the given index
func (list *circularLinkedList) remove(index int) {
	if index >= list.size {
		fmt.Println("Index not present in the Circular Linked List")
		return
	}

	if index == 0 {
		var temp = list.head
		list.head = temp.next
		list.tail.next = list.head
	} else {
		var iter = 0
		var curr = list.head

		for iter+1 < index {
			iter++
			fmt.Println(curr.data)
			curr = curr.next
		}
		var temp = curr
		curr.next = temp.next.next
	}

	list.size--
}

// Returns the size of the given circular linked list
func (list *circularLinkedList) length() int {
	return list.size
}

func main() {
	var list circularLinkedList

	list.insert(0)
	list.insert(1)
	list.insert(2)
	list.insert(3)
	list.display()
	list.remove(0)
	list.display()
	list.remove(1)
	list.display()
	list.remove(2)
}
