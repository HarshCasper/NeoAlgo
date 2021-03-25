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
	list.size = 0
}

// isEmpty(): if the head of list is not poiting any node then it will return true otherwise false
func (list *List) isEmpty() bool {
	return list.head == nil
}

// insertAtFront(): if the list is empty then it will assign the same value to head and tail of linked list
// otherwise it will insert node before the head in linked list
func (list *List) insertAtFront() {
	var value int
	fmt.Println("enter the value of element to be inserted at front:")
	fmt.Scanf("%d", &value)
	var node Node
	node.data = value
	if list.isEmpty() {
		list.head = &node
		list.tail = &node
		list.size = 1
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
	fmt.Println("enter the value of element to be inserted at the end:")
	fmt.Scanf("%d", &value)
	var node Node
	node.data = value
	if list.isEmpty() {
		list.head = &node
		list.tail = &node
		list.size = 1
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
	fmt.Println("enter the value of element to be inserted at above position:")
	fmt.Scanf("%d", &value)
	node.data = value
	if list.isEmpty() {
		list.head = &node
		list.tail = &node
		list.size = 1
	} else {
		temp := list.head
		if position < 2 {
			node.next = list.head
			list.head = &node
		} else if position == list.size+1 {
			list.tail.next = &node
			list.tail = &node
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

// we dont need deallocate memory from removed node manually
// because GO garbage collector will do it by it self automatically
func (list *List) deleteFromFront() {
	if list.isEmpty() {
		fmt.Println("Linked List empty could'n delete element")
	} else {
		list.head = list.head.next
		list.size--
		fmt.Println("successfully deleted element from the front")
	}
}

// deleteFromEnd(): it traverse through all liked list and just dereffrence the last node
func (list *List) deleteFromEnd() {
	if list.isEmpty() {
		fmt.Println("Linked List empty could'n delete element")
	} else {
		temp := list.head
		// iterate unitll temp become second last node
		for i := 0; i < list.size-1; i++ {
			temp = temp.next
		}

		// making second last node's next nil so GC will automatically free the
		// memory used by last node
		temp.next = nil
		list.size--
		fmt.Println("successfully deleted element from the end")
	}
}

func (list *List) deleteFromGivinPosition() {
	if list.isEmpty() {
		fmt.Println("Linked List empty could'n delete element")
	} else {
		temp := list.head
		var position int
		fmt.Println("enter the position of element")
		fmt.Scanf("%d", &position)

		// first node before given position
		for i := 0; i < position-2; i++ {
			temp = temp.next
		}

		// first node after given position
		nextNode := temp.next.next

		// will link the node which come after given position to
		// node which come before given position
		temp.next = nextNode

		// GC will deallocate memory from unsed node
		list.size--
		fmt.Printf("successfully deleted element from the given position: %d\n", position)
	}
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
		for i := 0; i < list.size; i++ {
			fmt.Printf("%d ", temp.data)
			temp = temp.next
		}
		fmt.Println()
	}
}

func main() {
	var linkList List
	linkList.initList() // initalizing the linkList for first time

	var choice int
	var isContinue bool = true
	fmt.Println("Please enter option")
	for isContinue {
		fmt.Println("1 -> insert element at front\n2 -> insert element at end\n" +
			"3 -> insert element at given position\n4 -> print length\n" +
			"5 -> delete element from front\n6 -> delete element from end\n" +
			"7 -> delete element from given position\n8 -> print the linked list\n" +
			"9 -> exit program")
		fmt.Scanf("%d", &choice)

		switch choice {
		case 1:
			linkList.insertAtFront()
			break
		case 2:
			linkList.insertAtEnd()
			break
		case 3:
			linkList.insertAtGivenPosition()
			break
		case 4:
			linkList.length()
			break
		case 5:
			linkList.deleteFromFront()
			break
		case 6:
			linkList.deleteFromEnd()
			break
		case 7:
			linkList.deleteFromGivinPosition()
			break
		case 8:
			linkList.print()
			break
		case 9:
			isContinue = false
			break
		default:
			fmt.Println("Please enter correct option")
			break
		}
	}
}

/*
	input/output sample

	Please enter option
	1 -> insert element at front
	2 -> insert element at end
	3 -> insert element at given position
	4 -> print length
	5 -> delete element from front
	6 -> delete element from end
	7 -> delete element from given position
	8 -> print the linked list
	9 -> exit program
	1
	enter the value of element to be inserted at front:
	1
	value added successfully at the front of the linked list
	1 -> insert element at front
	2 -> insert element at end
	3 -> insert element at given position
	4 -> print length
	5 -> delete element from front
	6 -> delete element from end
	7 -> delete element from given position
	8 -> print the linked list
	9 -> exit program
	2
	enter the value of element to be inserted at the end:
	2
	value added successfully at the end of the linked list
	1 -> insert element at front
	2 -> insert element at end
	3 -> insert element at given position
	4 -> print length
	5 -> delete element from front
	6 -> delete element from end
	7 -> delete element from given position
	8 -> print the linked list
	9 -> exit program
	3
	enter the position for element
	3
	enter the value of element to be inserted at above position:
	3
	value added successfully at position: 3 of the linked
	1 -> insert element at front
	2 -> insert element at end
	3 -> insert element at given position
	4 -> print length
	5 -> delete element from front
	6 -> delete element from end
	7 -> delete element from given position
	8 -> print the linked list
	9 -> exit program
	8
	the current state of linked list is:
	1 2 3

*/
