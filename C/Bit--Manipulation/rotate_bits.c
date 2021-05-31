// C program to Rotate a number by a specific bits
#include <stdio.h>

// Left Rotate 'cnt' number of bits of the given number 'n'
int left_rotate_bits(int n, int cnt)
{
    int msb;

    // 32 is the total number of bits used to store an INT variable in C++
    for (cnt = cnt % 31; cnt > 0; cnt--)
    {
        //Store the current MSB in a temporary variable
        msb = (n >> 31) & 1;
        //Left rotate the given number by one bit
        n = (n << 1);
        //Set the dropped MSB as the new LSB
        n = n | msb;
    }
    return n;
}

// Right Rotate 'cnt' number of bits of the given number 'n'
int right_rotate_bits(int n, int cnt)
{
    int lsb;

    // 32 is the total number of bits used to store an INT variable in C++
    for (cnt = cnt % 31; cnt > 0; cnt--)
    {
        //Store the current LSB in a temporary variable
        lsb = n & 1;
        //Right rotate the given number by one bit and drop its LSB
        n = (n >> 1) & (~(1 << 31));
        //Set the dropped LSB as the new MSB
        n = n | (lsb << 31);
    }
    return n;
}

int main()
{
    int n, cnt, left, right;
    printf("\nEnter the number? ");
    scanf("%d", &n);

    printf("How many bits do you want to rotate? ");
    scanf("%d", &cnt);

    //Call the sort function
    left = left_rotate_bits(n, cnt);
    right = right_rotate_bits(n, cnt);

    printf("The Left-rotated number is: %d\n", left);
    printf("The Right-rotated number is: %d\n", right);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

Enter the number? 39
How many bits do you want to rotate? 17
The Left-rotated number is: 5111808 
The Right-rotated number is: 1277952

*/
