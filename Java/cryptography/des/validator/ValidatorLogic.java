package des.validator;

import des.DESCryptographyModels;
import des.key.KeyGenerationModels;

/**
 * Validation Logic
 * 
 * 		class ValidatorLogic is a public class which acts as a main logic body for validation of
 * 		various models which are used in the algorithm.
 *
 */
public class ValidatorLogic
{
	/**
	 * This is a private method which is used to validate initial permutation table.
	 * 
	 * Validation Scheme
	 * 
	 * 		The table must not be empty
	 * 		The table must contain 64 elements
	 * 		Each element in the table must have an value between 1 to 64	
	 * 
	 * @param  initialPermutationTable This is the initial permutation table
	 * @return Boolean This is the flag which tells that the validation is successful or not
	 */
	private Boolean validateInitialPermutationTable(byte[] initialPermutationTable)
	{
		Boolean validationStatus = false;
		
		if (initialPermutationTable != null)
		{
			if (initialPermutationTable.length == 64)
			{
				for (int i = 0; i < initialPermutationTable.length; i++)
				{
					if (initialPermutationTable[i] >= 1 && initialPermutationTable[i] <= 64)
					{
						validationStatus = true;
					}
					else
					{
						validationStatus = false;
						break;
					}
				}
			}
		}
		return validationStatus;
	}
	
	/**
	 * This is a private method which is used to validate expansion table (32 to 48) table.
	 * 
	 * Validation Scheme
	 * 
	 * 		The table must not be empty
	 * 		The table must contain 48 elements
	 * 		Each element in the table must have an value between 1 to 32
	 * 
	 * 
	 * @param partitionExpand32To48Table This is the partition expansion table
	 * 
	 * @return Boolean This is the flag which tells that the validation is successful or not
	 */
	private Boolean validatePartitionExpansionTable32To48(byte[] partitionExpand32To48Table)
	{
		Boolean validationStatus = false;
		
		if (partitionExpand32To48Table != null)
		{
			if (partitionExpand32To48Table.length == 48)
			{
				for (int i = 0; i < partitionExpand32To48Table.length; i++)
				{
					if (partitionExpand32To48Table[i] >= 1 && partitionExpand32To48Table[i] <= 32)
					{
						validationStatus = true;
					}
					else
					{
						validationStatus = false;
						break;
					}
				}
			}
		}
		
		return validationStatus;
	}
	
	/**
	 * This is a private method which is used to validate S-BOX.
	 * 
	 * Validation Scheme
	 * 
	 * 		The table must not be empty
	 * 		The table must contain 8 elements, each element must have 64 elements
	 * 		Each element in the table must have an value between 0 to 15
	 * 
	 * @param sBox	   	This is the S-BOX
	 * @return Boolean	This is the flag which tells that the validation is successful or not
	 */
	private Boolean validateSBox(byte[][][] sBox)
	{
		Boolean validationStatus = false;
		
		if (sBox != null)
		{
			if (sBox.length == 8)
			{
				for (int i = 0; i < sBox.length; i++)
				{
					byte[][] subSBox = sBox[i];
					if (subSBox.length == 4)
					{
						for (int j = 0; j < subSBox.length; j++)
						{
							byte[] valueSBox = subSBox[j];
							if (valueSBox.length == 16)
							{
								for (int k = 0; k < valueSBox.length; k++)
								{
									if (valueSBox[k] >= 0 && valueSBox[k] <= 15)
									{
										validationStatus = true;
									}
									else
									{
										validationStatus = false;
										return validationStatus;
									}
								}
							}
							
						}
						
					}
				}
			}
		}
		return validationStatus;
	}
	
