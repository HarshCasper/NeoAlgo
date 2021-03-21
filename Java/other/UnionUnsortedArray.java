import java.util.HashMap;
import java.util.Map;

public class UnionUnsortedArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] array1 = {1,5,6,2,3,4,4};
		int[] array2 = {1,8,2,9,5,6,7};
		Map<Integer, Integer> map = new HashMap<Integer,Integer>();
		// insert elements of array1 in the map
		for(int i = 0 ; i < array1.length ; i++)
			map.put(array1[i], i);
		// insert elements of array1 in the map
		for(int i = 0 ; i < array2.length ; i++)
			map.put(array2[i], i);
		System.out.print("Union of two unsorted array : ");
		for(Map.Entry mapElement : map.entrySet())
			 System.out.print(mapElement.getKey() + " ");	
	}
}

//Output:
//Union of two unsorted array : 1 2 3 4 5 6 7 8 9 

