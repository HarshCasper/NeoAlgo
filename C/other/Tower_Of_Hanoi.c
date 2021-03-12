#include <stdio.h>
void towerOfHanoi(int,char,char,char);
 int main()
{
    int n;
    printf("Enter no of disks\n");
    scanf("%d",&n);
    towerOfHanoi(n, 'A', 'C', 'B');
}

void towerOfHanoi(int n, char from, char to, char temp)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n-1, from, temp, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n-1, temp, to, from);
}
}

/*
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
1) Only one disk can be moved at a time.
2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3) No disk may be placed on top of a smaller disk.

In this code, we use the recursive definition of Tower of Hanoi.

Time Complexity: O(2^N)
Space Complexity: O(N)

OUTPUT
Enter the value of n: 4
The value of n is: 4
1 -> 3
1 -> 2
3 -> 2
1 -> 3
2 -> 1
2 -> 3
1 -> 3
1 -> 2
3 -> 2
3 -> 1
2 -> 1
3 -> 2
1 -> 3
1 -> 2
3 -> 2
*/
