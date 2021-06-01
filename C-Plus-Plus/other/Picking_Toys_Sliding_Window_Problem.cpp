/*
Problem Statement : John and his mother go to a shopping mall. John sees a row of toys wants to buy 
them and so he asks his mother to buy him the toys. His mother places two conditions infront of him

Condition 1:He should start picking the toys in a continuous manner and therefore cannot skip in between
Condition 2:There should be only two types of toys with John.

Now we need to help John to maximize the toy count by considering these tow conditions.



Input: A string will be given where each letter denotes the type of toy.
Output: Maximum number of toys John can have obeying the conditions given by his mother.


Sample Input:
1
abaccab
Output:
4

Explanantion :
He will start picking the toys from 2nd index and will keep picking till 5th index i.e.a,c,c,a.
Here we have only two types of toys i.e. a and c and they are picked in continuos manner

Time Complexity: O(n)

How to relate this problem with Sliding Window?

Here if we see we have a string of certain length,the problem asks us to pick the toys in a continuous manner.
This implies that we basically need to select a substring in the given string.Secondly we need to pick only 
two types of toys which means that our string can have only two types of unique letters.

Therefore from these two observations we can come to a conlusion that this problem can be reduced to 
one of the standard Sliding Window problems in which we have to find a substring of maximum length 
with k unique characters and for our problem we have k=2.Therefore using the approach of this problem we can solve 
the problem of Picking Toys.

*/

//Let's look into the simple code of this problem in C++:

#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
                                            //instead of k I have sustituted its value as 2 you can also directly initialise k with 2 and place k
        int i=0,j=0;
        
        int mx = INT_MIN;
        unordered_map<char,int> mp;
        
        int len = s.length();
       
        while(j<s.length()){                //traversing whole string to get the max length
            mp[s[j]]++;
                                            //dividing the size into 3 parts
            if(mp.size()<2){
                j++;
            }
            else if(mp.size()==2){
                mx = max(mx,j-i+1);         //calculating max
                j++;
            }
            else{                           //removing the starting characters from the window
               while(mp.size()>2){
                   mp[s[i]]--;
                   if(mp[s[i]]==0){
                       mp.erase(s[i]);
                   }
                   i++;
               }
               j++;
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
