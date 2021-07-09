package main.phonetic;

import java.util.regex.Pattern;

/** @author {@link <a href="https://github.com/dhyces">Dhyces</a>} 7-8-2021 */
public class Soundex {
	
	private static final byte[] TABLE = new byte[] {0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
	private static final Pattern NOT_ATOZ = Pattern.compile("[^a-zA-Z]");

	/** This conversion is based on the {@link <a href="https://en.wikipedia.org/wiki/Soundex">WikiPedia article</a>} of the Soundex 
	 *  algorithm, following the standard American variation
	 *  @param s The string to convert. Must only contain word characters.
	 *  @return The four character Soundex representation of the word, or "Z000" if an empty or invalid string was passed.*/
	public static String convertToSoundex(String s) {
		if (s.isEmpty() || NOT_ATOZ.matcher(s).find()) return "Z000";
		s = s.toUpperCase();
		
		char c = s.charAt(0);
		String ret = String.valueOf(c);
		int i, lastVal = getVal(c);
		for (i = 1; i < s.length(); i++) {
			if (ret.length() == 4) break;
			c = s.charAt(i);
			byte charVal = getVal(c);
			// We want to drop digits that follow itself and we don't want to set the lastVal if the character is w or h. Follows step 3.
			if (lastVal == charVal || c == 'W' || c == 'H') continue;
			if (charVal != 0) ret += charVal;
			lastVal = charVal;
		}
		return ret.concat("0".repeat(4 - ret.length()));
	}
	
	/** Retrieves the corresponding byte value for a character.
	 * 	@param c The character to get
	 *  @return The byte value for a character or -1 for non-word or lowercase characters.*/
	private static byte getVal(char c) {
		if (!Character.isAlphabetic(c) || Character.isLowerCase(c)) return -1;
		return TABLE[(int)c%65];
	}
	
}
