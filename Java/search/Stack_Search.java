/* Stack search is a method to search an element in a stack and return the index at which its found. */

import java.util.*;

public class stack_search{
    
	public static void main(String[] args) {
	    
	    Scanner sc = new Scanner(System.in);
	    //enter the no of elemnts to be there inside stack
	    int n = sc.nextInt();
	    int no;
        Stack <Integer> st = new Stack <Integer> (); 
        for(int i = 1; i <= n; i++) {
        	no = sc.nextInt();
        	st.push(no);
        }
        // Displaying the Stack 
        System.out.println("The stack is: " + st); 
         //enter the element to be searched
            int item = sc.nextInt();
        // Checking for the element
            int search = st.search(item);
           System.out.println(item+" is seached at index="+(n-search+1));     
    } 
}
