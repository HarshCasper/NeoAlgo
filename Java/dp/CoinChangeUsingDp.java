import java.util.Scanner;

public class CoinChangeUsingDp {
	
	public static int coinChange(int[] coins, int amount) {
		
        if(amount==0) {
            return 0;
        }
        
        int n = coins.length;
        int t [][] = new int [n+1][amount+1];
        
        for(int i=0; i<amount+1; i++) {
            t[0][i] = Integer.MAX_VALUE-1;
        }
        
        for(int i=1; i<n+1; i++) {
            t[i][0] = 0;
        }
        
        for(int i=1; i<amount+1; i++) {
        	
            if(i%coins[0] == 0) {
                t[1][i] = i/coins[0];
            }
            else {
                t[1][i] = Integer.MAX_VALUE-1;
            }
        }
        
        for(int i=2; i<n+1; i++) {
        	
            for(int j=1; j<amount+1; j++) {
            	
                if(coins[i-1] <= j) {
                    t[i][j] = (1 + t[i][j-coins[i-1]]) < t[i-1][j] ? (1 + t[i][j-coins[i-1]]) : t[i-1][j];
                }
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        if(t[n][amount] == Integer.MAX_VALUE-1) {
            return -1;
        }
        else {
            return t[n][amount];
        }
    }

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		int array[] = new int [size];
		
		for(int i=0; i<size; i++) {
			array[i] = sc.nextInt();
		}
		
		int sum = sc.nextInt();
		
		System.out.println(coinChange(array, sum));
	}

}
