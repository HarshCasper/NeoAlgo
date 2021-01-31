/*This program finds the total number of possible combinations that can be used to
climb statirs . EG : for 3 stairs ,combination and output will be 1,1,1 , 1,2 , 2,1 i.e 3 . */
import java.util.Scanner;

class Staircase_problem{
    public static void main(String args[]){
        int count_stairs=0;
        Scanner input = new Scanner(System.in);
        System.out.println("Enter total number of Stairs:"); 
        count_stairs = input.nextInt();
        Staircase_problem sp = new Staircase_problem();
        int final_steps = sp.possibilities_count(count_stairs); 
        System.out.println("Total Number of possible Combinations = "+final_steps);
    }

    int possibilities_count(int a){
        int result = a;
        /*Using Recursion to find the total number of stairs as f(a) = f(a-1) + a(a-2) 
        where f(a) is the final result */
        if(result <= 1){
            result =  1;
        }else{
            result = possibilities_count(a-1) + possibilities_count(a-2);
        }
        return result;
    }
}
/* Output 
Enter total number of Stairs:
4
Total Number of possible Combinations = 5
*/
// Time Complexity : O(2^n)
// Space Complexity :O(1)
// Created by Shubham Patel on 16-12-2020 on WoC
