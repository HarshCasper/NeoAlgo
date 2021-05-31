/*
 - Next Greater Element :
  		given an array, we have to find the next greater element for every element in that array
 ALGORITHM:
  * Initialize stack and array
  * If the stack is empty then -1 is printed(no greater element to the right)
  * If not, then if the topmost element is greater than the number, print it
  * If topmost element is less then pop stack until empty or greater number is found
 */

import java.util.Scanner;
import java.lang.Stack;

public class NextGreaterElement {

	//next_greater_element method
	public static void next_greater_element(int[] array, int n) 
	{
		Stack<Integer> st=new Stack<>();
		int v[]=new int[n];
		for(int i=n-1;i>=0;i--)
		{
			if(st.empty())
			v[i]=-1;
			else if(st.empty()!=true && st.top()>array[i])
			v[i]=st.top();
			else if(st.empty()!=true && st.top()<=array[i])
			{
				while(st.empty()!=true && st.top()<=array[i])
				st.pop();

				if(st.empty())
				v[i]=-1;
				else
				v[i]=st.top();
			}
			st.push(array[i]);
		}
		for(int i=0;i<n;i++)
		System.out.print(v[i]+" ");
	}
	//main method
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the number of elements: ");
		//Input the number of elements you want in the array
		int n = sc.nextInt();

		//Creating array of n elements
		int[] array = new int[n];

		System.out.print("Enter the elements : ");
		//Putting elements in the array
		for(int i = 0 ; i < n ; i++) {
			array[i] = sc.nextInt();
		}
		//Calling next_greater_element method
		NextGreaterElement.next_greater_element(array, n);
		}
	}
}
/*
 - Test Cases :
      Input : Enter the number of elements: 5
              Enter the elements : 12 34 54 2 62
     Output : 34 54 62 62 -1

 - Complexity Analysis :
 *  Time Complexity : O(n)

 *  Space Complexity : O(n)
 */
  
