import java.util.Scanner;

class Triplet{
	
	public int x,y,gcd;
	public Triplet() {	
	}
	
}
public class ExtendedEuclidAlgo {
	
	public static int euclidAlgo(int a,int b) {
		if(b==0) {
			return a;
		}
		
		return euclidAlgo(b, a%b);
	}
	
	public static Triplet extendedEuclid(int a,int b) {
		if(b==0) {
			Triplet ans=new Triplet();
			ans.x=1;
			ans.y=0;
			ans.gcd=a;
			return ans;
		}
		
		Triplet subAns=extendedEuclid(b, a%b);
		Triplet ans=new Triplet();
		ans.x=subAns.y;
		ans.y=subAns.x-(a/b)*subAns.y;
		ans.gcd=subAns.gcd;
		
		return ans;
	}
	
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		Triplet ans=extendedEuclid(a, b);
		System.out.println("Gcd of ("+a+" , "+b+") : "+ans.gcd);
	}
	
//Sample Input 5 10 
//Sample Output : Gcd of (5 , 10) : 5

//Sample Input 51 68
//Sample Output : Gcd of (51 , 68) : 17	
	
}
