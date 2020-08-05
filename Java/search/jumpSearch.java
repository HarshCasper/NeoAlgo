import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int indexI,indexJ,searchElement,countsToJump,lengthOfArray,position;
		System.out.println("Enter number of elements in array");
		lengthOfArray=sc.nextInt();
		int array[]=new int[lengthOfArray];
		System.out.println("Enter array elements");
		for(indexI=0;indexI<lengthOfArray;indexI++)
		array[indexI]=sc.nextInt();
		System.out.println("Enter element to be searched");
		searchElement=sc.nextInt();
		countsToJump=(int)Math.sqrt(lengthOfArray);
		position=-1;indexI=0;
		while(indexI<lengthOfArray)
		{
		    if(array[indexI]==searchElement)
		    position=indexI;
		    if(array[indexI]>searchElement)
		    break;
		    indexI=indexI+countsToJump;
		    
		}
		indexJ=0;
		 
		  
		while(indexJ<countsToJump)
		{
		    
		    indexI--;
		    indexJ++;
		    if(array[indexI]==searchElement)
		    {position=indexI;
		    break;
		    }
		}
		if(position==-1)
		System.out.println("Element not found");
		else
		System.out.println("Element found at "+position);
	}
}
/* Enter number of elements in array                                                                                                            
10                                                                                                                                           
Enter array elements                                                                                                                         
1                                                                                                                                            
2                                                                                                                                            
3                                                                                                                                            
4                                                                                                                                            
5                                                                                                                                            
6                                                                                                                                            
7                                                                                                                                            
8                                                                                                                                            
9                                                                                                                                            
10                                                                                                                                           
Enter element to be searched                                                                                                                 
5                                                                                                                                            
Element found at 4 */                                                                                                                           
                  
