/*
Given two words and a string.
By using two words , Count How many different subsequence's can be created through the string.
Two subsequence's are considered to be different if they start or end
at different positions in the string.
*/

#include <bits/stdc++.h>
using namespace std;

//From this get_count_max_possible_subsequence() function we will count max different subsequence's can be created
int get_count_max_possible_subsequence(string word1, string word2, string text)
{
    int size_of_text = text.size();
    int size_of_word1 = word1.size();
    int size_of_word2 = word2.size();
    int count_max_possible_subsequence = 0;
    int count1 = 0;
    for(int i = 0; i < size_of_text; i++)
    {
        /* here we will check if string s1 is first word or not
        if yes we will increment the count1
         */
        string s1 = text.substr(i , size_of_word1);
        if(s1 == word1)
            count1++;
        string s2 = text.substr(i , size_of_word2);
        if(s2 == word2)
        {
            /* here we will check if string s2 is second word or not
            if yes we will increment the count_max_possible_subsequence
            with current count1 value
            */
            count_max_possible_subsequence += count1;
        }
    }
    return count_max_possible_subsequence;
}

int main()
{
    string text, word1, word2;
	
    cout << "Enter the two words : \n";
    cin >> word1 >> word2;
    cout << "Enter the string : \n";
    cin >> text;
	
    int count_max_possible_subsequence = get_count_max_possible_subsequence(word1, word2, text);
	
    cout << "Maximum possible subsequence can be created is : ";
    cout << count_max_possible_subsequence << endl;
}

/*
Standard Input and Output

Enter the two words :
KICK
START
Enter the string :
KICKXKICKXSTARTXKICKXSTART
Maximum possible subsequence can be created is : 5

Time Complexity : O( N )
Space Complexity : O( N )

*/
