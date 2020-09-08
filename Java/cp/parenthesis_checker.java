import java.util.*;
import java.io.*;
import java.lang.*;

class ParenthesisChecker
{
    
    static boolean paren(char x1, char x2){
        if((x1=='{'&& x2=='}') || (x1=='('&& x2==')') || (x1=='['&& x2==']')){
            return true;
        }
        return false;
    }
    static boolean isparenthesis(String x)
    {
        if(x.length()==1){
            return false;
        }
        Stack<Character> st=new Stack<Character>();
        for(int i=0;i<x.length();i++){
        if(x.charAt(i)=='{'||x.charAt(i)=='['||x.charAt(i)=='('){
            st.push(x.charAt(i));
        }else{
            if(st.isEmpty()){
                return false;
            }else if(paren(st.peek(),x.charAt(i))==false){
                return false;
            }else{
                st.pop();
            }
        }
        }
        
        return (st.isEmpty());
    }
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t= sc.nextInt();

        String str = sc.next();
        if(isparenthesis(str) == true){
            System.out.println("yes");
        }
        else{
            System.out.println("no");
        }
        
        
    }
}
/*
Input: “[()]{}{[()()]()}”
Output: yes

Input: “[(])”
Output: no

Time Complexity: O(n)
Auxiliary Space: O(n) (stack)
*/