	/**
	 * This is a private method which is used to validate P-BOX.
	 * 
	 * Validation Scheme
	 * 
	 * 		The table must not be empty
	 * 		The table must contain 32 elements
	 * 		Each element in the table must have an value between 1 to 32	
	 *
	 * @param pBox	This is the P-BOX
	 * @return 		Boolean This is the flag which tells that the validation is successful or not
	 */
	private Boolean validatePBox(byte[] pBox)
	{
		Boolean validationStatus = false;
		if (pBox != null)
		{
			if (pBox.length == 32)
			{
				for (int i = 0; i < pBox.length; i++)
				{
					if (pBox[i] >= 1 && pBox[i] <= 32)
					{
						validationStatus = true;
					}
					else
					{
						validationStatus = false;
						break;
					}
				}
			}
		}
		return validationStatus;
	}
	
	/**
	 * This is a private method which is used to validate inverse initial permutation table.
	 * 
	 * Validation Scheme
	 * 
	 * 		The table must not be empty
	 * 		The table must contain 64 elements
	 * 		Each element in the table must have an value between 1 to 6
	 *  
	 * @param inverseInitialPermutationTable This is the inverse initial permutation table
	 * @return Boolean This is the flag which tells that the validation is successful or not
	 */
	private Boolean validateInverseInitialPermutationTable(byte[] inverseInitialPermutationTable)
	{
		Boolean validationStatus = false;
		
		if (inverseInitialPermutationTable != null)
		{
			if (inverseInitialPermutationTable.length == 64)
			{
				for (int i = 0; i < inverseInitialPermutationTable.length; i++)
				{
					if (inverseInitialPermutationTable[i] >= 1 && inverseInitialPermutationTable[i] <= 64)
					{
						validationStatus = true;
					}
					else
					{
						validationStatus = false;
						break;
					}
				}
			}
		}
		
		return validationStatus;
	}
	
	/**
	 * This is a private method which is used to validate key compression table (64 to 56) table.
	 * 
	 * Validation Scheme
	 * 
	 * 		The table must not be empty
	 * 		The table must contain 56 elements
	 * 		Each element in the table must have an value between 1 to 64
	 * 
	 * @param keyCompressionTable64To56 This is the key compression table (64 to 56)
	 * @return Boolean This is the flag which tells that the validation is successful or not
	 */
	private Boolean validateKeyCompressionTable64To56(byte[] keyCompressionTable64To56)
	{
		Boolean validationStatus = false;
		
		if (keyCompressionTable64To56 != null)
		{
			if (keyCompressionTable64To56.length == 56)
			{
				for (int i = 0; i < keyCompressionTable64To56.length; i++)
				{
					if (keyCompressionTable64To56[i] >= 1 && keyCompressionTable64To56[i] <= 64)
					{
						validationStatus = true;
					}
					else
					{
						validationStatus = false;
						break;
					}
				}
			}
		}
		
		return validationStatus;
	}
	
	/**
	 * This is a private method which is used to validate number of shifts table.
	 * 
	 * Validation Scheme
	 * 
	 * 		The table must not be empty
	 * 		The table must contain 16 elements
	 * 
	 * @param numberOfShiftsTable This is number of shifts table
	 * @return Boolean This is the flag which tells that the validation is successful or not
	 */
	private Boolean validateNumberOfShiftsTable(byte[] numberOfShiftsTable)
	{
		Boolean validationStatus = false;
		if (numberOfShiftsTable != null)
		{
			if (numberOfShiftsTable.length == 16)
			{
				validationStatus = true;
			}
		}
		return validationStatus;
	}
	
	/**
	 * This is a private method which is used to validate key compression table (56 to 48) table.
	 * 
	 * Validation Scheme
	 *
	 * 		The table must not be empty
	 * 		The table must contain 48 elements
	 * 		Each element in the table must have an value between 1 to 56
	 *  
	 * @param keyCompressionTable56To48 This is the key compression table (56 to 48)
	 * @return Boolean This is the flag which tells that the validation is successful or not
	 */
	private Boolean validateKeyCompressionTable56To48(byte[] keyCompressionTable56To48)
	{
		Boolean validationStatus = false;
		
		if (keyCompressionTable56To48 != null)
		{
			if (keyCompressionTable56To48.length == 48)
			{
				for (int i = 0; i < keyCompressionTable56To48.length; i++)
				{
					if (keyCompressionTable56To48[i] >= 1 && keyCompressionTable56To48[i] <= 56)
					{
						validationStatus = true;
					}
					else
					{
						validationStatus = false;
						break;
					}
				}
			}
		}
		
		return validationStatus;
	}
	
