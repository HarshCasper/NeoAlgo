public class MoreAlgo {
	
	
	public static void check(int arr[]) {
		int count=0;
		for(int i=0;i<arr.length-1;i++) {
			count=1;
			for(int j=i+1;j<arr.length;j++) {
				if(arr[j]==arr[i]) {
					count++;
				}
			}
			if(count>arr.length/2) {
				System.out.println(arr[i]);
				System.exit(0);
			}
		}
		System.out.print("NO majority Elements ");
		
		
	}
	
	public static void main(String[] args) {
		int arr[]= {3, 3, 4, 2, 4, 4, 2, 4};
		check(arr);
	}

}
