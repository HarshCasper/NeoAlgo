/*
In our approach, we use a 2D Boolean array to store the results.
*/

#include<iostream>
#include<string>
using namespace std;

string DynamicProgrammingGetLongestPalindrome(string input_str)
{
    if(input_str.length()<=1)
        return input_str;
    int string_length = input_str.length();
    int palindromeLength = 0;
    bool bArray[string_length] [string_length];

    string resultstring = "";

    for (int current_length = 0; current_length < string_length; current_length++)
    {
        for (int i = 0; i < string_length -1 ; i++)
        {
            int j = i + current_length;

                if(input_str[i]==input_str[j] && (j-i<=2 || bArray[i+1][j-1]))
                {
                    bArray[i][j]=true;

                    if(j-i+1>palindromeLength)
                    {
                       palindromeLength = j-i+1; 
                       resultstring = input_str.substr(i, j+1);
                    }
            }
        }
    }
    return resultstring;


}


int main()
{
    string s;
    cout << "Enter a String" << "\n";
    cin >> s;
    string resultstring = DynamicProgrammingGetLongestPalindrome(s);
    cout<<"The longest palindromic substring is " << resultstring <<endl;
}

/*
Sample Input : Enter a String
               ptrabbart
Sample Output : The longest palindromic substring is trabbbart
Time complexity : O(n^2)
Space complexity : O(n^2)
*/ 