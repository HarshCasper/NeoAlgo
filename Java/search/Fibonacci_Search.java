/* Fibonacci search works for sorted array,
   it is basically a comparison-based techhnique
   that uses fibonacci numbers to search an element in an array.
*/

import java.util.*;
//Declaring fibonacci_Search class
class Fibonacci_Search
{
    //Method to find minimum in two numbers
    public static int min(int x,int y)
    {
        return (x<=y?x:y);
    }
    //Fibonacci serach method
    public static int fibonacci_Search(int arr[],int s,int n)
    {
	    int fib2=0;
	    int fib1=1;
	    int fib=fib2+fib1;
	    while(fib<n)
	    {
		    fib2=fib1;
		    fib1=fib;
		    fib=fib2+fib1;
	    }
	    int offset=-1;
	    while(fib>1)
	    {
		    int i=min(fib2+offset,n-1);
		    if(arr[i]<s)
		    {
			    fib=fib1;
			    fib1=fib2;
			    fib2=fib-fib1;
			    offset=i;
		    }
		    else if(arr[i]>s)
		    {
			    fib=fib2;
			    fib1=fib1-fib2;
			    fib2=fib-fib1;
		    }
		    else
			    return i;
	    }
		if(fib1==s && arr[offset+1]==s)
			return offset+1;
		return -1;
}
//driver code
public static void main(String args[])
{
    int n,s;
    System.out.println("Fibonacci Search program:");
    System.out.println("Enter the size of an array:");
    Scanner sc=new Scanner(System.in); 
    n=sc.nextInt();  
    int[] arr = new int[n];
    System.out.println("Enter the elements of the array:");  
    for(int i=0; i<n; i++)  
    {  
        //reading array elements from the user   
        arr[i]=sc.nextInt();  
    }   
    System.out.println("Enter the elements to search in array:");
    s=sc.nextInt();
    //calling function and printing output
    int index=fibonacci_Search(arr, s, n);
    if(index>=0)
        System.out.print("Found at index:" +index);
    else
        System.out.print(s+" isn't present in the array.");
}
}

/* Input_1:
Enter the size of an array:
5
Enter the elements of an array:
25
35
45
65
85
Enter the elements to search in array:
65
Output_1:
Found at index:3

Input_2:
Enter the size of an array:
5
Enter the elements of an array:
25
35
45
65
85
Enter the elements to search in array:
55
Output_2:
55 isn't present in the array.
*/