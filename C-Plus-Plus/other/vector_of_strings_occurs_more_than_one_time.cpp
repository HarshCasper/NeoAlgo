/*
Given a list of strings.
those strings occurs more than one time, return them as a vector of strings.
*/

#include <bits/stdc++.h>
using namespace std;

vector < string > get_duplicate_string( vector < string > vec_string, int Number)
{
    vector < string > duplicates;
    map < string , int > mp;
    for(int i = 0; i < vec_string.size(); i++)
    {
        /* if mp[vec_string[i]] == 0 means that
        that string is not present. right now it's occurrence
        is only 1
        */
        if(mp[vec_string[i]] == 0)
        {
            mp[vec_string[i]]++;
        }
        /* if mp[vec_string[i]] != 0 means that
        that string is already present. right now it's occurrence
        more than 1 , it's duplicate.
        */
        else if(mp[vec_string[i]] != 0)
        {
            duplicates.push_back(vec_string[i]);
        }
    }
    return duplicates;
}

int main()
{
    cout << "Enter the number of strings : \n";
    int Number;
    cin >> Number;
    vector < string > vec_string;
    cout << "Enter the strings :\n";
    for(int i = 1; i <= Number; i++)
    {
        string s;
        cin >> s;
        vec_string.push_back(s);
    }
    vector < string > duplicate_string = get_duplicate_string(vec_string, Number);
    cout << "Duplicate Strings are : ";
    for(auto i : duplicate_string)
    {
        cout << i << ' ';
    }
    cout << endl;
}
/*
Standard Input and Output

Enter the number of strings :
6
Enter the strings :
tom
lucius
ginny
harry
ginny
harry
Duplicate Strings are : ginny harry

Time Complexity : O(log N)
Space Complexity : O(N)

*/
