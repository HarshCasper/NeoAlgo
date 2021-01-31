package des;

import des.exception.ValidationException;
import des.general.GeneralMethods;
import des.key.KeyGenerationModels;
import des.key.KeyGenerator;
import des.validator.ValidatorLogic;

/**
 * <h1>Data Encryption Standard</h1> 
 * <b>Description</b>
 * <p>
 * 		class DESCryptographyLogic is a public class which acts as the main logic body, DESCryptographyLogic has many public
 * 		and private methods which functions interoperable with other methods to complete the whole algorithm.
 * </p>
 *
 */
public class DESCryptographyLogic
{
	/**
	 * <p>
	 * 		This is a private method which is used to generate left partition of initial permuted text
	 * </p>
	 * <b>Description</b>
	 * <p>
	 * 		Once the initial permutation is completed the 64-bit permuted text is needed to be divided in 2 parts, the current
	 * 		method helps in generating left part of the respective which is of 32-bits.
	 * </p>
	 * 
	 * @param  initialPermutationText This is the initial permuted text of 64-bits
	 * 
	 * @return                        byte[] This is left partition of initial permuted text
	 */
	private byte[] generateLeftPartition(byte[] initialPermutationText)
	{
		/*
		 * Total 17 left partitions are to be made(0 - 16), 0th is the original partition, the 0th partition is not used for
		 * encryption or decryption, the only use of the original partition(0th) is to help the preceding partition generate their
		 * values, only the 0th partition is generated in this method because the rest partitions are needed to be encrypted or
		 * decrypted with key and other necessary modules in algorithm.
		 */
		byte[] leftPartition = new byte[32];//used to store the 32-bit left partition
		
		// generating left partition, first 32-bits of initial permuted text
		for (int i = 0; i < 32; i++)
		{
			leftPartition[i] = initialPermutationText[i];
		}
		//returning generated left partition
		return leftPartition;
	}//End of generateLeftPartition(byte[]) method
	
	/**
	 * <p>
	 * 		This is a private method which is used to generate right partition of initial permuted text
	 * </p>
	 * <b>Description</b>
	 * <p>
	 * 		Once the initial permutation is completed the 64-bit permuted text is needed to be divided in 2 parts, the current
	 * 		method helps in generating right part of the respective which is of 32-bits.
	 * </p>
	 * 
	 * @param  initialPermutationText This is the initial permuted text of 64-bits
	 * 
	 * @return                        byte[] This is right partition of initial permuted text
	 */
	private byte[] generateRightPartition(byte[] initialPermutationText)
	{
		/*
		 * Total 17 left partitions are to be made(0 - 16), 0th is the original partition, the 0th partition is not used for
		 * encryption or decryption, the only use of the original partition(0th) is to help the preceding partition generate their
		 * values, only the 0th partition is generated in this method because the rest partitions are needed to be encrypted or
		 * decrypted with key and other necessary modules in algorithm.
		 */
		byte[] rightPartition = new byte[32];//used to store right partition of 32-biits
		
		//generating right partition, last 32-bits of initial permuted text
		for (int i = 0; i < 32; i++)
		{
			rightPartition[i] = initialPermutationText[i+32];
		}
		//returning generated right partition
		return rightPartition;
	}//End of generateRightPartition(byte[]) method
	
	/**
	 * <p>
	 * 		This is a private method which is used to expand the created partitions from 32-bits to 48-bits
	 * </p>
	 * <b>Description</b>
	 * <p>
	 *		Once the partitions are been created they are needed to be expanded from 32-bit to 48-bit text, this is done with the
	 * 		help of "PARTITION_EXPAND_32_TO_48" table which is also called as "E BIT-SELECTION TABLE". The expansion is done of
	 * 		the right partition as the key is of 48-bits and the right partition is needed to be XORed with the key in upcoming
	 * 		modules of the respective algorithm.
	 * </p>
	 * 
	 * @param  partition                  This is 32-bit partition (right partition)
	 * 
	 * @param  partitionExpand32To48Table This is an expansion table which expands size of text bits from 32 to 48-bit
	 * 
	 * @return                            byte[] This is the expanded 48-bit partition text
	 */
	private byte[] expandPartician32To48(byte[] partition, byte[] partitionExpand32To48Table)
	{
		//initializes 48-bit partition array
		byte[] expandedPartition = new byte[48];
		
		//iterates 48 times
		for (int i = 0; i < 48; i++)
		{
			/*
			 * Each new element in 48-bit array is generated with the help of PARTITION_EXPAND_32_TO_48 table, at each iteration the
			 * value of "PARTITION_EXPAND_32_TO_48" at ith index is used as the index of "partition" and the value which is
			 * retrieved from it is then used as the element in 48-bit array.
			 */
			expandedPartition[i] = partition[partitionExpand32To48Table[i] - 1];
		}
		//returning generated 48-bit partition
		return expandedPartition;
	}//End of expandPartician32To48(byte[],byte[]) method
	
