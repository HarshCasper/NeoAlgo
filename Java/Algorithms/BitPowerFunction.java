/*
 *  Description : 
 *  
 *  Customized power function where we can find power of any number using bitwise operator
 *  
 *  Time Complexity: O(logB)
 *  Space Complexity: O(1)
 */

import java.util.Scanner;
public class BitPowerFunction {
    public static void pow(int A, int B) {
      long ans=1,pow=A;
      int MOD=1000000007;
	     int i;
	     for(i=0;i<31;i++){
	    	if((B&(1<<i))>0){
	    	  ans=ans*pow;
	    	  ans%=MOD;
	    	}
	    	pow*=pow;
	    	pow%=MOD;
	     }
	    System.out.println((ans+MOD)%MOD);  
    }
	 public static void main(String...p){
		 Scanner sc=new Scanner(System.in); 
		 int x=sc.nextInt();
		 int y=sc.nextInt();
	 }
}
/*
 * Examples:
 * 
 * input1: A=9 B=4
 *  
 * output1: 6,561
 * 
 * input2: A=5 B=3
 *  
 * output2: 125
 * 
 * */



