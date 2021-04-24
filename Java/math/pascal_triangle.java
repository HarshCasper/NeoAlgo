/*
 Pascal's triangle is a triangular array of the binomial coefficients that arises in probability theory, combinatorics, and algebra.
*/
import java.util.Scanner;

public class pascal_triangle {
    //Function for calculating pascal triangle
    public static void pascal(int row , int c) {
    for(int i=1;i<=row;i++){
        for(int sp =1;sp<=(row+1-i);sp++)
              System.out.print(" ");
        for(int j=1;j<=i;j++){
            if(j!=1){
                c=c*(i+1-j)/(j-1);
                System.out.print(c+" ");
            }
            else
            {
                System.out.print(j+" ");
            }
        }
        System.out.print("\n");
    }
}
	public static void main(String[] args) {
		int c=1;
        //To read input from the user
		Scanner s = new Scanner(System.in);
        //To enter number of rows
        System.out.print("Enter number of rows ->");
		int row=s.nextInt();
        pascal(row,c);
	}
}
/*
Sample Output:
Enter number of rows -> 5
     1
    1 1
   1 2 1
  1 3 3 1
 1 4 6 4 1

Time Complexity : O(row^2)
Space complexity : O(row^2)
*/
