/*
Given a time in 12-hour AM/PM format, convert it to military (24-hour) time. 
Note: Midnight is 12:00:00 AM on a 12-hour clock and 00:00:00 on a 24-hour clock. 
Noon is 12:00:00 PM on 12-hour clock and 12:00:00 on 24-hour clock
*/

// C++ code ->

#include<bits/stdc++.h>
using namespace std;

string convertime(string str)  // fuction to convert the string
{
    string hour_str= str.substr(0,2);
    int hour = stoi(hour_str);
    size_t p = str.find ("PM");
    if (p!= string::npos){
        if( hour +12 <24){
            hour_str = to_string(hour + 12);
        }
    }
    else{
        if (hour == 12){
            hour_str= "00";
        }
    }
        return str.replace(0,2,hour_str).erase(str.size()-2);
}

//calling the function:

int main(){
    
    string S;
    cin>> S;
    string res= convertime(S);
    cout<< res<<"\n";
    
    return 0;
} 

/*
Test Case 1: 
            Input: 07:05:45 PM

            Output: 19:05:45

Test Case 2:
            Input: 01:20:45 PM

            Output: 13:20:45

Test Case 3:
            Input: 10:35:15 PM

            Output: 22:35:15

Time Complexity: O(1) 
Space Complexity: O(1)
*/