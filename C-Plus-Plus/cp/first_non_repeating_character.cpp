/*Problem statement :
Print the first non repeating character in a running stream of characters, 
that is the characters will input continuously until a '.'
is encountered you need to keep printing the first non repeating character. */

#include <bits/stdc++.h>
using namespace std;

void first_non_repeating(queue<char> q, int frequency[])
{
        while (!q.empty())
        {
            int index = q.front() - 'a';
            //If character already exists more than once, then pop
            if (frequency[index] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front() << endl;
                break;
            }
        }

        if (q.empty())
        {
            cout << "-1" << endl;
        }
}

int main()
{
    queue<char> q;
    int frequency[27] = { 0 };

    char ch;
    cin >> ch;
    while (ch != '.')
    {
        q.push(ch);
        frequency[ch - 'a']++;
        first_non_repeating(q,frequency);
        cin >> ch;
    }

    return 0;
}
/*
Example :
1)Input = a a b c c .
Output = a -1 b b b
2)Input: s d d g .
Output: s s s s 
Time Complexity : O(n) 
Space Complexity : O(1) */

