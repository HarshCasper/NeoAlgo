import java.util.Scanner;

public class RemoveDuplicateElement {

    /**
     *
     * Method 1 Using extra space
     *
     */



//     The function remove the duplicate element
//     Function take two argument array 'a' of size 'n'.
    static int DuplicateElement(int[] a, int n){

//        check if array is empty or it has only 1 element

        if (n==0 || n==1)
            return n;

//        Now we create an temporary array of  size an
//        it stores the unique element

        int[] temp = new int[n];

        int j=0;

//        start traversing the array

        for (int i=0; i<n-1; i++){
            // If current element is not equal
            // to next element then store that
            // current element

            if (a[i] != a[i+1]){

                temp[j++] = a[i];

            }
        }
        // Store the last element as whether
        // it is unique or repeated, it hasn't
        // stored previously
        temp[j++] = a[n-1];

//        modify original array

        for (int i=0; i<j; i++){
            a[i] = temp[i];
        }
        return j;
    }

    public static void main(String[] args) {
        
        // taking the input from the user
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the length of the array : ");
        int n = sc.nextInt();
        
        int a[] = new int[n];
        System.out.println("Enter the values for the array elements : ");
        // taking the values for the array from the user
        for(int i=0; i<n; i++)
        {
            a[i] = sc.nextInt();
        }

        n = DuplicateElement(a,n);

//        print the updated array
        for (int i=0; i<n; i++){
            System.out.print(a[i] + " ");
        }

    }

}

/*

Example : 

Input:
Enter the length of the array : 4
Enter the values for the array elements : 
1 1 2 2

Output:
1 2

*/
