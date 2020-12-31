import java.util.Scanner;

public class NthFoboElement {
    
    public static int fibonacciNumber(int n)
    {
    	
    	if(n == 0 || n == 1)
    	{
    		return n;
    	}
    	int ans =  fibonacciNumber(n - 1) + fibonacciNumber(n-2);
    	return ans;
    }
	
	public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
         int n = sc.nextInt();
         int ans = fibonacciNumber(n);
         System.out.println(ans);
         sc.close();
	}
}
