#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Function to sort the multimap
multimap<int, string, greater<int>> sort(map<string, int, greater<string>> &freqmap)
{
    //Multimap inverts key as value and viseversa.
    multimap<int, string, greater<int>> multiMap;

    map<string, int, greater<string>>::iterator it;
    for (it = freqmap.begin(); it != freqmap.end(); it++)
    {
        multiMap.insert(make_pair(it->second, it->first));
    }

    return multiMap;
}

//Function that counts frequency of word and print it in sorted order.
void getWordFrequency(string s)
{
    //Map stores key as a word and value as a count
    map<string, int, greater<string>> freqmap;

    //Intialize Word as an empty string
    string word = "";

    //Loop Stores all the words with its frequency counts in map
    for (int i = 0; i < s.size(); i++)
    {

        //If s[i] equals space then store word in map
        if (s[i] == ' ' || s[i] == '.')
        {
            //Corner Case:For multiple spaces
            if (word == "")
            {
                continue;
            }
            //If Word is not present in map then insert it with word frequency 1.
            if (freqmap.find(word) == freqmap.end())
            {
                freqmap.insert(make_pair(word, 1));
                word = "";
            }
            //If word is already present then increase frequency count.
            else
            {
                freqmap[word]++;
                word = "";
            }
        }

        else
        {
            word += s[i];
        }
    }
    //to insert last word in map
    if (freqmap.find(word) == freqmap.end())
    {
        freqmap.insert(make_pair(word, 1));
    }
    else
    {
        freqmap[word]++;
    }

    //Function sorts the multimap by value.
    multimap<int, string, greater<int>> mmfreqmap = sort(freqmap);

    //Traverse the map to print the frequency and word in sorted order
    multimap<int, string, greater<int>>::iterator itr;
    for (itr = mmfreqmap.begin(); itr != mmfreqmap.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
}

//Main Function
int main()
{
    string str;
    //Input String with getline() function
    getline(cin, str);

    //Transform whole string in lowercase
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    //Function that counts frequency of word and print it in sorted order.
    getWordFrequency(str);
}

//Test Cases:1
// Input:
//    This is a great example of how this task can be done.
//    It should be done in a way that shows it is done with the details and how it works.
// Output:
//     3 it
//     3 done
//     2 this
//     2 is
//     2 how
//     2 be
//     2 a
//     1 works
//     1 with
//     1 way
//     1 the
//     1 that
//     1 task
//     1 shows
//     1 should
//     1 of
//     1 in
//     1 great
//     1 example
//     1 details
//     1 can
//     1 and

// Test Case:2
// Input :
//       Hi my  name is  Maan.I am Computer   Engineer. I am in 3rd year.
// Ouput:
//       2 i
//       2 am
//       1 year
//       1 name
//       1 my
//       1 maan
//       1 is
//       1 in
//       1 hi
//       1 engineer
//       1 computer
//       1 3rd

//Time Complexity:O(freqmap)
//Space Complexity:O(1)