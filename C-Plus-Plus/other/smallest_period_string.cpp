
/*Given a string str of length n consisting of lowercase alphabets. Find the period of the string.
Period of the string is the minimum value of k (k >= 1), that satisfies str[i] = str[i % k] for all valid i.*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll period(string str) {
    ll left_ptr=0,right_ptr=0,i;
    
    /*length of string*/
    ll len=str.length();

    /* z function to store length of longest substring
       of str starting from i which is also prefix of str*/
    ll z[len];
    z[0]=len;
    
    for(i=1;i<len;i++){
        if(i > right_ptr){
            left_ptr = right_ptr = i;
            while(right_ptr < len && str[right_ptr - left_ptr] == str[right_ptr]) right_ptr++;
            z[i] = right_ptr - left_ptr;
            right_ptr--;
        }
        else{
            if((i + z[i-left_ptr]) <= right_ptr) z[i] = z[i-left_ptr];
            else{
                left_ptr = i;
                while(right_ptr < len && str[right_ptr - left_ptr] == str[right_ptr]) right_ptr++;
                z[i] = right_ptr - left_ptr;
                right_ptr--;
            }
        }
    }

    for(i=1;i<len;i++){
        if(z[i] + i == len) return i;
    }

    return len;
}

int main(){
   /*Read the given
    input string*/
    string str;
    cin>>str; 

    cout<<"Smallest period of the String is: "<<period(str)<<"\n";
    return 0;
}

/*
Input:
First line contains a string input 

TEST CASE
abababab

OUTPUT
Smallest period of the String is: 2

Time- complexity: O(n)

Space Complexity: O(n)
*/