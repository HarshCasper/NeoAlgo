package main

import (
	"errors"
	"fmt"
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
	object.Push(5)
	object.Push(10)
	fmt.Println(object.Peek())
	object.Push(15)
	fmt.Println(object.Pop())
	object.Push(20)
	fmt.Println(object.isEmpty())
	fmt.Println(object.Pop())
	fmt.Println(object.Pop())
	fmt.Println(object.Pop())
	fmt.Println(object.isEmpty())
	fmt.Println(object.Pop())
}