	/**
	 * <p>
	 * 		This is a private method which is used as a main entity in DES algorithm, this method is used for encryption and
	 * 		decryption both
	 * </p>
	 * <b>Description</b>
	 * <p>
	 * 		This method plays an important role in DES algorithm, this method is used for both encryption and decryption, there
	 * 		are many phases/steps which are performed in this method which fulfills the need of the respective algorithm, this
	 * 		method or module in DES is also called as "function f".
	 * </p>
	 * <b>Process</b>
	 * <p>
	 * 		This method is called 16 times while performing encryption and decryption.
	 * </p>
	 * <ul>
	 * 		<li>First, right partition and key of the respective iteration is taken</li>
	 * 		<li>Then, the right partition which is of 32-bits is expanded to 48-bits</li>
	 * 		<li>Then, XOR operation is performed between the expanded 48-bit right partition and key</li>
	 * 		<li>Then, the 48-bit resulting XOR is divided into 8 parts each part consists of 6-bits</li>
	 * 		<li>Then, every 8 parts are compressed to 4-bits from 6-bits using S-BOX
	 * 			<ul>
	 * 				<li>There are total 8 S-BOXES for each part one S-BOX, each S-BOX consists of 16 columns and 4 rows</li>
	 * 				<li>
	 * 					The first and last bit of the respective part are taken and converted to decimal number, this becomes the row
	 * 					number
	 * 				</li>
	 * 				<li>
	 * 					The middle 4 bits of the respective part are taken and converted to decimal number, this becomes the column
	 * 					number
	 * 				</li>
	 * 				<li>The row and column number are mapped with respective S-BOX and value at that particular index is taken</li>
	 * 				<li>The value which is retrieved from S-BOX is then converted to a 4-bit binary number</li>
	 * 				<li>That 4-bit binary number is then used as the bits in the respective part</li>
	 * 			</ul>
	 * 		</li>
	 * 		<li>
	 * 			After the 8 parts of 6 bits are compressed to 8 parts of 4 bits, they are concatenated which makes it total
	 * 			32-bit
	 * 		</li>
	 * 		<li>The concatenated bits are then permuted through P-BOX</li>
	 * 		<li>The permuted value is then returned</li>
	 * </ul>
	 * 
	 * @param  rightPartician        This is 32-bit right partition
	 * @param  key                   This is 48-bit key
	 * @param  desCryptographyModels This contains many models which are used during encryption and decryption
	 * 
	 * @return                       byte[] This is compressed 32-bit value
	 */
	private byte[] functionF(byte[] rightPartician, byte[] key, DESCryptographyModels desCryptographyModels)
	{
		//used to access general methods which are required for execution of algorithm
		GeneralMethods	generalMethods				= new GeneralMethods();						
		//stores expanded 48-bit right partition
		byte[]			expandedPartition			= expandPartician32To48(rightPartician, desCryptographyModels.getPARTITION_EXPAND_32_TO_48());
		//stores XORed value of key and 48-bit right partition
		byte[]			keyAndPartitionXor			= generalMethods.xorArray(expandedPartition, key);		
		//initializing array to store value of keyAndPartitionXor in 8 parts
		byte[][]		dividedKeyAndPartitionXor	= new byte[8][6];																				
		
		Integer	firstIndex	= 0;	// used to keep counter of 8 parts
		Integer	secondIndex	= 0;	// used to keep counter of 6-bits in each part
		
		//iterates 48 times
		for (int i = 0; i < keyAndPartitionXor.length; i++)
		{
			//if secondIndex exceeds 6th index then switch to preceding part and reset secondIndex
			if (secondIndex >= 6)
			{
				//switches to preceding part
				firstIndex++;
				//resets secondIndex
				secondIndex = 0;
			}
			//stores value in dividedKeyAndPartitionXor incrementally
			dividedKeyAndPartitionXor[firstIndex][secondIndex] = keyAndPartitionXor[i];
			//updates bit index number each iteration
			secondIndex++;
		}
		
		byte[][] compressedKeyAndPartition = new byte[8][4]; // initializing array to store compressed value which is to be generated from S-BOX
		
		SBoxLogic sbox = new SBoxLogic(); //initializing sbox, this will help to access compression methods of S-BOX
		
		//iterates through 8 parts
		for (int i = 0; i < 8; i++)
		{
			//compresses each part from 6-bits to 4-bits
			compressedKeyAndPartition[i] = sbox.compressBySBox(dividedKeyAndPartitionXor[i], i, desCryptographyModels.getSBOX());
		}
		
		//concatenates all the 8-parts together having a total of 32-bits
		byte[] compressedValueBySBox = sbox.concatenateSBoxValues(compressedKeyAndPartition);
		
		PBoxLogic pbox = new PBoxLogic(); //initializing pbox, this will help to access permutation methods of P-BOX
		
		//stores permuted value
		byte[] permutedValueByPBox = pbox.permuteByPBox(compressedValueBySBox, desCryptographyModels.getP_BOX());
		
		//returning permuted value
		return permutedValueByPBox;
	}// End of functionF(byte[],byte[],DESCryptographyModels) method
	
