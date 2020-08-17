// LIFO and FIFO in Golang
package main
  
import (
    "fmt"
)
  
type Node struct {
    Value int
}
  
func (n *Node) String() string {
    return fmt.Sprint(n.Value)
}
  
// NewStack returns a new stack.
func NewStack() *Stack {
    return &Stack{}
}
  
// Stack is a basic LIFO stack that resizes as needed.
type Stack struct {
    nodes []*Node
    count int
}
  
// Push adds a node to the stack.
func (s *Stack) Push(n *Node) {
    s.nodes = append(s.nodes[:s.count], n)
    s.count++
}
  
// Pop removes and returns a node from the stack in last to first order.
func (s *Stack) Pop() *Node {
    if s.count == 0 {
        return nil
    }
    s.count--
    return s.nodes[s.count]
}
  
// NewQueue returns a new queue with the given initial size.
func NewQueue(size int) *Queue {
    return &Queue{
        nodes: make([]*Node, size),
        size:  size,
    }
}
  
// Queue is a basic FIFO queue based on a circular list that resizes as needed.
type Queue struct {
    nodes []*Node
    size  int
    head  int
    tail  int
    count int
}
  
// Push adds a node to the queue.
func (q *Queue) Push(n *Node) {
    if q.head == q.tail && q.count > 0 {
        nodes := make([]*Node, len(q.nodes)+q.size)
        copy(nodes, q.nodes[q.head:])
        copy(nodes[len(q.nodes)-q.head:], q.nodes[:q.head])
        q.head = 0
        q.tail = len(q.nodes)
        q.nodes = nodes
    }
    q.nodes[q.tail] = n
    q.tail = (q.tail + 1) % len(q.nodes)
    q.count++
}
  
// Pop removes and returns a node from the queue in first to last order.
func (q *Queue) Pop() *Node {
    if q.count == 0 {
        return nil
    }
    node := q.nodes[q.head]
    q.head = (q.head + 1) % len(q.nodes)
    q.count--
    return node
}
  
func main() {
    s := NewStack()
    s.Push(&Node{3})
    s.Push(&Node{5})
    s.Push(&Node{7})
    s.Push(&Node{9})
    fmt.Println(s.Pop(), s.Pop(), s.Pop(), s.Pop())
  
    q := NewQueue(1)
    q.Push(&Node{2})
    q.Push(&Node{4})
    q.Push(&Node{6})
    q.Push(&Node{8})
    fmt.Println(q.Pop(), q.Pop(), q.Pop(), q.Pop())
}