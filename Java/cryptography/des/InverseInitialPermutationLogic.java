package des;

/**
 * Inverse Initial Permutation
 * 
 * 		class InverseInitialPermutationLogic is a public class which acts as a logic class which helps to permute through
 * 		inverse initial permutation
 * 
 */
public class InverseInitialPermutationLogic
{
	/**
	 * 
	 * 		This is a public method which is used to permute value through inverse initial permutation, this is done with the
	 * 		help of table INVERSE_INITIAL_PERMUTATION which is present in des.DESCryptographyModels.INVERSE_INITIAL_PERMUTATION
	 * 
	 * 
	 * @param  value                          This is a 64-bit value
	 * @param  inverseInitialPermutationTable This is the inverse initial permutation table
	 * 
	 * @return                                byte[] This is 64-bit permuted value
	 */
	public byte[] inverseInitialPermutation(byte[] value, byte[] inverseInitialPermutationTable)
	{
		//created an array which will hold permuted value
		byte[] inverseInitialPermutation = new byte[64];
		
		//iterates 64 time
		for (int i = 0; i < 64; i++)
		{
			/*
			 * Each new element in 64-bit array is generated with the help of INVERSE_INITIAL_PERMUTATION table, at each iteration
			 * the value of "INVERSE_INITIAL_PERMUTATION" at ith index is used as the index of "value" and the value which is
			 * retrieved from it is used as the element in 64-bit array.
			 */
			inverseInitialPermutation[i] = value[inverseInitialPermutationTable[i] - 1];
		}
		
		//returning inverse initial permuted value
		return inverseInitialPermutation;
	}
}