	/**
	 * <p>
	 * 		This is a private method which is used to generate pre-inverse initial permutation value
	 * </p>
	 * <b>Description</b>
	 * <p>
	 * 		Before proceeding to inverse initial permutation a final step needs to be completed, to generate this value the
	 * 		requirement is that we have generated R16 and L16 (17th right partition and 17th left partition, (0-16)), to
	 * 		concatenate both partitions, we first need to add 32-bits of right partition in first 32-bits of concatenated value,
	 * 		then 32-bits of left partition to last 32-bits of concatenated value.
	 * </p>
	 * 
	 * @param  leftPartition  This is 32-bit left partition L16
	 * @param  rightPartition This is 32-bit right partition R16
	 * 
	 * @return                byte[] This is 64-bits concatenated output(R16L16)
	 */
	private byte[] generatePreInverseInitialPermutationText(byte[] leftPartition, byte[] rightPartition)
	{
		//used to store pre-inverse initial permutation value it is of 64-bits
		byte[] finalValue = new byte[64];
		
		//iterates 64 times
		for (int i = 0; i < finalValue.length; i++)
		{
			//stores right partition in first 32-bits of finalValue
			if (i >= 0 && i <= 31)
			{
				finalValue[i] = rightPartition[i];
			}
			//stores left partition in last 32-bits of finalValue
			else
			{
				finalValue[i] = leftPartition[i - 32];
			}
		}
		//returning pre-inverse initial permuted value
		return finalValue;
	}// End of generatePreInverseInitialPermutationText(byte[],byte[]) method
	
