/* In this problem You are given an integer C. Let d be the smallest integer such that 2d is strictly greater than C.

Consider all pairs of non-negative integers (A,B) such that A,B<2d and A⊕B=C (⊕ denotes the bitwise XOR operation). Find the maximum value of A⋅B over all these pairs.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer C.
Output
For each test case, print a single line containing one integer ― the maximum possible product A⋅B.

Constraints
1≤T≤10^5
1≤C≤10^9 

Sample Input 
2
13
10

*/


#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

string decimalToBinary(ll n) 
{ 
    //finding the binary form of the number and  
    //coneverting it to string.  
    string s = bitset<64> (n).to_string(); 
      
    //Finding the first occurance of "1" 
    //to strip off the leading zeroes. 
    const auto loc1 = s.find('1'); 
      
    if(loc1 != string::npos) 
        return s.substr(loc1); 
      
    return "0"; 
} 


int main() {
	// below two lines used to take input output faster 
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t; 
    while(t--){
        ll N,a,b,j; 
        string str;
        cin>>N;
        str = decimalToBinary(N);
        j=str.length();
		//we use this for loop because if we see some test cases we will find that 
		//this pattern is repeating i.e. first place value is as it is and 
		//after that they are its complement 
        for(int i=1; i<j; i++){
            if(str[i]=='0'){
            str[i]='1';
            }
            else if(str[i]=='1'){
            str[i]='0';
            }
        }
		//this function take string as input and print out its integer value 
        a = stoi(str, 0, 2);
        
        b=a^N;
        cout<<a*b<<"\n";

    }

    return 0;
}


/* Sample Output
70
91 */