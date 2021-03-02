class String_to_int {
public:
    int myAtoi(string str) {
    	if (str.empty()) return 0;
    	int i = 0, sign = 1;
    	while (i + 1 < str.size() && isspace(str[i])) ++i;
    	
	long res = 0;
    	if (str[i] == '-' || str[i] == '+') sign = 44 - str[i++];
    
	while (i < str.size()) {
             if (isdigit(str[i])) res = 10 * res + str[i++] - '0';
             else return res * sign;
             if (res > INT_MAX) return sign == -1 ? INT_MIN : INT_MAX;
        }
        return res * sign;
    }
};

/*

TIME COMPLEXITY: 0(N) where N is length of string
SPACE COMPLEXITY: o(1)
TEST CASE

Input: "42"
Output: 42

Input: "4193 with words"
Output: 4193

*/

