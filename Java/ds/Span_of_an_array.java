/* Given a number n, and an array of n elements, The program is to find the span of array.
 Span of an array is defined as difference of maximum value of the array and minimum value of an array.*/

import java.io.*;
import java.util.*;

public class span {
    public static void main(String[] args) {
       /*taking the input for array*/
        Scanner scan = new Scanner(System.in);
        System.out.println("enter the size of array");
        int number = scan.nextInt();
        int[] arrelement = new int[number];
        System.out.println("enter the elements");
        for (int i = 0; i < arrelement.length; i++) {
            arrelement[i] = scan.nextInt();
         }
         /*Finding the maximum element from the array*/
        int max = arrelement[0];
        for (int j = 0; j < arrelement.length; j++) {
                if (arrelement[j] > max) {
                max = arrelement[j];
            }
        }
        /*Finding the minimum element from the array*/
        int min = arrelement[0];
        for (int k = 0; k < arrelement.length; k++) {
            if (arrelement[k] < min) {
                min = arrelement[k];
            }
        }
        /*Taking the difference of maximum and minmum number*/
        int span = max - min; 
        System.out.println("span of the array is"+ span);
    }
}

/*
Standard Input/Output 

Input:
enter the size of an array
6
enter the elements
15
30
40
4
11
9

Output:
span of the array is 36

Time complexity:o(n)
space complexity:o(n)
*/
