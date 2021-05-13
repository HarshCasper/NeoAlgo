/*
  The Playfair cipher( Playfair square ) encrypts pairs of letters (digraphs),
  instead of single letters as in the simple substitution cipher. The Playfair
  is thus significantly harder to break since the frequency analysis used for 
  simple substitution ciphers does not work with it.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Define size for input and key
#define SIZE 100

//This function will form the 5x5 key Matrix    
void keyTable(char key[],int size2,char keyMatrix[5][5]){
      
     int i,j;
     int c = 0;
     char alph[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm','n', 'o','p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
     int index[26];
     
     //initializing the array to 0 as it stores garbage values
     for(int z=0;z<26;z++){
         index[z] = 0;
     }

     int hash[size2]; 
     //marking the alphabets in key
     for(i=0;i<size2;i++){
         if(key[i] != 'j'){
            for(j=0;j<26;j++){
                if(key[i] == alph[j]){
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
            keyMatrix[i][j] = key[k];
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
int *search(char keyMatrix[5][5],char x,char y){

     static int list[4];

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
     return list;        
}    
     
//this function ciphers the plane text      
void cipher(char input[], char keyMatrix[5][5],int size1){
     
     int i = 0;
     int *list;
     //cipher the plain text with the key matrix we built
     while(i<size1){
         list = search(keyMatrix,input[i],input[i+1]);  
         if(list[0] == list[2]){
            input[i]   = keyMatrix[list[0]][(list[1]+1)%5];
            input[i+1] = keyMatrix[list[0]][(list[3]+1)%5];        
         }
         else if(list[1] == list[3]){
            input[i]   = keyMatrix[(list[0]+1)%5][list[1]];
            input[i+1] = keyMatrix[(list[2]+1)%5][list[1]]; 
         }
         else{
            input[i]   = keyMatrix[list[0]][list[3]];
            input[i+1] = keyMatrix[list[2]][list[1]]; 
         }
         i+=2;
     } 

}

//this function will encript the plain-text to cipher in playfail cipher
void playFairCipher(char input[],char key[]){
     
     char keyMatrix[5][5];
     int size1 = strlen(input)-1;
     int size2 = strlen(key)-1;
     
     //we adjust the input plane text to even size
     if(size1%2 != 0 ){
        input[size1++] = 'z';
        input[size1]   = '\0'; 
     }
     
     //generating key table
     keyTable(key,size2,keyMatrix);
     //cipher the plane text
     cipher(input,keyMatrix,size1); 
}

int main(void){

     char input[SIZE];
     printf("Enter the plain-text in small letters :");
     //we take plain text here
     fgets(input,100,stdin);
     printf("Enter the key :");
     char key[SIZE];
     //we take key here
     fgets(key,100,stdin);
     //calling the function to cipher the given plain text 
     playFairCipher(input,key); 

     printf("The Cipher text is :%s\n",input);
     return 0;
}
/*
     Sample I/O :

     Enter the plain-text in small letters :hello
     Enter the key :world
     The Cipher text is :kbekdv
*/
