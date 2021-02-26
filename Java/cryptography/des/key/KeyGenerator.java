package des.key;

import des.general.GeneralMethods;

/**
 * Key Generation 
 * Description
 * 
 * 		class KeyGenerator is a public class which acts as the main logic body for key generation, KeyGenerator has many
 * 		public and private methods which functions interoperable with other methods to complete the whole key generation
 * 		process.
 * 
 */
public class KeyGenerator
{
	
	/**
	 * 
	 * 		This is a private method which is used to compress 64-bit original key to 56-bit
	 * 
	 * Description
	 * 
	 * 
	 * 		The original 64-bit key which is provided is compressed to 56-bit and returned in this method, the compression is
	 * 		completed with the help of table KEY_COMPRESS_64_TO_56, which is present in
	 * 		des.key.KeyGenerationModels.KEY_COMPRESS_64_TO_56.
	 * 
	 * 
	 * @param  key                       This is the 64-bit original key
	 * @param  keyCompressionTable64To56 This is the key compression table (64-bits to 56-bits)
	 * 
	 * @return                           byte[] This is compressed 56-bit key
	 */
	private byte[] compressKey64To56(byte[] key, byte[] keyCompressionTable64To56)
	{
		//used to store compressed 56-bit key
		byte[] keyOf56Bit = new byte[56];
		
		//iterates 56 times
		for (int i = 0; i < keyCompressionTable64To56.length; i++)
		{
			/*
			 * Each new element in 56-bit array is generated with the help of KEY_COMPRESS_64_TO_56 table, at each iteration the
			 * value of "KEY_COMPRESS_64_TO_56" at ith index is used as the index of "key" and the value which is retrieved from it
			 * is used as the element in 56-bit array.
			 */
			keyOf56Bit[i] = key[keyCompressionTable64To56[i] - 1];
		}
		//returning compressed 56-bit key
		return keyOf56Bit;
	}
	
	/**
	 * 
	 * 		Once original key of 64-bits is compressed to 56-bits, the compressed key is then divided into two parts each of
	 * 		28-bits, namely C and D, this method helps generating 16 C Keys.
	 * 
	 * Process
	 * 
	 * 
	 * 		First, the compressed 56-bit key is taken as input
	 * 		Then, C0 is generated which consists of first 28-bits of compressed 56-bit key
	 * 		
	 * 		Then, C1 - C16 are generated with the help of their preceding key, a left shift operation is also included in the
	 * 		process to generate new key, number of shifts to be done at each iteration is decided in table NUMBER_OF_SHIFTS which
	 * 		is present in des.key.KeyGenerationModels.NUMBER_OF_SHIFTS
	 * 		
	 * @param  key                 This is 56-bit original key
	 * @param  numberOfShiftsTable This is the table which decides number of shifts at each iteration
	 * 
	 * @return                     byte[][] These are 17 C keys each of 28-bits
	 */
	private byte[][] generateCKeys(byte[] key, byte[] numberOfShiftsTable)
	{
		//used to store 17 C keys (0-16)
		byte[][] cKeys = new byte[17][28];
		
		//iterates 28 times
		for (int i = 0; i < 28; i++)
		{
			if (i < 28)
			{
				//stores 0th original C key, the 0th key is only used by their proceeding keys, they are not used for encryption or decryption
				cKeys[0][i] = key[i];
			}
		}
		
		//created an object of GeneralMethods to access its methods
		GeneralMethods generalMethods = new GeneralMethods();
		
		//iterates 16 times
		for (int i = 1; i <= 16; i++)
		{
			//stores 28-bit shifted key
			cKeys[i] = generalMethods.shiftLeft(cKeys[i - 1], numberOfShiftsTable[i - 1]);
		}
		
		//returning 17 C Keys which are generated
		return cKeys;
	}
	
	/**
	 * 
	 * 		Once original key of 64-bits is compressed to 56-bits, the compressed key is then divided into two parts each of
	 * 		28-bits, namely C and D, this method helps generating 16 D Keys.
	 * 
	 * Process
	 * 
	 * 
	 * 		First, the compressed 56-bit key is taken as input
	 * 		Then, D0 is generated which consists of last 28-bits of compressed 56-bit key
	 * 		
	 *		Then, D1 - D16 are generated with the help of their preceding key, a left shift operation is also included in the
	 * 		process to generate new key, number of shifts to be done at each iteration is decided in table NUMBER_OF_SHIFTS which
	 * 		is present in des.key.KeyGenerationModels.NUMBER_OF_SHIFTS
	 * 
	 * @param  key                 This is 56-bit original key
	 * @param  numberOfShiftsTable This is the table which decides number of shifts at each iteration
	 * 
	 * @return                     byte[][] These are 17 D keys each of 28-bits
	 */
	private byte[][] generateDKeys(byte[] key, byte[] numberOfShiftsTable)
	{
		//used to store 17 D keys (0-16)
		byte[][] dKeys = new byte[17][28];
		
		//iterates 28 times
		for (int i = 0; i < 28; i++)
		{
			// stores 0th original D key, the 0th key is only used by their proceeding keys, they are not used for encryption or decryption
			dKeys[0][i] = key[i + 28];
		}
		
		//created an object of GeneralMethods to access its methods
		GeneralMethods generalMethods = new GeneralMethods();
		
		//iterates 16 times
		for (int i = 1; i <= 16; i++)
		{
			//stores 28-bit shifted key
			dKeys[i] = generalMethods.shiftLeft(dKeys[i - 1], numberOfShiftsTable[i - 1]);
		}
		//returning 17 C Keys which are generated
		return dKeys;
	}
	
