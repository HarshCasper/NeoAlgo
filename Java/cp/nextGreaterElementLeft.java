/*
Given an array of numbers find the next greater element to the left of each element.
ALGORITHM:
*Using Stack class in Java, the problem can be solved in O(n) complexity
*/
import java.lang.Scanner;
import java.util.Stack;

public class NextGreaterElement
{
    public static void nextGreaterElementToLeft(int a[],int n)
    {
        Stack<Integer> st=new Stack<>();
        int v[]=new int[n];
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            v[i]=-1;
            else if(st.empty()!=true && st.top()>a[i])
            v[i]=st.top();
            else if(st.empty()!=true && st.top()<=a[i])
            {
                while(st.empty()!=true && st.top()<=a[i])
                st.pop();
                if(st.empty())
                v[i]=-1;
                else if(st.top()>a[i])
                v[i]=st.top();
            }
        }
        for(int i=0;i<n;i++)
        System.out.print(v[i]+" ");
    }

    public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the size of the array: ");
        int n=s.nextInt(System.in);
        System.out.println("Enter the elements: ");
        int a[]=new int[n];
        for(int i=0;i<n;i++)
        a[i]=s.nextInt();
        nextGreaterElementToLeft(a,n);        
    }
}

/*
Time Complexity: O(n)

Space Complexity: O(n)

Input:

Enter the size of the array: 
5
Enter the elements:
9 3 7 1 0

Output:

-1 9 9 7 1
*/