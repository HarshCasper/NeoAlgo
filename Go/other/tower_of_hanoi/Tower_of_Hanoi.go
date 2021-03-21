package main

import "fmt"

type solver interface {
	play(int)
}

type towers struct{}

func (t *towers) play(n int) {
	t.shiftN(n, 1, 2, 3)
}

func (t *towers) shiftN(n, from, to, via int) {
	if n > 0 {
		t.shiftN(n-1, from, via, to)
		t.shiftM(from, to)
		t.shiftN(n-1, via, to, from)
	}
}

func (t *towers) shiftM(from, to int) {
	fmt.Println("Shifting disk from rod", from, "to rod", to)
}

func main() {
	var t solver
	t = new(towers)
	t.play(4)
}

/*
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
1) Only one disk can be moved at a time.
2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3) No disk may be placed on top of a smaller disk.
In this code, we use the recursive definition of Tower of Hanoi.
Time Complexity: O(2^N)
Space Complexity: O(N)

INPUT: 4

OUTPUT:
Shifting disk from rod 1 to rod 3
Shifting disk from rod 1 to rod 2
Shifting disk from rod 3 to rod 2
Shifting disk from rod 1 to rod 3
Shifting disk from rod 2 to rod 1
Shifting disk from rod 2 to rod 3
Shifting disk from rod 1 to rod 3
Shifting disk from rod 1 to rod 2
Shifting disk from rod 3 to rod 2
Shifting disk from rod 3 to rod 1
Shifting disk from rod 2 to rod 1
Shifting disk from rod 3 to rod 2
Shifting disk from rod 1 to rod 3
Shifting disk from rod 1 to rod 2
Shifting disk from rod 3 to rod 2

*/
