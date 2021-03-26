/**
 * Minimum Window Substring 
 *          OR
 * Smallest Window in a String Containing All Characters of Another String
 * Given two strings string1 and string2, find the smallest substring in 
 * string1 containing all characters of string2. 
 */

#include <bits/stdc++.h>
using namespace std;

string minWindow(string str, string pattern)
{ //unordered map for storing the characters in pattern that we need to check for in str
    unordered_map<char, int> letters;
    for (auto c : pattern)
        letters[c]++;
    //counts number of pattern'str letters in current window
    int count = 0;
    int low = 0, min_length = INT_MAX, min_start = 0;
    for (int high = 0; high < str.length(); high++) {
        if (letters[str[high]] > 0)
            count++; //means that this letter is in pattern
        //reduce the count for the letter on which we are currently
        letters[str[high]]--;
        if (count == pattern.length()) {
            //if current windows contains all of the letters in pattern
            while (low < high && letters[str[low]] < 0)
                letters[str[low]]++, low++;
            //move low ahead if its not of any significance
            if (min_length > high - low)
                //update the min length
                min_length = high - (min_start = low) + 1;
            //move low ahead and also increment the value
            letters[str[low++]]++;
            //count-- as we are moving low ahead & low pointed to a char in pattern before
            count--;
        }
    }
    //check for edge case & return the result
    return min_length == INT_MAX ? "" : str.substr(min_start, min_length);
}
int main()
{
    //taking input from user
    string str, pattern;
    cout << "Enter a String text: ";
    cin >> str;
    cout << "Enter a String pattern: ";
    cin >> pattern;
    cout << "Smallest substring in text, containing all characters in pattern: ";
    cout << minWindow(str, pattern);
}
/*
    Test Cases:

    INPUT:
    Enter a String text: saazksaa
    Enter a String pattern: szk
    OUTPUT:
    Smallest substring in text, containing all characters in pattern: zks

    INPUT:
    Enter a String text: letuscontributetoopensource
    Enter a String pattern: ubr
    OUTPUT:
    Smallest substring in text, containing all characters in pattern: ribu

    Time Complexity: O(N)
    Space Compleaxity: O(Charcter Count)

 */
