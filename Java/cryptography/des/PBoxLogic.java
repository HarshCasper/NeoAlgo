package des;

/**
 * P-BOX
 * 
 * 		class PBoxLogic is a public class which acts as a logic class which helps to permute through P-BOX
 * 
 */
public class PBoxLogic
{
	/**
	 * 
	 * 		This is a public method which is used to permute value through P-BOX, this is done with the help of table P_BOX which
	 * 		is present in des.DESCryptographyModels.P_BOX
	 * 
	 * 
	 * @param  value     This is a 32-bit value
	 * @param  pBoxTable This is the P-BOX
	 * 
	 * @return           byte[] This is 32-bit permuted value
	 */
	public byte[] permuteByPBox(byte[] value, byte[] pBoxTable)
	{
		//created an array which will hold permuted value
		byte[] permutedByPBox = new byte[32];
		
		//iterates 32 time
		for (int i = 0; i < permutedByPBox.length; i++)
		{
			/*
			 * Each new element in 32-bit array is generated with the help of P_BOX table, at each iteration the value of "P_BOX" at
			 * ith index is used as the index of "value" and the value which is retrieved from it is used as the element in 64-bit
			 * array.
			 */
			permutedByPBox[i] = value[pBoxTable[i] - 1];
		}
		
		//returning P-BOX permuted value, it can
		return permutedByPBox;
	}
}
