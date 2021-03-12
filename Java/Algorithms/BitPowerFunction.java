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
		 System.out.println("TEST");
		 Scanner sc=new Scanner(System.in);
		 int x=sc.nextInt();
		 int y=sc.nextInt();
		 pow(x,y);
	 }
}
