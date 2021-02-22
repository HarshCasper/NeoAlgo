package des.general;

/**
 * <p>
 * 		class GeneralMethods is a public class which is used for providing general methods which can be used in different
 * 		modules in the algorithm, this class consists a couple of methods which are helpful in various parts of the
 * 		algorithm.
 * </p>
 */
public class GeneralMethods
{
	/**
	 * <p>
	 * 		This is a public method which is used to generate and return XORed values of byte arrays
	 * </p>
	 * 
	 * @param  arrayOne This is an array which is needed to be XORed
	 * @param  arrayTwo This is an array which is needed to be XORed
	 * 
	 * @return          byte[] This is the XORed value of arrayOne and arrayTwo
	 */
	public byte[] xorArray(byte[] arrayOne, byte[] arrayTwo)
	{
		byte[] xoredArray = null;
		if (arrayOne.length == arrayTwo.length)
		{
			xoredArray = new byte[arrayOne.length];
			for (int i = 0; i < arrayOne.length; i++)
			{
				xoredArray[i] = (byte) (arrayOne[i] ^ arrayTwo[i]);
			}
		}
		return xoredArray;
	}// End of xorArray(byte[] , byte[]) method
	
	/**
	 * <p>
	 * 		This is a public method which is used to convert binary number into its decimal equivalent
	 * </p>
	 * 
	 * @param  binaryNumber This is the binary number
	 * 
	 * @return              Integer This is the decimal equivalent to binaryNumber
	 */
	public Integer convertBinaryToDecimal(String binaryNumber)
	{
		Integer decimalNumber = 0;
		for (int i = 0; i < binaryNumber.length(); i++)
		{
			Integer binaryCharacter = binaryNumber.charAt(i) - '0';
			decimalNumber += binaryCharacter * (int) Math.pow(2, (binaryNumber.length() - 1) - i);
		}
		return decimalNumber;
	}// End of convertBinaryToDecimal(String) method
	
	/**
	 * <p>
	 * 		This is a public method which is used to convert decimal number into its 4-bit binary equivalent
	 * </p>
	 * 
	 * @param  decimalNumber This is the decimal number
	 * 
	 * @return               String This is 4-bit binary equivalent of decimalNumber
	 */
	public String convertDecimalToBinary(Integer decimalNumber)
	{
		/*
		 * StringBuilder is used because, it makes a mutable sequence of characters, due to appending of each binary character
		 * in binaryNumber, if we use String then it could cause creation of many immutable objects, so to make the code more
		 * efficient, StringBuilder is used.
		 */
		StringBuilder	binaryNumber	= new StringBuilder();
		
		Integer			dividend		= decimalNumber;
		while (dividend != 0)
		{
			Integer remainder = dividend % 2;
			binaryNumber.append(remainder);
			dividend = dividend / 2;
		}
		
		binaryNumber = binaryNumber.reverse();
		
		/*
		 * We need to convert decimal number to its 4-bit equivalent binary number, the following code is used to pad 0's if the
		 * length of the generated binary number is smaller than 4-bits
		 * 
		 * Example: If the decimal number is 7 then its binary number will be 111, but due to the condition of having a total
		 * length of 4-bit we need to pad one 0 at the starting which will not affect the value of the binary number and will
		 * satisfy the condition too, which makes the returnable binary number to 0111.
		 */
		if (binaryNumber.length() < 4)
		{
			Integer			remainingLength		= 4 - binaryNumber.length();
			StringBuilder	placeholdingBits	= new StringBuilder("");
			for (int i = 1; i <= remainingLength; i++)
			{
				placeholdingBits.append('0');
			}
			binaryNumber.insert(0, placeholdingBits.toString());
		}
		return binaryNumber.toString();
	}// End of convertDecimalToBinary(Integer) method
	
	/**
	 * <p>
	 * 		This is a public method which is used to perform shift left operation on elements of an array
	 * </p>
	 * 
	 * @param  value          This is the array whose elements needed to be shifted
	 * @param  numberOfShifts This is the number of times the elements should be shifted
	 * 
	 * @return                byte[] This is the left shifted array
	 */
	public byte[] shiftLeft(byte[] value, int numberOfShifts)
	{
		byte[] shiftedValue = new byte[value.length];
		
		for (int i = 1; i <= numberOfShifts; i++)
		{
			byte temp = value[0];
			
			for (int j = 0; j < value.length - 1; j++)
			{
				shiftedValue[j] = value[j + 1];
			}
			
			shiftedValue[value.length - 1] = temp;
			value = shiftedValue;
		}
		
		return shiftedValue;
	}// End of shiftLeft(byte[] , int) method
	
	
	/**
	 * <p>
	 * 		This is a static public method which is used to print text arrays like plain text, cipher text and decrypted text
	 * </p>
	 * 
	 * @param printText	This is an additional text if needed to be printed
	 * @param text		This is the array which is needed to be printed
	 */
	public static void printTextArray(String printText, byte[] text)
	{
		System.out.print(printText);
		for (int i = 0; i < text.length; i++)
		{
			//used for styling the output
			if (i % 8 == 0 && i != 0)
			{
				System.out.print(" ");
			}
			System.out.print(text[i]);
		}
		System.out.println();
	}//End of printTextArray(String, byte[]) method
	
	
}// End of class GeneralMethods
