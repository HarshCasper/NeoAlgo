// This program prints all the possible codes for a given string.
#include <bits/stdc++.h>
using namespace std;

void printallcodes(string number, string ans){
    if(number.size() == 0) { //Base case
        cout << ans << endl;
        return;
    }
    
    int ch = number[0] - '0';  
    
    if(ch != 0){
        char code = char(ch-1 + 'a'); //Extracting alphabet from its value
        string rstr = number.substr(1);  
        printallcodes(rstr, ans + code);
    }
    
    if(number.size() >= 2) {
        int num = stoi(number.substr(0,2));
        
        if(num >= 1 && num <= 26) {
            char code = char(num - 1+ 'a');
            string rstr = number.substr(2);
            printallcodes(rstr, ans + code);
        }
    }                 
}

int main() {
    string number;
    cout << "Enter the number";
    cin >> number;
    printallcodes(number, "");
    return 0;
}

/*Example:
Input : s = "1123"
Output :
aabc
aaw
alc
kbc
kw */
