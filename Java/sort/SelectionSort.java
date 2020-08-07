import java.util.*;
 class SelectionSort
{
	public static void main(String[] args) {
		int indexI,arrayLength,indexJ,temp=0,minElementIndex=0;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter size of array");
		arrayLength=sc.nextInt();
		int array[]=new int[arrayLength];
		System.out.println("Enter Elements of array");
		for(indexI=0;indexI<arrayLength;indexI++)
		array[indexI]=sc.nextInt();
		for(indexI=0;indexI<arrayLength;indexI++)
		{   
		    minElementIndex=indexI;
		    for(indexJ=indexI+1;indexJ<=arrayLength-1;indexJ++)
		    {
		        if(array[minElementIndex]>array[indexJ])
		        minElementIndex=indexJ;
		      }
		        
		        temp=array[indexI];
		        array[indexI]=array[minElementIndex];
		        array[minElementIndex]=temp;
		      }
		  
		  for(indexI=0;indexI<arrayLength;indexI++)
		    System.out.println(array[indexI]);
		}
		}
