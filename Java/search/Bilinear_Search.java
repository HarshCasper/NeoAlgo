import java.util.Scanner;
public class Bilinear_Search
{
    static int findElement(int arr[], int size, int search){
        /* l for left index; r for right index
        found==-1 means element not found
        found other than -1 will be location of the element */
        int l=0, r=size-1;
	    int found=-1;
	    while(l<=r){
	        if(arr[l]==search){
	            found=l;
	            break;
	        }else if(arr[r]==search){
	            found=r;
	            break;
	        }
	        else{
	            l++;
	            r--;
	        }
	    }
	    return found;
    }
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    System.out.print("Enter number of elements : ");
	    int n = sc.nextInt();
	    int[] arr = new int[n];
	    System.out.print("Enter the elements: ");
	    for(int i=0; i<n; i++){
	        arr[i] = sc.nextInt();
	    }
	    System.out.print("Enter element to search: ");
	    int search = sc.nextInt();
	    int found = findElement(arr, n, search);
	    if(found!=-1){
	        // found+1 because index starts from 0.
	        System.out.println("element found at location : "+(found+1));
	    }else{
	        System.out.println("element not found");
	    }
	}
}
/*
Sample input and output
Enter number of elements : 7
Enter the elements: 4 3 6 8 2 1 9
Enter element to search: 2
element found at location : 5


time complexity: O(n)
space complexity: O(n)
*/
