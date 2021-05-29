/*Java program to find Minimum Element in a Stack in Constant Time i.e O(1).
    Maintain an additional stack that will keep track of the minimum element
    of the Original Stack.

    Every push to the primary STACK, compare the current value
    with the TOS of the temporary Stack and IF the current value is less
    than the TOS push the current value to the temporary STACK,such that
    the minimum element is always at the top of the STACK

*/

import java.util.Scanner;
import java.util.Stack;

class Min_Element_In_Stack {

  //s1 will act as primary stack and s2 as temporary stack  
  Stack < Integer > s1 = new Stack < Integer > ();
  Stack < Integer > s2 = new Stack < Integer > ();

  //Push data to the top of the stack
  void insertData(int data) {
    //If both the stacks are empty add the item to both the stack
    if (s1.isEmpty() && s2.isEmpty()) {
      s1.push(data);
      s2.push(data);
    } else {
      s1.push(data);
      /* IF pushed value is less than TOS of the temporary stack i.e stack2(s2)
      push the value,such that minimum element is always at the TOS of stack2(s2)
      */
      if (s1.peek() <= s2.peek()) {
        s2.push(data);
      }
    }

  }

  //Find the minimum from top of the stack
  int findMinimum() {
    return s2.peek();
  }

  public static void main(String args[]) {
    Scanner inp = new Scanner(System.in);

    Min_Element_In_Stack mObj = new Min_Element_In_Stack();
    int n;
    System.out.print("Enter the no of Elements in the Stack:");
    n = inp.nextInt();

    System.out.println("Enter the values of the stack:");
    for (int i = 0; i < n; i++) {
      mObj.insertData(inp.nextInt());
    }

    //Find Minimun
    System.out.println("Minimum element in the above stack is :" + mObj.findMinimum());

  }
}

/*
  Time complexity: O(1) for finding the minimum
  Space complexity: O(n)
  
  Sample input/output:
  Enter the no of Elements in the Stack:5

  Enter the values of the stack:
  11
  5
  7
  2
  -5

  Minimum element in the above stack is : -5
  
 */