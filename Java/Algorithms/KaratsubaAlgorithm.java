import java.util.*;
public class KaratsubaAlgorithm {
	public static int digits(long n) {
		int count = 0;
		while(n>0) {
			count+=1;
			n/=10;
		}
		return count;
	}
	public static long Karatsuba(long n1, long n2) {
		
		int size1 = digits(n1);
		int size2 = digits(n2);
		int max = Math.max(size1, size2);
		max = max/2 + max%2;
		if(max<10)
			return n1*n2;
		
		long n1_l = (long) (n1/Math.pow(10, max));
		long n1_r = (long) (n1%Math.pow(10, max));
		long n2_l = (long) (n2/Math.pow(10, max));
		long n2_r = (long) (n2%Math.pow(10, max));
		long S1 = Karatsuba(n1_l, n2_l);
		long S2 = Karatsuba(n1_r, n2_r);
		long S3 = Karatsuba((n1_l + n1_r), (n2_l + n2_r));
		long S4 = S3 - S2 - S1;
		
		return S1 * (long) Math.pow(10, max) + S4 * (long) Math.pow(10, 2*max) + (long)S2;
		
	}

	public static void main(String[] args) {
  
		Scanner sc = new Scanner(System.in);
    
    System.out.println("Please enter the first number: ");
		long n1 = sc.nextLong();
    
    System.out.println("Please enter the second number: ");
		long n2 = sc.nextLong();
		
		System.out.println(Karatsuba(n1, n2));
	}

}
/* 
Test Input
4468
546

Test output
2439528
*\
