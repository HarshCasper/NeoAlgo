/*
A pronic number is a number which is the product of two consecutive integers.
Such as 2=2*1 (2 and 1 are consecutive numbers)
        12=4*3
             
This program will print the pronic numbers in the given range.        
*/

#include <iostream>
#include <math.h>
using namespace std;

/* Function to check whether number is pronic or not
A number is pronic if the root of equation i^2+i-num=0 is real and integer.
So, the discriminant of equation should be positive, odd  and perfect square for number to be pronic*/
bool is_pronic(int num)
{
    int dis = 1 + 4 * num;
    //checking discriminant is  positive,odd and perfect square
    if (dis >= 0 && floor(sqrt(dis)) == sqrt(dis))
        return true;
    else
        return false;
}

int main()
{
    int ll, hl;
    cout << "Enter the range for which you want to print PRONIC NUMBERS:\n";
    cout << "Enter lower limit:";
    cin >> ll;
    cout << "Enter higher limit:";
    cin >> hl;

    //Printing pronic numbers in given range
    cout << "Pronic numbers from " << ll << " to " << hl << " are:\n";
    for (int i = ll; i <= hl; i++)
    {
        if (is_pronic(i))
            cout << i << " ";
    }
}

/*

Sample Input/Output:

Input:
Enter the range for which you want to print PRONIC NUMBERS:
Enter lower limit:1
Enter higher limit:1000

Output:
Pronic numbers from 1 to 1000 are:
2 6 12 20 30 42 56 72 90 110 132 156 182 210 240 272 306 342 380 420 462 506 552 600 650 702 756 812 870 930 992

Time Complexity:O(n) where n is total numbers in range
Time Complexity of is_pronic()=O(1) 
Space Complexity:O(1)

*/
