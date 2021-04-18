/*
 1.Hashing is most frequently used in case you have operation like search, insert, delete or subset of these because
   hashing provides these operations in O(1) time on an average
 2.The data is stored in a hash table
 3.Collision happens when our hash function give the same hash value for two or more input values in that case we can use
   linear probing to avoid collisions.
 
 	Steps to be followed:
 	1.we will create an empty hash table and initialize all of its value as -1 which represent empty cells.
 	2.Then we will iterate over the input array and compute the hash value of all the keys to be inserted,
 	 put it in appropriate cells if that cell is already filled we will linearly search for next free cell
 	 and then put the key.
 	3.We have taken hash function as arr[i]%hashSize
*/

import java.util.*;
public class linearProbing {
	
static int[] linearProbing(int hashSize, int arr[], int arraySize)
    {
    int hash_table[] = new int[hashSize];
    
    for(int i = 0; i < hashSize; i++)
         hash_table[i] = -1;
    
    for(int i=0;i<arraySize;i++)
    {
        if(hash_table[arr[i]%hashSize]==-1)
        {
            hash_table[arr[i]%hashSize]=arr[i];
        }
        else
        {
            int counter=0;
            int k=(1+arr[i])%hashSize;
            while(counter<hashSize&&hash_table[k]!=-1)
            {
                 k=(k+1)%hashSize;
                 counter++;
            }
            if(counter<hashSize)
            hash_table[k]=arr[i];
        }
    }
    return hash_table;
}

public static void main(String[] args) {
	
	Scanner sc = new Scanner(System.in);
	int hashSize = sc.nextInt();
	int arraySize = sc.nextInt();
	int array[]=new int[arraySize];
	
	for(int i=0;i<arraySize;i++) {
		array[i]=sc.nextInt();
	}	
	int hashTable[]= linearProbing(hashSize,array,arraySize);	
	
	for(int i=0;i<hashSize;i++) {
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
