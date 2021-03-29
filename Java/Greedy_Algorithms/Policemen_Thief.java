/*
 
Author: Neha Baisane (@neha-baisane)

Problem-Stetement : An array of size 'e' will satisfy following conditions:
                    1. The array element will have a police or thief.
                    2. One thief can be caught by only one policemen.
                    3. Policemen can catch a thief who is within 'd' units away from him.
Likewise, we need to count maximum number of theives caught.

Example:
Input: array[] = {'T','P','P','T','T'}
             d = 3
Output: 2
Explanation: In this example, maximum 2 thieves can be caught.
             Policemen(P) at index 1 will catch Thief(T) at index 0.
             Policemen(P) at index 2 will catch Thief(T) at index 3.
  
*/



import java.util.*;
import java.io.*;
  
class Policemen_Thief
{
    
    // returns the value of thieves caught.
    static int policemenAndThief(char array[], int l, int d)
    {
        int result = 0;
       ArrayList<Integer> thief = new ArrayList<Integer>();
        ArrayList<Integer> policemen = new ArrayList<Integer>();
        

        // storing the indices inside the array list 
        for (int i = 0; i < l; i++) {
            if (array[i] == 'P'){
                 policemen.add(i);
            }else if (array[i] == 'T'){
                 thief.add(i);
            }
        } 
  
        // track lowest current indices of
        // thief: thief[x] and police: policemen[y]
        int x = 0, y = 0;
        while (x < thief.size() && y < policemen.size()) {
  
            // can be caught
            if (Math.abs(thief.get(x) - policemen.get(y)) <= d) {
            result++;
            x++;
            y++;
            } 
              
            // incrementing minimum index
            else if (thief.get(x) < policemen.get(y))
                x++;
            else
                y++;
        }
        return result;
    }
  
    // Driver program
    public static void main(String args[])
    {
       
        int d,l;
        String temp;

        Scanner s = new Scanner(System.in); 
        char array[] = new char[10];
        
       System.out.print("Enter the number of elements to be added in array: ");         
       int e = s.nextInt();
        
       for(int i=0; i<e; i++){
        System.out.print("Enter 'P' for Policemen and 'T' for Thief: "); 
        temp = s.next();
        array[i] = temp.charAt(0);
       }  
        
        System.out.print("Enter the distance under which policemen can catch thief: ");
        d = s.nextInt();
        l = array.length;
        System.out.print("Maximum number thieves caught are: " + policemenAndThief(array, l, d));
    }
}


/*

Test case1:
Input:
Enter the number of elements to be added in array: 4
Enter 'P' for Policemen and 'T' for Thief: P
Enter 'P' for Policemen and 'T' for Thief: T
Enter 'P' for Policemen and 'T' for Thief: T
Enter 'P' for Policemen and 'T' for Thief: P
Enter the distance under which policemen can catch thief: 2

Output:
Maximum number thieves caught are: 2

*/