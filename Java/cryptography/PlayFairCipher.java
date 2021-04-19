/*
  The Playfair cipher( Playfair square ) encrypts pairs of letters (digraphs),
  instead of single letters as in the simple substitution cipher. The Playfair
  is thus significantly harder to break since the frequency analysis used for 
  simple substitution ciphers does not work with it.
*/

import java.util.*;

class PlayFairCipher{
     
     //This function will form the 5x5 key Matrix 
     static void keyTable(String key,int size2,char[][] keyMatrix){

         int i=0;
         int j=0;
         int c = 0;
         char[] alph = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k','l',
         'm','n', 'o','p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
         int[] index = new int[26];

         //initializing the array to 0 as it stores garbage values
         for(int z=0;z<26;z++){
             index[z] = 0;
         }

         int[] hash = new int[size2];
         //marking the alphabets in key
         for(i=0;i<size2;i++){
            if(key.charAt(i) != 'j'){
               for(j=0;j<26;j++){
                   if(key.charAt(i) == alph[j]){
                      index[j] = 2;
                      hash[c] = j;
                      c++;
                   }
               }
            }
         }

        //marking alphabetic j
        index[9] = 1;
        i = 0;
        j = 0;

        //adding the marked alphabets  
        for(int k=0;k<size2;k++){

           if(index[hash[k]] == 2){
              index[hash[k]] -= 1;
              keyMatrix[i][j] = key.charAt(k);
              j++;
              if(j==5){
                 i++;
                 j=0;
              }
           }
        }

        //adding the remaining alphabets
        for(int k=0;k<26;k++){

           if(index[k] == 0){
              keyMatrix[i][j] = alph[k];
              j++;
              if(j==5){
                 i++;
                 j=0;
              }
           }
        }

     }

     
     /*this function searches for the characters of the digraph in key matrix 
       generated and gives their position*/ 
     static void search(char[][] keyMatrix,char x,char y,int[] list){

         //replacing j with i   
          if(x == 'j')
             x = 'i';
          else if(y =='j')
             y = 'i';

         //returning the positions of characters through list    
         for(int i=0;i<5;i++){
             for(int j=0;j<5;j++){
                 if(keyMatrix[i][j] == x){
                     list[0] = i;
                     list[1] = j;
                  }
                  else if(keyMatrix[i][j] == y){
                     list[2] = i;
                     list[3] = j;
                  }
              }
          }
     }

     //this function ciphers the plane text 
     static void cipher(String plaintext,char[][] keyMatrix,int size1){
          int i = 0;
          int[] list = new int[4];
          char[] plt = new char[size1];
          //cipher the plain text with the key matrix we built
          while(i<size1){
                 search(keyMatrix,plaintext.charAt(i),plaintext.charAt(i+1),list);
                 if(list[0] == list[2]){
                     plt[i]   = keyMatrix[list[0]][(list[1]+1)%5];
                     plt[i+1] = keyMatrix[list[0]][(list[3]+1)%5];
                  }
                  else if(list[1] == list[3]){
                     plt[i]   = keyMatrix[(list[0]+1)%5][list[1]];
                     plt[i+1] = keyMatrix[(list[2]+1)%5][list[1]]; 
                  }
                  else{
                     plt[i]   = keyMatrix[list[0]][list[3]];
                     plt[i+1] = keyMatrix[list[2]][list[1]]; 
                  }
                  i+=2;
          }   

          //printing the cipher 
          System.out.print("The cipher text is :");
          for(int k=0;k<size1;k++){
              System.out.print(plt[k]);
          } 
 
     }

     static int mod(int x){
      
       if(x<0){
         return 5+x;
       }
       else{
         return (x % 5);
       }
  
     }
 
     static void decrypt(String plaintext,char[][] keyMatrix,int size1){
          int i = 0;
          int[] list = new int[4];
          char[] plt = new char[size1];
          //cipher the plain text with the key matrix we built
          while(i<size1){
                 search(keyMatrix,plaintext.charAt(i),plaintext.charAt(i+1),list);
                 if(list[0] == list[2]){
                     plt[i]   = keyMatrix[list[0]][mod(list[1]-1)];
                     plt[i+1] = keyMatrix[list[0]][mod(list[3]-1)];
                 }
                 else if(list[1] == list[3]){
                     plt[i]   = keyMatrix[mod(list[0]-1)][list[1]];
                     plt[i+1] = keyMatrix[mod(list[2]-1)][list[1]]; 
                 }
                 else{
                     plt[i]   = keyMatrix[list[0]][list[3]];
                     plt[i+1] = keyMatrix[list[2]][list[1]]; 
                 }
                 i+=2;
          }

          //printing the decrypted text 
          System.out.print("The decrypted text is :");
          for(int k=0;k<size1;k++){
              System.out.print(plt[k]);
          }
 
     }   


     //this function will encript the plain-text to cipher in playfail cipher
     static void playFairCipher(String plaintext,String key){

         char[][] keyMatrix = new char[5][5];
         int size1 = plaintext.length();
         int size2 = key.length();

         //we adjust the input plane text to even size
         if(size1%2 != 0){
            plaintext += "z";
         } 
        
         size1 = plaintext.length(); 
 
         //generate keytable
         keyTable(key,size2,keyMatrix);
         //cipher the plaintext
         cipher(plaintext,keyMatrix,size1);    
     } 

     static void playFairCipherdecrypt(String plaintext,String key){

         char[][] keyMatrix = new char[5][5];
         int size1 = plaintext.length();
         int size2 = key.length();

         //generate keytable
         keyTable(key,size2,keyMatrix);
         //cipher the plaintext
         decrypt(plaintext,keyMatrix,size1);
     }

     public static void main(String[] args){
        
         Scanner scan = new Scanner(System.in);
         System.out.print("Enter 1 for encrypting and 2 for decrypting : ");
         char option = scan.nextLine().charAt(0); 

         if(option == '1') {
       
           System.out.print("Enter the key : ");
           //we take the key here
           String key = scan.nextLine();

           System.out.print("Enter the plain text for encryption: ");
           //we take the plaintext here
           String plaintext = scan.nextLine(); 
           scan.close();
           playFairCipher(plaintext,key);   
         }

         else if(option == '2'){
           
           System.out.print("Enter the key : ");
           //we take the key here
           String key = scan.nextLine();

           System.out.print("Enter the encrypted text for decryption: ");
           //we take the plaintext here
           String plaintext = scan.nextLine();
           scan.close();
           playFairCipherdecrypt(plaintext,key);
         }
     }
}

/*
     Sample I/O:

     Enter 1 for encrypting and 2 for decrypting : 1
     Enter the key : monarchy
     Enter the plain text for encryption: instruments    
     The cipher text is :gatlmzclrqtx

     Enter 1 for encrypting and 2 for decrypting : 2
     Enter the key : monarchy
     Enter the encrypted text for decryption: gatlmzclrqtx 
     The decrypted text is :instrumentsz
*/

