/*
Gray code is an ordering of the binary numeral system such that two successive values differ in only one bit (binary digit).
In gray code, two consecutive values are differed by one bit of binary digits. To convert gray code into binary number, 1st bit
in output is taken same as input's 1st bit. Further, xor operation is performed on recently calculated output bit & next input
bit.

Gray code to binary conversion: 3(Gray) = 0011(Binary)
0  0  1  1
| /| /| /|
0  0  1  0
Here, 1st bit, i.e 0 is taken as it is. Further, xor operations of recently calculated output bit(i.e 0) & its next input bit
(i.e 0) is performed. Same process is repeated until last input bit.(xor of (0,0) , (0,1) , (1,1)).
Therefore, 3 in gray code is equivalent to 2 in decimal format.

In this problem, the gray code is converted into decimal format.
Example:
I/O : 3
O/P : 2
Explanation: 3 is given in gray code. In binary, 3 is written as 0011. When converted into decimal format, it is 0010. But decimal
equivalent of 0010 is 2.
*/

#include<iostream>
using namespace std ;

int gray_code_to_decimal(int fn_in_gray)
{
    int fn_in_decimal = 0;

    /*
    To get decimal format number, xor of output number(number in decimal format) & gray code number has to be performed. In each
    iteration, gray code number is shifted to the right by 1. This process is continued till gray format number becomes 0.
    */
    for (; fn_in_gray; fn_in_gray = fn_in_gray >> 1)
    {
        fn_in_decimal ^= fn_in_gray ;
    }

    return fn_in_decimal;
}

int main(void)
{
    int n_in_gray = 0, n_in_decimal = 0 ;

    //Take user input as gray code number
    cout << "Enter the number in gray format : " << endl ;
    cin >> n_in_gray ;

    //Call to function gray_code_to_decimal
    n_in_decimal = gray_code_to_decimal(n_in_gray) ;

    cout << "The decimal value of gray code " << n_in_gray << " is : " << n_in_decimal << endl ;
    return 0 ;
}

/*
 Sample Example :
 I/O : 4
 O/P : 7

 Explanation: 4 in binary is written as 0100. When converted to decimal format, it is 0111. 0111 in decimal is 7.Hence code outputs 7.

 Time Complexity : O(1)
 Space Complexity : O(1)
*/

