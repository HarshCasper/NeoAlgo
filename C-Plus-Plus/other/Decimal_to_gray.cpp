/*Gray code is an ordering of the binary numeral system such that two successive values differ in only one bit (binary digit).
In gray code, two consecutive values are differed by one bit of binary digits.
Binary number can be converted to gray code by performing xor of two consecutive bits.

Decimal to Gray code Conversion: Decimal(2) = 0010(Binary)
0  0  1  0
|\ /\ /\ /
0 0  1  1
Here, 1st bit is taken as it is. Next, xor of 2 consecutive bits is performed[xor of (0,0) , (0,1) , (1,0)]. Therefore, gray
code for 2 in binary format is 0011.

In this problem, the number in decimal is converted into gray code in decimal format.
Example:
I/O : 2
O/P : 3
Explanation: 2 in binary format is 0010. When converted into gray code, it is 0011. But decimal equivalent of 0011 is 3.
*/

#include<iostream>
using namespace std ;

int dec_to_gray_code(int fn_in_decimal)
{
    /*
    To get gray code, xor has to be performed for consecutive bits. So instead of dealing with only one pair of bits at a
    time, all xor operations are performed at one step by performing xor of input number and number obtained by shifting input
    number to right by 1.
    */
    return fn_in_decimal ^ (fn_in_decimal >> 1);
}

int main(void)
{
    int n_in_decimal = 0, n_in_gray = 0 ;

    //Take user input as decimal number
    cout << "Enter the number in decimal : " << endl ;
    cin >> n_in_decimal ;

    //Call to function dec_to_gray_code
    n_in_gray = dec_to_gray_code(n_in_decimal) ;

    cout << "The gray code value for decimal number " << n_in_decimal << " is : " << n_in_gray << endl ;
    return 0 ;
}

/*
 Sample Example :
 I/O : 7
 O/P : 4

 Explanation: 7 in binary is written as 0111. When converted to gray code, it is 0100. 0100 in decimal is 4. Hence code outputs 4.

 Time Complexity : O(1)
 Space Complexity : O(1)
*/

