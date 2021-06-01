/*
Given an array of numbers find the next smallest element to the right of each element.
ALGORITHM:
*We use the concept of Last In First Out of stacks
*/ 

import java.util.Stack;
import java.util.Scanner;

public class NextSmallestToRight
{
    public static void nextSmallestToRight(int a[],int n)
    {
        //Initializing in-built stack
        Stack<Integer> st=new Stack<>();
        int v[]=new int[n];
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            v[i]=-1;
            else if(st.empty()!=true && st.top()<a[i])
            v[i]=st.top();
            else if(st.empty()!=true && st.top()>=a[i])
            {
                while(st.empty()!=true && st.top()>=a[i])
                st.pop();

                if(st.empty())
                v[i]=-1;
                else if(st.top()<a[i])
                v[i]=st.top();
            }
            st.push(a[i]);
        }
        for(int i=0;i<n;i++)
        System.out.print(v[i]+" ");
    }
    public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        int n;
        System.out.println("Enter the size of the array: ");
        n=s.nextInt();
        int a[]=new int[n];
        System.out.println("Enter the elements: ");
        for(int i=0;i<n;i++)
        a[i]=s.nextInt();
        nextSmallestToRight(a,n);
        s.close();        
    }
}

/*
Time Complexity: O(n)

Space Complexity: O(n)

Input:

Enter the size of the array: 
4
Enter the elements:
3 4 1 7

Output:

1 1 -1 -1
*/
