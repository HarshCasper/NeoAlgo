/*
This problem is solved using backtracking.
It will print all possible Palindromes in the string
*/
#include <bits/stdc++.h>
using namespace std;

/*To check whether a given string is Palindrome or not*/
int isPalindrome(string& word)
{
    int n = word.length() - 1;
    for (int i = 0; i < n; i++) {
        if (word[i] != word[n]) {
            return false;
        }
        n--;
    }
    return true;
}

// Prototype of PalindromeUtil
void printPalindrome(string str, int n, string result);

// Prints all possible Palindromes of given string
void Palindrome(string str)
{
    // Last argument is word
    printPalindrome(str, str.size(), "");
}

/* Result store the current word with spaces
 between words */
void printPalindrome(string str, int n, string result)
{
    //Process all words one by one
    for (int i = 1; i <= n; i++) {
        // Extract substring from 0 to i in word
        string word = str.substr(0, i);

        /* If dictionary conatins this word, then
         we check for remaining string. Otherwise
         we ignore this word (there is no else for
         this if) and try next */
        if (isPalindrome(word)) {
            // If no more elements are there, print it
            if (i == n) {
                // Add this element to previous word
                result += word;
                cout << result << endl;
                return;
            }
            printPalindrome(str.substr(i, n - i), n - i, result + word + " , ");
        }
    }
}

int main()
{
    // Function call
    string str;
    cin >> str;
    Palindrome(str);

    return 0;
}
/*
Input - abaaba
Output -
a , b , a , a , b , a
a , b , a , aba
a , b , aa , b , a
a , baab , a
aba , a , b , a
aba , aba
abaaba

Time Complexity - O(n^n)
Space Complexity - O(n*n)
*/
