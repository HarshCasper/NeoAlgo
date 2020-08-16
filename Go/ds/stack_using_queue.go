/*
	==============================================================
			Implementing QUEUE using STACK data structure
	==============================================================
	stack can be implemented using two queues

	 1 -> By making push() operation costly :
		This method enqueue new entered element in the pushQueue,
		so that pop() operation just dequeue from pushQueue. To put the element at top of pushQueue, popQueue is used.

	  2 -> By making pop() operation costly :
		In this method, in push() operation, the new element is entered at the top of pushQueue.
		In pop() operation, all the elements of pushQueue are dequeued and enqueued to popQueue and top of popQueue is returned.
		finally all the elements of popQueue dequeued and enqueued to pushQueue again

	  This program uses second way

*/

package main

import (
	"fmt"
)

// LENGTH of every Stack and Queue in this program
const LENGTH int = 10

// QUEUE user-definded data type to hold the variables for our queue data structure
type QUEUE struct {
	front int
	back  int
	array [LENGTH]int
}

func (queue *QUEUE) initQueue() {
	queue.front = -1
	queue.back = -1
}

// isEmpty(): checks if the both front and back are less than 0 it means Queue is empty
func (queue *QUEUE) isEmpty() bool {
	if queue.front < 0 && queue.back < 0 {
		return true
	}
	return false
}

// iFull(): checks if the back of Queue is greater or equals to last index of array,
// if so it will return true otherwise false
func (queue *QUEUE) isFull() bool {
	if queue.back >= LENGTH-1 {
		return true
	}
	return false
}

// enQueue(): it first checks if there is space available for new element,
// if available it will just enqueue the value
func (queue *QUEUE) enQueue(value int) {
	if queue.isFull() {
		fmt.Println("Queue is full")
	} else {
		if queue.front < 0 {
			queue.front++
		}
		queue.back++
		queue.array[queue.back] = value
	}
}

// pop(): this will remove the value from the front of the queue
func (queue *QUEUE) deQueue() int {
	var data int
	if queue.isEmpty() {
		fmt.Println("Queue is empty")
	} else {
		data = queue.array[queue.front]
		queue.front++
		if queue.front > queue.back {
			queue.initQueue()
		}
	}
	return data
}

// printQueue(): if queue is not empty then it will simply print the element
func (queue *QUEUE) printQueue() {
	for i := queue.front; i <= queue.back; i++ {
		fmt.Printf("%d ", queue.array[i])
	}
}

// STACK user-defined data type will use for implementing stack using queue
type STACK struct {
	top       int
	pushQueue QUEUE
	popQueue  QUEUE
}

func (stack *STACK) initStack() {
	stack.top = -1
	stack.pushQueue.initQueue()
	stack.popQueue.initQueue()
}

// isEmpty(): this checks if stack is empty or not
func (stack *STACK) isEmpty() bool {
	if stack.top < 0 {
		return true
	}
	return false
}

// isFull(): this checks if stack is full or not
func (stack *STACK) isFull() bool {
	if stack.top >= LENGTH-1 {
		return true
	}
	return false
}

// push(): if there is space for new element it will simply enqueue the element to pushQueue
func (stack *STACK) push() {
	var data int
	if stack.isFull() {
		fmt.Println("Stack is full")
	} else {
		stack.top++
		fmt.Println("enter the value: ")
		fmt.Scanf("%d", &data)
		stack.pushQueue.enQueue(data)
		fmt.Println("value pushed succesfully at the end of the Stack")
	}
}

// pop(): if stack is not empty then first it will dequeue all the element from pushQueue
// and enqueue them in popQueue and return the poped element by dequeuing popQueue
// and finally it will again enqueue all the element of popQueue by dequeuing
func (stack *STACK) pop() {
	var data int
	if stack.isEmpty() {
		fmt.Println("Stack is empty")
	} else {
		for i := 0; i <= stack.top; i++ {
			stack.popQueue.enQueue(stack.pushQueue.deQueue())
		}
		data = stack.popQueue.deQueue()
		stack.top--
		for i := 0; i <= stack.top; i++ {
			stack.pushQueue.enQueue(stack.popQueue.deQueue())
		}
		fmt.Printf("Poped element is: %d\n", data)
	}
}

// printStack(): if stack is not empty it will print the elements of pushQueue
func (stack *STACK) printStack() {
	if stack.isEmpty() {
		fmt.Println("Stack is empty")
	} else {
		stack.pushQueue.printQueue()
		fmt.Print("\n")
	}
}

func main() {
	var stack STACK
	stack.initStack() // initalizing stack for first time
	var choice int
	var isContinue bool = true
	fmt.Println("Please enter option")
	for isContinue {
		fmt.Println("1 -> push element\n2 -> pop element\n3 -> print Stack\n4 -> exit program")
		fmt.Scanf("%d", &choice)

		switch choice {
		case 1:
			stack.push()
			break
		case 2:
			stack.pop()
			break
		case 3:
			stack.printStack()
			break
		case 4:
			isContinue = false
			break
		default:
			fmt.Println("Please enter correct option")
			break
		}
	}
}
