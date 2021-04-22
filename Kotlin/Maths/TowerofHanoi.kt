/*
The Towers of Hanoi is a game where you have three pegs (#1, #2, and #3) and some circular disks of different sizes that slide onto the pegs.
They all start on one peg, largest to smallest (largest on the bottom). 
The goal is to move all the disks to another peg by following these rules:
you may only move one disk at a time from peg to peg no disk may be placed on top of a smaller disk.
    
Program will print the source and destination to transfer each disks for all the steps in chronological order.
*/

class Hanoi(disks: Int) {
    private var moves = 0

    init {
        println("Towers of Hanoi with $disks disks:\n")
        move(disks, 'L', 'C', 'R')                     
        println("\nCompleted in $moves moves\n")
    }

    private fun move(n: Int, from: Char, to: Char, via: Char) {
        if (n > 0) {
            move(n - 1, from, via, to)
            moves++
            println("Move disk $n from $from to $to")    
            move(n - 1, via, to, from)
        }
    }
}

fun main(args: Array<String>) {
     val sc = Scanner(System.`in`)

    println("Enter Number: ")                                
    val num: Int = sc.nextInt()
    Hanoi(num);
}

/*
Test Case :
******************************************************************
Input : 3
Output :
Towers of Hanoi with 3 disks:
Move disk 1 from L to C
Move disk 2 from L to R
Move disk 1 from C to R
Move disk 3 from L to C
Move disk 1 from R to L
Move disk 2 from R to C
Move disk 1 from L to C
******************************************************************
Time Complexity: O(2^n)
Space Complexity: O(n)
*/

