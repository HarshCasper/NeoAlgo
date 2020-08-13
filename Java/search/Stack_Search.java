// Stack search is simple code or simple algorithm to find an element in an Stack that the element is present in the stack or not if yes so at what index 
// in this the index output will be according to humans as at what place the user has enterd the element
import java.util.*;
public class Stack{
	public static void main(String[] args) {
	    Scanner sc=new Scanner(System.in);
	    //enter the no of elemnts to be their inside stack
	    int n=sc.nextInt();
	    int no;
        Stack<Integer> st = new Stack<Integer>(); 
        for(int i=1;i<=n;i++) {
        	no=sc.nextInt();
        	st.push(no);
        }
        // Displaying the Stack 
        System.out.println("The stack is: " + st); 
         //enter the item to be searched
            int item=sc.nextInt();
        // Checking for the item
            int search=st.search(item);
           System.out.println(item+" is seached at index="+(n-search+1));     
    } 

}
