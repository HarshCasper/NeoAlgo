/*
Given a number , check whether the number is power of 2 or not.
We can check this by doing some bitwise operation. Bitwise operations are best because they perform the operation in least possible time.
*/

#include <bits/stdc++.h>
using namespace std;

bool number_is_power_of_2(int number)
{
    if((number & (number - 1)) == 0)
        return true;
    return false;
}
int main()
{
    cout << "Enter the number \n";
    int number;
    cin >> number;
    bool solve = number_is_power_of_2(number);
    if(solve)
        cout << "The Number is power of 2\n";
    else
        cout << "No. the number is not power of 2\n";
}
/*
Standard Input and Output

Enter the number
64
The Number is power of 2

Enter the number
34
No. the number is not power of 2

Time Complexity : O(1)
Space Complexity : O(1)

*/
