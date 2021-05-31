/* This code is an implementation of Hill Cipher in Java.
   It is a polygraphic substitution cipher. It forms a nxn
   matrix of key and nx1 matrix(s) of the plaintext and then
   multiplies the two matrices to obtains the matrix of ciphertext.*/

import java.util.*;
import java.lang.*;

public class HillCipher {

	// This global variable defines the size of n
	public static int size = 3;

	/* This method forms the nxn matrix of keyword. The value of
	   n can be changed by setting the global vaiable size.*/
	static void generateKeyMatrix(String key, int[][] keymatrix) {

		int count = 0;
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				// Stores decimal value of ASCII
				keymatrix[i][j] = key.charAt(count);
				/* Here, a = 97, b = 98 and so on.
			   	We want a = 0, b = 1 and so on. So,
				we subtract 97.*/
				keymatrix[i][j] -= 97;
				count = count + 1;
			}
		}
	}

	/* This method forms the nx1 matrix of the plaintext. The value of n can be
	   changed by setting the global variable size.*/
	static void generatePlaintextMatrix(String plaintext, int[][] plaintextmatrix) {

		int count = 0;
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < 1; j++) {
				// Stores decimal value of ASCII
				plaintextmatrix[i][j] = plaintext.charAt(count);
				/* As we did above, we subtract 97 from the
				decimal value to start indexing from 0.*/
				plaintextmatrix[i][j] -= 97;
				count = count + 1;
			}
		}
	}

	/* This function forms the nx1 ciphertext matrix. The matrix of decimal is then converted
	to ascii value and combined and then returned.*/
	static String generateCiphertextMatrix(String plaintext, String key, int[][] ciphertextmatrix) {

		// Forming the keyword matrix
		int[][] keymatrix = new int[size][size];
		// Calling the keyord matrix function
		generateKeyMatrix(key, keymatrix);

		// Forming the plaintext matrix
		int[][] plaintextmatrix = new int[size][1];
		// Calling the plaintext matrix function
		generatePlaintextMatrix(plaintext, plaintextmatrix);

		/* Initializing the ciphertext matrix values to
		zero. Otherwise, it would store garbage values.*/
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < 1; j++) {
				ciphertextmatrix[i][j] = 0;
			}
		}

		/* Multiplying key matrix with plaintext matrix
		and forming the ciphertext matrix. */
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < 1; j++) {
				for(int k = 0; k < size; k++) {
					ciphertextmatrix[i][j] += keymatrix[i][k] * plaintextmatrix[k][j];
				}
			}
		}

		/* Taking mod 26 of obtained ciphertext values to
		ensure they lie within the range [0-25].*/
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < 1; j++) {
				ciphertextmatrix[i][j] = ciphertextmatrix[i][j] % 26;
			}
		}

		// Decalaring the ciphertext string
		String cipher = new String("");

		/* Since, we decremented 97 from the decimal values
		of plaintext and key, we add back 97 to the ciphertext
		values, in order to get proper ASCII.*/
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < 1; j++) {
				cipher += (char) (ciphertextmatrix[i][j] + 97);
			}
		}

		// Return the encrypted plaintext
		return cipher;
	}

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		
		System.out.println("\n-----------------HILL CIPHER-----------------\n");
		System.out.println("The length of plaintext must be same as size\n");
		System.out.println("Current value of size is " + size + "\n");

		// Taking plaintext as input from the user
		System.out.print("Enter a plaintext of size " + size + ": ");
		String plaintext = scan.nextLine();

		// Checking if proper message is provided or not.
		if(plaintext.length() != size) {
			System.out.println("Enter a valid message.");
			System.exit(0);
		}
		
		// Taking key as input from the user
		System.out.print("Enter a keyword of size " + size*size + ": ");
		String key = scan.nextLine();

		// Checking if proper key is provided or not.
		if(key.length() != size*size) {
			System.out.println("Enter a valid key.");
			System.exit(0);
		}

		scan.close();

		int[][] ciphertextmatrix = new int[size][1];

		String ciphertext = new String("");

		// Calling the method to get the encrypted plaintext
		ciphertext = generateCiphertextMatrix(plaintext, key, ciphertextmatrix);

		System.out.println("The encrypted plaintext is: " + ciphertext);
	}
}

/* Sample I/O:
	
-----------------HILL CIPHER-----------------

The length of plaintext must be same as size

Current value of size is 3

Enter a plaintext of size 3: pie
Enter a keyword of size 9: chocolate    
The encrypted plaintext is: mem
*/

