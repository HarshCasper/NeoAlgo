
/*Java program to solve fractional Knapsack Problem
 * Given weights and values of n items, 
 * we need to put these items in a knapsack of given capacity to get the maximum total value in the knapsack.
 * In Fractional Knapsack, we can break items for maximizing the total value of knapsack. 
 * This problem in which we can break an item is also called the fractional knapsack problem.
 */
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

//implementing by Greedy approach logic
public class FractionalKnapsack {
	
	private static double getMaxValue(int[] wt, int[] val,
									int capacity)
	{
		ItemValue[] iVal = new ItemValue[wt.length];

		for (int i = 0; i < wt.length; i++) {
			iVal[i] = new ItemValue(wt[i], val[i], i);
		}

		// sorting items by value;
		Arrays.sort(iVal, new Comparator<ItemValue>() {
			@Override
			public int compare(ItemValue o1, ItemValue o2)
			{
				return o2.cost.compareTo(o1.cost);
			}
		});

		double totalValue = 0d;

		for (ItemValue i : iVal) {

			int curWt = (int)i.wt;
			int curVal = (int)i.val;

			if (capacity - curWt >= 0) {
				// this weight can be picked while
				capacity = capacity - curWt;
				totalValue += curVal;
			}
			else {
				// item can't be picked whole
				double fraction
					= ((double)capacity / (double)curWt);
				totalValue += (curVal * fraction);
				capacity
					= (int)(capacity - (curWt * fraction));
				break;
			}
		}

		return totalValue;
	}

	// item value class
	static class ItemValue {
		Double cost;
		double wt, val, ind;

		// item value function
		public ItemValue(int wt, int val, int ind)
		{
			this.wt = wt;
			this.val = val;
			this.ind = ind;
			cost = new Double((double)val / (double)wt);
		}
	}

	// Writing Main function
	public static void main(String[] args)
	{
				
		Scanner sc = new Scanner(System.in);
		int object, m;
		System.out.println("Enter the Total Objects");
		object = sc.nextInt();
		int weight[] = new int[object];
		int profit[] = new int[object];
		int capacity;
		
		for (int i = 0; i < object; i++) {
			System.out.println("Enter the Profit");
			profit[i] = sc.nextInt();
			System.out.println("Enter the weight");
			weight[i] = sc.nextInt();
		}
		System.out.println("Enter the Knapsack capacity");
		capacity = sc.nextInt();


		double maxValue = getMaxValue(weight, profit, capacity);

		// Function call
		System.out.println("Maximum value we can obtain = "
						+ maxValue);
	}
}


/*
Sample Input Output
Enter the Total Objects
4
Enter the Profit
7
Enter the weight
3
Enter the Profit
8
Enter the weight
5
Enter the Profit
3
Enter the weight
6
Enter the Profit
9
Enter the weight
4
Enter the Knapsack capacity
10


Maximum value we can obtain = 20.8 
 */
