/*
___Paint Fence Algorithm___
Problem:
Given a fence with n posts and k colors
Find out the number of ways of painting the fence
such that at most 2 adjacent posts have the same color.
Input:
n : number of posts
k : number of colors
Output:
result: number of ways of painting
        considering the condition above
*/

import java.util.*;

public class Paint_Fence{

    //function uses permutation logic to output number of possible ways of painting

    public int paint_fence(int n,int k){
        if(n<2 | k<(n/2)){
            return -1;
        }
        int[] same = new int[n-1];
        int[] diff = new int[n-1];
        int[] total = new int[n-1];
        same[0]=k;
        diff[0]=k*(k-1);
        total[0]=k*k;
        for(int i=1;i<(n-1);++i){
            same[i]=diff[i-1];
            diff[i]=total[i-1]*(k-1);
            total[i]=diff[i]+same[i];
        }
        return total[n-2];
    }
    public static void main(String[] args){
        int n,k;
        Scanner input = new Scanner(System.in);
        System.out.println("Enter n,Number of Posts");
        n=input.nextInt();
        System.out.println("Enter k,Number of Colors");
        k=input.nextInt();
        Paint_Fence obj = new Paint_Fence();
        int result = obj.paint_fence(n,k);
        if(result==-1){
            System.out.println("Painting is not possible following the condition");
        }
        else{
            System.out.println("Number of Possiblities: "+result);
        }
        input.close();
    }
}

/*Sample Input/Output
Enter n,Number of Posts
3
Enter k,Number of Colors
5
Number of Possiblities: 120

Enter n,Number of Posts
10
Enter k,Number of Colors
4
Painting is not possible following the condition

Enter n,Number of Posts
5
Enter k,Number of Colors
3
Number of Possiblities: 180

Time Complexity  O(n)
Space Complexity O(n) 
*/
