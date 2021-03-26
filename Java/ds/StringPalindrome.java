import java.util.Scanner;

/*
 * Description
 * We have given Q queries and we have to check whether given substring is palindrome or not
 * Time Complexity: O(Q*N) where Q is size of Query , N length of String.
 * Space Complexity : O(1)
 * 
 * Test Cases:
 * string s=abcba
 * query={ {0,4}, {1,3}, {1,4} {1,5}};
 * 
 * output for
 * Query-01 : substring abcba is palindrome
 * Query-02 : substring bcb is palindrome
 * Query-03 : substring bcba is not palindrome
 * Query-04 : invalid range  
 * 
 * */
public class StringPalindrome{
	private static void solve(String string, int[][] query) {
	  int i,n=query.length;	
	  for(i=0;i<n;i++){
		 int l=query[i][0];
		 int r=query[i][1];
		 if(l<0 || r>=string.length()) {
			 System.out.println("invalid range");continue;
		  }
		 if(check(string,l,r)){
			 System.out.println(string.substring(l,r+1)+" palindrome");	 
		 }
		 else{
			//Not Palindrome
		 }
	  }	
	}
	private static boolean check(String string, int p1, int p2) {
	
	    while(p1<p2){
	     if(string.charAt(p1)==string.charAt(p2)){
	       p1++;
	       p2--;
	       
	     }
	     else return false;
	    }
		return true;
	}
	public static void main(String[] args) {
	  Scanner sc=new Scanner(System.in);
	  //Input String
	  String s=sc.next();
	  
	  //Query size
	  int n=sc.nextInt();
	  int i;
	  
	  int[][]query= new int[n][2];
	  for(i=0;i<n;i++){
		//insert limit L-R
		 int L=sc.nextInt();
		 int R=sc.nextInt();
		 
		 query[i][0]=L;
		 query[i][1]=R;
	  }
	  solve(s,query);

	}
}


