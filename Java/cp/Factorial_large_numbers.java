import java.util.*;
public class Factorial_large_numbers
{
    public static int len = 0;
    public static int[] Factorial(int n, int[] arr, int[] str2){
        int temp = 0, carry = 0, i=0;
        for(i=0; i<len; i++){
            temp = str2[i]*n + carry;
            carry = temp/10;
            arr[i] = temp%10;
        }
        while(carry!=0){
            arr[i] = carry%10;
            carry = carry/10;
            len+=1;
            i+=1;
        }
        return arr;
    }
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    System.out.print("Enter number : ");
	    int num = sc.nextInt();
	    String str = String.valueOf(num);
	    len = str.length();
	    int[] arr = new int[300];
	    int[] str2 = new int[300];
	    int i=0, temp=num;
	    for(i=0; i<len; i++){
	        str2[i] = temp%10;
	        temp=temp/10;
	    }
	    for(int j=1; j<num; j++){
    	    str2 = Factorial(j, arr, str2);
	    }
	    System.out.print("Factorial of "+num+" = ");
        for(i=len-1; i>=0; i--){
            System.out.print(str2[i]);
        }
	}
}

/*
Sample input and output
Enter number : 10
Factorial of 10 = 3628800

Complexities
time: O(n^2)
space: O(n)
*/