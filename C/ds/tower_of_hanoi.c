//Tower of Hanoi is mathematical puzzle here 3 disks are moved from source to destination using an auxiliary peg.
//This problem can be solved by method of recursion.It must following 2 conditions:
//1.Only one disk must be moved at a time.
//2.Smaller disk must be placed above larger disk and vice versa is not acceptable.

#include <stdio.h>
void tower_of_hanoi(int, char, char, char);
int main() {
    int number_of_disks;
    printf("Enter the number of disks : ");
    scanf("%d", & number_of_disks);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    tower_of_hanoi(number_of_disks, 'A', 'C', 'B');
    getch();
    return 0;
}
//The disk from source peg is moved to destination peg using an auxiliary peg.
void tower_of_hanoi(int number_of_disks, char source, char destination, char auxillary) {
    if (number_of_disks == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", source, destination);
        return;
    }
    tower_of_hanoi(number_of_disks - 1, source, auxillary, destination);
    printf("\n Move disk %d from peg %c to peg %c",number_of_disks, source, destination);
    tower_of_hanoi(number_of_disks - 1, auxillary, destination, source);
}

//OUTPUT:
//Enter the number of disks : 3
//The sequence of moves involved in the Tower of Hanoi are :
//Move disk 1 from peg A to peg C.
//Move disk 2 from peg A to peg B.
//Move disk 1 from peg B to peg C.
//Move disk 3 from peg c to peg B.
//Move disk 1 from peg A to peg C.
//Move disk 2 from peg B to peg C.
//Move disk 1 from peg A to peg C.

//Space complexity is O(n).
//Time complexity is O(2n).
