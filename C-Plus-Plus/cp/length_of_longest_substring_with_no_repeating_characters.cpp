/**
 * Length of Longest Substring Without Repeating Characters
 * Given a string, print the longest possible substring that has 
 * no repeating characters, i.e., all its characters are distinct. 
 * Consider a String contains upper and lower case alphabets.
 */

#include <bits/stdc++.h>
using namespace std;
int LongestSubstrNoRepeatingChar(string str)
{
    //2 pointer which denotes limits of current window
    int start = 0, end = 0;
    int len = str.length();
    //Maintain count of each character
    map<char, int> charCount;
    //Variable ans stores length og longest substring without repeating characters
    int ans = 0;
    while (end < len) {
        charCount[str[end]]++;
        //If window size and no. of distict elements are same
        //update ans
        if (charCount.size() == end - start + 1) {
            ans = max(ans, end - start + 1);
            end++;
        }

        else if (charCount.size() < end - start + 1) { //If there are repeating characters, we shorten substring by removing
            //characters from start, till we get a distinct substring.
            while (charCount.size() < end - start + 1) {
                charCount[str[start]]--;
                if (charCount[str[start]] == 0)
                    charCount.erase(str[start]);
                start++;
            }
            //move forward
            end++;
        }
    }
    return ans;
}

int main()
{
    //Taking input from user
    string str;
    cout << "Enter a string of alphabets: ";
    cin >> str;
    cout << "Length of longest substring with no repeating characters: ";
    cout << LongestSubstrNoRepeatingChar(str);
}

/*
	Test cases:

	INPUT:
	Enter a string of alphabets: xzvxzzvxxx
	OUTPUT:
	Length of longest substring with no repeating characters: 3

	INPUT:
	Enter a string of alphabets: PractisemakesanIndividualPerfect
	OUTPUT:
	Length of longest substring with no repeating characters: 10

	Time complexity: O(Length of String)
	Space complexity: O(52)

*/
