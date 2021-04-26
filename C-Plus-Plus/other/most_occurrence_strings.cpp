/*
Given a list of words as strings,
return the n-th most occurrence words(strings) .

Words should follow the lexicographical order.
means the lexicographical order is a generalization of the alphabetical order
of the dictionaries to sequences of ordered symbols or, more generally,
of elements of a totally ordered set.
*/

#include <bits/stdc++.h>
using namespace std;

// this print_words function will print the strings
void print_words(vector < string > most_occur_string)
{
    cout << "Most occurrence words are: \n";
    for(auto i : most_occur_string)
    {
        cout << i << ' ';
    }
    cout << endl;
    return;
}

//this get_most_occur_string function will give us the most occurrence strings
vector < string > get_most_occur_string(vector < string > words, int number, int occurrence_number)
{
    vector < string > get_words;

    // we will insert characters into the map
    map < string, int > occur_char;
    for(int i = 0; i < (int)words.size(); i++)
    {
        occur_char[words[i]]++;
    }
    /* multimap can contain duplicate keys. that's why we will use it.
    here multimap's key is the occurrence of each string.
    and multimap's value is that particular string.
    greater < int > will store them in descending order.
    */
    multimap < int , string, greater < int > > occur_char_2;
    for(auto i : occur_char)
    {
        occur_char_2.insert( { i.second , i.first } );
    }
    int count_occur = 0;
    for(auto i : occur_char_2)
    {
        /* if the count_occur is less than occurrence_number
        we will add the strings.
         */
        if(count_occur < occurrence_number)
        {
            get_words.push_back(i.second);
            count_occur++;
        }
        if(count_occur == occurrence_number)
        {
            break;
        }

    }
    return get_words;
}

int main()
{
    cout << "Enter the number of strings and occurrence number: ";
    int number, occurrence_number;
    cin >> number >> occurrence_number;
    vector < string > words;
    for(int i = 1; i <= number; i++)
    {
        string word;
        cin >> word;
        words.push_back(word);
    }
    vector < string > most_occur_string = get_most_occur_string(words, number, occurrence_number);

    print_words(most_occur_string);

}

/*
Standard Input and Output

Enter the number of strings and occurrence number:
8 3
this
day
this
this
day
is
good
day

Most occurrence words are:
day this good


Time Complexity : O( log N )
Space Complexity : O( N )

*/