	/**
	 * <p>
	 * 		This is a public method which is used to encrypt 64-bit plain text using Data Encryption Standard Algorithm
	 * </p>
	 * <b>Description</b>
	 * <p>
	 * 		In encryption process there are many modules involved:
	 * </p>
	 * <ul>
	 * 		<li>First, 64-bit plain text and original 64-bit key are taken</li>
	 * 		<li>Then, initial permutation is performed on the plain text</li>
	 * 		<li>Then, the permuted value is divided into two parts 32-bits each, which creates L0R0</li>
	 * 		<li>Then, 16 keys each of 48-bits are calculated</li>
	 * 		<li>Then, from L1R1 to L16R16 are calculated
	 * 			<ul>
	 * 				<li>L(n) = R(n-1)</li>
	 * 				<li>R(n) = L(n-1) ^ {@link #functionF(byte[], byte[], DESCryptographyModels) f}( R(n-1) , K(n) )</li>
	 * 			</ul>
	 * 		</li>
	 * 		<li>Then, final value is calculated by concatenating R16 and L16</li>
	 * 		<li>Then, the final value is permuted through inverse initial permutation</li>
	 * 		<li>Then, the permuted value is returned</li>
	 * </ul>
	 * 
	 * @param  plainText             This is 64-bit plain text
	 * @param  key                   This is 64-bit original key
	 * @param  desCryptographyModels This contains many models which are used during encryption and decryption
	 * @param  keyGenerationModels   This contains many models which are used during key generation
	 * 
	 * @return                       byte[] This is 64-bit cipher text
	 * 
	 * @throws ValidationException	 If any model has anything erroneous
	 */
	public byte[] encrypt(byte[] plainText, byte[] key, DESCryptographyModels desCryptographyModels, KeyGenerationModels keyGenerationModels) throws ValidationException
	{
		//used to access validation methods
		ValidatorLogic validate = new ValidatorLogic();
		//calling for applying validation checks on every models which will be used further
		String validationString = validate.mainInitValidator(plainText, key, desCryptographyModels, keyGenerationModels);
		//if the validationString is not empty means that an error has occurred
		if (!validationString.isEmpty())
		{
			//ValidationException is thrown to main and encryption process stops
			throw new ValidationException(validationString);
		}
		
		//initializing initialPermutation to access it methods
		InitialPermutationLogic	initialPermutation		= new InitialPermutationLogic();	
		//applying initial permutation
		byte[]					initialPermutationText	= initialPermutation.initialPermutation(plainText, desCryptographyModels.getINITIAL_PERMUTATION());	
		
		byte[][]				leftPartition			= new byte[17][32]; 		//used to store 17 left partitions each of 32-bits									
		byte[][]				rightPartition			= new byte[17][32];			//used to store 17 right partitions each of 32-bits
		
		//generating L0
		leftPartition[0]=generateLeftPartition(initialPermutationText);	
		//generating R0
		rightPartition[0]=generateRightPartition(initialPermutationText);		
		
		
		//generating 16 keys each of 48-bits
		byte[][] keys = new KeyGenerator().generateKey(key, keyGenerationModels);
		
		//initializing generalMethods to access general methods link conversion methods (decimal to binary, binary to decimal, xor of array, etc)
		GeneralMethods generalMethods = new GeneralMethods();
		
		//iterating 16 times
		for (int i = 1; i <= 16; i++)
		{
			// L(n) = R(n-1)
			leftPartition[i] = rightPartition[i - 1];
			// R(n) = L(n-1) ^ f( R(n-1) , K(n) )
			// keys[i-1] is taken as loop start from 1
			rightPartition[i] = generalMethods.xorArray(leftPartition[i - 1], functionF(rightPartition[i - 1], keys[i - 1], desCryptographyModels));
		}
		
		//final value is calculated by concatenating R16L16
		byte[] finalValue = generatePreInverseInitialPermutationText(leftPartition[16], rightPartition[16]);
		
		//initialized inverseInitialPermutation to access method for applying inverse initial permutation
		InverseInitialPermutationLogic inverseInitialPermutation = new InverseInitialPermutationLogic();
		
		//cipher text is the inverse initial permuted value
		byte[] cipherText = inverseInitialPermutation.inverseInitialPermutation(finalValue, desCryptographyModels.getINVERSE_INITIAL_PERMUTATION());
		
		//returning cipher text
		return cipherText;
	}// End of encrypt(byte[],byte[],DESCryptographyModels,KeyGenerationModels) method
	
