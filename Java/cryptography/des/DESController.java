package des;

import des.exception.ValidationException;
import des.key.KeyGenerationModels;

/**
 * <h1>Data Encryption Standard</h1>
 * <p>
 * 		To Implement Data Encryption Standard Symmetric Key Cryptography algorithm with 64-bit plain text and 64-bit cipher
 * 		text
 * </p>
 * <b>Description</b>
 * <p>
 * 		class DESController is a public class which acts as a controller, it is used to call cryptography methods of
 * 		DESCryptography class, the DES algorithm is the most widely used encryption algorithm in the world, DES has been
 * 		found vulnerable/breakable against many attacks, reflecting it's a decline in popularity but despite this DES will
 * 		live in many government and banking for years, due to its successor algorithms Triple-DES, AES, etc.
 * </p>
 * <b>Reference for understanding the algorithm</b>
 * <p>
 * 		<a href="http://page.math.tu-berlin.de/~kant/teaching/hess/krypto-ws2006/des.htm"> The DES Algorithm Illustrated </a>
 * </p>
 */
public class DESController
{
	/**
	 * This is the main method which makes use of the following methods:
	 * <ul>
	 * 		<li>DESCryptographyLogic.encrypt</li>
	 * 		<li>DESCryptographyLogic.decrypt</li>
	 * </ul>
	 * 
	 * And uses the following objects of types:
	 * <ul>
	 * 		<li>DESCryptographyLogic</li>
	 * </ul>
	 * 
	 * @param args not used
	 */
	public static void main(String[] args)
	{
		// Defining plain text of 64-bits
		byte[] plainText = {
				1, 1, 1, 0, 0, 0, 0, 1,
				0, 0, 1, 0, 0, 0, 1, 1,
				0, 1, 0, 0, 0, 1, 0, 1,
				0, 1, 1, 0, 0, 1, 1, 1,
				1, 0, 0, 0, 1, 0, 0, 1,
				1, 0, 1, 0, 1, 0, 1, 1,
				1, 1, 0, 0, 1, 1, 0, 1,
				1, 1, 1, 0, 1, 0, 1, 1
		};
		
		// Defining original key of 64-bits
		byte[] key = {
				0, 0, 0, 1, 0, 0, 1, 1,
				0, 0, 1, 1, 0, 1, 0, 0,
				0, 1, 0, 1, 0, 1, 1, 1, 
				0, 1, 1, 1, 1, 0, 0, 1,
				1, 0, 0, 1, 1, 0, 1, 1,
				1, 0, 1, 1, 1, 1, 0, 0,
				1, 1, 0, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 0, 0, 0, 1
		};
		
		//created object of type DESCryptographyModels to access models associated with the respective
		DESCryptographyModels	desCryptographyModels	= new DESCryptographyModels();
		//created object of type KeyGenerationModels to access models associated with the respective
		KeyGenerationModels		keyGenerationModels		= new KeyGenerationModels();
		
		//setting plain text
		desCryptographyModels.setPlainText(plainText);
		//setting original key
		desCryptographyModels.setKey(key);
		
		//printing plain text
		System.out.println("Plain Text:");
		for (int i = 0; i < plainText.length; i++)
		{
			//used for styling the output
			if (i % 8 == 0 && i != 0)
			{
				System.out.print(" ");
			}
			System.out.print(plainText[i]);
		}
		System.out.println();
		
		//created object of class DESCryptographyLogic which consists of encrypt and decrypt methods
		DESCryptographyLogic desCryptographyLogic = new DESCryptographyLogic();
		
		//used to store cipher text
		byte[] cipherText = new byte[64];
		try
		{
			//calling encrypt method and storing cipher text of 64-bits in cipherText byte array
			cipherText = desCryptographyLogic.encrypt(plainText, key, desCryptographyModels, keyGenerationModels);
		}
		catch (ValidationException e)
		{
			//printing error message
			System.out.println(e.getMessage());
		}
		
		//printing cipher text
		System.out.println("Cipher Text:");
		for (int i = 0; i < cipherText.length; i++)
		{
			//used for styling the output
			if (i % 8 == 0 && i != 0)
			{
				System.out.print(" ");
			}
			System.out.print(cipherText[i]);
		}
		System.out.println();
		
		//used to store the decrypted text
		byte[] decryptedText = new byte[64];
		try
		{
			//calling decrypt methods and storing decrypted text of 64-bits in decryptedText byte array
			decryptedText = desCryptographyLogic.decrypt(cipherText, key, desCryptographyModels, keyGenerationModels);
		}
		catch (ValidationException e)
		{
			//printing error message
			System.out.println(e.getMessage());
		}
		
		//printing decrypted text
		System.out.println("Decrypted Text:");
		for (int i = 0; i < decryptedText.length; i++)
		{
			//used for styling the output
			if (i % 8 == 0 && i != 0)
			{
				System.out.print(" ");
			}
			System.out.print(decryptedText[i]);
		}
		
	}// End of main(String[]) method
}// End of class DESController

/*
 * OUTPUT:
 * 
 * Plain Text: 00000001 00100011 01000101 01100111 10001001 10101011 11001101 11101111 
 * Cipher Text: 10000101 11101000 00010011 01010100 00001111 00001010 10110100 00000101 
 * Decrypted Text: 00000001 00100011 01000101 01100111 10001001 10101011 11001101 11101111
 * 
 */
