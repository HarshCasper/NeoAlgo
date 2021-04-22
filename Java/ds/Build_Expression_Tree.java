/*
This is the solution to build an expression tree from a given postfix expression.
The corresponding infix expression is obtained by inorder traversal of the built expression tree.

Constraints:
1)Operands in the expression should lie in (0,10^5) or (A,Z) or (a,z)
2)Operators in the expression - {+,-,*,/,%,^}

Approach:
1)Traverse through all the elements in the expression and check if it is an operator or operand.
2)If it is an operand, push it into the stack.
3)It it is an operator,pop the top 2 elements and make them the right and left child respectively of the current node.
  Push this node on the stack.
4)After the expression is traversed,only one element is left in the stack.
This is the root of the required expression tree.
*/


import java.util.*;
public class Build_Expression_Tree {

    //Class which defines the structure of each node in the binary tree
    static class Node {
        String data;
        Node left, right;
        Node(String data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    //Function to check if the element passed is an operator
    static boolean isOperator(String ch) {
        if (ch.equals("+") || ch.equals("-") || ch.equals("*") || ch.equals("/") || ch.equals("%") || ch.equals("^"))
            return true;
        else
            return false;
    }


    //Function which builds the expression tree and returns the root node of the tree
    static Node buildTree(ArrayList < String > exp) {
        Node root;
        Node temp1;
        Node temp2;
        Stack < Node > s = new Stack < > ();
        for (int i = 0; i < exp.size(); i++) {
            //If the element is an operand,push it on the stack
            if (!isOperator(exp.get(i))) {
                root = new Node(exp.get(i));
                s.push(root);
            }
            //If the character is an operator,pop the top two nodes and make them the children of the current character node
            else {
                root = new Node(exp.get(i));
                temp1 = s.pop();
                temp2 = s.pop();
                root.right = temp1;
                root.left = temp2;
                s.push(root);
            }
        }
        root = s.peek();
        s.pop();
        return root;
    }

    //Inorder traversal by recursion
    static void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.data + " ");
            inorder(root.right);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter postfix expression whose corresponding expression tree is required: ");
        ArrayList < String > exp = new ArrayList < > ();
        String val = " ";

        while (!val.equals("-1")) {
            System.out.println("Enter operator or operand or -1 to end");
            val = sc.next();
            if (!val.equals("-1"))
                exp.add(val);
        }

        Node root = buildTree(exp);

        System.out.println("The infix expression by traversing the expression tree is");
        inorder(root);

        sc.close();
    }
}

/*
Sample Input:

Enter postfix expression whose corresponding expression tree is required: 
Enter operator or operand or -1 to end
250
Enter operator or operand or -1 to end
300
Enter operator or operand or -1 to end
+
Enter operator or operand or -1 to end
3
Enter operator or operand or -1 to end
/
Enter operator or operand or -1 to end
5
Enter operator or operand or -1 to end
*
Enter operator or operand or -1 to end
10
Enter operator or operand or -1 to end
+
Enter operator or operand or -1 to end
-1

Sample Output:

The infix expression by traversing the expression tree is
250 + 300 / 3 * 5 + 10 

Time Complexity : O(n)
Space Complexity  : O(n)
*/
