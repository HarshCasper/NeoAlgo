#include <stdio.h>

void TowerOfHanoi(int n,int a,int b,int c){
    if(n){
        TowerOfHanoi(n-1,a,c,b);
        printf("%d -> %d\n", a,b);
        TowerOfHanoi(n-1,c,b,a);
    }
}

int main(){
    int number_of_discs;
    printf("Enter the value of n: ");
    scanf("%d",&number_of_discs);
    printf("\nThe value of n is: %d\n", number_of_discs);
    TowerOfHanoi(number_of_discs,1,2,3);
    //each rod is numbered as 1,2,3
    return 0;
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
