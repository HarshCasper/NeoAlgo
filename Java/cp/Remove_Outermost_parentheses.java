import java.util.*;
import java.lang.*;
import java.io.*;

class Stacks {
    public String removeOuterParentheses(String S) {
        if (S.length() == 0) return "";
        Stack<Character> stack = new Stack<>();
        int count = 0;
        
        for (int i = S.length() - 1; i > 0; i--)
            stack.push(S.charAt(i));
            
        String ans = "";
        while (!stack.isEmpty()){
            if (stack.peek() == '('){
                if (count >= 0)
                    ans+= stack.peek();
                count++;
            }
            else{
                if (count != 0)
                    ans += stack.peek();
                count --;
            }
            stack.pop();
        }
        return ans;
    }
}

/*
TIME COMPLEXITY: 0(N) where n is size of string
SPACE COMPLEXITY:0(N) where n is size of string
TEST CASE

INPUT
"(()())(())"

OUTPUT
"()()()"

INPUT
"(()())(())(()(()))"

OUTPUT
"()()()()(())"

*/

