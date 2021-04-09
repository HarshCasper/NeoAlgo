/*Problem Statement:
Given a collection of numbers that might contain duplicates, 
return all possible unique permutations excluding the user input. */
#include<bits/stdc++.h>
using namespace std;

char temp[1000];
set<string>s;
void permute(string in, int i)
{
    if(in[i]=='\0')
    {
      s.insert(in); 
      return;
    }

    for(int j=i;in[j]!='\0';j++)
    {
       swap(in[i],in[j]);
       permute(in,i+1);
       /*Backtracking so that more permutations could
       be generated*/
       swap(in[i],in[j]);
    }


}
int main()
{
   string in;
   cout<<"Enter string: "<<endl;
   cin>>in;
   string temp;
   temp=in;
   permute(in,0);
   set<string> :: iterator itr;
   cout<<"all distinct permutations are: "<<endl;

   for(itr=s.begin();itr!=s.end();itr++)
   {
     if(*itr>temp)
     {
         cout<<*itr<<endl;
     }
   }
   return 0;
}
/*Example:
Input:-
Enter string:
112
Output:-
all distinct permutations are:
121
211 
Time Complexity: O(n)
Space Complexity: O(n)
*/

