/* Below code is an implementation of Vigenere Cipher in Java.
It is a form of substitution cipher. Given a plaintext and a key.
If the length of key is smaller than that of plaintext, then we 
repeat the contents of the key in a circular fashion till both of
their lengths is same. Plaintext and key are converted to number 
[0-25] and then each character of plaintext is shifted by character
present at the same index in the key to form the encrypted message.*/

import java.util.*;
import java.lang.*;

public class VigenereCipher {

	/*This method generates the key if the length of key
	is shorter than the length of the plaintext.*/
	static String generateKey(String key, int size) {

		int i = 0;
		/*In a circular fashion, we add the contents of
		the key from front to the end, till the length of
		the key becomes equal to the length of the plaintext.*/
		while(i < size) {
			if(i == size) {
				i = 0;
			}
			if(key.length() == size) {
				break;
			}
			key += key.charAt(i);
			i = i + 1;
		}
		// Return the final key to be used
		return key;
	}

	// This method generates the cipher text
	static String generateCipher(String plaintext, String key) {
		
		/* Calling the above function to ensure that the length
		of the key is same as length of the plaintext*/
		String keyUpdated = generateKey(key, plaintext.length());
		String ciphertext = new String("");

		// Shifting the plaintext to generate the ciphertext
		for(int i = 0; i < plaintext.length(); i++) {
			int temp = 0;
			temp = (plaintext.charAt(i) - 97) + (keyUpdated.charAt(i) - 97);
			temp = temp % 26;
			temp = temp + 97;
			ciphertext += (char) temp;
		}
		// Returns the ciphertext
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
		// Return the final formatted ciphertext
		return finalencrypted;
	}

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);

		// Taking plaintext as input from the user
		System.out.print("Enter a plaintext to encrypt: ");
		String plaintext = scan.nextLine();

		// Taking key as input from the user
		System.out.print("Enter a key to encrypt      : ");
		String key = scan.nextLine();

		scan.close();

		// Generating and formatting the ciphertext
		String ciphertext = generateCipher(plaintext.toLowerCase(), key.toLowerCase());
		String encrypted = format(plaintext, ciphertext);

		// Printing the ciphertext
		System.out.println("Encrypted plaintext is      : " + encrypted);
	}
}

/* Sample I/O:
	Enter a plaintext to encrypt: HelloWorld
	Enter a key to encrypt      : Mercury 
	Encrypted plaintext is      : TicniNmdpu
*/

