// https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm

// Time Complexity:-O(N+M).
// Space Complexity:-O(M).

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void computeLPS(string &, vector<int> &);
void searchByKMP(string &, string &);

int main()
{
    string text = "abacaaabaccabacabaabb";
    string patt = "abacab";

    searchByKMP(text, patt);
    return 0;
}
// Prints starting index where patt is found in the string text.

void searchByKMP(string &text, string &patt)
{
    int N = text.size(), M = patt.size();

    vector<int> lps(M);

    computeLPS(patt, lps);

    int i = 0, j = 0;

    while (i < N)
    {
        if (patt[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == M)
        {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < N && patt[j] != text[i])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

// Function to Compute LPS.
// LPS = Longest Prefix which also a suffix.
void computeLPS(string &patt, vector<int> &lps)
{
    int M = patt.size(), len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < M)
    {
        if (patt[i] == patt[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}