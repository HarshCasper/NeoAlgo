/*
AIM :: To solve the Tower of Hanoi problem.

                WHAT IS TOWER OF HANOI ?
The Tower of Hanoi is a mathematical game or puzzle. 
It consists of three rods and a number of disks of different sizes, 
which can slide onto any rod. The puzzle starts with the disks in a neat stack in ascending order of size on one rod, 
the smallest at the top, thus making a conical shape.

RULES ::
1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
3. No larger disk may be placed on top of a smaller disk.

*/

#include <stdio.h>
#include <conio.h>

void Tower_Of_Hanoi(int, char, char, char);

int main()
{
    int number_of_disks;
    printf("\nEnter the number of disks :: ");
    scanf("%d", &number_of_disks);

    /*
    here A , B , C is the towers 
    A :: source 
    B :: auxilary 
    C :: destination
    */
    Tower_Of_Hanoi(number_of_disks, 'A', 'C', 'B');

    return 0;
}

void Tower_Of_Hanoi(int number_of_disk, char source, char destination, char auxilary)
{
    //if there is only one disk then move it form source to destination
    if (number_of_disk == 1)
    {
        printf("\nmove disk %d from %c -> %c ", number_of_disk, source, destination);
        return;
    }

    //else if there is more than 1 disk, then move n-1 disk form source to auxilary using destintion
    Tower_Of_Hanoi(number_of_disk - 1, source, auxilary, destination);

    // so at this point of time there is only one disk in peg s rest  of n - 1 disk we have moved so manually move that
    printf("\nMove disk %d from %c -> %c ", number_of_disk, source, destination);

    //moving remaining disk from auxilary to destination using source
    Tower_Of_Hanoi(number_of_disk - 1, auxilary, destination, source);
}

/*
TEST CASE


Enter the number of disks :: 3

move disk 1 from A -> C
Move disk 2 from A -> B
move disk 1 from C -> B
Move disk 3 from A -> C
move disk 1 from B -> A
Move disk 2 from B -> C
move disk 1 from A -> C

TIME COMPLEXITY :: O(2^n) [exponential time]
*/
