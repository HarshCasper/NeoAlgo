/*
    Steps to be followed:
 	1.we will create an empty hash table and initialize all of its value as -1 which represent empty cells.
 	2.Then we will iterate over the input array and compute the hash value of all the keys to be inserted,
 	 put it in appropriate cells if that cell is already filled we will add square of a constant value to find
 	 an empty cell if we found one we will put the key in the cell otherwise we will increment the constant value
 	 and then put the key.
 	3.We have taken hash function as arr[i]%hashSize
*/
import java.util.Scanner;
public class quadraticProbing {
	
static void quadraticProbing(int[] hashTable, int hashSize, int arr[], int arraySize){
	
    for(int i=0;i<hashSize;i++) {
    	hashTable[i] = -1;
    }
    
    for(int i=0;i<arraySize;i++){
        if(hashTable[arr[i]%hashSize]==-1){
            hashTable[arr[i]%hashSize]=arr[i];
        }
        else{
            int k=arr[i]%hashSize;
            int power=1;
            while( hashTable[(k+power*power)%hashSize] != -1){
                 power++;
            }
            hashTable[(k+power*power)%hashSize]=arr[i];
        }
    }
}   

public static void main(String[] args) {
	
	Scanner sc = new Scanner(System.in);
	System.out.println("Enter hash size :");	
	int hashSize = sc.nextInt();
	
	System.out.println("Enter array size :");	
	int arraySize = sc.nextInt();
	
	int array[]=new int[arraySize];
	
	System.out.println("Enter elements of array :");
	for(int i=0;i<arraySize;i++) {
	    array[i]=sc.nextInt();
	}	
	
	int hashTable[] = new int[hashSize];
	quadraticProbing(hashTable,hashSize,array,arraySize);	
	
	for(int i=0;i<hashSize;i++) {
	    System.out.print(hashTable[i]+" ");
	}		
    }
}
/*
Sample input :
Enter hash size :
11
Enter array size :
4
Enter elements of array :
21 10 32 43

Sample output :
10 -1 -1 32 -1 -1 -1 -1 43 -1 21 
*/
//Time complexity - O(n)
//Space complexity - O(1)
