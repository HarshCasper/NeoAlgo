// https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm

// Time Complexity:-O(N+M).
// Space Complexity:-O(M).

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Fills lps for given patttern pat[0..M-1]
void computeLPS(string &patt, vector<int> &lps)
{
    int M = patt.size();
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0;

    int i = 1;
    // the loop calculates lps[i] for i = 1 to M-1
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


// Prints occurrences of patt in text
void searchByKMP(string &text, string &patt)
{
    int N = text.size(), M = patt.size();

    // create lps vector that will hold the longest prefix suffix values for pattern
    vector<int> lps(M);

    // Preprocess the pattern(calculate lps vector)
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

int main()
{
    string text = "", patt = "";

    int n;

    cout << "Enter Number of test Cases:";
    cin >> n;

    while (n)
    {
        cout << endl;
        cout << "Enter the text string:";
        cin >> text;

        cout << endl << "Enter the pattern string:";
        cin >> patt;

        searchByKMP(text, patt);
        n--;
        text.clear();
        patt.clear();
    }

    return 0;
}