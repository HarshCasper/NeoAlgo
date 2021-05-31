/**
 * Longest Substring with k Distinct Characters
 * Given a string, print the longest possible substring that 
 * has exactly K unique characters.
 */

#include <bits/stdc++.h>
using namespace std;

int kUniqueChar(string str, int k)
{
    //2 Pointers to point to start and end of current window
    int start = 0, end = 0;
    int len = str.length();
    //Map maintains current count of each letter
    map<char, int> charCount;
    //Variable ans stores the length of longest possible substring that has exactly n unique characters
    int ans = 0;
    //Iterate until end of current window reaches end of string
    while (end < len) {
        //Updating count of current letter
        charCount[str[end]]++;
        //unique elements less than required increase window size
        if (charCount.size() < k)
            end++;
        /*if unique element equals to required we need to check
          if on increasing the window size whether repetitive element is present or not
          if present then update it as ans and increase window size*/
        else if (charCount.size() == k) {
            ans = max(ans, end - start + 1);
            end++;
        }
        else if (charCount.size() > k) {
            /*If there are more than k unique characters in
              current window, remove element from left side*/
            while (charCount.size() > k) {
                charCount[str[start]]--;
                // If occurence of character becomes 0,then we will remove it from map
                if (charCount[str[start]] == 0)
                    charCount.erase(str[start]);
                start++;
            }
            /*move forward
              increment end*/
            end++;
        }
    }
    return ans;
}

int main()
{
    string str;
    int k;
    cout << "Enter a string: ";
    cin >> str;
    cout << "Enter number of distict characters: ";
    cin >> k;
    cout << "Longest substring with " << k << " distinct characters: ";
    cout << kUniqueChar(str, k);
}

/*
	Test cases:

	INPUT:
	Enter a string: aabcbcbcbd
	Enter number of distict characters: 3
	OUTPUT:
	Longest substring with 3 distinct characters: 9

	INPUT:
	Enter a string: perepeereyjjjjj
	Enter number of distict characters: 4
	OUTPUT:
	Longest substring with 4 distinct characters: 10

	Time complexity: O(N)
	Space complexity: O(N)

*/