	/**
	 * This is a private method which is used to validate plain text.
	 * 
	 * Validation Scheme
	 * 
	 * 		The table must not be empty
	 * 		The table must contain 64 elements
	 * 		Each element in the table must have an value 1 or 0	
	 *  
	 * @param plainText This is the plain text
	 * @return Boolean This is the flag which tells that the validation is successful or not
	 */
	private Boolean validatePlainText(byte[] plainText)
	{
		Boolean validationStatus = false;
		
		if (plainText != null)
		{
			if (plainText.length == 64)
			{
				for (int i = 0; i < plainText.length; i++)
				{
					if (plainText[i] == 1 || plainText[i] == 0)
					{
						validationStatus = true;
					}
					else
					{
						validationStatus = false;
						break;
					}
				}
			}
		}
		
		return validationStatus;
	}
	
	/**
	 * This is a private method which is used to validate original key.
	 * 
	 * Validation Scheme
	 * 
	 * 		The table must not be empty
	 * 		The table must contain 64 elements
	 * 		Each element in the table must have an value 1 or 0
	 * 
	 * @param key This is the original key
	 * @return Boolean This is the flag which tells that the validation is successful or not
	 */
	private Boolean validateOriginalKey(byte[] key)
	{
		Boolean validationStatus = false;
		
		if (key != null)
		{
			if (key.length == 64)
			{
				for (int i = 0; i < key.length; i++)
				{
					if (key[i] == 1 || key[i] == 0)
					{
						validationStatus = true;
					}
					else
					{
						validationStatus = false;
						break;
					}
				}
			}
		}
		
		return validationStatus;
	}
	
	/**
	 * This is a private method which is used to validate cipher text.
	 * 
	 * Validation Scheme
	 * 
	 * 		The table must not be empty
	 * 		The table must contain 64 elements
	 * 		Each element in the table must have an value 1 or 0
	 * 
	 *  
	 * @param cipherText This is the cipher text
	 * @return Boolean This is the flag which tells that the validation is successful or not
	 */
	private Boolean validateCipherText(byte[] cipherText)
	{
		Boolean validationStatus = false;
		
		if (cipherText != null)
		{
			if (cipherText.length == 64)
			{
				for (int i = 0; i < cipherText.length; i++)
				{
					if (cipherText[i] == 1 || cipherText[i] == 0)
					{
						validationStatus = true;
					}
					else
					{
						validationStatus = false;
						break;
					}
				}
			}
		}
		
		return validationStatus;
	}
	
