/*
Score of Parentheses Using Divide and Conquer Strategy

You are given a balanced parentheses string str, 
your task is to compute the score of the string based on the 
enlisted rules:-
(1) () has got a score of 1
(2) AB has a score of A + B, where A and balenced parentheses string
(3) (A) has got a score of 2 + A where A is balenced parentheses string
*/

import java.util.*;
import java.io.*;

public class Score_of_Parentheses_usingDC
{
    //the approach that we take is that we
    //try splitting the string str into two A and B , where A nad B are 
    //balenced parentheses string, and A is smallest possible 
    //non empty prefix of str
    //function to calculate score of parentheses recursively
    public int parenthesesScore(String str) 
    {
        return fun(str, 0, str.length());
    }

    //we keep a track of balence i.e. no. of '('
    // minus no. of ')' and partition str into primitive substrings
    //then the total score will be sum of the scores of each substrings
    public int fun(String str, int start, int end) 
    {
        //Score of balanced string str[start:end] i.e. from start point to end point
        int result = 0, balance = 0;

        //split string into primitives substrings
        //for each primitive substring if the string is of length then
        //the score will be 1, otherwise its twice 
        for (int pass = start; pass < end; pass++) 
        {
            balance += str.charAt(pass) == '(' ? 1 : -1;

            if (balance == 0) 
            {
                if (pass - start == 1) 
                {
                    result++;
                }
                else 
                {
                    result += 2 * fun(str, start + 1, pass);
                }
                start = pass + 1;
            }
        }

        return result;
    }

    //driver code 
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        //for input 
        System.out.println("Enter the string of parentheses : ");
        String str = sc.nextLine();
        //we pass this str into the parenthesesScore function which will
        //calculate the score of the input

        //for output
        System.out.println("The score of the string of parentheses is : ");
        System.out.println(parenthesesScore(str));
    }
}

/*
EXAMPLE:-

INPUT--
Enter the string of parentheses : ()
OUTPUT--
The score of the string of parentheses is : 1

INPUT--
Enter the string of parentheses : (()(()))
OUTPUT--
The score of the string of parentheses is : 6

TIME COMPLEXITY --> O(N^2)
SPACE COMPLEXITY --> O(N)
*/
