/* You are given two lists of integers weights and values which have 
the same length and an integer capacity. weights[i] and values[i] 
represent the weight and value of the ith item. Given that you can 
take at most capacity weights, and that you can take a fraction of 
an item's weight with proportionate value, return the maximum amount
of value you can get, rounded down to the nearest integer. */


import java.util.*;

public class FractionalKnapsack {

    /* Pair class used to store the weight, value, and ratio of value:weight of a particular item */
    static class Pair{
        int wt;
        int val;
        double ratio;
    }
    
    /* Used to sort all items based on their value:weight ratio in descending order */
    static class SortByRatio implements Comparator<Pair>{
        public int compare(Pair a, Pair b){
            if(b.ratio >= a.ratio){
                return 1;
            }else{
                return -1;
            }
        }
    }

    /* Function created to get maximum Profit */
    public static int getMaxProfit(int[] weights, int[] values, int capacity) {

        /* Creating a pairs array which stores all the items according to their weight,value and ratio */
        Pair pairs[] = new Pair[weights.length];

        /* Adding items to the pairs array */
        for(int i=0; i<weights.length; i++){

            Pair p = new Pair();
            p.val = values[i];
            p.wt = weights[i];
            double wt = weights[i];
            double val = values[i];
            
            p.ratio = val/wt;       
            pairs[i] = p; 
        }

        /* Sorting the pairs array based on their ratio */
        Arrays.sort(pairs, new SortByRatio());

        /* Initializing an ans variable */
        int ans = 0;

        /* Traversing through all items in the array */
        for(Pair p : pairs){

            /* Including a particular item, if we can accommodate it */
            if(p.wt <= capacity){
                ans += p.val;
                capacity-=p.wt;
            }
            /* Taking the fractional value of the item if we cannot accommodate it */
            else{
                ans += (p.ratio * capacity);

                /* Breaking from loop as we reached our peak capacity */
                break;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);

        int items = input.nextInt();

        int weights[] = new int[items];
        int values[] = new int[items];

        int capacity = 0;

        for(int i=0; i<items; i++){
            weights[i] = input.nextInt();
        }

        for(int i=0; i<items; i++){
            values[i] = input.nextInt();
        }

        capacity = input.nextInt();

        input.close();

        System.out.println(getMaxProfit(weights, values, capacity));
    }
}

/*
Input

weights = [5, 6, 2]
values = [100, 100, 1]
capacity = 8

Output

150

Explanation

Take the item with weight 5 and value 100, we are left with capacity 3
Take half of the item with weight 6, so it's value would become 50.
Thereby getting a maximum profit of 150

Time Complexity : O(N)
Space Complexity : O(N)

*/

