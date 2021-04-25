#include <bits/stdc++.h>
using namespace std;

/*
Efficient solution is to first count the number of lexicographically smaller strings.
Lexicographic rank of current string = 1 + number of lexicographically smaller strings

Lets understand this approach by an example



Let the string be ="hero".

Take a pointer ptr and move it from start to end.
We start moving the ptr from the first character i.e  'h'. Then count the number of characters in the right, which is smaller than
'h'. There is one character -'e'.

Lexicographically smaller strings than "hero" can be e _ _ _. The three dashes signify that we can put any of the remaining character i.e 'h', 'r', 'o' there.
So, count= 1* 3! =6.

Now, move ptr to second character i.e 'e'. Then count the number of characters in the right, which is smaller than
'e'. There is no such chracter.

Now, move ptr to third character i.e 'r'. Then count the number of characters in the right, which is smaller than
'r'. There is one character -'o'. 

Lexicographically smaller strings than "hero" can be heo _. The one dash signify that we can put any of the remaining character i.e 'r' there.
So, count + = 1.= (6+1)=7

Now, move ptr to fourth character i.e 'o'. Then count the number of characters in the right, which is smaller than
'o'. It is obviously zero and there will be no character in right.

Therefore, lexicographic rank of current string "hero" = count+1 = 7 + 1 = 8.

*/
int rank(string S){
	
    int length_of_string=S.size();
    
    //calculating factorial upto the length_of_string so that we don't need to calculate the factorial again.
    long long int factorial[length_of_string];
    factorial[0]=1;
    factorial[1]=1;
    for(int counter=2;counter<length_of_string;counter++)
    {
        factorial[counter]=((factorial[counter-1]%1000000007)*(counter%1000000007))%1000000007;
    }
    long long int lexicographically_smaller_strings=0;
    for(int counter=0; counter < length_of_string; counter++)
    {
       
        int count=0;
        //count no of elements on right hand side smaller than the current character
        for(int iterator = counter+1 ; iterator < length_of_string ; iterator++)
        {
            if (S[iterator] < S[counter])
            count++;
        }
        
        //calculating number of lexicographically smaller strings
        lexicographically_smaller_strings+=((factorial[length_of_string-counter-1]%1000000007)*(count%1000000007))%1000000007;
    }
    //Lexicographic rank of current string = 1 + number of lexicographically smaller strings
    return (lexicographically_smaller_strings+1)%1000000007;
    
    
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--)
	{
        string str;
        cin>>str;
        cout<<rank(str)<<"\n";
    }
}  // } Driver Code Ends

/*

Input: 
2
hero
kingdom

Output:
9
2480

*/
