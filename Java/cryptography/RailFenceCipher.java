import java.util.Queue;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * <h1>Rail Fence</h1>
 * <p>
 * RailFence class acts as a custom Data Structure which consits of a Queue of Characters, Queue is used due to its
 * FIFO(First In First Out) property.
 * </p>
 */
class RailFence
{
    public Queue<Character> railFenceQueue;
}

/**
 * <h1>Rail Fence Cipher</h1>
 * <p>
 * To Implement Rail Fence Cipher
 * </p>
 * <b>Description</b>
 * <p>
 * class RailFenceCipher is used to encrypt plainText to cipherText using Rail Fence Cipher and decrypt cipherText to
 * plainText using the respective algorithm, Rail Fence Cipher is also called as Zig-Zag Cipher, it is a form of
 * Transposition cipher, it has derived its name from the technique it uses to encode the plain text, which forms a
 * zig-zag pattern which looks like a rail fence, it jumbles up the characters in the plain text to form the cipher
 * text.
 * </p>
 * <b>Requirements</b>
 * <p>
 * A string plain text and an integer key are required for encryption and for decryption the cipher text which is
 * calculated from the given key and the key itself.
 * </p>
 */
public class RailFenceCipher
{
    /**
     * <p>
     * This is a public method used to encrypt plainText using integer key using the Rail Fence Cipher algorithm.
     * </p>
     * 
     * <b>Process</b>
     * <ul>
     * <li>Place the characters in rail fence sequence
     * <p>
     * Here plain text= HelloHiHowAreYou? and key =3
     * </p>
     * <p>
     *    0 H               O                   O                       E                   ?
     *    1    E       L       H          H           W           R           Y        U
     *    2        L               I                       A                       O
     * </p>
     * </li>
     * 
     * <li>Fetch all the characters in index 0 then iterate it over other indexes until the last character of the index is
     * fetched Here in the above example,
     * <ul>
     * <li>First, fetch all the characters which come in index 1, i.e. HOOE?</li>
     * <li>Then, fetch all the characters which come in index 2, i.e. ELHHWRYU</li>
     * <li>Then, fetch all the characters which come in index 3, i.e. LIAO</li>
     * </ul>
     * Then concatenate all the strings of different indexes which becomes our cipher text = HOOE?ELHHWRYULIAO</li>
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
        StringBuilder cipherText           = new StringBuilder("");// used to store cipher text
        RailFence[]   railFence            = new RailFence[key];   // used to store rail fence sequence
        Integer       currentIndexPosition = 0;                    // used to store the current index position 0 - (key-1)
        Boolean       incrementFlag        = false;                // used as a flag to know whether to increment/decrement value of currentIndexPosition
        
        // Initializing railFence
        for (int i = 0; i < key; i++)
        {
            railFence[i] = new RailFence();
            railFence[i].railFenceQueue = new LinkedList<Character>();
        }
        
        // Iterating through each character in plainText
        for (int i = 0; i < plainText.length(); i++)
        {
            // If currentIndexPosition reaches to its full length, then it needs to be decremented
            if (currentIndexPosition == key - 1)
            {
                incrementFlag = true;
            }
            // If currentIndexPosition reaches to its minimum length, then it needs to be incremented
            else if (currentIndexPosition == 0)
            {
                incrementFlag = false;
            }
            
            // Adds the current character to railFence sequence at a particular sequence
            railFence[currentIndexPosition].railFenceQueue.add(plainText.charAt(i));
            
            /*
             * If incrementFlag=true then currentIndexPosition has reached its maximum possible length, i.e. key-1 and
             * currentIndexPosition needs to be decremented now to satisfy the algorithm
             * 
             * If incrementFlag=false then currentIndexPosition has reached its minumum possible length, i.e. 0 and
             * currentIndexPosition needs to be incremented now to satisfy the algorithm
             */
            if (incrementFlag)
            {
                currentIndexPosition--;
            }
            else
            {
                currentIndexPosition++;
            }
        }
        
        // Iterating through railFence
        for (int i = 0; i < key; i++)
        {
            RailFence        rail       = railFence[i];       // used to store current railFence
            Queue<Character> characters = rail.railFenceQueue;// used to store queue of current railFence
            
            while (!characters.isEmpty())
            {
                // polls the character from the sequence
                Character currentCharacter = characters.poll();
                // appends the polled character to ciphertext
                cipherText.append(currentCharacter);
            }
        }
        
        // cipher text is retured
        return cipherText.toString();
    }
    
    /**
     * <p>
     * This is a public method used to decrypt cipher using integer key using Rail Fence Cipher algorithm.
     * </p>
     * <b>Process</b>
     * <ul>
     * <li>As in Rail Fence Cipher technique, the length of cipher text is equal to plain text, we first make a placeholder
     * rail fence sequence to get an idea of the length of each index</li>
     * <li>Incrementally we place each character of cipher text in the rail fence</li>
     * <li>Then we fetch each character from each index</li>
     * <li>Finally, we concatenate all the characters to get plain text</li>
     * </ul>
     * 
     * @param cipherText This is a String parameter to decrypt method, this signifies cipher text which is passed.
     * @param key        This is an Integer parameter to decrypt method, this signifies key which is passed to decrypt
     *                   cipherText
     * 
     * @return String This returns the plainText.
     */
    public String decrypt(String cipherText, Integer key)
    {
        StringBuilder plainText                     = new StringBuilder("");// used to store plain text
        RailFence[]   railFenceForPlacement         = new RailFence[key];   // used as a placeholder/template for railFence
        RailFence[]   railFence                     = new RailFence[key];   // used to store rail fence sequence
        Integer       currentIndexPosition          = 0;                    // used to store the current index position 0 - key-1 for railFenceForPlacement
        Integer       currentIndexPositionForDecode = 0;                    // used to store the current index position 0 - key-1 for railFence
        Integer       indexPointerForCharacter      = 0;                    // used to store the current pointing character in cipherText
        Boolean       incrementFlag                 = false;                // used as a flag to know wheter to increment/decrement value of currentIndexPosition
        Boolean       incrementFlagForDecode        = false;                // used as a flag to know wheter to increment/decrement value of currentIndexPositionForDecode
        
        // Initializing railFenceForPlacement and railFence
        for (int i = 0; i < key; i++)
        {
            railFenceForPlacement[i] = new RailFence();
            railFenceForPlacement[i].railFenceQueue = new LinkedList<Character>();
            railFence[i] = new RailFence();
            railFence[i].railFenceQueue = new LinkedList<Character>();
        }
        
        // Making a template for getting knowledge of length of characters in an index acts as a placeholder to railFence
        for (int i = 0; i < cipherText.length(); i++)
        {
            // If currentIndexPosition reaches to its full length then it needs to be decremented
            if (currentIndexPosition == key - 1)
            {
                incrementFlag = true;
            }
            // If currentIndexPosition reaches to its minimum length then it needs to be incremented
            else if (currentIndexPosition == 0)
            {
                incrementFlag = false;
            }
            
            // Adds a temporary to railFenceForPlacement sequence at a particular sequence
            railFenceForPlacement[currentIndexPosition].railFenceQueue.add('*');
            
            /*
             * If incrementFlag=true then currentIndexPosition has reached its maximum possible length, i.e. key-1 and
             * currentIndexPosition needs to be decremented now to statisfy the algorithm
             * 
             * If incrementFlag=false then currentIndexPosition has reached its minumum possible length, i.e. 0 and
             * currentIndexPosition needs to be incremented now to statisfy the algorithm
             */
            if (incrementFlag)
            {
                currentIndexPosition--;
            }
            else
            {
                currentIndexPosition++;
            }
        }
        
        // Iterating through railFenceForPlacement to make railFence character sequence
        for (int i = 0; i < key; i++)
        {
            RailFence        rail       = railFenceForPlacement[i]; // used to store current railFenceForPlacement
            Queue<Character> characters = rail.railFenceQueue;      // used to store queue of current railFenceForPlacement
            while (!characters.isEmpty())
            {
                // Adds cipherText indexPointerForCharacter character to railFence sequence at a particular location
                railFence[i].railFenceQueue.add(cipherText.charAt(indexPointerForCharacter));
                // polls the current character in Queue of railFenceForPlacement, making it empty
                railFenceForPlacement[i].railFenceQueue.poll();
                // Increments the count to point to next character in cipherText
                indexPointerForCharacter++;
            }
            
        }
        
        // Iterating through cipherText
        for (int i = 0; i < cipherText.length(); i++)
        {
            // If currentIndexPositionForDecode reaches to its full length, then it needs to be decremented
            if (currentIndexPositionForDecode == key - 1)
            {
                incrementFlagForDecode = false;
            }
            // If currentIndexPositionForDecode reaches to its minimum length, then it needs to be incremented
            else if (currentIndexPositionForDecode == 0)
            {
                incrementFlagForDecode = true;
            }
            
            RailFence        rail       = railFence[currentIndexPositionForDecode];// used to store current railFence
            Queue<Character> characters = rail.railFenceQueue;                     // used to store queue of current railFence
            
            // appends the polled character to plainText
            plainText.append(characters.poll());
            
            /*
             * If incrementFlag=true then incrementFlagForDecode has reached its maximum possible length, i.e. key-1 and
             * currentIndexPositionForDecode needs to be decremented now to satisfy the algorithm
             * 
             * If incrementFlag=false then incrementFlagForDecode has reached its minumum possible length, i.e. 0 and
             * currentIndexPositionForDecode needs to be incremented now to satisfy the algorithm
             */
            if (incrementFlagForDecode)
            {
                currentIndexPositionForDecode++;
            }
            else
            {
                currentIndexPositionForDecode--;
            }
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
     * <li>RailFenceCipher</li>
     * </ul>
     * 
     * @param args not used
     */
    public static void main(String[] args)
    {
        Integer         key;                                     // Created an object of Integer class for storing key to be entered by the user
        String          plainText;                               // Create an object of String class for storing plain text to be entered by the user
        Scanner         scan            = new Scanner(System.in);// Created an object of Scanner class for asking for user input.
        RailFenceCipher railFenceCipher = new RailFenceCipher(); // Created an object of RailFenceCipher for accessing it's method for encryption and decryption
        
        // Asking user to enter plain text
        System.out.println("Please Enter Plain Text:");
        plainText = scan.nextLine();
        
        // Asking user to enter integer key
        System.out.println("Please Enter Key:");
        key = scan.nextInt();
        
        // Accessing method 'encrypt' of RailFenceCipher class to encrypt plainText by key
        String cipherText = railFenceCipher.encrypt(plainText, key);
        // Printing cipher text
        System.out.println("Cipher Text: " + cipherText);
        
        // Accessing method 'decrypt' of RailFenceCipher class to decrypt cipherText by key
        String decryptedText = railFenceCipher.decrypt(cipherText, key);
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
 * Cipher Text: Acl'rs 0 atakAiestop t50 Mtdyt c oa:Po
 * 
 * Decrypted Text: Attack Alice's troops at 5:00 PM today
 */
