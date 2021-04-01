//Evaluate Expression-->
/*In an internal software created by IIT Mandi, the access to services can only be accessed if the expression,
 shown on screen on login, is evaluated correctly.
 It was internally communicated to all the stakeholders that the actual expression will be of the form:*/

// X = n1 ^ pow1 + n2 ^ pow2 + ... + nN ^ powN, where n1, n2 to nN are integers and pow1, pow2 to powN are one digit integers.

/* The expression shown on the screen will be a bit different from the actual expression.
The expression on the screen will be of the form:

X = A1 + A2 + …. + AN, where A1, A2 to AN are integers.*/

/*For example, if the expression on the screen is of the form: X = 212 + 1253,
then the actual expression will be of the form: X = 21^2+ 125^3 
(since the last digit of each addend in expression screen will go to power in actual expression).

All the stakeholders knew that expression on the screen has to be evaluated as an actual expression always to get access.
This became a big task to do for everybody. 
Therefore, the authorities want you to read the expression on screen and evaluate it as an actual expression. Can you complete this task?
Note: a^N is read as “a raised to power N” and a^N = a · a · ... · a (N times).

Input Format:
The first line of input contains the integer N, the number of the numbers to be added from the expression on screen.
Each of the following N lines contains the integer Ai, that represents a number from expression on screen.

Output Format:
The first and only line of output should contain the value of expression on screen, evaluated as actual expression, as described in the task.

Sample Input 1:
3
202
1253
12

Sample Output 1:
1953526 

Explanation:
The actual expression evaluated will be as follows: 
20^2 + 125^3 + 1^2 = 400 + 1953125 + 1 = 1953526. */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int digit;
    int sum = 0;
    while (t--)
    {
        cin >> digit;
        int ld = digit % 10;
        int num = digit / 10;

        sum += pow(num, ld);
    }
    cout << sum;
    return 0;
}