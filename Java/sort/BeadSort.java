import java.util.*;
class sorting
{
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        int indexI,indexJ,arrayLength,temp,indexK;
        System.out.println("Enter the length of array");
        arrayLength=sc.nextInt();
        int array[]=new int[arrayLength];
        System.out.println("Enter array elements");
        for(indexI=0;indexI<arrayLength;indexI++)
        array[indexI]=sc.nextInt();
        indexI=0;indexJ=1;
        while(indexI<arrayLength-2)
        {    indexJ=indexI+1;
             while(array[indexI]<=array[indexJ])
            {   if(indexI==arrayLength-2)
                break;
                indexI++;
                indexJ=indexI+1;
            }
            if(array[indexI]>array[indexJ])
            {
                temp=array[indexJ];
                array[indexJ]=array[indexI];
                array[indexI]=temp;
                indexI=0;
                continue;
            }
        }
        for(indexI=0;indexI<arrayLength;indexI++)
        System.out.println(array[indexI]+" ");
    }
    
} 

/*
Input :
Enter the length of array
5
Enter array elements
1
2
3
1
1

Output :
1 
1 
1 
2 
3 */
