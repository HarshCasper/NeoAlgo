/**
 * XOR Cipher method is used for data encryption. It works upon a property of XOR operation according to which a ^ b = c, then c ^ b = a.
 * This encryption is done by taking a specific key which can be any character of your choosing.
 * Then XOR operation is performed on every character of the string with the key chosen which ends in the formation of encoded string.
 * The encoded string is decoded again by passing the encoded string again to the function which gives us back the original string.
 * 
 */

import java.util.*;

public class XORCipher{
    //this function is used for decoding as well as encoding of data
    static String process(String s){
        char[] charArray = s.toCharArray();
        char key = 'M'; //any key can be choosen
        String output = ""; //used to store output of function

        for(int i = 0; i < charArray.length; i++)
            output += (char)(charArray[i] ^ key); //XOR operation on character of string with key
        return output; 
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the string to be encrypted : ");
        String s = sc.next();

        String encoded = process(s); //storing the encoded data
        System.out.println("Data after encoding : "+ encoded);
        String decoded = process(encoded); //decoding the encoded data
        System.out.println("Data after decoding : "+ decoded);
        sc.close();
    }
}
/**
 * Complexity :
 * Time Complexity : O(N)
 * Space Complexity : O(N)
 *
 * Sample Output :
 * Enter the string to be encrypted : XORCipher
 * Data after encoding : $=%(?
 * Data after decoding : XORCipher
 */
