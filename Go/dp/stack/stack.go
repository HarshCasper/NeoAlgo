// Stack in Go

package main

import "fmt"

type stack []int

var limit = 5

func (stk *stack) pushStack(ele int) {
	if !((*stk).isFull()) {
		*stk = append(*stk, ele)
		fmt.Printf("Added element: %v\n", ele)
	} else {
		fmt.Println("Stack is full!")
	}
}

func (stk *stack) popStack() {
	if !((*stk).isEmpty()) {
		top_ele, top := (*stk).peekStack()
		fmt.Printf("Popped Element: %v\n", top_ele)
		(*stk) = (*stk)[:top]
	} else {
		fmt.Println("Stack is empty!")
	}
}

func (stk *stack) isEmpty() bool {
	return len(*stk) == 0
}

func (stk *stack) isFull() bool {
	return len(*stk) == limit
}

func (stk *stack) peekStack() (int, int) {
	top := len(*stk) - 1
	top_ele := (*stk)[top]
	return top_ele, top
}

func main() {
	fmt.Println("Welcome to Stack program in Go!")
	var stack1 stack
	stack1.pushStack(4)
	stack1.pushStack(5)
	stack1.pushStack(1)
	stack1.pushStack(3)
	stack1.pushStack(7)
	stack1.pushStack(9)
	stack1.popStack()
	stack1.popStack()
	stack1.popStack()
	topOfStack, topIndex := stack1.peekStack()
	fmt.Printf("Top element of stack: %v\tIndex of top element: %v\n", topOfStack, topIndex)
}
