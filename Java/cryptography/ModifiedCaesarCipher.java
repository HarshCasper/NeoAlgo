import java.util.Scanner;

/**
 * <h1>Modified Caesar Cipher</h1>
 * <p>
 * To Implement Modified Version of Caesar Cipher
 * </p>
 * <b>Description</b>
 * <p>
 * class ModifiedCaesarCipher is used to encrypt plainText to cipherText using Modified Caesar Algorithm and decrypt
 * cipherText to plainText using the respective algorithm, in Modified Caesar Cipher the encryption takes place by
 * increasing or decreasing the key-value to the character based on its index number from A-Z series, instead of just
 * increasing the key to the character which was done in Caesar Cipher, which provides more enhancement in security and
 * decreases the chances of attack.
 * </p>
 * <b>Requirements</b>
 * <p>
 * A string plain text and an integer key are required for encryption and for decryption the cipher text which is
 * calculated from the given key and the key itself.
 * </p>
 * 
 * <b>Reference for understanding the algorithm</b>
 * <a href="https://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.402.8295&rep=rep1&type=pdf"> Modified CaesarCipher
 * for Better Security Enhancement </a>
 * 
 */
public class ModifiedCaesarCipher
{
    /**
     * <p>
     * This is a public method used to encrypt plainText using integer key using Modified Caesar Cipher algorithm.
     * </p>
     * <b>Process</b>
     * <ul>
     * <li>a string plain text and integer key are taken as input</li>
     * <li>iteratively each character of plain text is encrypted
     * <ul>
     * <li>The character index of the current character is calculated, if the character is whitespace then it is not
     * calculated</li>
     * <li>If the character index is even then the character value is incremented by the key-value, else decremented</li>
     * <li>If the sum of the character value and key-value extends or descends within the letter group range (A-Z,a-z,0-9),
     * then the values are circulated and encrypted unless and until their encrypted value comes it the range.</li>
     * <li>The encrypted value is returned</li>
     * </ul>
     * </li>
     * </ul>
     * 
     * @param plainText This is a String parameter to encrypt method, this signifies plain text which is passed.
     * @param key       This is an Integer parameter to encrypt method, this signifies key which is passed to encrypt
     *                  plainText.
     * 
     * @return String This returns the cipherText.
     */
    public String encrypt(String plainText, Integer key)
    {
        /*
         * StringBuilder is used because, it makes a mutable sequence of characters, due to appending of each encrypted
         * character in cipherText, if we use String then it could cause creation of many immutable objects, so to make the code
         * more efficient, StringBuilder is used.
         */
        StringBuilder cipherText = new StringBuilder("");
        
        // Iterating through each character in plainText
        for (int i = 0; i < plainText.length(); i++)
        {
            // Checking for the character index and storing its value in variable 'characterIndex'
            Integer characterIndex = 0;
            // Withing range a-z
            if (plainText.charAt(i) >= 'a' && plainText.charAt(i) <= 'z')
            {
                characterIndex = plainText.charAt(i) - 'a';
            }
            // Withing range A-Z
            else if (plainText.charAt(i) >= 'A' && plainText.charAt(i) <= 'Z')
            {
                characterIndex = plainText.charAt(i) - 'A';
            }
            // Withing range 0-9
            else if (plainText.charAt(i) >= '0' && plainText.charAt(i) <= '9')
            {
                characterIndex = plainText.charAt(i) - '0' + 1;
            }
            // Special Characters
            else
            {
                cipherText.append(plainText.charAt(i));
                continue;
            }
            
            /*
             * If there's an occurrence of whitespace observed in the plainText then it is passed as it is to the cipherText without
             * encrypting it.
             */
            if (plainText.charAt(i) == ' ')
            {
                cipherText.append(' ');
                continue;
            }
            
            int encryptedChar = plainText.charAt(i);
            
            // If the value characterIndex is even then the value of the character is incremented
            if (characterIndex % 2 == 0)
            {
                encryptedChar += key;
            }
            // If the value characterIndex is odd then the value of the character is decremented
            else
            {
                encryptedChar -= key;
            }
            
            /*
             * Flag used to know that if the encrypted character is withing its group range or not
             * 
             * exit = false signifies that the character is within the range
             * 
             * exit = true signifies that the character was not within its range and needs one more iteration for circulation
             */
            boolean exit = false;
            do
            {
                if (plainText.charAt(i) >= 'a' && plainText.charAt(i) <= 'z')
                {
                    exit = false;
                    if (encryptedChar < 'a' || encryptedChar > 'z')
                    {
                        if (encryptedChar < 'a')
                        {
                            encryptedChar += ('z' - 'a' + 1);
                        }
                        else if (encryptedChar > 'z')
                        {
                            encryptedChar -= ('z' - 'a' + 1);
                        }
                        exit = true;
                    }
                }
                else if (plainText.charAt(i) >= 'A' && plainText.charAt(i) <= 'Z')
                {
                    exit = false;
                    if (encryptedChar < 'A' || encryptedChar > 'Z')
                    {
                        if (encryptedChar < 'A')
                        {
                            encryptedChar += ('Z' - 'A' + 1);
                        }
                        else if (encryptedChar > 'Z')
                        {
                            encryptedChar -= ('Z' - 'A' + 1);
                        }
                        exit = true;
                    }
                }
                else if (plainText.charAt(i) >= '0' && plainText.charAt(i) <= '9')
                {
                    exit = false;
                    
                    if (encryptedChar < '0' || encryptedChar > '9')
                    {
                        if (encryptedChar < '0')
                        {
                            encryptedChar += ('9' - '0' + 1);
                        }
                        else if (encryptedChar > '9')
                        {
                            encryptedChar -= ('9' - '0' + 1);
                        }
                        exit = true;
                    }
                }
            }
            while (exit);
            
            /*
             * At the end of for loop(which was used to iterate through each character in plainText), the encrypted character
             * 'encryptedChar' is appended to cipherText
             */
            cipherText.append((char) encryptedChar);
        }
        
        // cipher text is retured
        return cipherText.toString();
    }
    
