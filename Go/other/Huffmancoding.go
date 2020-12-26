package main

import (
	"container/heap"
	"fmt"
)

type HuffmanTree interface {
	Freq() int
}

type HuffmanLeaf struct {
	freq int
	value rune
}

type HuffmanNode struct {
	freq int
	left, right HuffmanTree
}

func (self HuffmanLeaf) Freq() int {
	return self.freq
}

func (self HuffmanNode) Freq() int {
	return self.freq
}

type treeHeap []HuffmanTree

func (th treeHeap) Len() int { return len(th) }
func (th treeHeap) Less(i, j int) bool {
	return th[i].Freq() < th[j].Freq()
}
func (th *treeHeap) Push(ele interface{}) {
	*th = append(*th, ele.(HuffmanTree))
}
func (th *treeHeap) Pop() (popped interface{}) {
	popped = (*th)[len(*th)-1]
	*th = (*th)[:len(*th)-1]
	return
}
func (th treeHeap) Swap(i, j int) { th[i], th[j] = th[j], th[i] }

func BuildTree(symFreqs map[rune]int) HuffmanTree {
  var trees treeHeap
	for c, f := range symFreqs {
		trees = append(trees, HuffmanLeaf{f, c})
	}

	heap.Init(&trees)
	for trees.Len() > 1 {
		a := heap.Pop(&trees).(HuffmanTree)
		b := heap.Pop(&trees).(HuffmanTree)
		heap.Push(&trees, HuffmanNode{a.Freq() + b.Freq(), a, b})
	}
	return heap.Pop(&trees).(HuffmanTree)
}

func printCodes(tree HuffmanTree, prefix []byte) {
	switch i := tree.(type) {
	case HuffmanLeaf:
		fmt.Printf("%c\t%d\t%s\n", i.value, i.freq, string(prefix))
	case HuffmanNode:
		prefix = append(prefix, '0')
		printCodes(i.left, prefix)
		prefix = prefix[:len(prefix)-1]
		prefix = append(prefix, '1')
		printCodes(i.right, prefix)
		prefix = prefix[:len(prefix)-1]
	}
}

// Test Code
func main() {
	test := "code"

	symFreqs := make(map[rune]int)

	for _, c := range test {
		symFreqs[c]++
	}

	Tree := BuildTree(symFreqs)
	fmt.Println("SYMBOL\tWEIGHT\tHUFFMAN CODE")
	printCodes(Tree, []byte{})
}


// Output
//SYMBOL	WEIGHT	HUFFMAN CODE
//  d	      1	        00
//  o     	1	        01
//  c	      1	        10
//  e     	1	        11

// Time Complexity = O(n) Space Complexity = O(n)
