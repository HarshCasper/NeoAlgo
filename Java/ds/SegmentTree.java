/*Implementation of Segment Tree for a problem where
	we have to find the sum of element from a given range(l,r) 
and also perform the update operation at particular index/*
*/

public class SegmentTree{
	
//	A function for returning the size of the segment Tree
	public static int sizeOfSegmentTree(int n) {
		 
		 int y = (int) (Math.ceil(Math.log(n) / Math.log(2))); 
		 int size = 2 * (int) Math.pow(2, y) - 1; 
	  
	  return size;
	}
	
	
//	A recursive function for creating a segment tree from a given array	
	public static void buildTree(int start,int end,int treeIndex,int arr[],int tree[]) {

		if(start==end) {
			tree[treeIndex]=arr[start];
			return;
		}
		
		int mid=(start+end)/2;
		buildTree(start, mid, 2*treeIndex, arr, tree);
		buildTree(mid+1, end, 2*treeIndex+1, arr, tree);
		
		tree[treeIndex]=tree[2*treeIndex]+tree[2*treeIndex+1];
	}
	
	
//	Function for updating a value at particular index	
	public static void update(int start,int end,int index,int value,int treeIndex,int arr[],int tree[]) {
		
		if(start==end) {
			arr[start]=value;
			tree[treeIndex]=value;
			return;
		}
		
		int mid=(start+end)/2;
		if(index>mid) {
//			right side tree
			update(mid+1, end, index, value, 2*treeIndex+1, arr, tree);
		}else {
//			left side tree
			update(start, mid, index, value, 2*treeIndex, arr, tree);
		}
		
		tree[treeIndex]=tree[2*treeIndex]+tree[2*treeIndex+1];
	}
	
//	Function which return the sum of elements from left index to right index	
	public static int query(int start,int end,int left,int right,int treeIndex,int tree[]) {
		
//		Completely outside
		if(start>right||end<left) {
			return 0;
		}
//		Completely inside
		if(start>=left&&end<=right) {
			return tree[treeIndex];
		}
//		Partial 
		int mid=(start+end)/2;
		
		int leftSum=query(start, mid, left, right, 2*treeIndex, tree);
		int rightSum=query(mid+1, end, left, right, 2*treeIndex+1, tree);
		
		return (leftSum+rightSum);
	}
	
	public static void main(String[] args) {
		
		int arr[]= {1,3,2,4,1,5};
		int n=arr.length;
		
		int size=sizeOfSegmentTree(n);
		
//		Segment Tree
		int tree[]=new int[size];
		buildTree(0, n-1, 1, arr, tree);
		
		System.out.println("Sum of element from 2 to 5 index : "+query(0, n-1, 2, 5, 1, tree));
		
//		Updating value at index 3 in given array to 6
		int index=3;
		int value=6;
		update(0, n-1, index, value, 1, arr, tree);
//		After updation new Array : {1,3,2,6,1,5}
		
		
		System.out.println("Sum of element from 2 to 5 index : "+query(0, n-1, 2, 5, 1, tree));
		
	}

}
