package def;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class MergeOverlappingArray {
	
	 public static int[][] merge(int[][] intervals) {
	        List<int[]> list = new ArrayList<>();
	        
	        if(intervals.length == 0 || intervals == null)
	            list.toArray(new int[0][]);
	            
	        Arrays.sort(intervals, (a,b) -> a[0] - b[0]);
	        int begin = intervals[0][0];
	        int end = intervals[0][1];
	        for(int [] j : intervals){
	            if(j[0] <= end){
	                end = Math.max(end,j[1]); 
	            }
	            else{
	                list.add(new int[]{begin,end});
	                begin = j[0];
	                end = j[1];
	            }
	        }
	            list.add(new int[]{begin,end});
	            intervals = list.toArray(new int[0][]);
	            return intervals;
	            
	    }

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of intervals: ");
		int n = sc.nextInt();
		System.out.println("Enter intervals: ");
		int[][] arr = new int[n][2]; 
		for(int k =0;k<arr.length;k++) {
			for(int l=0;l<arr[k].length;l++) {
				arr[k][l] = sc.nextInt();
			}
		}
		int[][] t= merge(arr);
		 for (int[] row : t) {
             System.out.println(Arrays.toString(row)); 
     } 
		sc.close();
	}
}

/*
*Input and Output of program

Enter number of intervals: 
2
Enter intervals: 
1 8
2 7
[1, 8]

Enter number of intervals: 
4
Enter intervals: 
1 3
2 6
8 10
15 18
[1, 6]
[8, 10]
[15, 18]

*Time Complexity: O(nlogn) + O(n)
*Space Complexity: O(n)

*/
