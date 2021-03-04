/* This is a java code of checking whether the Strings are anagram to each outher and not...
An anagram of a string is another string that contains the same characters, only the order of characters can be different.
For example, “abcd” and “dabc” are an anagram of each other.
*/
import java.util.Scanner;
import java.lang.String;
public class Annagram {

	static boolean isAnagram(String a, String b) {
		a = a.toLowerCase();
		b = b.toLowerCase();
		boolean c = true;
		int al[] = new int[256];
		int bl[] = new int[256];
		for (char d : a.toCharArray()) {
			int index = (int) d;
			al[index]++;
		}
		for (char d : b.toCharArray()) {
			int index = (int) d;
			bl[index]++;
		}
		for (int i = 0; i < 256; i++) {
			if (al[i] != bl[i]) {
				c = false;
				break;
			}
		}
		return c;
	}

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		System.out.println("Please enter the first String : ");
		String a = scan.next();
		System.out.println("Please enter the Second String : ");
		String b = scan.next();
		scan.close();
		boolean ret = isAnagram(a, b);
		System.out.println((ret) ? "String are Anagrams..." : "Strings are Not Anagrams...");
	}
}
/*
Time complexity is O(n)
Space complexity is O(1)

Input :
Please enter the first String :
abcd
Please enter the Second String :
dcab

Output:
String are Anagrams...

*/
