#include <stdio.h>

/******* PROGRAM DESCRIPTION :- ********/
/*
An unsigned integer will be given as an input, you have to swap it's adjacent bits and return the decimal output number.
Eg:- 57(111001) : Just swap the bits present at even and odd positions with each other and you will get 110110 which is 54.
So, your output will be 54.  
*/

/*
Sample I/P and O/P:- 
       Input:- 49
       Output:- 50 
*/

unsigned int swapBits(unsigned int x)
{
    /* 0x is written here. It means it is hexadecimal number and computer stores hexadecimal number in binary format. 
    Also, A is written here 8 times. So, it means it will store 32 bits integer i.e., (8*4=32) . Each A will be replaced by 1010 . 
    So, in that way 32 bit integer  will be stored. 
    */

    /*A in binary is 1010 . So, by performing bitwise & operation, we will get all the even bits of number x since, 1 is 
      present at even positions. (Masking) */
    unsigned int evenBits = x & 0xAAAAAAAA;

    /*5 in decimal is 0101. So, by performing bitwise & operation, we will get
     all the odd bits of number x since 1 is present at odd positions.
    (Masking) */
    unsigned int oddBits = x & 0x55555555;

    evenBits >>= 1; // Right shifting even bits
    oddBits <<= 1;  // Left shifting odd bits

    return (evenBits | oddBits); // While doing this bitwise OR operation, the adjacent( even and odd bits ) are
                                 // interchanged
}

int main()
{
    unsigned int x;
    printf("Enter the number whose bits need to be swapped:-\n");
    scanf("%u", &x);
    printf("%u ", swapBits(x));
    return 0;
}

/* Time Complexity:- O(1)
   Space Complexity:- O(1)
*/