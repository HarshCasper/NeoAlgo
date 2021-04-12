/*
	A neon number is a number where :- 
	the sum of digits of square of the number is equal to the number. 
	The task is to check and print neon numbers in a range given by the user.
*/

#include <bits/stdc++.h>
using namespace std;
//Function that prints the sum of digits of a number
int sum_of_digits(int y)
{
    int s = 0,v;
    while (y != 0)
    {
        v=y%10;
        s = s + v;
        y = y / 10;
    }
    return s;
}
bool Neon(int n)
{
    int sq = pow(n,2);
    int result = sum_of_digits(sq);
    //If sum of digits become equal to the number
    if (result == n)
        return true;
    else
        return false;
}

int main()
{
    cout << "Enter the range:";
    int a, b;
    cin >> a >> b;

    // Printing Neon Numbers according to the range
    cout<<"Neon numbers in between "<<a<<" to "<<b<<" are : ";
    for (int i = a; i <= b; i++)
        if (Neon(i) == true)
            cout << i << " ";
}
/*
   Input: Enter the range:1 10000
   Output: Neon numbers in between 1 to 10000 are : 1 9
*/
/*
   Time Complexity:O(nlogn) //where n is the range of a to b.
   Space Complexity:O(1)
*/
