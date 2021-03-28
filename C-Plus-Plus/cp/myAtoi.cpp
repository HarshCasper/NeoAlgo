//Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

//Example:

//Input: s = "42"
//Output: 42
//Explanation: The underlined characters are what is read in, the caret is the current reader position.
//Step 1: "42" (no characters read because there is no leading whitespace)
//         ^
//Step 2: "42" (no characters read because there is neither a '-' nor '+')
//         ^
//Step 3: "42" ("42" is read in)
//           ^
//The parsed integer is 42.
//Since 42 is in the range [-231, 231 - 1], the final result is 42.

//Link for the question: https://leetcode.com/problems/string-to-integer-atoi/

#include<iostream>
#include<string>

using namespace std;

class Solution {
	string str;
public:
	void Input_str(){
		cout<<"Enter the string: ";
		fflush(stdin);
		getline(cin,str);
	}
    int myAtoi(string str) {
        if (str.empty()) return 0;
        str += '.';
        long long res = 0;
        int sign = 1;
        size_t i = str.find_first_not_of(" ");
        if (i != string::npos and str[i] == '-' or str[i] == '+') {
            sign = str[i++] == '-' ? -1 : 1;
        }
        while (i != string::npos and isdigit(str[i])) {
            res = (res * 10) + (str[i++] - '0');
            if (res * sign > INT_MAX) return INT_MAX;
            if (res * sign < INT_MIN) return INT_MIN;
        }
        return res * sign;
    }

    void display(){
    	int result = myAtoi(str);
    	cout<<"The converted result: "<<result<<endl;
	}
};

int main(){
	Solution s;
	s.Input_str();
	s.display();
}
