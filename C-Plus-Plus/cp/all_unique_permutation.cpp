/*Problem Statement:
You are given a string containing numbers, the task is to print all the unique permutations 
that are possible excluding the string that was entered by the user,that is the entered combination
of characters entered as string shouldn't be printed. */
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

