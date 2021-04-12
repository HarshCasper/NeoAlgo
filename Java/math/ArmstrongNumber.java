import java.util.*;
public class ArmstrongNumber
{
	static int length_number(int num){
		return String.valueOf(num).length();
	}
    	static boolean isArmstrong(int x){
        	int res = x;
		int val = 0;
		int len = length_number(x);
		while(res>0){
			int temp = res % 10;
			val += Math.pow(temp, len);
			res = res / 10;
		}
		if(x == val)
		    return true;
		else    
		    return false;
    	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number: ");
		int num = sc.nextInt();
		if(isArmstrong(num))
		    System.out.println(num+" is an Armstrong Number.");
		else 
		    System.out.println(num+" is not an Armstrong Number.");
	}
}

/*
Sample input and output
Example 1:
Enter a number : 1002
Number is not an armstrong number.

Example 2:
Enter a number : 153
Number is an armstrong number.

Example 3:
Enter a number : 8208
8208 is an armstrong number.

Complexities
time: O(log(n))
space: O(1)
*/
