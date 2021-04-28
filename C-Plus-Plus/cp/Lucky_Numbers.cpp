/*
Description : 
        The numbers of all offices in the new building of the Tax Office of IT City will have lucky numbers. 
        Lucky number is a number that consists of digits 7 and 8 only. 
        Find the maximum number of offices in the new building of the Tax Office given that a door-plate can
        hold a number not longer than n digits.
*/

#include <iostream>
using namespace std;
int main()
{
    long long a = 1, sum = 0;
    int i;
    cout << "Enter the maximum length of a number that a door-plate can hold : " << endl;
    cin >> i;
    /*Loop to increse the number of digits from 1 to n*/
    for (int k = 1; k <= i; k++)
    {
        //Number of choices an k digit number has
        a = a * 2;
        //Calculate sum
        sum += a;
    }
    cout << "Maximum number of offices in the new building : " << endl;
    cout << sum;
}

/*
Time complexity : O(N)
Space complexity  : O(1)
*/

/*I/O Example-
Input
Enter the maximum length of a number that a door-plate can hold : 
2

Output
Maximum number of offices in the new building : 
6
*/

