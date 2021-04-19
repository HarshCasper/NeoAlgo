/* Given n non-negative integers representing the histogram's bar height where 
the width of each bar is 1, find the area of largest rectangle in the histogram */

import java.util.*;
import java.lang.*;
import java.io.*;

class RectArea {
    private static int largestRectangleArea(int[] array) {
        int n = array.length;
        Stack<Integer> s = new Stack<Integer>();
        int[] left_nearest_small = new int[n];
        int[] right_nearest_small = new int[n];
        for(int i = 0; i < n; i++) {
            while(!s.isEmpty() && array[s.peek()] >= array[i])
                s.pop();
            left_nearest_small[i] = (s.isEmpty() ? -1 : s.peek());
            s.push(i);
        }
        s = new Stack<Integer>();
        for(int i = n-1; i >= 0; i--) {
            while(!s.isEmpty() && array[s.peek()] >= array[i])
                s.pop();
            right_nearest_small[i] = (s.isEmpty() ? n : s.peek());
            s.push(i);
        }
        int area = 0;
        // find area for each possible bar being the maximum heighted bar in the considered bars
        for(int i = 0; i < n; i++)
            area = Math.max(area, (right_nearest_small[i]-left_nearest_small[i]-1)*array[i]);
        return area;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] array = new int[n];
        // take input
        for(int i = 0; i < n; i++)
            array[i] = sc.nextInt();
        System.out.println(largestRectangleArea(array));
    }
}


/**

Input:
6
2 1 5 6 2 3
Output:
10
TimeComplexity : O(n)
SpaceComplexity : O(n)

**/


