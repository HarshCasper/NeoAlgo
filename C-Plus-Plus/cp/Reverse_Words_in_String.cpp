/**
 * @author omkarlanghe
 * Given a String of length S, reverse the whole string without reversing the individual words in it.
 * Words are separated by dots.
 * 
 * Input:
 * The first line contains T denoting the number of testcases. 
 * T testcases follow. Each case contains a string S containing characters.
 * 
 * Output:
 * For each test case, in a new line, output a single line containing the reversed String.
 * 
 * Example:
 * Input:
 * 2
 * i.like.this.program.very.much
 * pqr.mno
 * 
 * Output:
 * much.very.program.this.like.i
 * mno.pqr
*/
#include <iostream>
#include <stack>

int main() {
    int t;
    std::cout << "Enter test cases : " << std::endl;
    std::cin >> t;
    while (t--) {
        std::stack<std::string> str_stack;
        std::string str, stack_string;

        std::cout << "Enter the string : " << std::endl;
        std::cin >> str;

        for (int i = 0 ; i < str.size() ; i++) {
            if (str[i] != '.') {
                stack_string += str[i];
            } else {
                str_stack.push(stack_string);
                str_stack.push(".");
                stack_string = "";
            }
        }
        str_stack.push(stack_string);
        str = "";
        while (!str_stack.empty()) {
            str += str_stack.top();
            str_stack.pop();
        }
        std::cout << str << std::endl;
    }
    return (0);
}
