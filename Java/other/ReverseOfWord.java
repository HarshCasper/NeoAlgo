// java program to reverse a String
import java.util.Scanner;

public class reverseWord {

	
	// Method to reverse words of a String
      public static String reversewords (String s) {
	int i = s.length()-1;
	String ans = " ";
	while (i>=0) {
		while( i>=0 && s.charAt(i) == ' ')i--;
		int j =i;
	if(i<0)break;
		while( i>=0 && s.charAt(i) != ' ')i--;
	if(ans.isEmpty()) {
		ans = ans.concat(s.substring(i+1,j+1));
		}
		else { ans=ans.concat(" " + s.substring(i+1,j+1));
	}
    }
	return ans;
	
    }
//Driver methods to test above method
public static void main(String[] args) {
	Scanner sc = new Scanner(System . in);
	
	System.out.print("Input = ");
	
		String c;
    c = sc.nextLine();
  
	
	System.out.println("Output ="+ reversewords(c));

     }
}
Example -

Input = I am a student
Output = student a am I

Input = I like this program very much
Output = much very program this like I