	/**
	 * This is a private method which is used to concatenate 16 C and D keys(1-16) each of 28-bits into 56-bit key
	 * 
	 * @param  cKeys These are 17 C Keys each of 28-bits
	 * @param  dKeys These are 17 D Keys each of 28-bits
	 * 
	 * @return       byte[][] These are 16 concatenated keys each of 56-bits
	 */
	private byte[][] generateConcatenatedKey(byte[][] cKeys, byte[][] dKeys)
	{
		//used to store 16 keys each of 56-bits
		byte[][] concatenatedKey = new byte[16][56];
		
		//iterates 16 times
		for (int i = 1; i <= 16; i++)
		{
			//concatenates C keys to first 28 bits (0 - 27)
			for (int j = 0; j < 28; j++)
			{
				concatenatedKey[i - 1][j] = cKeys[i][j];
			}
			//concatenates D keys to last 28 bits (28 - 55)
			for (int j = 0; j < 28; j++)
			{
				concatenatedKey[i - 1][j + 28] = dKeys[i][j];
			}
		}
		//returning 16 concatenated keys each of 56-bits
		return concatenatedKey;
	}
	
	/**
	 * 
	 * 		This is a private method which is used to compress 56-bit key to 48-bit, the compression takes place with the help of
	 * 		table KEY_COMPRESS_56_TO_48 which is present in des.key.KeyGenerationModels.KEY_COMPRESS_56_TO_48
	 * 
	 * 
	 * @param  key                       This is a 56-bit key
	 * @param  keyCompressionTable56To48 This is the key compression table (56-bits to 48-bits)
	 * 
	 * @return                           byte[] This is a 48-bit compressed key
	 */
	private byte[] compressKey56To48(byte[] key, byte[] keyCompressionTable56To48)
	{
		//used to store 48-bit compressed key
		byte[] keyOf48Bit = new byte[48];
		
		//iterates 48 times
		for (int i = 0; i < keyCompressionTable56To48.length; i++)
		{
			/*
			 * Each new element in 48-bit array is generated with the help of KEY_COMPRESS_56_TO_48 table, at each iteration the
			 * value of "KEY_COMPRESS_56_TO_48" at ith index is used as the index of "key" and the value which is retrieved from it
			 * is used as the element in 48-bit array.
			 */
			keyOf48Bit[i] = key[keyCompressionTable56To48[i] - 1];
		}
		//returning 48-bit compressed key
		return keyOf48Bit;
	}
	
	/**
	 * This is a private method which is used to generate final set of compressed keys
	 * 
	 * @param  concatenatedKey           These are the concatenated C and D 16 keys each of 56-bit
	 * @param  keyCompressionTable56To48 This is the key compression table (56-bits to 48-bits)
	 * 
	 * @return                           byte[][] These are compressed 16 keys each of 48-bit
	 */
	private byte[][] generateFinalKeys(byte[][] concatenatedKey, byte[] keyCompressionTable56To48)
	{
		//used to store compressed 16 keys each of 48-bits
		byte[][] key = new byte[16][48];
		
		//iterates 16 times
		for (int i = 0; i < 16; i++)
		{
			//stores compressed key, invokes method compressKey56To48 to compress each key
			key[i] = compressKey56To48(concatenatedKey[i], keyCompressionTable56To48);
		}
		//returning 16 keys each of 48-bit
		return key;
	}
	
	/**
	 * This is a public method, which is used to generate 16 keys which would be used in encryption and decryption process
	 * Description
	 * 
	 * 		The method gerenateKey acts as the main logic to generate keys which will be used for encryption and
	 * 		decryption, the respective method consists of calling of substantial methods which would complete the
	 * 		whole module of key generation in Data Encryption Standard (DES) algorithm.
	 * 
	 * Process
	 * 
	 * 		First, the original 64-bit key is taken as input
	 * 		Then, the original 64-bit key is compressed to 56-bit key
	 * 		Then, the 56-bit key is divided into 2 parts namely C0 and D0 each of 28-bit
	 * 		Then, with the help of C0 and D0, another 16 keys are generated from C1 - C16 and D1 - D16
	 * 		
	 * 		Then, the generated 16 C and D keys are concatenated (0th key is counted as void, it is not used for encryption
	 * 		and decryption)
	 * 		
	 * 		Then, the 16 concatenated keys are compressed to 48-bit keys
	 * 		Then, the 16 compressed keys each of 48-bit are returned
	 * 
	 * @param  key                 This is original 64-bit key
	 * @param  keyGenerationModels This is a container of models which are used in key generation process
	 * 
	 * @return                     byte[][] These are 16 keys where each key consists 48-bit
	 */
	public byte[][] generateKey(byte[] key, KeyGenerationModels keyGenerationModels)
	{
		
		byte[]		compressedKey		= compressKey64To56(key, keyGenerationModels.getKEY_COMPRESS_64_TO_56());				// compressed from 64-bit to 56-bit
		byte[][]	cKeys			= generateCKeys(compressedKey, keyGenerationModels.getNUMBER_OF_SHIFTS());				// 17 C keys are generated (0 - 16)
		byte[][]	dKeys			= generateDKeys(compressedKey, keyGenerationModels.getNUMBER_OF_SHIFTS());				// 17 D keys are generated (0 - 16)
		byte[][]	concatenatedKey		= generateConcatenatedKey(cKeys, dKeys);												// last 16 C and D keys are concatenated (0th C and D
																															// keys are excluded)
		byte[][]	mainKey			= generateFinalKeys(concatenatedKey, keyGenerationModels.getKEY_COMPRESS_56_TO_48());			// the concatenated keys are then compressed to 48-bit
		
		//returning 48-bit compressed key
		return mainKey;
	}
}
