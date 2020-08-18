//program to find longest common subsequence using dynamic programming in java
import java.util.*;
public class lcsdp {

	public static void main(String args[]) {
		Scanner s=new Scanner(System.in);
		System.out.println("enter first string");//input the string1
		String a=s.next(); //sample input- asdfgk
		System.out.println("enter second string");//input the string2
		String b=s.next();//sample input- adflom
		lcs(a,b);//call lcs function
	             //sample output-3
		s.close();
	}
		
		public static void lcs(String s1, String s2){
			
		int[][] storage = new int[s1.length() + 1][s2.length() + 1];
		        System.out.println("The length of lcs is " +lcsDP(s1, s2, storage));

		    }

		  public static int lcsDP(String s, String t, int[][] storage) {
				int m = s.length();
				int n = t.length();
				int storage1[][] = new int[s.length() + 1][t.length() + 1];
				for(int i=0;i<=m;i++){ //initialize 1st row as 0
			           storage1[i][0]=0;
			        }
			        for(int i=0;i<=n;i++){//initialize 1st column as zero
			           storage1[0][i]=0;
			        }
			          for(int i=1;i<=m;i++){
			             for(int j=1;j<=n;j++){
			                if(s.charAt(m-i)==t.charAt(n-j)){//down to top approach
			                   storage1[i][j]=1+storage1[i-1][j-1];
			                }else{
			                   storage1[i][j]=Math.max(storage1[i][j-1],storage1[i-1][j]);
			                    //maximum out of the two
			                }
			             }
			          }
			         return storage1[m][n];
			    }


}
