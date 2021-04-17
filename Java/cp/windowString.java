import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class windowString {
	static class Reader {
		static BufferedReader reader;
		static StringTokenizer tokenizer;

		/** call this method to initialize reader for InputStream */
		static void init(InputStream input) {
			reader = new BufferedReader(new InputStreamReader(input));
			tokenizer = new StringTokenizer("");
		}

		/** get next word */
		static String next() throws IOException {
			while (!tokenizer.hasMoreTokens()) {
				// TODO add check for eof if necessary
				tokenizer = new StringTokenizer(reader.readLine());
			}
			return tokenizer.nextToken();
		}

		static int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		static String nextLine() throws IOException {
			return reader.readLine();
		}

		static long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		static double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) throws IOException {
		Reader.init(System.in);
		String a = Reader.next();
		String b = Reader.next();
		String ans = a;
		int flag = 0;
		HashMap<Character, Integer> hmA = new HashMap<>();
		HashMap<Character, Integer> hmB = new HashMap<>();
		for (int i = 0; i < b.length(); i++) {
			char ch = b.charAt(i);
			if (hmB.containsKey(ch)) {
				int num = hmB.get(ch);
				hmB.put(ch, num + 1);
				continue;
			}
			hmB.put(ch, 1);
		}
		int acquire = 0;
		int release = 0;
		String make = "";
		int counter = 0;
		while (acquire < a.length()) {
			char ch = a.charAt(acquire);
			if (hmB.containsKey(ch)) {
				int bCount = hmB.get(ch);
				if (hmA.containsKey(ch)) {
					int aCount = hmA.get(ch);
					if (aCount < bCount)
						counter += 1;
					hmA.put(ch, aCount + 1);
				} else {
					hmA.put(ch, 1);
					counter += 1;
				}
			} else
				hmA.put(ch, 1);
			make += ch;
			if (counter == b.length()) {
				flag = 1;
				while (release <= acquire && counter == b.length()) {
					char chR = a.charAt(release);
					int rfeq = hmA.get(chR);
					if (hmB.containsKey(chR)) {
						if (rfeq > hmB.get(chR)) {
							make = make.substring(1);
							if (make.length() < ans.length())
								ans = make;
						} else {
							if (make.length() < ans.length())
								ans = make;
							make = make.substring(1);
							counter -= 1;
						}
					} else {
						make = make.substring(1);
						if (make.length() < ans.length())
							ans = make;
					}
					hmA.put(chR, rfeq - 1);
					release += 1;
				}
			}
			acquire += 1;
		}
		if (flag == 0)
			ans = "";
		System.out.println(ans);
	}
}

/*
 * For solving this problem I had to use two hashmaps to store the frequencies of each
 * character of both the given string. Then use two pointer approach and traverse in 
 * string a to have OVERALL TIME COMPLEITY O(N) where N is length of string a.
 * 
 * SAMPLE TEST CASES:
 * 
 * TEST:1
 * INPUT:
 * a = DBAECBBABDCAAFBDDCABGBA
 * b = ABBCDC
 * OUTPUT:
 * CBBABDC
 * 
 * TEST:2
 * INPUT:
 * a = ADOBECODEBANC
 * b = ABC
 * OUTPUT:
 * BANC
 * 
 * TEST:3
 * INPUT:
 * a = AB
 * b = A
 * OUTPUT:
 * A
 * 
 *
 */
