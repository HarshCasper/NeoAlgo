/*
You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they are all the same height, then return the height.

Example
h1 = [1, 2, 1, 1]
h2 = [1, 1, 2]
h3 = [1, 1]

There are  and  cylinders in the three stacks, with their heights in the three arrays. Remove the top 2 cylinders from  (heights = [1, 2]) and from  (heights = [1, 1]) so that the three stacks all are 2 units tall. Return  as the answer.

Note: An empty stack is still a stack.

Function Description

Complete the equalStacks function in the editor below.

equalStacks has the following parameters:

int h1[n1]: the first array of heights
int h2[n2]: the second array of heights
int h3[n3]: the third array of heights
Returns

int: the height of the stacks when they are equalized
Input Format

The first line contains three space-separated integers, , , and , the numbers of cylinders in stacks , , and . The subsequent lines describe the respective heights of each cylinder in a stack from top to bottom:

The second line contains  space-separated integers, the cylinder heights in stack . The first element is the top cylinder of the stack.
The third line contains  space-separated integers, the cylinder heights in stack . The first element is the top cylinder of the stack.
The fourth line contains  space-separated integers, the cylinder heights in stack . The first element is the top cylinder of the stack.
Constraints

Sample Input

STDIN       Function
-----       --------
5 3 4       h1[] size n1 = 5, h2[] size n2 = 3, h3[] size n3 = 4
3 2 1 1 1   h1 = [3, 2, 1, 1, 1]
4 3 2       h2 = [4, 3, 2]
1 1 4 1     h3 = [1, 1, 4, 1]
Sample Output

5
*/


#include<stdio.h>

int main()
{
    int sum_stack1, sum_stack2, sum_stack3;
    int stack_height1, stack_height2, stack_height3;
    int st1_top, st2_top, st3_top;
    int minimum, value;

    // Initializing
    sum_stack1 = 0;
    sum_stack2 = 0;
    sum_stack3 = 0;

    //Input of Stack no of height blocks
    scanf("%d", &stack_height1);
    scanf("%d", &stack_height2);
    scanf("%d", &stack_height3);

    // Tops init()
    st1_top = stack_height1-1;
    st2_top = stack_height2-1;
    st3_top = stack_height3-1;

    //Stack Init
    int stack1[stack_height1],stack2[stack_height2], stack3[stack_height3];

    //Input for stack1
    for(int i=stack_height1-1; i>=0;i--)
    {
        scanf("%d",&stack1[i]);
        sum_stack1 += stack1[i];
    }

    //Input for stack2
    for(int i=stack_height2-1; i>=0;i--)
    {
        scanf("%d",&stack2[i]);
        sum_stack2 += stack2[i];
    }

    //Input for stack3
    for(int i=stack_height3-1; i>=0;i--)
    {
        scanf("%d",&stack3[i]);
        sum_stack3 += stack3[i];
    }


    int dum = 1;

    while (dum == 1)
    {
        minimum = 0;

        // min setting
        if (sum_stack1 <= sum_stack2 && sum_stack1 <= sum_stack3)
            minimum = sum_stack1;
        else if (sum_stack2 <= sum_stack1 && sum_stack2 <= sum_stack3)
            minimum = sum_stack2;
        else
            minimum = sum_stack3;

        // Removing
        if (sum_stack1 > minimum)
        {
            value = stack1[st1_top];
            st1_top -=1;
            sum_stack1 -= value;
        }

        if (sum_stack2 > minimum)
        {
            value = stack2[st2_top];
            st2_top -=1;
            sum_stack2 -= value;
        }

        if (sum_stack3 > minimum)
        {
            value = stack3[st3_top];
            st3_top -=1;
            sum_stack3 -= value;
        }

        if ((sum_stack1 == sum_stack2) && (sum_stack2 == sum_stack3) && (sum_stack1 == sum_stack3))  break;

    }

    printf("%d", minimum);

    return 0;
}
