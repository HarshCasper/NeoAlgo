/*
Delete the same consecutive words in a sequence using stacks
OBJECTIVE:
Output the sequence after deletion of consecutive same words
*/

#include<bits/stdc++.h>
using namespace std;

int deleteSameConsecutiveWords(vector<string> v)
{
    stack<string> str;
    for(int i = 0;i < v.size(); i++)
    {
        if(str.empty())
        str.push(v[i]);
        else
        {
            string st_temp = str.top();
            if(st_temp.compare(v[i]) == 0)
            str.pop();
            else 
            str.push(v[i]);
        }        
    }
    //Creating a temporary vector to store the words after deletion
    vector<string> temp;
    while(str.empty() != true)
    {
        string s = str.top();
        str.pop();
        temp.push_back(s);        
    }
    //Reversing the vector because stack follows 'First In First Out' 
    reverse(temp.begin(),temp.end());
    for(int i = 0;i < temp.size(); i++)
    cout<<temp[i]<<" ";
}

//Driver Code
int main()
{
    cout<<"Enter the number of words in the sequence\n";
    int n;
    cin >> n;
    vector<string> v(n);
    string temp;
    cout << "Enter the sequence :\n";
    for(int i = 0;i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    cout << "The sequence after deletion:\n";
    deleteSameConsecutiveWords(v);
}

/*
Time Complexity: O(n)

Space complexity: O(n)

Example:
Input:
Enter the number of words in the sequence
5
Enter the sequence :
hello crello crello bello tello

Output:
The sequence after deletion:
hello bello tello
*/
