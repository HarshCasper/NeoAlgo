/*
Description :  
        Palindrome Number : Given an integer x, return true if x is palindrome integer.
                            An integer is a palindrome when it reads the same backward as forward.
                            This code is implemented without using extra space.                       
*/

#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(int num)
{
    // divi =  divisor
    int divi = 1;

    //finding the apt. divisor for the number
    while (num / divi >= 10)
    {
        divi *= 10;
    }
    while (num != 0)
    {
        int leading = num / divi;
        int trailing = num % 10;
        if (leading != trailing)
        {
            return false;
        }
        //reducing number to compare
        num = (num % divi) / 10;
        divi = divi / 100;
    }
    return true;
}
int main()
{
    int num;
    cout << "Enter the number to check : " << endl;
    cin >> num;
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

