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

type stack struct {
	top  *node
	size int
}

func (obj *stack) isEmpty() bool {
	return obj.size == 0
}

// Adds the given element to the beginning of the stack
func (obj *stack) Push(value interface{}) {
	obj.top = &node{
		data: value,
		next: obj.top,
	}
	obj.size++
}

// Removes the element at the beginning of the stack
// and returns the element along with an error message
// if the stack is empty else 'nil'
func (obj *stack) Pop() (interface{}, error) {
	if obj.top == nil {
		return nil, errors.New("Empty stack")
	}

	var data interface{}
	data, obj.top = obj.top.data, obj.top.next
	obj.size--

	return data, nil
}

// Returns a random element to insert in the Stack
func getElement() interface{} {
	var temp interface{} = rand.Intn(100)
	fmt.Println("Element: ", temp)

	return temp
}

// Returns the value at the beginning of the stack
// along with the error message
func (obj *stack) Peek() (interface{}, error) {
	if obj.top == nil {
		return nil, errors.New("Empty stack")
	}

	return obj.top.data, nil
}

func main() {
	var object stack
	var flag bool = true
	var choice int

	for flag {
		fmt.Print("Menu\n1. Push element\n2. Pop element\n3. Peek element\n4. Count of elements\n5. Exit\nEnter your choice: ")
		fmt.Scan(&choice)

		switch choice {
		case 1:
			element := getElement()
			object.Push(element)
		case 2:
			element, err := object.Pop()
			fmt.Println("Element: ", element)
			fmt.Println("Error: ", err)
		case 3:
			element, err := object.Peek()
			fmt.Println("Element: ", element)
			fmt.Println("Error: ", err)
		case 4:
			fmt.Println("The total number of elements present in the Stack are: ", object.size)
		case 5:
			flag = false
		default:
			fmt.Println("Please enter valid choice.")
		}
	}
}
