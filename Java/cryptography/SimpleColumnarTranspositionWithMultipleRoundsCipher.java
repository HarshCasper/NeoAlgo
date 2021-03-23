import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.ListIterator;
import java.util.Scanner;

/**
 * <h1>Columnar</h1>
 * <p>
 * Columnar class acts as a custom Data Structure which consits of a List of Characters.
 * </p>
 */
class Columnar
{
    List<Character> characterList;
}

/**
 * <h1>Simple Columnar Transposition Cipher With Multiple Rounds</h1>
 * <p>
 * To Implement Simple Columnar Transposition Cipher With Multiple Rounds
 * </p>
 * <b>Description</b>
 * <p>
 * class SimpleColumnarTranspositionWithMultipleRoundsCipher is used to encrypt plainText to cipherText using Columnar
 * Transposition and decrypt cipherText to plainText using the respective algorithm, Simple Columnar Transposition is a
 * variation of Transposition technique just like Rail Fence Cipher
 * </p>
 * <b>Requirements</b>
 * <p>
 * A string plain text and a string key are required for encryption and for decryption the cipher text which is
 * calculated from the given key and the key itself.
 * </p>
 */
public class SimpleColumnarTranspositionWithMultipleRoundsCipher
{
    /**
     * <p>
     * This is a private method used to validate the key provided by the user.
     * </p>
     * <b>Validation Scheme</b>
     * <p>
     * There must be NO occurance of repetative characters in a string, occurance of repetative characters can lead to
     * malfunctioning of the code and algorithm leading to mismatched output.
     * </p>
     * <p>
     * Thou same letters with different cases(UpperCase and LowerCase) can be accepted.
     * </p>
     * <p>
     * Example: AaZ can be a valid key, but AAZ will not be considered as a valid key.
     * </p>
     * 
     * @param key This is a String parameter to validateKey method, this signifies key which is passed to perform encryption
     *            and decryption.
     * 
     * @return Boolean Tells whether the key entred is a valid key or not
     */
    private Boolean validateKey(String key)
    {
        for (int i = 0; i < key.length() - 1; i++)
        {
            for (int j = i + 1; j < key.length(); j++)
            {
                // An occurance of same character in key found.
                if (key.charAt(i) == key.charAt(j))
                {
                    return false;
                }
            }
        }
        // No occurance of same character in key found.
        return true;
    }
    
    /**
     * <p>
     * This is a public method which is used to encrypt plain text using Simple Columnar Transposition With Multiple Rounds
     * technique.
     * </p>
     *
     * <b>Process</b>
     * <ul>
     * <li>The plain text is placed row-wise in the columnar table</li>
     * <li>According to the ascending order of the characters in key, its particular column is fetched and appended in
     * cipher text</li>
     * <li>This process is repeated numberOfRounds times, after first round the plain text becomes the cipher text
     * PLAIN_TEXT(n)=CIPHER_TEXT(n-1)</li>
     * </ul>
     * 
     * @param plainText      This is a String parameter to encrypt method, this signifies plain text which is passed.
     * @param key            This is a String parameter to encrypt method, this signifies key which is passed to encrypt
     *                       plainText.
     * @param numberOfRounds This is an Integer parameter to encrypt method, this signifies total number of rounds needed to
     *                       be performed
     * 
     * @return String This returns the cipherText.
     */
    String encrypt(String plainText, String key, Integer numberOfRounds)
    {
        StringBuilder cipherText = new StringBuilder("");// used to store cipher text
        
        // Iterates until i reaches numberOfRound
        for (int numberOfRound = 1; numberOfRound <= numberOfRounds; numberOfRound++)
        {
            cipherText = new StringBuilder("");// Re-initializing cipherText
            
            Columnar[] columnars   = new Columnar[key.length()];// used to store plainText in columnar sequence given by algorithm
            Integer    columnIndex = 0;                         // used to store current column index of columnars
            
            // Initializing columnars
            for (int i = 0; i < key.length(); i++)
            {
                columnars[i] = new Columnar();
                columnars[i].characterList = new ArrayList<Character>();
            }
            
            // Iterates through plainText and stores its characters in a columnar sequence given by the algorithm
            for (int i = 0; i < plainText.length(); i++)
            {
                // It the value of columnIndex reaches to its peak then it is reassigned its value to 0, to start from a new row
                if (columnIndex == key.length())
                {
                    columnIndex = 0;
                }
                
                // Adds plainText character to columnars
                columnars[columnIndex].characterList.add(plainText.charAt(i));
                
                // Incrementes the value of columnIndex by 1
                columnIndex++;
            }
            
            // sorts the characters in key in ascending order and stores it in sortedKey
            char[] keyArray = key.toCharArray();
            Arrays.sort(keyArray);
            String sortedKey = new String(keyArray);
            
            // Iterates through the columnars
            for (int i = 0; i < key.length(); i++)
            {
                char                    currentChar             = sortedKey.charAt(i);               // used to store the current character in sorted key
                int                     indexOfCurrentCharInKey = key.indexOf(currentChar);          // used to store the index of currentChar in key
                Columnar                columnar                = columnars[indexOfCurrentCharInKey];// used to get Columnar at position indexOfCurrentCharInKey
                List<Character>         characterList           = columnar.characterList;            // used to store the List of Characters in columnar
                ListIterator<Character> characterListIterator   = characterList.listIterator();      // used as an iterator for characterList
                
                // Iterates through characterList
                while (characterListIterator.hasNext())
                {
                    // Appends plainText characters which were stored in columnars column wise
                    cipherText.append(characterListIterator.next());
                }
            }
            // PLAIN_TEXT(n)=CIPHER_TEXT(n-1)
            plainText = cipherText.toString();
        }
        
        // cipher text is retured
        return cipherText.toString();
    }
    