	// main validator
	/**
	 * 
	 * 		This is a public method which is used to validate models/tables/texts at the initial stage, before cipher text is calculated
	 * 		this method is used when plain text and key is passed to the encrypt.
	 * 
	 * List of models validated
	 * 
	 * 		Original Key
	 * 		Plain Text
	 * 		Key Compression (56 to 48)
	 * 		Number of Shifts
	 * 		Key Compression (64 to 56)
	 * 		Inverse Initial Permutation
	 * 		P-BOX
	 * 		S-BOX
	 * 		Expansion table (32 to 48)
	 * 		Initial permutation table
	 * 
	 * @param plainText				This is the plain text
	 * @param key					This is the original key	
	 * @param desCryptographyModels This contains many models which are used during encryption and decryption
	 * @param keyGenerationModels	This contains many models which are used during key generation
	 * @return						String error message, which indicates error in a particular model, if no such error found it is passed empty
	 */
	public String mainInitValidator(byte[] plainText, byte[] key, DESCryptographyModels desCryptographyModels, KeyGenerationModels keyGenerationModels)
	{
		StringBuilder validationString = new StringBuilder();
		
		Boolean	keyValidationStatus				= validateOriginalKey(key);
		Boolean	plainTextValidationStatus			= validatePlainText(plainText);
		Boolean	keyCompressionTable56To48ValidationStatus	= validateKeyCompressionTable56To48(keyGenerationModels.getKEY_COMPRESS_56_TO_48());
		Boolean	numberOfShiftsTableValidationStatus		= validateNumberOfShiftsTable(keyGenerationModels.getNUMBER_OF_SHIFTS());
		Boolean	keyCompressionTable64To56ValidationStatus	= validateKeyCompressionTable64To56(keyGenerationModels.getKEY_COMPRESS_64_TO_56());
		Boolean	inverseInitialPermutationTableValidationStatus	= validateInverseInitialPermutationTable(desCryptographyModels.getINVERSE_INITIAL_PERMUTATION());
		Boolean	pBoxValidationStatus				= validatePBox(desCryptographyModels.getP_BOX());
		Boolean	sBoxValidationStatus				= validateSBox(desCryptographyModels.getSBOX());
		Boolean	partitionExpansion32To48ValidationStatus	= validatePartitionExpansionTable32To48(desCryptographyModels.getPARTITION_EXPAND_32_TO_48());
		Boolean	initialPermutationTableValidationStatus		= validateInitialPermutationTable(desCryptographyModels.getINITIAL_PERMUTATION());
		
		if (!keyValidationStatus)
		{
			validationString.append("-> ORIGINAL KEY PROVIDED IS INVALID, PLEASE MODIFY AND RE-RUN\n");
		}
		if (!plainTextValidationStatus)
		{
			validationString.append("-> PLAIN TEXT PROVIDED IS INVALID, PLEASE MODIFY AND RE-RUN\n");
		}
		if (!keyCompressionTable56To48ValidationStatus)
		{
			validationString.append("-> KEY COMPRESSEION TABLE (56 to 48) PROVIDED IS INVALID, PLEASE MODIFY AND RE-RUN\n");
		}
		if (!numberOfShiftsTableValidationStatus)
		{
			validationString.append("-> NUMBER OF SHIFTS TABLE PROVIDED IS INVALID, PLEASE MODIFY AND RE-RUN\n");
		}
		if (!keyCompressionTable64To56ValidationStatus)
		{
			validationString.append("-> KEY COMPRESSEION TABLE (64 to 56) PROVIDED IS INVALID, PLEASE MODIFY AND RE-RUN\n");
		}
		if (!inverseInitialPermutationTableValidationStatus)
		{
			validationString.append("-> INVERSE INITIAL PERMUTATION TABLE PROVIDED IS INVALID, PLEASE MODIFY AND RE-RUN\n");
		}
		if (!pBoxValidationStatus)
		{
			validationString.append("-> P-BOX PROVIDED IS INVALID, PLEASE MODIFY AND RE-RUN\n");
		}
		if (!sBoxValidationStatus)
		{
			validationString.append("-> S-BOX PROVIDED IS INVALID, PLEASE MODIFY AND RE-RUN\n");
		}
		if (!partitionExpansion32To48ValidationStatus)
		{
			validationString.append("-> EXPANSION TABLE (32 to 48) PROVIDED IS INVALID, PLEASE MODIFY AND RE-RUN\n");
		}
		if (!initialPermutationTableValidationStatus)
		{
			validationString.append("-> INITIAL PERMUTATION TABLE PROVIDED IS INVALID, PLEASE MODIFY AND RE-RUN\n");
		}
		
		return validationString.toString();
	}
	
	/**
	 * This is a public method which is used to validate the cipher text given for decryption.
	 * 
	 * @param cipherText	This is the cipher text
	 * @return				String error message, which indicates error in a particular model, if no such error found it is passed empty
	 */
	public String cipherTextValidator(byte[] cipherText)
	{
		StringBuilder	validationString			= new StringBuilder();
		Boolean			cipherTextValidationStatus	= validateCipherText(cipherText);
		if (!cipherTextValidationStatus)
		{
			validationString.append("-> CIPHER TEXT PROVIDED IS INVALID, PLEASE MODIFY AND RE-RUN\n");
		}
		return validationString.toString();
	}
}
