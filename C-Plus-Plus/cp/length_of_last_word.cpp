/*
	Given a string s consists of some words separated by spaces,
	return the length of the last word in the string. 
	If the last word does not exist, return 0.
	A word is a maximal substring consisting of non-space characters only.
*/

#include <bits/stdc++.h>
using namespace std;

/*
		Well, the basic idea is very simple. 
		Start from the tail of s and move backwards to find the first non-space character. 
		Then from this character, move backwards and count the number of non-space characters 
		until we pass over the head of s or meet a space character.
		The count will then be the length of the last word.
*/

int lengthOfLastWord(string s)
{
    int lengthofword = 0, tail = s.length() - 1;
    while (tail >= 0 && s[tail] == ' ')
        tail--;
    while (tail >= 0 && s[tail] != ' ')
    {
        lengthofword++;
        tail--;
    }
    return lengthofword;
}

int main()
{
    cout << "Enter the string:";
    string str;
    getline(cin, str);

    int ans = lengthOfLastWord(str);
    cout << "The length of the last word in the string is: " << ans;
}

/*
	   Input:Hello World
	   Output:5
*/
/*
	   Time Complexity:O(n),where n is the length of the string
	   Space Complexity:O(1)
*/
