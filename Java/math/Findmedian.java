/*
Problem statement: A stream of integers is given and we have to find the median of the stream.

Solution: Median is the middle element that is a boundary of the lower half and the higher half. If the input array size is odd, then the middle element of the sorted data is taken to be the median and if the iput array sizs is even, then the average of the two middle elements from the sorted streams is taken to be the median. Here, we have solved the problem using two heaps that is the less heap and more heap which is implemented using the priority queue class in Java.

Implementation of code:

Step 1: Two heaps have been created. The less heap to store higher half of the stream and the more heap to store the lower half of the stream. The median value is initialized to 0.
Step 2: Now there can be 3 cases:
Case 1: When the size of more heap is more than the size of less heap and the element is less than the previous median then, pop the top element of the more heap and insert it into less heap and insert the new element in the more heap or else insert the new element to less heap. The new median is the average of top elements of both the heaps.
Case 2: When the size of more heap is less than the size of less heap and the element is greater than the previous median then, pop the top element of the less heap and insert into the more heap and insert the new element to less heap or else insert the new element to more heap. The new median is the average of top elements of both the heaps.
Case 3: If the size of both heaps is equal, then check if the present element is less than the previous median and if it is so, then insert it to the more heap and the new median will be equal to the top element of more heap. But if it is the other side and the present element is more than the previous median then insert it to low heap and the new median will be equal to the top element of low heap.
*/

import java.util.Collections;
import java.util.PriorityQueue;

public class Findmedian
{
	
	// Funtion to calculate median of stream
	public static void calculate_median(int[] a)
	{
		
		double median = a[0];
		
		// maximum priority queue to store the lower half side of the elements 
		PriorityQueue<Integer> less = new PriorityQueue<>
		(Collections.reverseOrder());
		
		// minimum priority queue to store the higher half side of the elements 
		PriorityQueue<Integer> more = new PriorityQueue<>();
		
		less.add(a[0]);
		System.out.println(median);
		
		// scanning the elements of stream 
		for(int i = 1; i < a.length; i++)
		{
			
			int temp = a[i];
			
			// when left priority queue has more elements
			if(less.size() > more.size())
			{
				if(temp < median)
				{
					more.add(less.remove());
					less.add(temp);
				}
				else
					more.add(temp);
				median = (double)(less.peek() + more.peek())/2;
			}
			
			// when both the priority queues have eqaul number of elements
			else if(less.size() == more.size())
			{
				if(temp < median)
				{
					less.add(temp);
					median = (double)less.peek();
				}
				else
				{
					more.add(temp);
					median = (double)more.peek();
				}
			}
			
			// when right priority queue has more number of elements 
			else
			{
				if(temp > median)
				{
					less.add(more.remove());
					more.add(temp);
				}
				else
					less.add(temp);
				median = (double)(less.peek() + more.peek())/2;
				
			}
			System.out.println(median);
		}
	}
	
	// Driver code
	public static void main(String []args)
	{
		
		// input stream of integers 
		int[] arr = new int[]{15, 9, 6, 11, 22};
		calculate_median(arr);
	}
}

/*
prints
15.0
12.0
9.0
10.0
11.0

Time complexity: The time complexity is of order O(nlog n) because the complexity insert element in low heap is log n.

Space complexity: The space complexity is of order O(n).
*/

