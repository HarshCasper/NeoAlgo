/*
	==============================================================
			Implementing QUEUE using STACK data structure
	==============================================================
	  queue can be implemented in two ways:

	  1 -> By making enQueue() operation costly :
		This method push the new element at the top of enQueueStack,
		so that deQueue operation just pops from enQueueStack.
		To put the element at top of enQueueStack, deQueueStack is used.

	  2 -> By making deQueue() operation costly :
		In this method, in en-queue operation, the new element is entered at the top of enQueueStack.
		In de-queue operation, all the elements of enQueueStack are moved to deQueueStack and top of deQueueStack is returned.
		finally all the elements of deQueueStack are moved to enQueueStack

	This program uses second way

*/

package main

import (
	"fmt"
)

// LENGTH of every Stack and Queue in this program
const LENGTH int = 10

// STACK user-definded data type to hold the variables for our stack data structure
type STACK struct {
	top   int
	array [LENGTH]int
}

// init(): this will initialize the stack for use
func (stack *STACK) initStack() {
	stack.top = -1
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

// push(): this will push the value to the top of the stack
func (stack *STACK) push(value int) {
	if stack.isFull() {
		fmt.Println("Stack is Full")
	} else {
		stack.top++
		stack.array[stack.top] = value

	}
}

// pop(): this will remove the value from the top of the stack
func (stack *STACK) pop() int {
	var data int
	if stack.isEmpty() {
		fmt.Println("Stack is empty")
	} else {
		data = stack.array[stack.top]
		stack.top--

	}

	return data
}

// QUEUE user-defined data type will use for implemnting Queue data structure using Stack
type QUEUE struct {
	front        int
	back         int
	enQueueStack STACK
	deQueueStack STACK
}

func (queue *QUEUE) initQueue() {
	queue.front = -1
	queue.back = -1
	queue.enQueueStack.initStack()
	queue.deQueueStack.initStack()
}

func (queue *QUEUE) length() {
	if queue.isEmpty() {
		fmt.Println("The current length of Queue is 0")
	} else {
		fmt.Printf("The current length of Queue is %d\n", queue.back-queue.front+1)
	}
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
// if available it will just push the value in the enQueueStack
func (queue *QUEUE) enQueue() {
	var data int
	if queue.isFull() {
		fmt.Println("Can't insert value")
		fmt.Println("Queue is full")
	} else {
		if queue.front < 0 {
			queue.front++
		}
		fmt.Print("enter the value: ")
		fmt.Scanf("%d", &data)
		queue.back++
		queue.enQueueStack.push(data)
		fmt.Println("value inserted succesfully at the end of the Queue")
	}
}

// deQueue(): if the underlying stacks are not empty then it will pop all elemnt from enQueueStack
// and push them to deQueueStack and return the value by poping it from deQueueStack
// and finally it will pop all element from deQueueStack and push them to enQueueStack again
func (queue *QUEUE) deQueue() {
	if queue.front < 0 || queue.front > queue.back {
		fmt.Println("Can't delete value")
		fmt.Println("Queue is empty")
	} else {
		for i := 0; i <= queue.back-queue.front; i++ {
			queue.deQueueStack.push(queue.enQueueStack.pop())
		}
		fmt.Printf("Succesfully deleted element %d from the front of the Queue\n", queue.deQueueStack.pop())
		queue.front++
		for i := 0; i <= queue.back-queue.front; i++ {
			queue.enQueueStack.push(queue.deQueueStack.pop())
		}
		if queue.front > queue.back {
			queue.initQueue()
		}
	}
}

// printQueue(): if queue is not empty then it will simply
// print all the elements of enQueueStack
func (queue *QUEUE) printQueue() {
	if queue.isEmpty() {
		fmt.Println("Queue is empty")
	} else {
		fmt.Println("Current state of Queue is")
		for i := 0; i <= queue.back-queue.front; i++ {
			fmt.Printf("%d ", queue.enQueueStack.array[i])
		}
		fmt.Print("\n")
	}
}

func main() {
	var queue QUEUE
	queue.initQueue() // initalizing queue for first time
	var choice int
	var isContinue bool = true
	fmt.Println("Please enter option")
	for isContinue {
		fmt.Println("1 -> insert element\n2 -> delete element\n3 -> print Queue\n4 -> print length\n5 -> exit program")
		fmt.Scanf("%d", &choice)

		switch choice {
		case 1:
			queue.enQueue()
			break
		case 2:
			queue.deQueue()
			break
		case 3:
			queue.printQueue()
			break
		case 4:
			queue.length()
			break
		case 5:
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
	1 -> insert element
	2 -> delete element
	3 -> print Queue
	4 -> print length
	5 -> exit program
	1
	enter the value: 4
	value inserted succesfully at the end of the Queue
	1 -> insert element
	2 -> delete element
	3 -> print Queue
	4 -> print length
	5 -> exit program
	1
	enter the value: 5
	value inserted succesfully at the end of the Queue
	1 -> insert element
	2 -> delete element
	3 -> print Queue
	4 -> print length
	5 -> exit program
	1
	enter the value: 6
	value inserted succesfully at the end of the Queue
	1 -> insert element
	2 -> delete element
	3 -> print Queue
	4 -> print length
	5 -> exit program
	3
	Current state of Queue is
	4 5 6
	1 -> insert element
	2 -> delete element
	3 -> print Queue
	4 -> print length
	5 -> exit program
	2
	Succesfully deleted element 4 from the front of the Queue
	1 -> insert element
	2 -> delete element
	3 -> print Queue
	4 -> print length
	5 -> exit program
	2
	Succesfully deleted element 5 from the front of the Queue
	1 -> insert element
	2 -> delete element
	3 -> print Queue
	4 -> print length
	5 -> exit program
	3
	Current state of Queue is
	6
	1 -> insert element
	2 -> delete element
	3 -> print Queue
	4 -> print length
	5 -> exit program
	4
	The current length of Queue is 1
*/
