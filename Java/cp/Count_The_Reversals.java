//Given a string S consisting only of opening and closing curly brackets '{' and '}' find out the minimum number of reversals required to make a balanced expression.
//
//        Input
//        The first line of input contains an integer T, denoting the number of test cases. Then T test cases
//        follow. The first line of each test case contains a string S consisting only of { and }.
//
//        Output
//        Print out minimum reversals required to make S balanced. If it cannot be balanced, then print -1.
//
//        Constraints
//        1 <= T <= 100
//        0 <= |S| <= 50
//
//        Examples
//        Input
//        4
//        }{{}}{{{
//        {{}}}}
//        {{}{{{}{{}}{{
//        {{{{}}}}
//
//        Output
//        3
//        1
//        -1
//        0

import java.util.Scanner;
import java.util.Stack;

public class Count_the_Reversals {
    public static void main(String[] args) {
        Stack ss=new Stack();
        System.out.println(ss.size());

        Scanner s=new Scanner(System.in);
        int t=s.nextInt();
        while (t-->0){
            Stack<Character> stack=new Stack<>();
            String str=s.next();
            if (str.length()%2!=0){
                System.out.println(-1);
            }
            else {
                for (int i = 0; i <str.length() ; i++) {
                    if(str.charAt(i)=='{'){
                        stack.push(str.charAt(i));


                    }
                    else {
                        if(!stack.isEmpty()&&stack.peek()=='{'){
                            stack.pop();
                        }
                        else {
                            stack.push(str.charAt(i));
                        }
                    }

                }
                int m=stack.size();
                int n = 0;
                while (!stack.empty() && stack.peek() == '{')
                {
                    stack.pop();
                    n++;
                }
                System.out.println(m/2+n%2);
            }

        }
    }
}
