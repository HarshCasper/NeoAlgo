/*
Description : 
        Given a string str and another string pattern. Find the character in pattern that 
        is present at the minimum index in str. If no character of patt is present in 
        str then print ‘No character found from the given pattern’.
*/

#include <bits/stdc++.h>
using namespace std;

class Pattern
{
public:
    //Function to find the minimum indexed character.
    int min_index(string str, string patt)
    {
        int minIndex = INT_MAX;
        unordered_map<char, int> umap;
        int n = patt.size();
        int m = str.size();

        //storing index character
        for (int i = 0; i < m; i++)
            if (umap.find(str[i]) == umap.end())
                umap[str[i]] = i;

        //iterating over the second string "patt".
        for (int i = 0; i < n; i++)
        {
            if (umap.find(patt[i]) != umap.end() && umap[patt[i]] < minIndex)
            {
                //updating minimum index.
                minIndex = umap[patt[i]];
            }
        }

        if (minIndex != INT_MAX)
            return minIndex;
        else
            return -1;
    }
};

int main()
{
    //input string
    string str;
    cout << "Enter the string " << endl;
    cin >> str;
    //pattern string
    string pattern;
    cout << "Enter the pattern to be found " << endl;
    cin >> pattern;

    Pattern ob;
    int res = ob.min_index(str, pattern);
    //if no pattern returned from the function
    if (res == -1)
    {
        cout << "No character found from the given pattern " << endl;
    }
    else
    {
        cout << "First character present from pattern " << endl;
        cout << str[res];
    }
    return 0;
}

/*
Time complexity : O(n)
Space complexity : O(n)
*/

/*
Test Case :
 Input :
 Enter the string
 xyxyxz
 Enter the pattern to be found
 tree

 Output :
 No character found from the given pattern
*/