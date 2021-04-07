/*Keyword cipher is a form of monoalphabetic substitution, where a keyword is used as the key. Now
  a encryption is formed of alphabets from [a-z] such that the first part of encrption contains 
  unique letters of the keyword and the rest are the remaining alphabets from [a-z]. That is,
  until the keyword is used up, whereupon the rest of the ciphertext letters are used in alphabetical 
  order, excluding those already used in the key.*/

import java.util.*;

public class KeyWord{
   
   //This function builds the encoder based on the key given as input
   static String encoder(char[] key){
       
        String str = "";
        int[] array = new int[26];

        for(int k=0;k<26;k++){
            array[k] = 0;  
        }
        
        //Iterating the key and building the encoder
        for(int i=0;i<key.length;i++){
          if(key[i] != ' '){
            if(array[key[i]-97] == 0){
                 str += key[i];
                 array[key[i]-97] = 1;                     
            }
          }
        }
         
        //Adding the remaining alphabetics
        for(int i=0;i<26;i++){
          if(array[i] == 0){
             array[i] = 1;
             str += (char)(i+97);
          }
        }
        
        return str;
   }
  
   //We cipher the text in this function
   static void cipher(String plaintext,String keyencoder){

        String output="";
        char space = ' ';
        char[] message = plaintext.toCharArray();        
       
        /*for every letter in the plaintext we replace it with
          the corresponding letter in the encoded string we use*/  
        for(int i=0;i<message.length;i++){
          if(message[i] == space)
             //adding the space if input has one
             output += message[i];
          else 
             output += keyencoder.charAt(message[i]-97);
        } 
        
        //printing the cipher text 
        System.out.println("The cipher text is :"+output); 
   }

   public static void main(String []args){
       
        String plaintext,key;
        
        Scanner scan = new Scanner(System.in);
        //We take plaintext and key here 
        System.out.print("Enter the Plaintext :");
        plaintext = scan.nextLine();
        
        System.out.print("Enter the key :");
        key = scan.nextLine(); 
        scan.close();

        //we call this function to cipher the plaintext
        cipher(plaintext,encoder(key.toCharArray()));
   }

}
/*
   Simple I/O :
   
   Enter the Plaintext :hello world
   Enter the key :asdf
   The cipher text is :gbkkn wnqkf    
*/

