package des.validator;

import des.DESCryptographyModels;
import des.key.KeyGenerationModels;

/**
 * <h1>Validation Logic</h1>
 * <p>
 * 		class ValidatorLogic is a public class which acts as a main logic body for validation of
 * 		various models which are used in the algorithm.
 *</p>
 */
public class ValidatorLogic
{
	/**
	 * <p>
	 * 		This is a private method which is used to validate initial permutation table.
	 * </p>
	 * <b>Validation Scheme</b>
	 * <ul>
	 * 		<li>The table must not be empty</li>
	 * 		<li>The table must contain 64 elements</li>
	 * 		<li>Each element in the table must have an value between 1 to 64</li>	
	 * </ul>
	 * 
	 * 
	 * @param  initialPermutationTable 	This is the initial permutation table
	 * @return 							Boolean This is the flag which tells that the validation is successful or not
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
	}// End of validateInitialPermutationTable(byte[]) method
	
	/**
	 * <p>
	 * 		This is a private method which is used to validate expansion table (32 to 48) table.
	 * </p>
	 * <b>Validation Scheme</b>
	 * <ul>
	 * 		<li>The table must not be empty</li>
	 * 		<li>The table must contain 48 elements</li>
	 * 		<li>Each element in the table must have an value between 1 to 32</li>	
	 * </ul>
	 * 
	 * @param partitionExpand32To48Table 	This is the partition expansion table (32-bit to 48-bit)
	 * 
	 * @return 								Boolean This is the flag which tells that the validation is successful or not
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
	}// End of validatePartitionExpansionTable32To48(byte[]) method
	
	/**
	 * <p>
	 * 		This is a private method which is used to validate S-BOX.
	 * </p>
	 * <b>Validation Scheme</b>
	 * <ul>
	 * 		<li>The table must not be empty</li>
	 * 		<li>The table must contain 8 elements, each element must have 64 elements</li>
	 * 		<li>Each element in the table must have an value between 0 to 15</li>	
	 * </ul>
	 * 
	 * @param sBox	   	This is the S-BOX
	 * @return 			Boolean	This is the flag which tells that the validation is successful or not
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
	}// End of validateSBox(byte[][][]) method
	
	/**
	 * <p>
	 * 		This is a private method which is used to validate P-BOX.
	 * </p>
	 * <b>Validation Scheme</b>
	 * <ul>
	 * 		<li>The table must not be empty</li>
	 * 		<li>The table must contain 32 elements</li>
	 * 		<li>Each element in the table must have an value between 1 to 32</li>	
	 * </ul>
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
	}// End of validatePBox(byte[]) method
	
	/**
	 * <p>
	 * 		This is a private method which is used to validate inverse initial permutation table.
	 * </p>
	 * <b>Validation Scheme</b>
	 * <ul>
	 * 		<li>The table must not be empty</li>
	 * 		<li>The table must contain 64 elements</li>
	 * 		<li>Each element in the table must have an value between 1 to 64</li>	
	 * </ul>
	 *  
	 * @param inverseInitialPermutationTable 	This is the inverse initial permutation table
	 * @return 									Boolean This is the flag which tells that the validation is successful or not
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
	}// End of validateInverseInitialPermutationTable(byte[]) method
	
	/**
	 * <p>
	 * 		This is a private method which is used to validate key compression table (64 to 56) table.
	 * </p>
	 * <b>Validation Scheme</b>
	 * <ul>
	 * 		<li>The table must not be empty</li>
	 * 		<li>The table must contain 56 elements</li>
	 * 		<li>Each element in the table must have an value between 1 to 64</li>	
	 * </ul>
	 *  
	 * @param keyCompressionTable64To56 This is the key compression table (64-bit to 56-bit)
	 * @return 							Boolean This is the flag which tells that the validation is successful or not
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
	}// End of validateKeyCompressionTable64To56(byte[]) method
	
	/**
	 * <p>
	 * 		This is a private method which is used to validate number of shifts table.
	 * </p>
	 * <b>Validation Scheme</b>
	 * <ul>
	 * 		<li>The table must not be empty</li>
	 * 		<li>The table must contain 16 elements</li>	
	 * </ul> 
	 * 
	 * @param numberOfShiftsTable 	This is number of shifts table
	 * @return 						Boolean This is the flag which tells that the validation is successful or not
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
	}// End of validateNumberOfShiftsTable(byte[]) method
	
	/**
	 * <p>
	 * 		This is a private method which is used to validate key compression table (56-bit to 48-bit) table.
	 * </p>
	 * <b>Validation Scheme</b>
	 * <ul>
	 * 		<li>The table must not be empty</li>
	 * 		<li>The table must contain 48 elements</li>
	 * 		<li>Each element in the table must have an value between 1 to 56</li>	
	 * </ul>
	 *  
	 * @param keyCompressionTable56To48 This is the key compression table (56-bit to 48-bit)
	 * @return 							Boolean This is the flag which tells that the validation is successful or not
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
	}// End of validateKeyCompressionTable56To48(byte[]) method
	
	/**
	 * <p>
	 * 		This is a private method which is used to validate plain text.
	 * </p>
	 * <b>Validation Scheme</b>
	 * <ul>
	 * 		<li>The table must not be empty</li>
	 * 		<li>The table must contain 64 elements</li>
	 * 		<li>Each element in the table must have an value 1 or 0</li>	
	 * </ul>
	 *  
	 * @param plainText This is the plain text
	 * @return 			Boolean This is the flag which tells that the validation is successful or not
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
	}// End of validatePlainText(byte[]) method
	
	/**
	 * <p>
	 * 		This is a private method which is used to validate original key.
	 * </p>
	 * <b>Validation Scheme</b>
	 * <ul>
	 * 		<li>The table must not be empty</li>
	 * 		<li>The table must contain 64 elements</li>
	 * 		<li>Each element in the table must have an value 1 or 0</li>	
	 * </ul>
	 * 
	 * @param key 	This is the original key
	 * @return 		Boolean This is the flag which tells that the validation is successful or not
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
	}// End of validateOriginalKey(byte[]) method
	
	/**
	 * <p>
	 * 		This is a private method which is used to validate cipher text.
	 * </p>
	 * <b>Validation Scheme</b>
	 * <ul>
	 * 		<li>The table must not be empty</li>
	 * 		<li>The table must contain 64 elements</li>
	 * 		<li>Each element in the table must have an value 1 or 0</li>	
	 * </ul>
	 *  
	 * @param cipherText 	This is the cipher text
	 * @return 				Boolean This is the flag which tells that the validation is successful or not
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
	}// End of validateCipherText(byte[]) method
	
	// main validator
	/**
	 * <p>
	 * 		This is a public method which is used to validate models/tables/texts at the initial stage, before cipher text is calculated
	 * 		this method is used when plain text and key is passed to the encrypt method.
	 * </p>
	 * <b>List of models validated</b>
	 * <ul>
	 * 		<li>Original Key</li>
	 * 		<li>Plain Text</li>
	 * 		<li>Key Compression (56 to 48)</li>
	 * 		<li>Number of Shifts</li>
	 * 		<li>Key Compression (64 to 56)</li>
	 * 		<li>Inverse Initial Permutation</li>
	 * 		<li>P-BOX</li>
	 * 		<li>S-BOX</li>
	 * 		<li>Expansion table (32 to 48)</li>
	 * 		<li>Initial permutation table</li>
	 * </ul>
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
	}// End of mainInitValidator(byte[],byte[],DESCryptographyModels,KeyGenerationModels) method
	
	/**
	 * <p>
	 * 		This is a public method which is used to validate the cipher text given for decryption.
	 * </p>
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
	}// End of cipherTextValidator(byte[]) method
}// End of class ValidatorLogic
