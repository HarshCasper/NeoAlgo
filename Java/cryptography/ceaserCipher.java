import java.util.*;
class ceaserCipher
{
    static String encrypt( String str , int n )
    {
        String s1 = "";
        for(int indexI = 0; indexI < str.length(); indexI++)
        {
            s1 = s1 + (char)((str.charAt(indexI) - 65 + n) % 26 + 65);
        }
        return s1; 
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string to encrypt");
        String str = sc.nextLine();
        System.out.println("Enter a integer");
        int n = sc.nextInt();
        str = str.toUpperCase();
        String encryptedString, decryptedString;
        encryptedString =  encrypt(str,n);
        decryptedString =  encrypt(encryptedString,(26-n));
        System.out.println("Encrypted String " + encryptedString);
        System.out.println("Decrypted String " + decryptedString);
    }
}

/* 
Enter a string to encrypt
quick
Enter a integer
3
Encrypted String TXLFN
Decrypted String QUICK
*/
