/*In Vernam cipher, also known as the One-Time Pad, the length
  of the plaintext, ciphertext, and key is the same. Below is
  an implementation of Vernam cipher in Java. Here the ith letter
  of the cipher text is fomred by shifting the numerical value of
  ith letter of the plaintext by the numerical value ofith letter
  of key. The conversion here is a-0, b-1, c-2, ...., z-25.*/

import java.util.*;
import java.lang.*;

public class vernamCipher {

	/* This method takes a string as input and converts
	   each character in the string to its respective
	   numerical value and returns it.*/
	static int[] asciiToDec(String str) {

		int[] decimal = new int[str.length()];

		for(int i = 0; i < str.length(); i++) {

			/* We first convert the character to its
			 decimal and then shift it by 97 as, a-97,
			 b-98, and so on. So to change the indexing
			 and start from 0, we subtract the value by 97.*/
			decimal[i] = str.charAt(i);
			decimal[i] = decimal[i] - 97;
		}

		return decimal;
	}

	/* This method is the encryption method. It takes 
	   plaintext and key as the input.*/
	static String encrypt(String plaintext, String key) {

		String ciphertext = new String("");

		/* Converting both plaintext and key to their
		   respective numerical values.*/
		int[] plaintextArray = asciiToDec(plaintext);
		int[] keyArray = asciiToDec(key);

		int[] ciphertextArray = new int[keyArray.length];

		/* Forming the ciphertext by shifting each value of
		plaintext by the value present at same index of the key*/
		for(int i = 0; i < keyArray.length; i++) {
			ciphertextArray[i] = (plaintextArray[i] + keyArray[i]) % 26;

			//Shifting the values by 97, to get proper ascii values.
			ciphertextArray[i] += 97;
		}

		/* Converting the decimal values to respective ascii
		values and forming the ciphertext string.*/
		for(int i = 0; i < ciphertextArray.length; i++) {
			ciphertext += (char)ciphertextArray[i];
		}

		return ciphertext;
	}

	/* This method formats the ciphertext according to the plaintext.
	From the encrypt function above, we send plaintext in lowercase.
	So, the ciphertext we get is also in all lowercase. Here, we format
	the ciphertext so that wherever there is capital letter in the plaintext,
	same follows in the ciphertext.*/
	static String format(String plaintext, String ciphertext) {

		String finalencrypted = new String("");

		/* Check wherever the plaintext is capital and
		then capitalize that character in the ciphertext*/
		for(int i = 0; i < plaintext.length(); i++) {
			if(Character.isUpperCase(plaintext.charAt(i))) {
				finalencrypted += Character.toUpperCase(ciphertext.charAt(i));
			}
			else {
				finalencrypted += ciphertext.charAt(i);
			}
		}
		return finalencrypted;
	}

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		// Take plaintext and key as input from the user.
		System.out.print("Enter a plaintext to encrypt: ");
		String plaintext = scan.nextLine();

		System.out.print("Enter a key of same size    : ");
		String key = scan.nextLine();

		/*If the length of key is not equal to the
		length of the plaintext, then terminate.*/
		if(plaintext.length() != key.length()) {
			System.out.println("Invalid input.");
			System.exit(0);
		}
		scan.close();

		// Call the methods and print the encrypted message.
		String encryptedplaintext = encrypt(plaintext.toLowerCase(), key.toLowerCase());
		String encrypted = format(plaintext, encryptedplaintext);

		System.out.println("Encrypted plaintext is      : " + encrypted);
	}
}

/* Sample I/O:
a)	Enter a plaintext to encrypt: ThisIsAMessage
	Enter a key of same size    : MercuryisHottt
	Encrypted plaintext is      : FlzuCjYUwzgtzx

b)	Enter a plaintext to encrypt: MessageTooBIg
	Enter a key of same size    : KeynotMatch
	Invalid input.
*/

