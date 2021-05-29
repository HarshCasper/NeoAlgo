/* RABIN KARP ALGO in c issue - 2943
Rabin-Karp is  pattern searching algorithm to find the pattern in a more efficient way, 
finds the hash value. When the hash value is matched, then only it tries to check each character */
#include <stdio.h>
#include<string.h>
void hash(char word[], char format[], int max, int len1 ,int pos, int num, int  initial){
 /* C hash value calculation for pattern and text*/
  for (int index = 0; index < len1; index++) {
    initial = (num *  initial +format[index]) % max;
/* getting initial updated with hash value*/
    pos = (num * pos + word[index]) % max;
/* getting pos updated with hash value*/
  }
}
/* checking whether the pattern is present or not*/
int checking(char word[], char format[], int len2 , int len1 ,int pos, int  initial){
    int Index;
  for ( int index = 0; index <= len2 - len1; index++) {
 /* we check both size and intial positions */
    if (pos ==  initial) {
      for (Index = 0; Index < len1; Index++) {
        if (format[index + Index] != word[Index])
          break;
      }
 /* checking the len1 and the Indexes are equal or not */
      if (Index == len1)
        printf( "PATTERN IS AT POSITION %d", index + 1 );
/*printing the position of word present in format text*/
    }
  }
}
int main() {
   char format[1000];
   printf("enter the string format ");
   /* giving input text in string format */
   gets(format);
    char word[1000];
    printf("give pattern ");
    /*giving the pattern for checking word in text*/
    gets(word);
  int max = 100,index=0,Index=0;
 /* getting the length stored in len1 for word*/ 
  int len1 = strlen(word);
/*getting the length stored in len2 for format string*/  
  int len2 = strlen(format);
  int pos= 0, initial = 0, valuehash = 1, num=10;
  for (index = 0; index < len1- 1; index++){
    valuehash = (valuehash * num) % max;
  }
    hash(word, format, max , len1,pos, num, initial );
    checking(word, format, len2, len1, pos,  initial);
 /*we are checking the intial with lenght1 and 2, if is less make it postive by adding max*/  
for (index = 0; index <= len2 - len1; index++) {
    if ( initial < 0)
         initial= ( max +initial);
 if (index <len2 - len1) {
       initial = (num * ( initial - format[index] * valuehash) +format[index +len1]) % max;
 /* we have final output in form of integer to specify the positin*/
    }
   }
}
/* input :
enter the string format abcdehu                                                                                                                                                      
give pattern ab  
output: PATTERN IS AT POSITION 1 
time complexity  O(n+m) for searching at instance
space complexity O(1)
*/ 
