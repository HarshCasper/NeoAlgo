/*

Stock Span Problem
===================
You are given the price of a stock for N consecutive days and are required to find the span
of stock's price on ith day. The span of a stock's price on a given day i, is the maximum
consecutive days before the (i+1)th day, for which the stock's price is less than equal to that on
the ith day.

*/

import java.util.*;

public class StockSpan {
	public static void main(String args[]) {
		// Input number of days
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] price = new int[n];
		int[] span = new int[n];

		// Input price for n days
		for (int i = 0; i < n; i++)
			price[i] = sc.nextInt();

		// Stack for keeping track of span of largest element till now
		Stack<Integer> s = new Stack<Integer>();
		// Push first element in the stack
		s.push(0);
		// Span for first day will always be 1
		span[0] = 1;

		// Looping through rest of the days
		for (int i = 1; i < n; i++) {

			// While we have elements in the stack and currPrice is greater than equal to topPrice
			// keeping popping out elements and update the currSpan
			while (s.empty() == false && price[s.peek()] <= price[i])
				// Pop out the topmost element as its price was less than currPrice
				s.pop();

			// Calculate the span for the current day
			span[i] = (s.empty()) ? i + 1 : i - s.peek();
			// Push curr element into the stack
			s.push(i);
		}

		// Print ans
		for (int i = 0; i < n; i++)
			System.out.print(span[i] + " ");
		System.out.println();
	}
}


/*

Input :
5
30 35 40 38 35
Output :
1 2 3 1 1

Application: Stack data structure
Time Complexity: O(n)
Space Complexity: O(n)

*/


