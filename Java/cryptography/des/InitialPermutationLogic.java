package des;

/**
 * Initial Permutation
 * 
 * 		class InitialPermutationLogic is a public class which acts as a logic class which helps to permute through initial
 * 		permutation
 * 
 */
public class InitialPermutationLogic
{
	/**
	 * 
	 * 		This is a public method which is used to permute value through initial permutation, this is done with the help of
	 * 		table INITIAL_PERMUTATION which is present in des.DESCryptographyModels.INITIAL_PERMUTATION
	 * 
	 * 
	 * @param  value                   This is a 64-bit value
	 * @param  initialPermutationTable This is the initial permutation table
	 * 
	 * @return                         byte[] This is 64-bit permuted value
	 */
	public byte[] initialPermutation(byte[] value, byte[] initialPermutationTable)
	{
		//created an array which will hold permuted value
		byte[] initialPermutation = new byte[64];
		
		//iterates 64 time
		for (int i = 0; i < initialPermutationTable.length; i++)
		{
			/*
			 * Each new element in 64-bit array is generated with the help of INITIAL_PERMUTATION table, at each iteration the value
			 * of "INITIAL_PERMUTATION" at ith index is used as the index of "value" and the value which is retrieved from it is
			 * used as the element in 64-bit array.
			 */
			initialPermutation[i] = value[initialPermutationTable[i] - 1];
		}
		//returning initial permuted value
		return initialPermutation;
	}
}
