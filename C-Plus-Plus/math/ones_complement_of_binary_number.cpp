
/*A C program to input binary number from user and find ones complement of binary number.
Ones complement of a binary number is defined as value obtained by inverting all binary bits.
It is the result of swapping all 1s to 0s and all 0s to 1s.

Example
Input binary number: 01000011
Ones complement: 10111100


Step by step logic to find ones complement of binary number.

Input a binary string from user. Store it in a variable say binary.
Run a loop from 1 to length of binary string, increment 1 in each iteration. 
The loop structure should look like for(i=0; i<SIZE; i++) (where SIZE is the length of binary digit).
Inside loop there are two possibilities -
Print 0 for each 1 binary bit i.e. if(binary[i] == '1').
Print 1 for each 0 binary bit i.e. if(binary[i] == '0').*/




#include <iostream>
#define SIZE 8
using namespace std;

int main()

{
    char binary[SIZE + 1], onesComp[SIZE + 1];
    int i, error=0;

   cout<<"Enter " <<SIZE<< " bit binary value: ";
    
    /* Input binary string from user */
    cin>>binary;

    /* Store all inverted bits of binary value to onesComp */
    for(i=0; i<SIZE; i++)
    {
        if(binary[i] == '1')
        {
            onesComp[i] = '0';
        }
        else if(binary[i] == '0')
        {
            onesComp[i] = '1';
        }
        else
        {
            cout<<"Invalid Input";
            error = 1;

            /* Exits from loop */
            break;
        }
    }

    /* Marks the end of onesComp string */
    onesComp[SIZE] = '\0';

    /* Check if there are binary string contains no error */
    if(error == 0)
    {
       cout<<"Original binary = "<<binary;
       cout<<"\n";
      cout<<"Ones complement = "<< onesComp;
    }

    return 0;
}


/*
Output

Enter 8 bit binary value: 11110000                                                                                              
Original binary = 11110000                                                                                                      
Ones complement = 00001111 

*/

