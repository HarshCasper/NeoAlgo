/*Problem statement :
Print the first non repeating character in a running stream of characters, 
that is the characters will input continuously until a '.'
is encountered you need to keep printing the first non repeating character. */

#include <bits/stdc++.h>
using namespace std;

/*Program description: 
First it takes the input from the user, It pushes the character into the queue
and increments its respective digit. Now, while the queue is not empty, if the 
frequency of that character is more than 1, it pops it out of the queue
Else, it is the first occurance and therefore it prints it. */

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

