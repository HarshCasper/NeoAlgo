import java.util.*;
public class CheckForSubSequence
{
    public boolean CheckForSubSequenceFunc(String st1, String st2){
	    char[] ch1 = st1.toCharArray();
	    char[] ch2 = st2.toCharArray();
	    int count2=0, count1=0;
	    for(count2=0; count2<ch2.length && count1<ch1.length; count2++){
	        if(Character.compare(ch1[count1], ch2[count2]) == 0) count1++;
	    }
	    return (count1 == ch1.length);
    }
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    System.out.print("Enter first string: ");
	    String st1 = sc.next();
	    System.out.print("Enter second string: ");
	    String st2 = sc.next();
	    CheckForSubSequence cfs = new CheckForSubSequence();
	    if(cfs.CheckForSubSequenceFunc(st1, st2)) System.out.print(st1+" is a subsequence of "+st2);
	    else System.out.print(st1+" is a not subsequence of "+st2);
	}
}

/*Sample input and output

# 1
Enter first string: pogy
Enter second string: appology
pogy is a subsequence of appology

# 2
Enter first string: race
Enter second string: horse
race is a not subsequence of horse

Complexities
time: O(n)
space: O(n)*/