    /**
     * <p>
     * This is a public method used to decrypt cipherText using integer key using Modified Caesar Cipher algorithm.
     * </p>
     * <b>Process</b>
     * <ul>
     * <li>a string cipher text and integer key are taken as input</li>
     * <li>iteratively each character of cipher text is decrypted
     * <ul>
     * <li>The character index of the current character is calculated, if the character is whitespace then it is not
     * calculated</li>
     * <li>If the key is even then
     * <ul>
     * <li>If the character index is even then the character value is decremented by the key-value</li>
     * <li>If the character index is odd then the character value is incremented by the key-value</li>
     * </ul>
     * </li>
     * <li>If the key is odd then
     * <ul>
     * <li>If the character index is even then the character value is incremented by the key-value</li>
     * <li>If the character index is odd then the character value is decremented by the key-value</li>
     * </ul>
     * </li>
     * <li>If the sum of the character value and key-value extends or descends within the letter group range (A-Z,a-z,0-9),
     * then the values are circulated and decrepted unless and until their decrypted value comes it the range.</li>
     * <li>The decrypted value is returned</li>
     * </ul>
     * </li>
     * </ul>
     * 
     * @param cipherText This is a String parameter to decrypt method, this signifies cipher text which is passed.
     * @param key        This is an Integer parameter to decrypt method, this signifies key which is passed to decrypt
     *                   cipherText.
     * 
     * @return String This returns the plainText.
     */
    public String decrypt(String cipherText, Integer key)
    {
        /*
         * StringBuilder is used because, it makes a mutable sequence of characters, due to appending of each decrypted
         * character in plainText, if we use String then it could cause creation of many immutable objects, so to make the code
         * more efficient, StringBuilder is used.
         */
        StringBuilder plainText = new StringBuilder("");
        
        // Iterating through each character in cipherText
        for (int i = 0; i < cipherText.length(); i++)
        {
            // Checking for the character index and storing its value in variable 'characterIndex'
            Integer characterIndex = 0;
            
            // Withing range a-z
            if (cipherText.charAt(i) >= 'a' && cipherText.charAt(i) <= 'z')
            {
                characterIndex = cipherText.charAt(i) - 'a';
            }
            // Withing range A-Z
            else if (cipherText.charAt(i) >= 'A' && cipherText.charAt(i) <= 'Z')
            {
                characterIndex = cipherText.charAt(i) - 'A';
            }
            // Withing range 0-9
            else if (cipherText.charAt(i) >= '0' && cipherText.charAt(i) <= '9')
            {
                characterIndex = cipherText.charAt(i) - '0' + 1;
            }
            // Special Characters
            else
            {
                plainText.append(cipherText.charAt(i));
                continue;
            }
            
            /*
             * If there's an occurrence of whitespace observed in the cipherText then it is passed as it is to the plainText without
             * decrypting it.
             */
            if (cipherText.charAt(i) == ' ')
            {
                plainText.append(' ');
                continue;
            }
            
            int decryptedChar = cipherText.charAt(i);
            
            /*
             * AND logic is used to determine increment or decrement in the cipherText
             * 
             * 0 X 1 = 0
             * 
             * 1 X 0 = 0
             * 
             * 1 X 1 = 1
             * 
             * 0 X 0 = 0
             * 
             * Where 0 determines odd number and 1 determines even in this case
             */
            // If the value key is even
            if (key % 2 == 0)
            {
                // If the value characterIndex is even then the value of the character is decremented
                if (characterIndex % 2 == 0)
                {
                    decryptedChar -= key;
                }
                // If the value characterIndex is odd then the value of the character is incremented
                else
                {
                    decryptedChar += key;
                }
            }
            // If the value key is odd
            else
            {
                // If the value characterIndex is even then the value of the character is incremented
                if (characterIndex % 2 == 0)
                {
                    decryptedChar += key;
                }
                // If the value characterIndex is odd then the value of the character is decremented
                else
                {
                    decryptedChar -= key;
                }
            }
            
            /*
             * Flag used to know that if the decrypted character is withing its group range or not
             * 
             * exit = false signifies that the character is within the range
             * 
             * exit = true signifies that the character was not within its range and needs one more iteration for circulation
             */
            boolean exit = false;
            
            do
            {
                if (cipherText.charAt(i) >= 'a' && cipherText.charAt(i) <= 'z')
                {
                    exit = false;
                    if (decryptedChar < 'a' || decryptedChar > 'z')
                    {
                        if (decryptedChar < 'a')
                        {
                            decryptedChar += ('z' - 'a' + 1);
                        }
                        else if (decryptedChar > 'z')
                        {
                            decryptedChar -= ('z' - 'a' + 1);
                        }
                        exit = true;
                    }
                }
                else if (cipherText.charAt(i) >= 'A' && cipherText.charAt(i) <= 'Z')
                {
                    exit = false;
                    if (decryptedChar < 'A' || decryptedChar > 'Z')
                    {
                        if (decryptedChar < 'A')
                        {
                            decryptedChar += ('Z' - 'A' + 1);
                        }
                        else if (decryptedChar > 'Z')
                        {
                            decryptedChar -= ('Z' - 'A' + 1);
                        }
                        exit = true;
                    }
                }
                else if (cipherText.charAt(i) >= '0' && cipherText.charAt(i) <= '9')
                {
                    exit = false;
                    
                    if (decryptedChar < '0' || decryptedChar > '9')
                    {
                        if (decryptedChar < '0')
                        {
                            decryptedChar += ('9' - '0' + 1);
                        }
                        else if (decryptedChar > '9')
                        {
                            decryptedChar -= ('9' - '0' + 1);
                        }
                        exit = true;
                    }
                }
            }
            while (exit);
            
            /*
             * At the end of for loop(which was used to iterate through each character in cipherText), the decrypted character
             * 'decryptedChar' is appended to plainText
             */
            plainText.append((char) decryptedChar);
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
     * <li>java.lang.Integer</li>
     * <li>ModifiedCaesarCipher</li>
     * </ul>
     * 
     * @param args not used
     */
    public static void main(String[] args)
    {
        Integer              key;                                              // Created an object of Integer class for storing key to be entered by the user
        String               plainText;                                        // Create an object of String class for storing plain text to be entered by the user
        Scanner              scan                 = new Scanner(System.in);    // Created an object of Scanner class for asking for user input.
        ModifiedCaesarCipher modifiedCaeserCipher = new ModifiedCaesarCipher();// Created an object of ModifiedCaesarCipher for accessing it's method for encryption and decryption
        
        // Asking user to enter plain text
        System.out.println("Please Enter Plain Text:");
        plainText = scan.nextLine();
        
        // Asking user to enter integer key
        System.out.println("Please Enter Key:");
        key = scan.nextInt();
        
        // Accessing method 'encrypt' of ModifiedCaesarCipher class to encrypt plainText by key
        String cipherText = modifiedCaeserCipher.encrypt(plainText, key);
        
        // Printing cipher text
        System.out.println("Cipher Text: " + cipherText);
        
        // Accessing method 'decrypt' of ModifiedCaesarCipher class to decrypt cipherText by key
        String decryptedText = modifiedCaeserCipher.decrypt(cipherText, key);
        
        // Printing decrypted text
        System.out.println("Decrypted Text: " + decryptedText);
        
        // Closing the Scanner object scan
        scan.close();
    }
}

/*
 * OUTPUT:
 * 
 * Please Enter Plain Text:
 * 
 * Attack Alice's troops at 5:00 PM today
 * 
 * Please Enter Key:
 * 
 * 3
 * 
 * Cipher Text: Dqqdfn Dilfh'v qorrmv dq 8:77 MP qradb
 * 
 * Decrypted Text: Attack Alice's troops at 5:00 PM today
 */