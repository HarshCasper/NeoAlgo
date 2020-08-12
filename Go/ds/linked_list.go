package main

import "fmt"

// A linked list node
type Node struct {
	data	int
	next	*Node	
}

type LinkedList struct {
	head	*Node
	length	int
}

// Adds the given data to the end of the linked list
func (list *LinkedList) append(data int) {
	temp := Node{data, nil}
	if list.head == nil {
		list.head = &temp
	} else {
		curr := list.head
		for {
			if curr.next == nil {
				break
			}
			curr = curr.next
		}
		curr.next = &temp
	}
	list.length++
}

// Prints the data stored in all the nodes of the linked list
func (list *LinkedList) display() {
	curr := list.head
	for {
		if curr == nil {
			break
		}	
		fmt.Print(curr.data)
		fmt.Print(" ")
		curr = curr.next
	}
	fmt.Println()
}

// Inserts the given data at the given position(index) in the linked list
func (list *LinkedList) insert(index int, data int) {
	if (index >= 0 && index <= list.length) {
		temp := Node{data, nil}
		if (index == 0) {
			temp.next = list.head
			list.head = &temp
		} else {
			curr := list.head
			for itr := 0; itr < index - 1; itr++ {
				curr = curr.next
			}
			temp.next = curr.next
			curr.next = &temp
		}
		list.length++
	}			
}

// Removes the node at the given postion(index) from the linked list
func (list *LinkedList) delete(index int) (int) {
	if (index == 0) {
		temp := list.head
		list.head = list.head.next
		list.length--
		return temp.data
	} else {
		curr := list.head
		temp := curr
		for itr:= 0; itr < index; itr++ {
			temp = curr
			curr = curr.next
		}
		temp.next = curr.next
		list.length--
		return curr.data
	}
}

func main() {
	list := LinkedList{nil, 0}
	list.append(3)
	list.append(5)
	list.insert(0, 2)
	list.append(11)
	list.insert(3, 7)
	list.display()
	list.delete(3)
	list.display()
	fmt.Print(list.length)
}
