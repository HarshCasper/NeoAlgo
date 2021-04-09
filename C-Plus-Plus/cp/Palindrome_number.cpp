/*
Description :  
            Palindrome Number : Given an integer x, return true if x is palindrome integer.
                                An integer is a palindrome when it reads the same backward as forward.
								For example, 121 is palindrome while 123 is not.
                                This code is implemented without using extra space.                       
*/

#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(int n)
{
    // divi =  divisor
    int divi = 1;

    //finding the apt. divisor for the number
    while (n / divi >= 10)
    {
        divi *= 10;
    }
    while (n != 0)
    {
        int l = n / divi;
        int t = n % 10;
        if (l != t)
        {
            return false;
        }
        //reducing number to compare
        n = (n % divi) / 10;
        divi = divi / 100;
    }
    return true;
}
int main()
{
    int n;
    cout << "Enter the number to check : " << endl;
    cin >> n;
    checkPalindrome(n) ? cout << "True" : cout << "False";
    return 0;
}

/*

Time complexity : O(n2)
Space complexity : O(1)

*/

/*

Test Case : 
     Test case 1 :
          Input : 1001
          Output : True
    Test case 2 : 
          Input : 1234
          Output : False

*/
