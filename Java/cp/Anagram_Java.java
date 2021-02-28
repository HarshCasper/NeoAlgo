package HACKER_RANK;

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
		System.out.println((ret) ? "String are Anagrams" : "Strings are Not Anagrams");
	}
}