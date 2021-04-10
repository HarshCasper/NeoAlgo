/*
 *         Description
 *      
 *   Problem:  Finding median of two sorted array
 *  
 * we will have two sorted arrays of size N and M respectively and element in array, which can be duplicated.
 * we will find median of array without merging the two arrays.
 * example:  A = [1, 5, 8]
 *           B = [1,2, 3,9]
 *          merged : [1,2,3,4,5]  (If we merge, we have to use extra space)
 *          output : 3.0
 *          
 *  If we merge the job is so simple. In this case TC O(N+M) , SC O(N+M)
 *  but we will apply binary search which will do it in TC O(log(max-min)*(logm+logn)), SC O(1).    
 * 
 */
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class MedianOfArray {
	public static double findMedianSortedArrays(final List<Integer> a, final List<Integer> b) {
		int i, n = a.size(), m = b.size();
		int low = 0, high = 0;
		//Handling Edge Case
		if (n == 0) {
			low = b.get(0);
			high = b.get(m - 1);
		} else if (m == 0) {
			low = a.get(0);
			high = a.get(n - 1);
		} else {
			low = Math.min(a.get(0), b.get(0));
			high = Math.max(a.get(n - 1), b.get(m - 1));
		}
		//Main Code
		int k = ((n + m) / 2);
		double d1 = 0.0, d2 = 0.0;
		d1 = getAns(low, high, a, b, k);
		
		//check for even length median
		if ((n + m) % 2 == 0) {
			d2 = getAns(low, high, a, b, k - 1);
			System.out.println((d1 + d2) / 2);
			return (d1 + d2) / 2;
		} else {
			System.out.println(d1);  //odd length median
			return d1;
		}
	}
	public static double getAns(int low, int high, List<Integer> a, List<Integer> b, int k) {
		int mid = 0;
		while (low <= high) {
			mid = (high - low) / 2 + low;
			int p = countLess(a, mid) + countLess(b, mid);
			int q = countEqual(a, mid) + countEqual(b, mid);
			if (p > k)
				high = mid - 1;
			else {
				if (p + q <= k)
					low = mid + 1;
				else
					return mid;
			}

		}
		return mid;
	}
	public static int countLess(List<Integer> a, int x) {
		int low = 0, high = a.size() - 1;
		int mid = 0;
		int index = -1;
		while (low <= high) {
			mid = (high - low) / 2 + low;
			if (a.get(mid) >= x) {
				high = mid - 1;
			} else {
				index = mid;
				low = mid + 1;
			}
		}
		return index + 1;
	}
	private static int countEqual(List<Integer> a, int x) {
		int low = 0, high = a.size() - 1;
		int mid = 0;
		int index = -1;
		while (low <= high) {
			mid = (high - low) / 2 + low;
			if (a.get(mid) >= x) {
				index = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		int index2 = -1;
		low = 0;
		high = a.size() - 1;
		while (low <= high) {
			mid = (high - low) / 2 + low;
			if (a.get(mid) <= x) {
				index2 = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		if (index == -1)
			return 0;
		else
			return index2 - index + 1;
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		//Size of First List
		int n=sc.nextInt();
		
		//Size of Second List
		int m=sc.nextInt();
		int i;
		List<Integer> firstList=new ArrayList<Integer>();
		for(i=0;i<n;i++) {
		  int val=sc.nextInt();	
		  firstList.add(val);
		}
		
		List<Integer> secondList=new ArrayList<Integer>();
		for(i=0;i<n;i++) {
		  int val=sc.nextInt();	
		  secondList.add(val);
		 }
		findMedianSortedArrays(firstList,secondList);
	}
}
/*
 * Finding Median of Two sorted arrays: 
 * 
 * Time Complexity: O(NlogN)
 * Space Complexity: O(1)
 * 
 * Sample Input:
 * 
 * Input1:
 * first sorted list: [1,2,3]
 * second sorted list: [4]
 * 
 * output 1: median : (2+3)/2 = 2.5
 *  
 * Input2: 
 * first sorted list: [1,4,9,10]
 * second sorted list: [2,3,7]
 * 
 * output2: 4.0
 * 
 * 
 * */
