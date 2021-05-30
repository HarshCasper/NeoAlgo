/*
    At the Perfect programming Company, programmers program in pairs in order to ensure that the highest quality code is produced. 
    The productivity of each pair of programmers is the speed of the slower programmer. 
    For an even number of programmers, give an efficient algorithm for pairing them up so that 
    sum of productivity of all pairs is maximized. 
    Analyze the running time of your algorithm.
*/

import java.util.*;

public class Pair_programmers_productivity_problem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no of programmers(even):- ");
        int n = sc.nextInt();

        int[] speed = new int[n];
        System.out.println("Enter the speed of programmers:- ");
        for(int i = 0; i<n; i++){
            speed[i] = sc.nextInt();
        }
        System.out.println(String.format("Maximum sum of speed of programmers is %d", maximum_sum_of_speed_of_programmers(speed, n)));               
    }
    /*
    We use the Greedy Approach here in this problem. We sort the speed[] array, 
    traverse it with a gap of 2(since we have to pair the programmers) and just add the speed
    */
    public static int maximum_sum_of_speed_of_programmers(int arr[], int n){
        Arrays.sort(arr);
        int max_sum = 0;
        for(int j = 0; j<n; j+=2){
            max_sum += arr[j];
        }
        return max_sum;
    }
}
/*
    Time Complexity:- O(n)
    Space Complexity:- O(1)
*/

/*
Sample testcase:
Enter the no of programmers(even):- 6

Enter the speed of programmers:- 10 2 4 15 20 22

Maximum sum of speed of programmers is 32
*/
