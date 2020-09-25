//algorithm for swap nibbles in O(1) time complexity and O(1) space complexity

#include <stdio.h>

int swapnibbles(int num)
{
    return (((num & 0x0F) << 4) | ((num & 0xF0) >> 4));
}

int main()
{   
    //taking input
    int num;
    printf(" Enter a number : \n");
    scanf("%d",&num);
    int result = swapnibbles(num);
    printf("output is  %d\n",result);
}

/*
Input:
Enter a number: 50
Output: 
35
*/ 
