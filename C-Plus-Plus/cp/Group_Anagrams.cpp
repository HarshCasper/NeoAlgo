/*
Introduction 
Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Argument/Return Type
Given a vector of strings as input
return answer as vector of vectors and print the result
*/

#include <bits/stdc++.h> 
using namespace std;

//Function to print all the groups of anagrams
void printGroups(vector<vector<string>>& Groups)
{
    //Print each group in a new line
    for(auto group : Groups)
    {
        for(auto str : group)
        {
            cout<<str<<" ";
        }
        cout<<endl;
    }
}

//Function to group anagrams together and return the result
vector<vector<string>> groupAnagrams(vector<string>& strings) 
{
    //Create a vector to store all groups of anagrams
    vector<vector<string>>Groups;
    //Create a map to store group number of each string
    map<string,int>groupNumber;
    
    //Keep count of number of groups
    int NumberOfGroups=0;
    
    //Visit all strings
    for(auto str : strings)
    {
        /* Create a temp string and sort it
        without disturbing original string */
        string temp=str;
        sort(temp.begin(),temp.end());

        //If the sorted string doesnot have a group already
        if(groupNumber[temp]==0)
        {
            /* Create a new group of strings
             push the string to the group and 
             push this group to the other groups */ 
            vector<string>group;
            group.push_back(str);
            Groups.push_back(group);

            //Increase no.of groups as new group is created
            NumberOfGroups++;
            //Store the group number of this sorted string
            groupNumber[temp]=NumberOfGroups;
        }
        else
        {
            /* If the group which this string belongs to already exists ,
              push the string to the corresponding group */
            Groups[groupNumber[temp]-1].push_back(str);
        }
    }

    return Groups;   
}

// Driver code
int main()
{
    //Take the input of total no.of strings
    int n;
    cout<<"Enter the total no.of strings : ";
    cin>>n;

    //Take input of the strings as vector
    vector<string>strings;
    for(int i=1;i<=n;i++)
    {
        string str;
        cout<<"Enter string "<<i<<" : ";
        cin>>str;
        strings.push_back(str);
    }

    //Call the function and print the result
    vector<vector<string>>result;
    result=groupAnagrams(strings);
    cout<<"Hence the grouped anagrams are "<<endl;
    printGroups(result);

    return 0; 
}
    
/*
Input:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.

Sample Test Case 1  

Input Format : 
Example :
Enter the total no.of strings : 6
Enter string 1 : eat
Enter string 2 : tea
Enter string 3 : tan
Enter string 4 : ate
Enter string 5 : nat
Enter string 6 : bat

Output Format :
Example : ( Output to the above input example ) 
Hence the grouped anagrams are
eat tea ate
tan nat
bat

Time/Space Complexity
  Time Complexity : O(n*klogk) 
  Space Complexity : O(n*k) 
*/
