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
        if (s[i] == ' ')
        {
            tmp.push_back(str);
            str = "";
        }
        else
        {
            str += s[i];
        }
        }
    tmp.push_back(str);
    for (int i = tmp.size() - 1; i > 0; i--)
    {
        cout << tmp[i] << " ";
    }
    cout << tmp[0] << endl;
}

int main()
{
    string str;
    getline(cin, str);
    rev_words(str);
    return 0;
}
