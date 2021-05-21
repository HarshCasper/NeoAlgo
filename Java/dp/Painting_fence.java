/*
Problem statement : 
There is a fence with n posts, you are given k colors to paint the fence. 
Each post can be painted with one of the k colors. You have to paint all the posts 
with the k colors such that atmost two adjacent posts have the same color. 
You have to find the total number of ways to paint the fence.
*/

import java.util.Scanner;

class Code {
    // paintfence function uses permutations to find the number of ways of painting
    // fences
    static int paintfence(int n, int k) {
        int total, diff, same;
        same = k;
        diff = k * (k - 1);
        total = k * k;
        for (int i = 1; i < n - 1; i++) {
            same = diff;
            diff = total * (k - 1);
            total = same + diff;
        }
        return total;
    }

    public static void main(String[] args) {
        int n, k;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of posts");
        n = sc.nextInt();
        System.out.println("Enter the number of colors");
        k = sc.nextInt();
        System.out.println("The number of ways of painting the fence is : " + paintfence(n, k));   
    }
}

/*
Sample I/O:
Enter the number of posts
3
Enter the number of colors
2
The number of ways of painting the fence is : 6

Time complexity : O(n)
Space complexity : O(1)
*/
