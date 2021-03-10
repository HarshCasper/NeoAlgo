/******************************************************************************

Author - @Suvraneel 
        Suvraneel Bhuin

*Luhn's Algorithm for credit card validation*

A credit card number consists of 16 decimal digits. The first (leftmost) digit corresponds to the type of the
card (4 for VISA cards, 5 for MASTERCARDs, 3 for Diners Club and American Express cards, and so on).
The next 6 digits correspond to the number of the bank that issues the card. The next 8 digits constitute the
account number of the card-holder. The last (rightmost) digit is a check digit that determines whether the
credit card number is valid or not. In order to determine the check digit, a checksum is computed as follows.
We first add the digits at the even positions (that is, the second, fourth, sixth, ... , sixteenth digits) of the card
number. Next, each digit in an odd position is doubled. If the doubled value exceeds 9, then the two digits
are added. Finally, these doubled digits (after adjustment of 2-digit values) are added to the checksum. The
check digit is so chosen that the checksum is a multiple of 10. Here is an example.
Card Number   5        9   8         7   6         5   4   0   2   4   6         8   1   3   5         5
Step 1        10       9   16        7   12        5   8   0   4   4   12        8   2   3   10        5
Step 2        1+0 = 1  9   1+6 = 7   7   1+2 = 3   5   8   0   4   4   1+2 = 3   8   2   3   1+0 = 1   5

Checksum = 1 + 9 + 7 + 7 + 3 + 5 + 8 + 0 + 4 + 4 + 3 + 8 + 2 + 3 + 1 + 5 = 70
           3   6   5   0   1   4   4   5   7   2   9   1   2    0    1   5
Since the checksum is divisible by ten, 5987654024681355 is a valid credit card number. Write a program
that, upon input a 16-digit credit card number, determines whether the card number is valid. A 16-digit
integer cannot be accommodated in a long int variable, so read the input as a string (a character array).
*******************************************************************************/
#include <stdio.h>
#include <string.h>                              //header for string operations

int main()
{
    char card[16];                               //character array
    printf("Enter the credit card number:\n");
    gets (card);
    int checksum = 0;
    for (int i=0; i<strlen(card) ; i++){
            int digit = card[i] - '0';
            if (i%2==1){                         //even positions
            checksum += digit;
            printf(" + %d", digit);
        }
        if (i%2==0){                             //odd positions
            checksum += (2*digit<10) ? (2*digit):((2*digit)%10)+1;
            /*(n modulo 10) + 1 yields same value as the 2digit adjustment
            (eg, (11%10)+1 = 2 = 1+1   ;   10%10+1 =1 = 1+0 )
            */
            printf(" + %d", (2*digit<10) ? (2*digit):(((2*digit)%10)+1));        
        } 
    }
    printf("\t = %d\t",checksum);                //test if checksum is valid (ie, if modulo10 = 0)
    printf(checksum%10==0 && (int)strlen(card) == 16 ? "(Valid)":"(Invalid)");       
    if ((int)strlen(card) != 16)                 //the card number must have exactly 16 digits   
        printf("\n[Invalid because card number must have exactly 16 digits.]");            
    return 0; 
}

/*
Time Complexity = O(1)
Space Complexity = O(1)

Std O/P 1:
Enter the credit card number:
5987654024681355        
 + 1 + 9 + 7 + 7 + 3 + 5 + 8 + 0 + 4 + 4 + 3 + 8 + 2 + 3 + 1 + 5         = 70  (Valid)

Std O/P 2:
Enter the credit card number:
5987654024681353
 + 1 + 9 + 7 + 7 + 3 + 5 + 8 + 0 + 4 + 4 + 3 + 8 + 2 + 3 + 1 + 3         = 68  (Invalid)

Std O/P 3:
Enter the credit card number:
59876540246813550
 + 1 + 9 + 7 + 7 + 3 + 5 + 8 + 0 + 4 + 4 + 3 + 8 + 2 + 3 + 1 + 5 + 0     = 70  (Invalid)
[Invalid because card number must have exactly 16 digits.]

*/
