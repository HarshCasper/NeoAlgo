/*
 reverse linked list is an implimention of a singly linked list with an algorithm to reverce the order of the list
*/
package main

import (
	"fmt"
)

type Node struct {
	value int
	next  *Node
}

type List struct {
	head *Node
	tail *Node
	size int
}

// makeLinkedList: creates an empty linked list
func makeLinkedList() List {
	var node *Node = nil
	l := List{node, node, 1}
	return l
}

// createAtFront: create a node at the front of the list with the value the passed in int
func (list *List) createAtFront(data int) {
	var node Node
	node.value = data
	node.next = list.head
	if list.tail == nil {
		list.tail = &node
	}
	list.head = &node
	list.size++
	fmt.Printf("created a node with the value %d at the frount of the list\n", data)
}

// printList: prints out the linked list from head to tail.
// func (list *List) printList() {
// 	currentNode := list.head
// 	for currentNode != nil {
// 		fmt.Printf("%d ", currentNode.value)
// 	}
// }

// printList: prints out the linked list from head to tail
func (list *List) printList() {
	currentNode := list.head
	for currentNode != nil {
		fmt.Printf("%d->", currentNode.value)
		currentNode = currentNode.next
	}
	fmt.Printf("\n")
}

// reverseLinkedList: reverses the linked list
func (list *List) reverseLinkedList() {
	// grabs first node in the list
	currentNode := list.head
	// setting up the previous node
	var prev *Node = nil
	// grabs the next node in the list
	next := currentNode.next
	// while not at the end of the list
	for currentNode != nil {
		// takes the next node after the current node
		next = currentNode.next
		// swap the current nodes next node to previous
		currentNode.next = prev
		// the new previous becomse the old previous
		prev = currentNode
		// the current node becomes the next node
		currentNode = next
	}
	// the lists tail is now the head
	list.tail = list.head
	// the lists head is now the last not nil node
	list.head = prev
	fmt.Println("successfully reversed the linked list")
}

// fillListWithDummyData: add's values 1 - 9 to the linked list by calling create at frount 9 times
func (list *List) fillListWithDummyData() {
	for i := 0; i < 10; i++ {
		list.createAtFront(i)
	}
	fmt.Println("added to the list with numbers 0-9")
}

func main() {
	list := makeLinkedList()
	userInput := 0
	shouldRun := true
	// I used the format from the other linked list in go to keep consistency between the two programs
	for shouldRun == true {
		fmt.Printf("1 -> insert element at front\n")
		fmt.Printf("2 -> insert dummy data\n")
		fmt.Printf("3 -> print linked list\n4 -> reverse linked list\n")
		fmt.Printf("4 -> reverse linked list\n")
		fmt.Printf("5 -> quit\n")
		for userInput <= 0 && userInput <= 5 {
			fmt.Scanf("%d", &userInput)
		}
		switch userInput {
		case 1:
			var value int
			fmt.Scanf("%d", &value)
			list.createAtFront(value)
			break
		case 2:
			list.fillListWithDummyData()
			break
		case 3:
			list.printList()
			break
		case 4:
			list.reverseLinkedList()
			break
		case 5:
			shouldRun = false
			break
		}
		userInput = 0
		fmt.Printf("\n\n")
	}
}
