/* Vigenere Cipher in C# */

using System; 
      
class Vigenere_Cipher  
{ 
    static String generateKey(String str, String key) 
    { 
        int x = str.Length; 
        for (int i = 0; ; i++) 
        { 
            if (x == i) 
                i = 0; 
            if (key.Length == str.Length) 
                break; 
            key+=(key[i]); 
        } 
        return key; 
    } 
  
    static String cipherText(String str, String key) 
    { 
        String cipher_text="";     
        for (int i = 0; i < str.Length; i++) 
        { 
            int x = (str[i] + key[i]) %26;    
            x += 'A';     
            cipher_text+=(char)(x); 
        } 
        return cipher_text; 
    } 
  
    static String originalText(String cipher_text, String key) 
    { 
        String orig_text="";     
        for (int i = 0 ; i < cipher_text.Length && i < key.Length; i++) 
        { 
            int x = (cipher_text[i] - key[i] + 26) %26; 
            x += 'A'; 
            orig_text+=(char)(x); 
        } 
        return orig_text; 
    } 
    
    public static void Main(String[] args)  
    { 
        String str;; 
        String word; 
        Console.WriteLine("Enter a string:");
        str = Console.ReadLine(); 
            
        Console.WriteLine("Enter a pattern word:"); 
        word = Console.ReadLine(); 
            
        String key = generateKey(str, word); 
        String cipher_text = cipherText(str, key); 
    
        Console.WriteLine("Ciphertext: " + cipher_text); 
        Console.WriteLine("Decrypted Text: " + originalText(cipher_text, key)); 
    } 
} 

/* OUTPUT

Enter a string:                                                                                                                               
HACKINCODES                                                                                                                              
Enter a pattern word:                                                                                                                         
HACK                                                                                                                                     
Ciphertext: OAEUCAWYULS                                                                                                                  
Decrypted Text: HACKINCODES 
  
*/  