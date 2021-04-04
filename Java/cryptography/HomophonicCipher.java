import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

/**
 * <h1>Homophonic Cipher</h1>
 * <p>
 * To Implement Homophonic Cipher
 * </p>
 * 
 * <b>Description</b>
 * <p>
 * Homophonic Cipher is a substitution cipher, it replaces each letter with a varity of substitues, it is very similar
 * to Monoalphabetic cipher, the key difference between Homophonic cipher and Monoalphabetic cipher is that, in
 * Monoalphabetic cipher there is a constant replacement of character to another character whereas in Homophonic cipher
 * we have a set of characters which we can substitute.
 * </p>
 */
public class HomophonicCipher
{
    // Character Mapping table for Homophonic Cipher
    private static HashMap<Character, List<Character>> homophonicSequence;
    
    /**
     * <p>
     * This is a public method which is used to initialize homophonicSequence with character mapping.
     * </p>
     */
    public void initializeHomophonicSequence()
    {
        // Initializing homophonicSequence
        homophonicSequence = new HashMap<Character, List<Character>>();
        
        // Character Mapping for letter 'A'
        List<Character> aCharacterList = new ArrayList<Character>();
        aCharacterList.add('D');
        aCharacterList.add('9');
        HomophonicCipher.homophonicSequence.put('A', aCharacterList);
        
        // Character Mapping for letter 'B'
        List<Character> bCharacterList = new ArrayList<Character>();
        bCharacterList.add('X');
        HomophonicCipher.homophonicSequence.put('B', bCharacterList);
        
        // Character Mapping for letter 'C'
        List<Character> cCharacterList = new ArrayList<Character>();
        cCharacterList.add('S');
        HomophonicCipher.homophonicSequence.put('C', cCharacterList);
        
        // Character Mapping for letter 'D'
        List<Character> dCharacterList = new ArrayList<Character>();
        dCharacterList.add('F');
        HomophonicCipher.homophonicSequence.put('D', dCharacterList);
        
        // Character Mapping for letter 'E'
        List<Character> eCharacterList = new ArrayList<Character>();
        eCharacterList.add('Z');
        eCharacterList.add('7');
        eCharacterList.add('2');
        eCharacterList.add('1');
        HomophonicCipher.homophonicSequence.put('E', eCharacterList);
        
        // Character Mapping for letter 'F'
        List<Character> fCharacterList = new ArrayList<Character>();
        fCharacterList.add('E');
        HomophonicCipher.homophonicSequence.put('F', fCharacterList);
        
        // Character Mapping for letter 'G'
        List<Character> gCharacterList = new ArrayList<Character>();
        gCharacterList.add('H');
        HomophonicCipher.homophonicSequence.put('G', gCharacterList);
        
        // Character Mapping for letter 'H'
        List<Character> hCharacterList = new ArrayList<Character>();
        hCharacterList.add('C');
        HomophonicCipher.homophonicSequence.put('H', hCharacterList);
        
        // Character Mapping for letter 'I'
        List<Character> iCharacterList = new ArrayList<Character>();
        iCharacterList.add('V');
        iCharacterList.add('3');
        HomophonicCipher.homophonicSequence.put('I', iCharacterList);
        
        // Character Mapping for letter 'J'
        List<Character> jCharacterList = new ArrayList<Character>();
        jCharacterList.add('I');
        HomophonicCipher.homophonicSequence.put('J', jCharacterList);
        
        // Character Mapping for letter 'K'
        List<Character> kCharacterList = new ArrayList<Character>();
        kCharacterList.add('T');
        HomophonicCipher.homophonicSequence.put('K', kCharacterList);
        
        // Character Mapping for letter 'L'
        List<Character> lCharacterList = new ArrayList<Character>();
        lCharacterList.add('P');
        HomophonicCipher.homophonicSequence.put('L', lCharacterList);
        
        // Character Mapping for letter 'M'
        List<Character> mCharacterList = new ArrayList<Character>();
        mCharacterList.add('G');
        HomophonicCipher.homophonicSequence.put('M', mCharacterList);
        
        // Character Mapping for letter 'N'
        List<Character> nCharacterList = new ArrayList<Character>();
        nCharacterList.add('A');
        nCharacterList.add('5');
        HomophonicCipher.homophonicSequence.put('N', nCharacterList);
        
        // Character Mapping for letter 'O'
        List<Character> oCharacterList = new ArrayList<Character>();
        oCharacterList.add('Q');
        oCharacterList.add('0');
        HomophonicCipher.homophonicSequence.put('O', oCharacterList);
        
        // Character Mapping for letter 'P'
        List<Character> pCharacterList = new ArrayList<Character>();
        pCharacterList.add('L');
        HomophonicCipher.homophonicSequence.put('P', pCharacterList);
        
        // Character Mapping for letter 'Q'
        List<Character> qCharacterList = new ArrayList<Character>();
        qCharacterList.add('K');
        HomophonicCipher.homophonicSequence.put('Q', qCharacterList);
        
        // Character Mapping for letter 'R'
        List<Character> rCharacterList = new ArrayList<Character>();
        rCharacterList.add('J');
        HomophonicCipher.homophonicSequence.put('R', rCharacterList);
        
        // Character Mapping for letter 'S'
        List<Character> sCharacterList = new ArrayList<Character>();
        sCharacterList.add('R');
        sCharacterList.add('4');
        HomophonicCipher.homophonicSequence.put('S', sCharacterList);
        
        // Character Mapping for letter 'T'
        List<Character> tCharacterList = new ArrayList<Character>();
        tCharacterList.add('U');
        tCharacterList.add('6');
        HomophonicCipher.homophonicSequence.put('T', tCharacterList);
        
        // Character Mapping for letter 'U'
        List<Character> uCharacterList = new ArrayList<Character>();
        uCharacterList.add('O');
        HomophonicCipher.homophonicSequence.put('U', uCharacterList);
        
        // Character Mapping for letter 'V'
        List<Character> vCharacterList = new ArrayList<Character>();
        vCharacterList.add('W');
        HomophonicCipher.homophonicSequence.put('V', vCharacterList);
        
        // Character Mapping for letter 'W'
        List<Character> wCharacterList = new ArrayList<Character>();
        wCharacterList.add('M');
        HomophonicCipher.homophonicSequence.put('W', wCharacterList);
        
        // Character Mapping for letter 'X'
        List<Character> xCharacterList = new ArrayList<Character>();
        xCharacterList.add('Y');
        HomophonicCipher.homophonicSequence.put('X', xCharacterList);
        
        // Character Mapping for letter 'Y'
        List<Character> yCharacterList = new ArrayList<Character>();
        yCharacterList.add('B');
        HomophonicCipher.homophonicSequence.put('Y', yCharacterList);
        
        // Character Mapping for letter 'Z'
        List<Character> zCharacterList = new ArrayList<Character>();
        zCharacterList.add('N');
        HomophonicCipher.homophonicSequence.put('Z', zCharacterList);
    }
    
