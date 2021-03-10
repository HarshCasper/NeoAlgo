import java.util.*;
public class balancedBrackets
{
    public static boolean isBalanced(String s)
    {
        java.util.Stack<Character> stack=new java.util.Stack<>();
        if(s.length()==1)
        return false;
        for(int i=0;i<s.length();i++)
        {
        char c=s.charAt(i);
        if(c=='('||c=='['||c=='{')
        stack.add(c);       
        else
        {
            if(c==')')
            {
                if(stack.isEmpty())
                return false;
                char c2=stack.pop();
                if(c2!='(')
                return false;
            }
            else if(c==']')
            {
                if(stack.isEmpty())
                return false;
                char c2=stack.pop();
                if(c2!='[')
                return false;
            }
            else if(c=='}')
            {
                if(stack.isEmpty())
                return false;
                char c2=stack.pop();
                if(c2!='{')
                return false;
            }
        } 
        }
        if(!stack.isEmpty())
        return false;
        return true;     
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the string consisting of brackets");
        String s=sc.nextLine();
        if(isBalanced(s))
        System.out.println("The given string "+s+" has balanced brackets in it.");
        else
        System.out.println("The given string "+s+" does not have balanced brackets in it.");
    }
}