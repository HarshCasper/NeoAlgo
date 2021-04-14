/* Java Program to implement a stack using two queues
by making the push operation costly*/

import java.util.*;

public class StackUsingQueue {
    static class Stack {
        // the 2 queues
        Queue<Integer> qu1 = new LinkedList<>();
        Queue<Integer> qu2 = new LinkedList<>();

        // storing current size
        int currentSize;

        Stack() {
            currentSize = 0;
        }

        void push(int num) {
            currentSize++;

            // first, push num into an empty qu2
            qu2.add(num);

            // now we push the other elements from qu1 to qu2
            while (!qu1.isEmpty()) {
                qu2.add(qu1.peek());
                qu1.remove();
            }
        }

        void pop() {
            if (qu2.isEmpty()) {
                return;
            }

            // remove element and reduce size if qu2 not empty
            qu2.remove();
            currentSize--;
        }

        int top() {
            if (qu2.isEmpty()) {
                return -1;
            }

            // return the top element
            return qu2.peek();
        }

        int size() {
            return currentSize;
        }
    }

    public static void main(String[] args) {
        Stack stack = new Stack();

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size:");
        int size = sc.nextInt();
        System.out.println("Enter the numbers:");
        for (int i = 0; i < size; i++) {
            stack.push(sc.nextInt());
        }
        sc.close();

        System.out.println("Current Size:" + stack.size());
        for (int i = size; i > 0; i--) {
            System.out.println(stack.top());
            stack.pop();
        }
        System.out.println("Current Size:" + stack.size());
    }
}

/**
 * Sample input/output:
 * 
 * Enter size:
 * 5
 * Enter the numbers:
 * 5
 * 4
 * 3
 * 2
 * 1
 * Current Size:5
 * 5
 * 4
 * 3
 * 2
 * 1
 * Current Size:0
 * 
 * Time complexity: O(n) for push, O(1) for pop
 * Space complexity: O(n)
 */
