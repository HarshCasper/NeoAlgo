//Implementation of Z algorithm (Linear time pattern searching Algorithm)
#include <iostream>
#include<string>
using namespace std;
void Z_arr(string str, int Z[])    // Fills Z array for given string str[]
{
    int n = str.length(), Left = 0, Right = 0, k;
    for(int i = 1; i < n; i++)
    {
        if(i > Right)    // if i>Right nothing matches so we will calculate z[i]
        {
            Left = Right = i;
            while(Right < n && str[Right - Left] == str[Right])   // Right-Left = 0 in starting, so it will start checking from 0'th index
                Right++;
            Z[i] = Right - Left;
            Right--;
        }
        else
        {
            k = i - Left;    // k = i-Left so k corresponds to number which matches in [Left,Right] interval.
            if(Z[k] < Right - i + 1)    //if Z[k] is less than remaining interval then Z[i] will be equal to Z[k].
                Z[i] = Z[k];
            else
            {
                Left = i;     // else start from R

                while(Right < n && str[Right - Left] == str[Right])
                    Right++;
                Z[i] = Right - Left;
                Right--;
            }
        }
    }
}
void search_pattern(string text, string pattern)
{
    string concatenate = pattern + "$" + text;
    int size = concatenate.length();
    int *Z = new int[size];
    Z_arr(concatenate, Z);
    for(int i = 0; i < size; i++)
        if(Z[i] == pattern.length())
            cout << "Pattern found at position " <<  i - pattern.length() -1 << endl;
    delete[] Z;
}
int main()
{
    string text ;
    string pattern;
    cout<<"Enter the String  text  ";
    cin>>text;
    cout<<"Enter the String pattern  ";
    cin>>pattern;
    search_pattern(text, pattern);
    return 0;
}

/*
Input:
    namanchamanbomanamansanam
    aman
Output:
Pattern found at 2
Pattern found at 8
Pattern found at 17
*/
