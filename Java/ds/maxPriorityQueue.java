/*
Implementing the class for Max Priority Queue which includes the required functions......
//Max Priority Queue is a data structure which manage a list of values, it gives priority to element with maximum value i.e elements are inserted in the order 
in which they arrive the queue and the maximum value is always removed first from the queue.
*/
import java.util.ArrayList;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class maxPriorityQueue {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));;
	static StringTokenizer st;
	private ArrayList<Integer> heap=new ArrayList<>();
	boolean isEmpty() {
	   return heap.size() == 0;
	}
	int getSize() {
           return heap.size();
	}
	int getMax() {
           if(isEmpty()){
             return Integer.MIN_VALUE;
	   }   
          return heap.get(0);
	}
	void insert(int element) {
           heap.add(element);
           int childIndex = heap.size() - 1;
           int parentIndex = (childIndex - 1) / 2;
           while(childIndex > 0){
            if(heap.get(childIndex) > heap.get(parentIndex)) {
                int temp = heap.get(childIndex);
                heap.set(childIndex, heap.get(parentIndex));
                heap.set(parentIndex, temp);
                childIndex = parentIndex;
                parentIndex = (childIndex - 1) / 2;
               }else{
                 return;
               }
	    }	
        }
        int removeMax() {
          if(isEmpty())
            return Integer.MIN_VALUE;
        int remove=heap.get(0);
        heap.set(0,heap.get(heap.size()-1));
        heap.remove(heap.size()-1);
        int parentIndex = 0;
        int leftchildIndex = (2*parentIndex)+1;
        int rightchildIndex = (2*parentIndex)+2;
        while(leftchildIndex<heap.size())
        {
            int p=heap.get(parentIndex);
            int l=heap.get(leftchildIndex);
            if(rightchildIndex>=heap.size()){
                if(p<l){
                    heap.set(parentIndex,l);
                    heap.set(leftchildIndex,p);
                    return remove;
                }else{
                    return remove;
		        }
            }
            int r=heap.get(rightchildIndex);
             if(p>l&&p>r){
                return remove;
	         }else if(p<l&&p<r){
                if(l>=r){
                   heap.set(parentIndex,l);
                    heap.set(leftchildIndex,p);
                    parentIndex =leftchildIndex;
                }else{
                    heap.set(parentIndex,r);
                    heap.set(rightchildIndex,p);
                    parentIndex =rightchildIndex;
                }
                leftchildIndex = (2*parentIndex)+1;
                rightchildIndex = (2*parentIndex)+2;
            }else if(p<l){
                heap.set(parentIndex,l);
                heap.set(leftchildIndex,p);
                parentIndex =leftchildIndex;
                leftchildIndex = (2*parentIndex)+1;
                rightchildIndex = (2*parentIndex)+2;
            }else{
                heap.set(parentIndex,r);
                heap.set(rightchildIndex,p);
                parentIndex =rightchildIndex;
                leftchildIndex = (2*parentIndex)+1;
                rightchildIndex = (2*parentIndex)+2;
            }
        }
        return remove;
	}
     void printArray(ArrayList<Integer> array, int size) {
        for (Integer i : array) {
           System.out.print(i + " ");
           }
          System.out.println();
         }
	
     public static void main(String args[]) {
                st = new StringTokenizer(br.readLine());
		PQ pq = new PQ();
		int choice = Integer.parseInt(st.nextToken());
		while(choice != -1) {
			switch(choice) {
				case 1 : // insert
					int element = Integer.parseInt(st.nextToken());
					pq.insert(element);
					break;
				case 2 : // getMax
					System.out.println(pq.getMax());
					break;
				case 3 : // removeMax
					System.out.println(pq.removeMax());
					break;
				case 4 : // size
					System.out.println(pq.getSize());
					break;
				case 5 : // isEmpty
					System.out.println(pq.isEmpty());
				default :
						return;
			}
			choice = Integer.parseInt(st.nextToken());
      
         }
}
/*
 Sample Input
 2
 6 4 2 12 10 
 Sample Output
 12
*/
