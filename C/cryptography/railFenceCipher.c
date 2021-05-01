/* The rail fence cipher (also called a zigzag cipher) is a form of transposition cipher.
   It derives its name from the way in which it is encoded. Given a plain-text message and a numeric key, it cipher the
   given text using Rail Fence algorithm(here key == 2). 
*/

#include<stdio.h>
#include<string.h>
  
void cipher(char input[100],int size){
   
  int i = 0;
  int count;
  char string [2][size]; 
  //This is where we cipher the text and store in the 2D array
    while( i < size ) {
    
         for ( count = 0 ; count < 2 ; count++ ) {
              string[count][i] = input[i];
              i++;
         }
    
    }
    //we store the plain text after cipher in this char array 
    char output[size];
    int k = 0;
    int b;
    //Concatenating all the charecters we stored row wise
    while( k < size ) {
  
         for( int a = 0 ; a < 2 ; a++ ) {
              b = a;       
              while( b < size ) { 
                  output[k] = string[a][b];
                  k++;
                  b = b+2;
    
              }
  
         }
  
    }
    printf( "Cipher :" );
    //Printing the cipher after the concatenation
    for( int c = 0; c < size ; c++ ) {
  
         if( output[c] != '\n' )  
             printf("%c", output[c] );
    
    }
}


int main( void ) {
  
  char input[100];
  printf( "Enter your plain text here :" );
  //we take the input here
  fgets( input , 100 , stdin );  
  int size = strlen( input );
    
  cipher(input,size);
  return 0;
} 
/*
 Sample I/O : 
   
 Enter your plain text here :Hello World
 Cipher :HloWrdel ol

 Time complexity  : O(n)  
 Space complexity : O(n)
 */
