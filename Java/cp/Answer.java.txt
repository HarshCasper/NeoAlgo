package def;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Answer {
	
	 public static void merge(int[][] intervals) {
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
	            for (int[] row :list ) {
		            System.out.println(Arrays.toString(row)); 
		    } 
	            return ;
	            
	    }

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of intervals: ");
		int n = sc.nextInt();
		System.out.println("Enter intervals: ");
		int[][] arr = new int[n][n]; 
		for(int k =0;k<arr.length;k++) {
			for(int l=0;l<arr[k].length;l++) {
				arr[k][l] = sc.nextInt();
			}
		}
		merge(arr);
		sc.close();
	}
}

