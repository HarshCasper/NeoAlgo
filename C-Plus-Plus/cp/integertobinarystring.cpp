#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

string decimalToBinary(ll n) 
{      
    string s = bitset<64> (n).to_string();  // stl to convert integer tobinary and convert into string 
      
    //Finding the first occurance of "1" 
    //to strip off the leading zeroes. 
    const auto loc1 = s.find('1'); 
      
    if(loc1 != string::npos) 
        return s.substr(loc1); 
      
    return "0"; 
} 


int main() {
    
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"binary string of given number is :"<< decimalToBinary(n);

    return 0;
}