    /**
     * <p>
     * This is a public method which is used to decrypt cipher text using Simple Columnar Transposition With Multiple Rounds
     * technique.
     * </p>
     *
     * <b>Process</b>
     * <ul>
     * <li>As the length of cipher text and plain text is the same, we first create a placeholder columnar for getting an
     * idea of the size of each column</li>
     * <li>Arranging cipherText characters in columnar according to the size of the column</li>
     * <li>Iterating through columnar row-wise and appending each character in plain text</li>
     * <li>This process is repeated numberOfRounds times, after first round the cipher text becomes the plain text
     * CIPHER_TEXT(n)=PLAIN_TEXT(n-1)</li>
     * </ul>
     * </ul>
     * 
     * @param cipherText     This is a String parameter to decrypt method, this signifies cipher text which is passed.
     * @param key            This is a String parameter to decrypt method, this signifies key which is passed to decrypt
     *                       cipherText.
     * @param numberOfRounds This is an Integer parameter to encrypt method, this signifies total number of rounds needed to
     *                       be performed
     * 
     * @return String This returns the plainText.
     */
    String decrypt(String cipherText, String key, Integer numberOfRounds)
    {
        StringBuilder plainText = new StringBuilder("");
        
        for (int numberOfRound = 1; numberOfRound <= numberOfRounds; numberOfRound++)
        {
            plainText = new StringBuilder("");// used to store plain text
            
            Columnar[] columnars             = new Columnar[key.length()];// used to store columnar
            Columnar[] columnarsForPlacement = new Columnar[key.length()];// used as a placeholder/template for columnars
            Integer    columnIndex           = 0;                         // used to store column index in columnars
            Integer    indexForCharacter     = 0;                         // used to store index of character in cipherText
            
            // sorts the characters in key in ascending order and stores it in sortedKey
            char[] keyArray = key.toCharArray();
            Arrays.sort(keyArray);
            String sortedKey = new String(keyArray);
            
            // Initializing columnars and columnarsForPlacement
            for (int i = 0; i < key.length(); i++)
            {
                columnars[i] = new Columnar();
                columnars[i].characterList = new ArrayList<Character>();
                columnarsForPlacement[i] = new Columnar();
                columnarsForPlacement[i].characterList = new ArrayList<Character>();
            }
            
            // Creating a placeholder for getting an idea of size of column
            for (int i = 0; i < cipherText.length(); i++)
            {
                if (columnIndex == key.length())
                {
                    columnIndex = 0;
                }
                columnarsForPlacement[columnIndex].characterList.add('*');
                columnIndex++;
            }
            
            // Arranges cipherText characters according to the columnar algorithm sequence
            for (int i = 0; i < key.length(); i++)
            {
                Character               currentKeyCharacter   = sortedKey.charAt(i);                    // used to store current character in sorted key
                Integer                 indexForColumnar      = key.indexOf(currentKeyCharacter);       // used to store index of currentKeyCharacter in key
                Columnar                columnarPlaceholder   = columnarsForPlacement[indexForColumnar];// used to store Columnar at position indexForColumnar
                List<Character>         characterList         = columnarPlaceholder.characterList;      // used to store List of Characters in columnarsForPlacement
                ListIterator<Character> characterListIterator = characterList.listIterator();           // used as an iterator for characterList
                // Iterates through characterList
                while (characterListIterator.hasNext())
                {
                    // Adds a character in cipherText at indexForCharacter to characterList
                    columnars[indexForColumnar].characterList.add(cipherText.charAt(indexForCharacter));
                    // Iterates over to the next element in characterListIterator
                    characterListIterator.next();
                    // Incrementes the value of indexForCharacter by 1
                    indexForCharacter++;
                }
            }
            
            // Keeps a counter of key index
            Integer keyIndex = 0;
            
            // Iterates through cipherText
            for (int i = 0; i < cipherText.length(); i++)
            {
                // If keyIndex reaches its maximum possible limit(length of key) then it is assigned 0
                if (keyIndex >= key.length())
                {
                    keyIndex = 0;
                }
                
                Columnar        columnar      = columnars[keyIndex];   // used to store Columnar of columnars at index keyIndex
                List<Character> characterList = columnar.characterList;// used to store List of Characters in columnar
                
                if (!characterList.isEmpty())
                {
                    // appends characters at 0th position to plainText
                    plainText.append(characterList.get(0));
                    // removes the 0th character in characterList which makes it self iterative and saves space
                    characterList.remove(0);
                }
                
                // Increments keyIndex by 1
                keyIndex++;
            }
            // CIPHER_TEXT(n)=PLAIN_TEXT(n-1)
            cipherText = plainText.toString();
        }
        // plain text is retured
        return plainText.toString();
    }
    
