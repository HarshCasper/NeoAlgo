/* 
	 A string is a pangram if the string contains all the English alphabet letters.
	 Given a string , the task is to check whether that string is pangram or not.
	 
	 Input: str = “The quick brown fox jumps over the lazy dog”
	 Output: Yes
		
	 Input: str = “We promptly judged antique ivory buckles for the prize”
	 Output: No

*/

#include <bits/stdc++.h>
using namespace std;

int pangram(string &str)
{
    //map to store the frequency of each alphabet
    map<char, int> frequency;
    //To count number of alphabets
    int count = 0;
    //If 26 alphabets are not present,pangram is impossible
    if (str.size() < 26)
        return -1;
    else
    {

        for (int i = 0; i < str.size(); i++)
        {
            //Ignore spaces
            if (str[i] == ' ')
                continue;
            //Convert each letter to upper case
            str[i] = toupper(str[i]);
            //If the alphabet is not present in frequency map
            if (!frequency[str[i]])
            {
                //Increase the frequency and the count of alphabets
                frequency[str[i]]++;
                count++;
            }
        }
    }
    //26 means all alphabets are present
    if (count == 26)
        return 1;
    else
        return -1;
}
int main()
{
    cout << "Enter the string:";
    string s;
    //To get the entire string
    getline(cin, s);
    int result = pangram(s);

    if (result == 1)
        cout << "Yes,the string is a pangram";
    else
        cout << "No,the string is not a pangram";

    return 0;
}

/* 
    Input: str = “The quick brown fox jumps over the lazy dog”
    
    Output: Yes
*/

/*

	Time Complexity: O(N), where N is the length of the string.
	Auxiliary Space: O(N),as we have used a map
*/
