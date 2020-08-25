package main

import (
	"errors"
	"fmt"
	"math/rand"
)

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
func (list *circularLinkedList) remove(index int) (interface{}, error) {
	if index >= list.size {
		return nil, errors.New("Index not present")
	}

	list.size--
	if index == 0 {
		var temp = list.head
		list.head = temp.next
		list.tail.next = list.head

		return temp.data, nil
	}

	var iter = 0
	var curr = list.head

	for iter+1 < index {
		iter++
		fmt.Println(curr.data)
		curr = curr.next
	}
	var temp = curr
	curr.next = temp.next.next

	return temp.next.data, nil
}

// Returns the size of the given circular linked list
func (list *circularLinkedList) length() int {
	return list.size
}

// Returns a random element to insert in the Circular Linked List
func getElement() interface{} {
	var temp interface{} = rand.Intn(100)

	return temp
}

// Returns a random index to remove from the Circular Linked List
func getIndex(size int) int {
	var temp int = rand.Intn(100) % size

	return temp
}

func main() {
	var list circularLinkedList
	var choice int
	var flag bool

	flag = true

	for flag {
		fmt.Print("Menu\n1. Insert element\n2. Remove element\n3. Display elements\n4. Count of elements\n5. Exit\nEnter your choice: ")
		fmt.Scan(&choice)

		switch choice {
		case 1:
			element := getElement()
			list.insert(element)
			fmt.Println("Inserted: ", element)
		case 2:
			if list.size == 0 {
				fmt.Println("No element present in the list.")
			} else {
				index := getIndex(list.size)
				data, err := list.remove(index)
				if err == nil {
					fmt.Println("Removed: ", data)
				} else {
					fmt.Println("Error: ", err)
				}
			}
		case 3:
			list.display()
		case 4:
			count := list.length()
			fmt.Println("Length: ", count)
		case 5:
			flag = false
		default:
			fmt.Println("Please enter a valid choice.")
		}
	}
}