	/**
	 * <p>
	 * 		This is a public method which is used to decrypt 64-bit cipher text using Data Encryption Standard Algorithm
	 * </p>
	 * <b>Description</b>
	 * <p>
	 * 		In decryption process there are many modules involved, the decryption process is same as the encryption process
	 * 		except that the keys are used in descending order(16-1):
	 * </p>
	 * <ul>
	 * 		<li>First, 64-bit cipher text and original 64-bit key are taken</li>
	 * 		<li>Then, initial permutation is performed on the cipher text</li>
	 * 		<li>Then, the permuted value is divided into two parts 32-bits each, which creates L0R0</li>
	 * 		<li>Then, 16 keys each of 48-bits are calculated</li>
	 * 		<li>Then, from L1R1 to L16R16 are calculated
	 * 			<ul>
	 * 				<li>L(n) = R(n-1)</li>
	 * 				<li>R(n) = L(n-1) ^ {@link #functionF(byte[], byte[], DESCryptographyModels) f}( R(n-1) , K(16-n) )</li>
	 * 			</ul>
	 * 		</li>
	 *		<li>Then, final value is calculated by concatenating R16 and L16</li>
	 * 		<li>Then, the final value is permuted through inverse initial permutation</li>
	 * 		<li>Then, the permuted value is returned</li>
	 * </ul>
	 * 
	 * @param  cipherText            This is 64-bit cipher text
	 * @param  key                   This is 64-bit original key
	 * @param  desCryptographyModels This contains many models which are used during encryption and decryption
	 * @param  keyGenerationModels	 This contains many models which are used during key generation
	 * 
	 * @return                       This is 64-bit plain text
	 * 
	 * @throws ValidationException	 If any model has anything erroneous
	 */
	public byte[] decrypt(byte[] cipherText, byte[] key, DESCryptographyModels desCryptographyModels, KeyGenerationModels keyGenerationModels) throws ValidationException
	{
		//used to access validation methods
		ValidatorLogic validate = new ValidatorLogic();
		//calling for applying validation checks on every models which will be used further
		String validationString = validate.mainInitValidator(cipherText, key, desCryptographyModels, keyGenerationModels);
		//if the validationString is not empty means that an error has occurred
		if (!validationString.isEmpty())
		{
			//ValidationException is thrown to main and decryption process stops
			throw new ValidationException(validationString);
		}
		
		//initializing initialPermutation to access it methods
		InitialPermutationLogic	initialPermutation		= new InitialPermutationLogic();	
		//applying initial permutation
		byte[]					initialPermutationText	= initialPermutation.initialPermutation(cipherText, desCryptographyModels.getINITIAL_PERMUTATION());	
		
		byte[][]				leftPartition			= new byte[17][32]; 		//used to store 17 left partitions each of 32-bits									
		byte[][]				rightPartition			= new byte[17][32];			//used to store 17 right partitions each of 32-bits
		
		//generating L0
		leftPartition[0]=generateLeftPartition(initialPermutationText);	
		//generating R0
		rightPartition[0]=generateRightPartition(initialPermutationText);		
		
		
		//generating 16 keys each of 48-bits
		byte[][] keys = new KeyGenerator().generateKey(key, keyGenerationModels);
		
		//initializing generalMethods to access general methods link conversion methods (decimal to binary, binary to decimal, xor of array, etc)
		GeneralMethods generalMethods = new GeneralMethods();
		
		//iterating 16 times
		for (int i = 1; i <= 16; i++)
		{
			// L(n) = R(n-1)
			leftPartition[i] = rightPartition[i - 1];
			// R(n) = L(n-1) ^ f( R(n-1) , K(16-n) )
			rightPartition[i] = generalMethods.xorArray(leftPartition[i - 1], functionF(rightPartition[i - 1], keys[16 - i], desCryptographyModels));
		}
		
		//final value is calculated by concatenating R16L16
		byte[] finalValue = generatePreInverseInitialPermutationText(leftPartition[16], rightPartition[16]);
		
		//initialized inverseInitialPermutation to access method from applying inverse initial permutation
		InverseInitialPermutationLogic inverseInitialPermutation = new InverseInitialPermutationLogic();
		//plain text is the inverse initial permuted value
		byte[] plainText = inverseInitialPermutation.inverseInitialPermutation(finalValue, desCryptographyModels.getINVERSE_INITIAL_PERMUTATION());
		
		//returning plain text
		return plainText;
	}// End of decrypt(byte[],byte[],DESCryptographyModels,KeyGenerationModels) method
}// End of class DESCryptographyLogic
