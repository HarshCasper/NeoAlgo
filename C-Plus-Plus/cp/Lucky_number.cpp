/*
Description :
            Lucky numbers are subset of integers. let us see the process of arriving at lucky numbers,
            Take the set of integers
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,……
            First, delete every second number, we get following reduced set.
            1, 3, 5, 7, 9, 11, 13, 15, 17, 19,…………
            Now, delete every third number, we get
            1, 3, 7, 9, 13, 15, 19,….….
            Continue this process indefinitely……
            Any number that does NOT get deleted due to above process is called “lucky”. 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count = 1;
    //function to check for lucky number
    bool is_lucky(int n)
    {
        count++;
        if (count > n)
        {
            return true;
        }
        if (n % count == 0)
        {
            return false;
        }

        return is_lucky(n - n / count);
    }
};

int main()
{
    //n = input number
    int n;
    cout << "Enter the number to check : " << endl;
    cin >> n;
    Solution obj;
    //checking wether number is lucky or not
    if (obj.is_lucky(n))
    {
        cout << "It's a lucky number : " << endl;
    }
    else
    {
        cout << "It's not a lucky number : " << endl;
    }
    return 0;
}
/*
Time complexity : O(sqrt(N))
Space complexity : O(sqrt(N))
*/

/*
Test Case :
 Input :
 Enter the number to check : 
 5

 Output :
 It's not a lucky number : 
*/

