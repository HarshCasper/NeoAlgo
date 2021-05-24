/*
Optimal Division of numbers 

For the given array of integers arr[], you have to
perform float division of adjacent integers present in arr[].
You can add as many number of parenthesis you want at any position 
to change the priority of positions. But your task is to add
parenthesis in such a way that the expression gives 
the maximum value after evaluation.
*/

import java.io.* ;
import java.util.* ;

public class Optimal_division_of_numbers
{
    //function to find expression such as to maximize the value of expression
    public String optimizedDivisionOfNum(int[] arr)
    {
        //In case of just one element present in array
        //we simply write the number
        if (arr.length == 1)
        {
            return arr[0] + " ";
        }
        //In case of 2 elements present in the array 
        //we just need to divide the two 
        if (arr.length == 2)
        {
            return arr[0] + " / " + arr[1];
        }

        //otherwise adding parenthesis
        StringBuilder reqExpression = new StringBuilder(arr[0] + " / ( " + arr[1]);

        //the approach that we develop over here is that
        //we try to manimize the denominator part
        //as far as possible so as to maximize the value 
        //of the expression that we are getting
        //Thus trying to minimize the denominator
        for(int pass = 2; pass < arr.length; pass++)
        {
            reqExpression.append(" / " + arr[i]);
        }
        reqExpression.append(" ) ");

        return reqExpression.toString();
    }

    //drivers code
    public static void main(String[] args) 
    {
        //for input
        Scanner sc = new Scanner(System.in);

        //size of array
        System.out.println("Enter size greater than or equal to 1");
        System.out.println("Enter the number of elements of array: ");
        int size = sc.nextInt();

        int []arr = new int[size];
        //array elements
        System.out.println("Enter the elements for array: ");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }

        //for output
        System.out.println("The expression goes like this : ");
        System.out.print(optimizedDivisionOfNum(arr));
    }
}

/*
EXAMPLES:--

Input--
Enter size greater than or equal to 1
Enter the number of elements of array: 4
Enter the elements for array: 1000 100 10 2
Output--
The expression goes like this : 1000 / ( 100 / 10 / 2)

Input--
Enter size greater than or equal to 1
Enter the number of elements of array: 1
Enter the elements for array: 4
Output--
The expression goes like this : 4

TIME COMPLEXCITY --> O(N)
SPACE COMPLEXITY --> O(N)
*/
