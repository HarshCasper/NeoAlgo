/*

Ques:- Given a string S containing only digits, Your task is to complete the function genIp() which returns a vector containing all possible combination of valid 
IPv4 ip address and takes only a string S as its only argument.
Note : Order doesn't matter.

Concept:- 1.)Split the string with ‘ . ‘ recusively and then check for all corner cases. 
          2.)Corner cases are:- For string "25011255255"
                                a)25.011.255.255 is not valid as 011 is not valid.
                                b)25.11.255.255 is not valid either as you are not allowed to change the string.
                                c)250.11.255.255 is valid as number lies between 0 to 255 in ipv4 address
                                
Time - O(N^4)

*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
void ipv4(string str, int index, vector<string> &ans, int dotNum)
{
    //base..
    if (index <= str.size() - 1 && dotNum == 4) //if dots finishes and string left,valid
    {
        string p = str;
        p.push_back('.');
        int st = 0;

        for (int i = 0; i < p.length(); ++i)
        {
            if (p[i] == '.')
            {
                string sub = p.substr(st, i - st);

                st = i + 1;

                if (sub[0] == '0' && sub.size() > 1) // 0230.11.1.90(invalid) for this type of cases, and 10.11.0.9 is valid
                    return;

                long long num = stoll(sub);
                if (num > 255) //lie between 0 to 255
                    return;
            }
        }
        ans.push_back(str); //push in the answer string of array
        return;
    }

    if (dotNum <= 3 && index >= str.size() - 1) //if dot remains less than 3 and string ends,invalid
        return;

    for (int i = index; i < str.size() - 1; ++i)
    {
        string temp1 = str.substr(0, i + 1); //partioning via dot
        string temp2 = str.substr(i + 1);

        temp1 += "."; //adding the dot
        temp1 += temp2;

        ipv4(temp1, i + 2, ans, dotNum + 1);
    }

    return;
}

vector<string> genIp(string &s)
{
    // Your code here
    vector<string> ans;

    if (s.size() > 3)
    {
        ipv4(s, 0, ans, 1); //(current string,index just after which dot to be added,vector of strinf ie. answer,the dot number to be added currently)
    }

    return ans;
}