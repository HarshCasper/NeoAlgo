/* 
This program finds the number of binary trees given the length of the preorder sequence = n.
A tree is an acyclic graph . A binary tree is a tree where each node has 0, 1 or 2 children. 
Preorder traversal means traversing a tree in the following order : Root - Left child - Right child.  
    
We use the dynamic programming approach where our root is fixed and the rest of the n-1 nodes
are split as left and right children. Hence, we calculate the number of binary trees possible
while exploring splits varying from 0 to n-1.
    
Time Complexity - O(n^2)
Space Complexity - O(n)
    
Note:- The approach is similar to finding the nth catalan number.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli PossibleBinaryTrees(int number)
{
    lli *table=(lli *)malloc((number+1)*sizeof(lli));
    
    //Since number of trees that can be formed for n=0/1 is 1
    table[0]=1,table[1]=1;    
    
    //Calculating possible number of binary trees for all i<=n and storing them for future use-Tabulation Method
    for(int loop1=2;loop1<=number;loop1++)                      
    {
        table[loop1]=0;
        
        //We loop over the possible splits from 0 to i-1
        for(int loop2=0;loop2<loop1;loop2++)                       
        {
            table[loop1]+=(table[loop2]*table[loop1-loop2-1]);
        }
    }
    
    lli answer=table[number];
    free(table);
    return answer;
}

//Driver function
int main()                                                      
{
    //Enter length of preorder sequence
    int number;                                                 
    cin>>number;
    cout<<PossibleBinaryTrees(number)<<endl;
    return 0;
}
/* 
Sample input:-
n = 5;
Output = 42;
*/
