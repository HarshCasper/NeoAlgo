/*
Code to reverse individual words in a sentence without using stacks
*/

#include<bits/stdc++.h>
using namespace std;

void reverseWord(string s[],int n)
{
    for(int i=0;i<n;i++)
    {
        reverse(s[i].begin(),s[i].end());
        cout<<s[i]<<" ";
    }    
}

//Driver code
int main()
{
    int n;
    cout<<"Enter the number of words in a sentence: ";
    cin>>n;
    cout<<"Enter the sentence: ";
    string st[n];
    for(int i=0;i<n;i++)
    {
        cin>>st[i];
    }
    cout<<"\nSentence with each word reversed: ";
    reverseWord(st,n);
}

/*
Input:
Enter the number of words in a sentence: 4
Enter the sentence: India is my country

Output:
Sentence with each word reversed: aidnI si ym yrtnuoc

Time Complexity: O(n)

Space Complexity:O(n)
*/
