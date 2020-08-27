// C program to illustate Affine Cipher

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
// function declaration
int CalculateGCD(int);
int CalculateMultiplicativeInverse(int);

int main() {
  int index, indx, k, gcd, alpha, beta, num_msg[100], numcipher[100], numdecipher[100], decipher[100], alphaInverse;
  char msg[size], cipher[100];
  printf("Input :\n");
  printf("Enter Cipher message : ");
  scanf("%[^\n]%*c", msg);
  //converting entered string to Capital letters
  for (index = 0, indx = 0; index < strlen(msg); index++) {
    if (msg[index] != ' ') {
      msg[indx] = toupper(msg[index]);
      indx++;
    } else {
      msg[indx] = ' ';
      indx++;
    }
  }
  //adding '\0' at end of string
  msg[indx] = '\0';
  printf("Enter the value of key alpha :");
  scanf("%d", & alpha);
  //Checking whether key alpha is in range of(1-25)
  if (alpha < 1 || alpha > 25) {
    printf("Alpha should lie in between 1 and 25\nTry again !\n");
    exit(0);
  }
  
  //  calling CalculateGCD function
  gcd = CalculateGCD(alpha);
  if (gcd != 1) {
    printf("Mandotory condition : gcd(alpha,26)=1 but \n gcd(%d,26)=%d\n Try again !\n", alpha, gcd);
    exit(0);
  }
  
  printf("Enter the value of key beta : ");
  scanf("%d", & beta);
  //Checking whether key beta is in range of(0-25)
  if (beta < 0 || beta > 25) {
    printf("Beta value should lie between 0 and 25\n");
    exit(0);
  }
  //Conditions Over
 //Storing message in terms of ASCII and replacing spaces used  to -20
  for (index = 0; index < strlen(msg); index++)
  {
    if (msg[index] != ' ')
      num_msg[index] = msg[index] - 'A';
    else
      num_msg[index] = -20;
  }
  
  //Ciphering Process
    printf("Output : \n");
    printf("Encrypted Message is : ");
     /* applying encryption formula ( alpha x + beta ) mod m {here x is num_msg[index] and m is 26} and added 'A' to  
         bring it in range of ASCII alphabet[ 65-90 | A-Z ] */
    for (index = 0; index < strlen(msg); index++) {
    if (num_msg[index] != -20)  {
      numcipher[index] = ((alpha * num_msg[index]) + beta) % 26;
      printf("%c", (numcipher[index] + 'A'));
      cipher[index] = numcipher[index] + 'A';
    } 
    else {
      printf(" ");
      cipher[index] = ' ';
    }
  }
  
  //Deciphering Process
    for (index = 0; index < strlen(cipher); index++) {
    //Storing encrypted message in terms of ASCII and replacing spaces to -20
    if (cipher[index] != ' ')
      numdecipher[index] = cipher[index] - 'A';
    else
      numdecipher[index] = -20;
    }
    //For Decryption we need to find multiplicative inverse of Alpha
    alphaInverse = CalculateMultiplicativeInverse(alpha);
    printf("\nDecrypted Message is : ");
   /*Applying decryption formula alpha^-1 ( x - beta ) mod m  {here x is numdecipher[index] and m is 26} and added 'A'  
     to bring it in range of ASCII alphabet[ 65-90 | A-Z ] */
    for (index = 0; index < strlen(cipher); index++) {
      if (numdecipher[index] != -20)  {
      decipher[index] = (alphaInverse * (numdecipher[index] - beta)) % 26;
      if (decipher[index] < 0) {
        //To avoid negative numbers
        decipher[index] = decipher[index] + 26;
      }
      printf("%c", (decipher[index] + 'A'));
    } else
      //adding of  white space
       printf(" ");
  }
  printf("\n");
  return 0;
}
// main ends here

//CalculateGCD Function definition 
int CalculateGCD(int alpha) {
  int GCD;
  int a = alpha;
  int m = 26;
  while (m != 0) {
    GCD = m;
    m = a % m;
    a = GCD;
  }
  return (a);
}

//CalculateMultiplicativeInverse Function definition
int CalculateMultiplicativeInverse(int alpha) {
  int count, a_inv;
  for (count = 1; count <= alpha; count++) {
    a_inv = ((count * 26) + 1);
    if (a_inv % alpha == 0)
    {
      break;
    }
  }
  a_inv = a_inv / alpha;
  return (a_inv);
}

/* 
 Input :
 Input size of array : 15
 Enter the Cipher message : AFFINE CIPHER
 Enter the value of key alpha : 17
 Enter the value of key beta : 20
 Output : 
 Encrypted Message is : UBBAHK CAPJKX
 Decrypted Message is : AFFINE CIPHER
 Time Complexity :  O(n)
 Space Complexity : O(1)
 */
