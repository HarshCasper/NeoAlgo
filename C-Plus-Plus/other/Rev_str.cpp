//C++ Program to display words in reverse order of a given sentence.
#include <bits/stdc++.h>
using namespace std;

// Function to reverse words
void rev_words(string s)
{

    // temporary vector to store all words
    vector<string> tmp;
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        //Check if we get space then push str to the vector,make str NULL.
        if (s[i] == ' ')
        {
            tmp.push_back(str);
            str = "";
        }
        //Else add word to str to form current word
        else
        {
            str += s[i];
        }
        }
    //Add last word to the vector.
    tmp.push_back(str);
    
    // Now print from last to first in vector
    for (int i = tmp.size() - 1; i > 0; i--)
    {
        cout << tmp[i] << " ";
    }
    // Print Last word.
    cout << tmp[0] << endl;
}

int main()
{
    string str;
    //Take string input
    getline(cin, str);
    //Function call
    rev_words(str);
    return 0;
}


/*
Input: str = “the sky is blue”
Output: blue is sky the

Inpu: str = “I love programming”
Output: programming love I
*/

//Time Complexity: O(n) 
//Space Complexity: O(n)
