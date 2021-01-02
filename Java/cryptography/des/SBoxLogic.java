package des;

import des.general.GeneralMethods;

/**
 * <h1>S-BOX</h1>
 * <p>
 * 		class SBoxLogic is a public class which acts as a logic class which helps to compress value through S-BOX
 * </p>
 */
public class SBoxLogic
{
	/**
	 * <p>
	 * 		This is a public method which is used to compress value through S-BOX, this is done with the help of
	 *		table S_BOX which is present in des.DESCryptographyModels.S_BOX
	 * </p>
	 * <b>Process</b>
	 * <ul>
	 * 		<li>First, a 6-bit value is taken with its respective index position (0-7)</li>
	 * 		<li>
	 * 			The first and last bit of the respective part are taken and converted to decimal number, this becomes the row
	 * 			number
	 * 		</li>
	 * 		<li>
	 * 			The middle 4 bits of the respective part are taken and converted to decimal number, this becomes the column
	 * 			number
	 * 		</li>
	 * 		<li>
	 * 			The row and column number are mapped with respective S-BOX and value at that particular index(row,column) is
	 * 			taken
	 * 		</li>
	 * 		<li>The value which is retrieved from S-BOX is then converted to a 4-bit binary number</li>
	 * 		<li>That 4-bits are then returned as a resultant compressed value</li>
	 * </ul>
	 * 
	 * @param  value     This is the 6-bit value
	 * @param  index     This is the index which lies between 0-7
	 * @param  sBoxTable These are 8 S-BOXes
	 * 
	 * @return           byte[] This is 4-bit compressed value
	 */
	public byte[] compressBySBox(byte[] value, Integer index, byte[][][] sBoxTable)
	{
		//an array is created to store the final compressed value
		byte[] compressedValue = new byte[4];
		
		/*
		 * StringBuilder is used because, it makes a mutable sequence of characters, due to appending of each bit character in
		 * rowIndexBinary and columnIndexBinary, if we use String then it could cause creation of many immutable objects, so to
		 * make the code more efficient, StringBuilder is used.
		 */
		StringBuilder	rowIndexBinary		= new StringBuilder("");	// used to store binary row index
		StringBuilder	columnIndexBinary	= new StringBuilder("");	// used to store binary column index
		
		//iterates 6 times
		for (int i = 0; i < value.length; i++)
		{
			//when i reaches 1st or last index, the character at the respective index is appended to rowIndexBinary
			if (i == 0 || i == value.length - 1)
			{
				rowIndexBinary.append(value[i]);
			}
			//otherwise the character at the respective index is appended to columnIndexBinary
			else
			{
				columnIndexBinary.append(value[i]);
			}
		}
		
		//used to access general methods which are required for execution of algorithm
		GeneralMethods generalMethods = new GeneralMethods(); 
		
		Integer	rowIndexDecimal		= generalMethods.convertBinaryToDecimal(rowIndexBinary.toString());		//used to store decimal row index value
		Integer	columnIndexDecimal	= generalMethods.convertBinaryToDecimal(columnIndexBinary.toString());	//used to store decimal column index value
		
		byte compressedDecimalValue = 0; // used to store the value which will be fetched from S_BOX
		
		/*
		 * The new element is generated with the help of S_BOX table, the value of "SBOX" at index(0-7) index,
		 * rowIndexDecimal(0-3) row and columnIndexDecimal(0-15) column is fetched as the compressed value and stored in
		 * compressedDecimalValue as a decimal value
		 */
		compressedDecimalValue = sBoxTable[index][rowIndexDecimal][columnIndexDecimal];
		
		//the compressed value is then converted to 4-bit binary String
		String compressedBinaryValueString = generalMethods.convertDecimalToBinary((int) compressedDecimalValue);
		
		//the binary string is converted to array of size 4
		//iterates 4 times
		for (int i = 0; i < compressedValue.length; i++)
		{
			compressedValue[i] = (byte) (compressedBinaryValueString.charAt(i) - '0');
		}
		
		//returning the compressed value
		return compressedValue;
	}// End of compressBySBox(byte[],Integer,byte[][][]) method
	
	/**
	 * <p>
	 * 		This is a public method which is used to concatenate values of 8 S-BOXes each containing 4 bits which becomes total
	 * 		32-bits
	 * </p>
	 * 
	 * @param  values This contains 8 different S-BOXes value each containing 4-bits
	 * 
	 * @return        byte[] This is 32-bit output
	 */
	public byte[] concatenateSBoxValues(byte[][] values)
	{
		//used to store 32-bit concatenated output
		byte[] concatenatedSBoxValue = new byte[32];
		//used to store the current index of concatenatedSBoxValue
		Integer concatenatedIndex = 0;
		
		//iterates total 32 times
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				//stores the current i,j value of values in concatenatedSBoxValue
				concatenatedSBoxValue[concatenatedIndex] = values[i][j];
				//increments counter of concatenatedIndex by 1
				concatenatedIndex++;
			}
		}
		//returning the concatenated output
		return concatenatedSBoxValue;
	}// End of concatenateSBoxValues(byte[][]) method
}// End of class SBoxLogic
