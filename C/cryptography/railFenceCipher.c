// This is Rail Fence Cipher algorithm works for key = 2. So when given a plain-text message, we cipher the given text using Rail Fence algorithm.  

#include<stdio.h>
#include<string.h>

int main( void ) {

  char input[100];

  printf( "Enter your plain text here :" );
  //we take the input here
  fgets( input , 100 , stdin );  

  int size = strlen( input );
  //we use this 2D array to store our input in a Zig-Zag manner
  char string [2][size];

  int i = 0;
  int count;

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

  return 0;

}
/*
 Sample I/O : 
   
 Enter your plain text here :Hello World
 Cipher :HloWrdel ol
 */

