import java.util.*;
import java.lang.*;
import java.io.*;

class Validate_stack {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int N = pushed.length;
        Stack<Integer> stack = new Stack();

        int j = 0;
        for (int x: pushed) {
            stack.push(x);
            while (!stack.isEmpty() && j < N && stack.peek() == popped[j]) {
                stack.pop();
                j++;
            }
        }

        if (j == N) return true;
	else return false;
    }
}

/*
TIME COMPLEXITY: 0(N) where n is size of string
SPACE COMPLEXITY:0(N) where n is size of string
TEST CASE

INPUT
[1,2,3,4,5]
[4,5,3,2,1]

OUTPUT 
true

*/