    /**
     * This is the main method which makes use of the following methods:
     * <ul>
     * <li>encrypt</li>
     * <li>decrypt</li>
     * </ul>
     * 
     * And uses the following objects of types:
     * <ul>
     * <li>java.util.Scanner</li>
     * <li>SimpleColumnarTranspositionWithMultipleRoundsCipher</li>
     * </ul>
     * 
     * @param args not used
     */
    public static void main(String[] args)
    {
        
        String                                              key;                                                // Created an object of String class for storing key to be entered
                                                                                                                // by the user
        String                                              plainText;                                          // Create an object of String class for storing plain text to be
                                                                                                                // entered by the user
        Integer                                             numberOfRounds;                                     // Creates an object of Integer class for storing number of rounds
                                                                                                                // needed to be performed
        Scanner                                             scan = new Scanner(System.in);                      // Created an object of Scanner class for asking for user input.
        SimpleColumnarTranspositionWithMultipleRoundsCipher simpleColumnarTranspositionWithMultipleRoundsCipher;// Created an object of
                                                                                                                // SimpleColumnarTranspositionWithMultipleRoundsCipher for
                                                                                                                // accessing it's method for encryption and decryption
        simpleColumnarTranspositionWithMultipleRoundsCipher = new SimpleColumnarTranspositionWithMultipleRoundsCipher();
        
        // Asking user to enter plain text
        System.out.println("Please Enter Plain Text:");
        plainText = scan.nextLine();
        
        // Asking user to enter String key
        System.out.println("Please Enter Key:");
        key = scan.next();
        
        // Asking user to enter number of rounds needed to be performed
        System.out.println("Please Enter Number Of Rounds:");
        numberOfRounds = scan.nextInt();
        
        // Checks if the key entered is valid or not
        Boolean keyValidationStatus = simpleColumnarTranspositionWithMultipleRoundsCipher.validateKey(key);
        
        // If the key entered by the user is valid
        if (keyValidationStatus)
        {
            // Accessing method 'encrypt' of SimpleColumnarTranspositionWithMultipleRoundsCipher class to encrypt plainText by key
            // and numberOfRounds
            String cipherText = simpleColumnarTranspositionWithMultipleRoundsCipher.encrypt(plainText, key, numberOfRounds);
            // Printing cipher text
            System.out.println("Cipher Text: " + cipherText);
            
            // Accessing method 'decrypt' of SimpleColumnarTranspositionWithMultipleRoundsCipher class to decrypt cipherText by key
            // and numberOfRounds
            String decryptedText = simpleColumnarTranspositionWithMultipleRoundsCipher.decrypt(cipherText, key, numberOfRounds);
            // Printing decrypted text
            System.out.println("Decrypted Text: " + decryptedText);
        }
        // If the key entered by the user is not valid
        else
        {
            // Printing error message
            System.out.println("An Occurance of repetative characters in key is found, please enter unique characters");
        }
        
        // Closing the Scanner object scan
        scan.close();
    }
}
/*
 * Please Enter Plain Text:
 * 
 * Attack Alice's troops at 5:00 PM today
 * 
 * Please Enter Key:
 * 
 * ATCK13pa
 * 
 * Please Enter Number Of Rounds:
 * 
 * 3
 * 
 * Cipher Text: ac0tpkdlMAatA 0aciys5 o rP:'tesot to
 * 
 * Decrypted Text: Attack Alice's troops at 5:00 PM today
 */