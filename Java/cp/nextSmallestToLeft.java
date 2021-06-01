/*
Given an array of numbers find the next smallest element to the left of each element.
ALGORITHM:
*We use the concept of Last In First Out of stacks
*Here we use the Stack class
*/ 

import java.util.Stack;
import java.util.Scanner;

public class NextSmallestToLeft
{
    public static void nextSmallestToLeft(int a[],int n)
    {
        //Initializing in-built stack
        Stack<Integer> st=new Stack<>();
        int v[]=new int[n];
        for(int i=0;i<n;i++)
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
5
Enter the elements:
4 6 2 9 0

Output:

-1 4 -1 2 -1
*/
