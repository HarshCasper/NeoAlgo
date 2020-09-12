#include <bits/stdc++.h>
using namespace std;
//Main Begin
int main()
{
    string str, res;
    //Count variable take care
    //of number of count prsent
    int count = 0;
    //Input the String
    cout << "Enter String :" << endl;
    cin >> str;
    //For Each loop
    //traverse the entire str
    for (auto ch : str) {
        /*Check if '(' is present,
    	    then increment count variable
    	    by +1
    	    else decrement the count variable 
    	    by -1
    	    */
        if (ch == '(') {
            ++count;
            //if count >0 then
            //add ch to res String
            if (count != 1) {
                res += ch;
            }
        }
        else {
            --count;
            //if count >1 then
            //add ch to res String
            if (count != 0) {
                res += ch;
            }
        }
    }
    //Print the final output
    cout << "Output:" << res;
    return 0;
}

/* Sample Input Output 1.
Enter String : "(()())(())"
Output:  ()()()
Sample Input Output 1.
Enter String : "()()"
Output: ""
Complexities :
Time Complexity : O(n)
Space Complexity : O(n)
*/
