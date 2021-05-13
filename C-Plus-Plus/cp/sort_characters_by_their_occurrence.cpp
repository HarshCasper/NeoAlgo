/*
Given a string,
sort it in decreasing order based on the occurrence of each characters.
then return new string.
*/

#include <bits/stdc++.h>
using namespace std;

// this get_string_sort_characters_by_their_occurrence will give us the new string
string get_string_sort_characters_by_their_occurrence(string s)
{
    // we will insert characters into the map
    map < char, int > occur_char;
    for(int i = 0; i < (int)s.size(); i++)
    {
        occur_char[s[i]]++;
    }
    /* multimap can contain duplicate keys. that's why we will use it.
    here multimap's key is the occurrence of each character
    and multimap's value is that particular character.
    greater < int > will store them in descending order.
    */
    multimap < int , char, greater < int > > occur_char_2;
    for(auto i : occur_char)
    {
        occur_char_2.insert( { i.second , i.first } );
    }

    string new_string = "";

    for(auto i : occur_char_2)
    {
        int freq = i.first;
        while(freq--)
        {
            /* for each occurrence
            we will add particular character to
            our new string
            */
            new_string += i.second;
        }

    }
    return new_string;
}

int main()
{
    cout << "Enter the string : ";
    string s;
    cin >> s;
    string new_string = get_string_sort_characters_by_their_occurrence(s);
    cout << "The New String based on the occurrence of each characters is : \n";
    cout << new_string << endl;
}

/*
Standard Input and Output

Enter the string :
GMAFGGGMMAF

The New String based on the occurrence of each characters is :
GGGGMMMAAFF

Time Complexity : O( log N )
Space Complexity : O( N )

*/