    /**
     * <p>
     * This is a public method which is used to encrypt plain text using Homophonic Substitution Cipher method
     * </p>
     * 
     * @param plainText This is a String parameter to encrypt method, this signifies plain text which is passed.
     * 
     * @return String This returns the cipherText.
     */
    public String encrypt(String plainText)
    {
        StringBuilder cipherText = new StringBuilder("");// used to store cipher text
        
        // Iterates through plainText
        for (int i = 0; i < plainText.length(); i++)
        {
            // Gets List of mapping characters to the current character
            List<Character> characterList = HomophonicCipher.homophonicSequence.get(plainText.charAt(i));
            // If character mapping is found
            if (characterList != null)
            {
                // Random character index is picked from the set of characters
                Integer indexToUse = new Random().nextInt(characterList.size());
                // character selected by random is appended to cipherText
                cipherText.append(characterList.get(indexToUse));
            }
            // If character mapping is not found
            else
            {
                // Without encryption plainText character will be appended to cipherText
                cipherText.append(plainText.charAt(i));
            }
        }
        // cipher text is retured
        return cipherText.toString();
        
    }
    
    /**
     * This is the main method which makes use of the following methods:
     * <ul>
     * <li>encrypt</li>
     * </ul>
     * 
     * And uses the following objects of types:
     * <ul>
     * <li>java.util.Scanner</li>
     * <li>HomophonicCipher</li>
     * </ul>
     * 
     * @param args not used
     */
    public static void main(String[] args)
    {
        String           plainText;                                 // Create an object of String class for storing plain text to be entered by the user
        Scanner          scan             = new Scanner(System.in); // Created an object of Scanner class for asking for user input.
        HomophonicCipher homophonicCipher = new HomophonicCipher(); // Created an object of HomophonicCipher for accessing it's method for encryption
        
        // Initializing homophonicCipher
        homophonicCipher.initializeHomophonicSequence();
        
        // Asking user to enter plain text
        System.out.println("Please Enter Plain Text:");
        plainText = scan.nextLine();
        
        // Accessing method 'encrypt' of HomophonicCipher class to encrypt plainText
        String cipherText = homophonicCipher.encrypt(plainText.toUpperCase());
        // Printing cipher text
        System.out.println("Cipher Text: " + cipherText);
        
        // Closing the Scanner object scan
        scan.close();
    }
}
/*
 * Please Enter Plain Text:
 * 
 * Attack Alice's troops at 5:00 PM today
 * 
 * Cipher Text: DU6DST 9PVS2'4 6J0QLR 9U 5:00 LG UQFDB
 */