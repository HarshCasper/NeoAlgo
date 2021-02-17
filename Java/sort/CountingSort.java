import java.util.*;
import java.lang.*;

/*
Counting sort is an algorithm for sorting a collection of objects according to keys that are small integers; that is, it is an integer sorting algorithm. It operates by counting the number of objects that have each distinct key value, and using arithmetic on those counts to determine the positions of each key value in the output sequence. 
Worst complexity: O(n+k)
Average complexity: O(n+k)
Space complexity: O(n+k)
where n is the number of elements in input array and k is the range of input.
*/

class CountingSort
{
    static void sortIntegerArray(int arr[])
    {
        int i=0;
        int n = arr.length;
        int minElement=Integer.MAX_VALUE;
        int maxElement=Integer.MIN_VALUE;

        //Maximum and Minimum element from input array
        for(i=0;i<n;i++)
        {
            if (arr[i] > maxElement) {
                maxElement=arr[i];
            }
            if (arr[i] < minElement){
                minElement=arr[i];
            }
        }
        
        int range = maxElement-minElement+1;
        int[] arrElementCount = new int[range];
        int[] sortedArray = new int[n];
        
        //count occurance of an element
        for(i=0;i<n;i++)
        {
            arrElementCount[arr[i]-minElement]++;
        }
        //Accumulative sum of elements
        for(i=0;i<range-1;i++){
            arrElementCount[i+1]+=arrElementCount[i];
        }
        //Shift array by one index
        int temp=arrElementCount[0];
        for(i=1;i<range;i++){
            int nextTemp=arrElementCount[i];
            arrElementCount[i]=temp;
            temp=nextTemp;
        }
        arrElementCount[0]=0;
        //store element at right index
        for(i=0;i<n;i++){
            sortedArray[arrElementCount[arr[i]-minElement]]=arr[i];
            arrElementCount[arr[i]-minElement]++;
        }
        //copy sorted array to input array
        for(i=0;i<n;i++){
            arr[i]=sortedArray[i];
        }
    }
    
    static void sortCharArray(char arr[])
    {
        int i=0;
        int n = arr.length;
        int range=256;
        int[] arrElementCount = new int[range];
        char[] sortedArray = new char[n];

        //count occurance of an element
        for(i=0;i<n;i++)
        {
            arrElementCount[arr[i]]++;
        }
        //Accumulative sum of elements
        for(i=0;i<range-1;i++){
            arrElementCount[i+1]+=arrElementCount[i];
        }
        //Shift array by one index
        int temp=arrElementCount[0];
        for(i=1;i<range;i++){
            int nextTemp=arrElementCount[i];
            arrElementCount[i]=temp;
            temp=nextTemp;
        }
        arrElementCount[0]=0;
        //store element at right index
        for(i=0;i<n;i++){
            sortedArray[arrElementCount[arr[i]]]=arr[i];
            arrElementCount[arr[i]]++;
        }
        //copy sorted array to input array
        for(i=0;i<n;i++){
            arr[i]=sortedArray[i];
        }
    }

    public static void main (String[] args) throws java.lang.Exception
    {
	CountingSort sort = new CountingSort();

        Scanner sc = new Scanner(System.in);

        //Input:- Integer Array
        System.out.println("Enter space separated integer:");
        String intString[]= sc.nextLine().split(" ");
        int size = intString.length;
        int[] arrInt = new int[size];
        for(int i=0 ;i<size;i++){
            arrInt[i]= Integer.parseInt(intString[i]);
        }
        sort.sortIntegerArray(arrInt);
        System.out.println("Sorted Integer Array:- ");
        for(int i=0; i<size;i++)
        {
            System.out.print(arrInt[i]+" ");
        }
        System.out.println();

        //Input:- Character Array
        System.out.println("\nEnter space separated character:");
        String charString[] = sc.nextLine().split(" ");
        int Size=charString.length;
        char[] arrChar = new char[Size];
        for(int i=0 ;i<Size;i++){
            arrChar[i] = charString[i].charAt(0);
        }
        sort.sortCharArray(arrChar);
        System.out.println("Sorted Character Array:- ");
        for(int i=0; i<Size;i++)
        {
            System.out.print(arrChar[i]+" ");
        }
        System.out.println();
    }
}

/*
Sample Input-Output

Enter space separated integer:
7 8 9 4 5 6 7
Sorted Integer Array:- 
4 5 6 7 7 8 9

Enter space separated character:
a b t r a b c f
Sorted Character Array:- 
a a b b c f r t
*/
