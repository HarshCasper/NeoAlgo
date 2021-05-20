/*
Problem statement : 
There is a fence with n posts, you are given k colors to paint the fence. 
Each post can be painted with one of the k colors. You have to paint all the posts 
with the k colors such that atmost two adjacent posts have the same color. 
You have to find the total number of ways to paint the fence.

Explanation : 
Suppose we have a single post, The number of ways of painting the fence with k 
colors is k Now we consider 2 posts, Then the number of ways of painting the 
second fence with the same color as the first post is k, and the number of ways 
of painting the second post with a different color is k*(k-1) as we have k-1 colors 
that are different from the first post's color. So the total number of ways of 
painting 2 fences is k*(k-1) + k. Now we consider 3 posts, Then the number of ways 
of painting the third fence same as the second fence is the number of ways of painting 
the second fence with a different color that is k*(k-1). The number of ways of painting 
the third fence using a different color is equal to the total number of ways of painting 
the second fence times (k-1). Hence the total number of ways of painting 3 fences is 
k*(k-1) + (k+k*(k-1))*(k-1). This way we can find the total number of ways of painting 
n fences
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
