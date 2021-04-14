/*
 1.Hashing is most frequently used in case you have operation like search, insert, delete or subset of these because
   hashing provides these operations in O(1) time on an average
 2.The data is stored in a hash table
 3.Collision happens when our hash function give the same hash value for two or more input values in that case we can use
   linear probing to avoid collisions.
 
*/

import java.util.*;
public class linearProbing {
	
	    static int[] linearProbing(int hashSize, int arr[], int arraySize)
	        {
	    	 //Function to fill the array elements into a hash table 
		    //using Linear Probing to handle collisions.
	            int hash_table[] = new int[hashSize];
	            
	            //putting -1 to the table which means empty cell
	            for(int i = 0; i < hashSize; i++)
	                 hash_table[i] = -1;
	            
	            //iterating over the array. 
	            for(int i=0;i<arraySize;i++)
	            {
	                //if the value of hash table at index (arr[i]%hashSize) is -1 
	                //which means empty then, we insert arr[i] at that place.
	                if(hash_table[arr[i]%hashSize]==-1)
	                {
	                    hash_table[arr[i]%hashSize]=arr[i];
	                }
	                //else we move linearly from the filled position 
	                //to find an index with -1 in hash table.
	                else
	                {
	                    int counter=0;
	                    int k=(1+arr[i])%hashSize;
	                    
	                    //using a loop which runs until we find an index with -1
	                    //in hash table which means empty.
	                    while(counter<hashSize&&hash_table[k]!=-1)
	                    {
	                         k=(k+1)%hashSize;
	                         counter++;
	                    }
	                    //if we find a position where arr[i] can be inserted 
	                    //then we insert the element.
	                    if(counter<hashSize)
	                    hash_table[k]=arr[i];
	                }
	            }
	            //returning the hash table.
	            return hash_table;
	        }


	public static void main(String[] args) {

		// scanner class to take input from the user
		Scanner sc = new Scanner(System.in);
		
		// Taking an Hash table size as input
		int hashSize = sc.nextInt();
				
		// Taking an array size as input
		int arraySize = sc.nextInt();
		
		// creating the array
		int array[]=new int[arraySize];
		
		// Taking input in the array
		for(int i=0;i<arraySize;i++) {
			array[i]=sc.nextInt();
		}
		
		// creating the hash table from the returned array form the function linearProbing
		int hashTable[]= linearProbing(hashSize,array,arraySize);
		
		
		for(int i=0;i<hashSize;i++) {
			//printing the values
			System.out.print(hashTable[i]+" ");
		}
		
	}
}

/*
Sample input 1:
8 4
15 48 98 63

Output 1:
48 63 98 -1 -1 -1 -1 15 

Sample input 2:
10 6
45 80 90 60 74 10

Output 2:
80 90 60 10 74 45 -1 -1 -1 -1 
 */

// Time complexity - O(n)
// Space complexity - O(1)