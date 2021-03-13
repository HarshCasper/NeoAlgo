/*
 * Check given substring is palindrome or not 
 *  We have Q queries and for each query we have to check substring from [l,r] (0-index) is plindrome or not
 *  eg: str=abcba
 *  for query [0,4] abcba is plindrome
 *  for query [0,3] abcb is not palindrome
 *  for query [1,3] bcb is palindrome
 *  Time Complexity = O(Q+N)
 *  Space Complexity = O(N) (powers array, PreHash Array, ReverseHash Array)
 *  used mode:1e9+7 because value could be be very large for large string 
 */ 
public class PalindromicSubstring {
 public static void solve(String str,int[][] Query){
   int i,n=str.length(),m=Query.length;
   long PreHash[]=new long[n+1];      //PreHashArray
   long ReverseHash[]=new long[n+1];  //ReverseHashArray
   long powers[]=new long[n+1];       //Storing Power of 26
   int MOD=1000000007;  
   int k=26;    //Hashing Parameter
   long pow=1;
   for(i=n;i>0;i--){
	 powers[i]=pow;
	 pow*=k;
	 pow%=MOD;
   }
   //calculating PreHash Array
   for(i=1;i<=n;i++) PreHash[i]=(PreHash[i-1]+str.charAt(i-1)*powers[i])%MOD; 
   
   
   //calculating ReverseHash Array
   for(i=n-1;i>=0;i--) ReverseHash[i]=(ReverseHash[i+1]+str.charAt(i)*powers[n-i])%MOD;
   
   for(i=0;i<m;i++){
	 int l=Query[i][0];
	 int r=Query[i][1];
	 if(check(PreHash,ReverseHash,powers,l,r,str)){
	   System.out.println(str.substring(l,r+1)+" palindrme");	 
	 }
	 else System.out.println(str.substring(l,r+1)+" Not palindrme");
   }
   
	 
	 
 }
 private static boolean check(long[] preHash, long[] reverseHash,long[] powersArray,int l,int r,String str) {
   int MOD=1000000007;
   
   long a=(preHash[r+1]-preHash[l]+MOD);   
   
   long b=power(powersArray[r+1],MOD-2,MOD);
   
   long leftHash=(a*b)%MOD;
   
   
   long c=reverseHash[l]-reverseHash[r+1]+MOD;
   long d=power(powersArray[str.length()-l],MOD-2,MOD);
   
   long rightHash=(c*d)%MOD;

   
   if(leftHash==rightHash) return true;
   return false;
   
	
 }
 public  static long power(long x,long y,int MOD){      	
 	if(y==0) return 1L;
     if(y==1)  return x;

     long temp=power(x,y/2,MOD)%MOD;
     temp = (temp*temp)%MOD;
     if(y%2==1) {
         temp = (temp*x)%MOD;
     }
     return temp;
 }
 
public static void main(String[] args) {
	 int query[][]={
			      {0,4},{1,3},{0,3},{1,4}
	               };
	 solve("aabbaa",query);	
	}

}
/*  example
 *  str=abcba
 *  for query [0,4] abcba is plindrome
 *  for query [0,3] abcb is not palindrome
 *  for query [1,3] bcb is palindrome
 *  Time Complexity = O(Q+N)
 *  Space Complexity = O(N) (powers array, PreHash Array, ReverseHash Array)
 *  used mode:1e9+7 because value could be be very large for large string 
 * 
 * */
 