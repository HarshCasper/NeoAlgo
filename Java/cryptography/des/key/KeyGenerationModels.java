package des.key;

/**
 *<h1>DES Key Generation Models</h1>
 */
public class KeyGenerationModels
{
	//key compression table 64-bits to 56-bits
	private final byte[] KEY_COMPRESS_64_TO_56 = {
			57, 49, 41, 33, 25, 17, 9,
			1,  58, 50, 42, 34, 26, 18,
			10, 2,  59, 51, 43, 35, 27,
			19, 11, 3,  60, 52, 44, 36,
			63, 55, 47, 39, 31, 23, 15, 
			7,  62, 54, 46, 38, 30, 22,
			14, 6,  61, 53, 45, 37, 29,
			21, 13, 5,  28, 20, 12, 4
	};
	
	//number of shifts table
	private final byte[] NUMBER_OF_SHIFTS = {
			1, 
			1, 
			2, 
			2,
			2,
			2, 
			2, 
			2, 
			1,
			2,
			2,
			2,
			2,
			2,
			2, 
			1
	};
	
	//key compression table 56-bits to 48-bits
	private final byte[] KEY_COMPRESS_56_TO_48= {
			14 , 17 , 11 , 24 , 1 ,  5,
			3 ,  28 , 15 , 6 ,  21 , 10,
			23 , 19 , 12 , 4 ,  26 , 8,
			16 , 7 ,  27 , 20 , 13 , 2,
			41 , 52 , 31 , 37 , 47 , 55,
			30 , 40 , 51 , 45 , 33 , 48,
			44 , 49 , 39 , 56 , 34 , 53,
			46 , 42 , 50 , 36 , 29 , 32
	};

	/**
	 * <p>
	 * 		This is a public method which is used to get key compression table 64-bits to 56-bits
	 * </p>
	 * 
	 * @return	byte[] key compression table(64-bits to 56-bits)
	 */
	public byte[] getKEY_COMPRESS_64_TO_56()
	{
		return KEY_COMPRESS_64_TO_56;
	}// End of getKEY_COMPRESS_64_TO_56() method

	/**
	 * <p>
	 * 		This is a public method which is used to get number of shifts table
	 * </p>
	 * 
	 * @return	byte[] number of shifts table
	 */
	public byte[] getNUMBER_OF_SHIFTS()
	{
		return NUMBER_OF_SHIFTS;
	}// End of getNUMBER_OF_SHIFTS() method

	/**
	 * <p>
	 * 		This is a public method which is used to get key compression table 56-bits to 48-bits
	 * </p>
	 * 
	 * @return	byte[] key compression table (56-bits to 48-bits)
	 */
	public byte[] getKEY_COMPRESS_56_TO_48()
	{
		return KEY_COMPRESS_56_TO_48;
	}// End of getKEY_COMPRESS_56_TO_48() method
}// End of class KeyGenerationModels
