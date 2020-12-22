/*Letter Case Permutation using recursion

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.
Print all possible strings we could create. return the output in any order. */


#include <iostream>
using namespace std;

void solve(string output, string str)
{
    if (str.length() == 0)
    {
        cout << output << " ";
        return;
    }

    if (isalpha(str[0]))
    {

        string output1 = output;
        output1.push_back(tolower(str[0]));
        string output2 = output;
        output2.push_back(toupper(str[0]));

        str.erase(str.begin() + 0);

        solve(output1, str);
        solve(output2, str);
    }
    else
    {
        string output3 = output;
        output3.push_back(str[0]);

        str.erase(str.begin() + 0);

        solve(output3, str);
    }
}

int main()
{
    string str;
    cout << "Enter an alphanumeric string : ";
    cin >> str;

    cout << "Output : " << endl;

    string output = "";

    solve(output, str);
    return 0;
}

/*
Input
Enter an alphanumeric string : a1b2                                                                                                           
Output :                                                                                                                                      
a1b2 a1B2 A1b2 A1B2

Time complexity O(2^n) 
Space complexity O(2^n)
*/
