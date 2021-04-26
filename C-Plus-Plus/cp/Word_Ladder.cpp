
/*
Problem Statement:
Given two strings as startWord and endWord and,
Given a list of n words (s1 -> s2 -> s3------>sn)such that:
Every adjacent pair of words differ by a single letter.
StartWord may note be present in the List
Sn==endWord.
Find the number of words in the shortest sequence from startWord to endWord, or 0 if no such sequence exists.

Input:
     ABCV
     EBAD
     4
     ABCD XYZA EBCD  EBAD

Output: 4
    
*/


#include <bits/stdc++.h>

using namespace std;

int WordLadder(string startWord, string endWord, vector<string>& s) {
        
        if(find(s.begin(), s.end(),endWord)==s.end())
            return 0;
        
        bool visit[s.size()];
        memset(visit,false,sizeof(visit));
        
       queue<pair<string,int> > q;
        
        // first word of the required sequence and word count 
        q.push({startWord,1});
        
    
        while(!q.empty())
        {
            pair<string,int> p= q.front();
            
             string temp=p.first;
             
            int count=p.second;
            
            q.pop();
            
            // end word found
             if(temp==endWord)
             {
                 return count;  
             }
            
            //  Traverse through the list
            for(int i=0;i<s.size();i++)
            {
                // if ith element not visited before
                if(visit[i]==false)
                { 
                    int a=0;
                   string x=s[i];
                   
                   for(int j=0;j<temp.length();j++)
                   {
                       if(temp[j]!=x[j])
                           a++;
                   }
                 
                 // if word differ by single character
                   if(a==1)
                   {
                       visit[i]=true;
                       
                       // push string count pair to queue
                       // and increment ladder's word count
                       q.push({x,count+1});
                   }
                }
            }  
        }
        
        return 0;
    }


int main()
{
    string startWord;  // Starting Word
    cin>>startWord;
    
    string endWord;  // Ending word
    cin>>endWord;
    
    int n;   // Number of words in list
    cin>>n;
    
    // Word List
    vector<string> s;
    
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        
        s.push_back(temp);
    }
    
    // Result
    int res;
    
    res= WordLadder(startWord, endWord, s);
    
    cout<<res<<endl;

    return 0;
}

/*

   Time complexity: O(n²m), where n is the number of entries originally in the Word List
                    and m is the size of the string. 
*/

/*
  Example 1:

   Input:
     hit 
     cog
     6
     hot dot dog lot log cog
  
  Output:
     5
   
  Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
  
  Example 2:
  Input:
     hit 
     cog
     5
     hot dot dog lot log 
  
  Output:
     0
   
   Explanation: "cog" is not in the word List
*/


