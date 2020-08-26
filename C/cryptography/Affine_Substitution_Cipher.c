#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

// function declaration
int CalculateGCD(int);
int CalculateMultiplicativeInverse(int);

// C program to illustate Affine Cipher
int main() {
  int index, index_2, k, gcd, alpha, beta, num_msg[100], numcipher[100], numdecipher[100], decipher[100], alphaInverse;
  char msg[100], cipher[100];
  printf("Enter Cipher message : ");
  scanf("%[^\n]%*c", msg);
  //converting entered string to Capital letters
  for (index = 0, index_2 = 0; index < strlen(msg); index++) {
    if (msg[index] != ' ') {
      msg[index_2] = toupper(msg[index]);
      index_2++;
    } else {
      msg[index_2] = ' ';
      index_2++;
    }
  }
  msg[index_2] = '\0';
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
  for (index = 0; index < strlen(msg); index++) {
    if (msg[index] != ' ')
      num_msg[index] = msg[index] - 'A';
    else
      num_msg[index] = -20;
  }
  //Ciphering Process
  /* If numcipher is more than 25 .We need to convert and ensure that lie
    in between 0 and 25.(indicating Alphabets) A-0,B-1,C-2,.....Y-24,Z-25 */
  printf("Encrypted Message is :");
  for (index = 0; index < strlen(msg); index++) {
    if (num_msg[index] != -20) {
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
  printf("\nDecrypted Message is : ");
  for (index = 0; index < strlen(cipher); index++) {
    //Storing encrypted message in terms of ASCII and replacing spaces to -20
    if (cipher[index] != ' ')
      numdecipher[index] = cipher[index] - 'A';
    else
      numdecipher[index] = -20;
  }
  //For Decryption we need to find multiplicative inverse of  Alpha
  alphaInverse = CalculateMultiplicativeInverse(alpha);
  //Deciphering Process
  /*If numdecipher is more than 25 .We need to convert and ensure that 
     lie in between 0 and 25.(indicating Alphabets)A-0,B-1,C-2,.....Y-24,Z-25*/
  for (index = 0; index < strlen(cipher); index++) {
    if (numdecipher[index] != -20) {
      decipher[index] = (alphaInverse * (numdecipher[index] - beta)) % 26;
      if (decipher[index] < 0) {
        //To avoid negative numbers
        decipher[index] = decipher[index] + 26;
      }
      printf("%c", (decipher[index] + 'A'));
    } else {
      printf(" ");
    }
  }
  printf("\n");
  return 0;
} 
// main ends here
//Function definition 
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

int CalculateMultiplicativeInverse(int alpha) {
  int count, a_inv;
  for (count = 1; count <= alpha; count++) {
    a_inv = ((count * 26) + 1);
    if (a_inv % alpha == 0) {
      break;
    }
  }
  a_inv = a_inv / alpha;
  return (a_inv);
}

/* 
Input:
Enter the Cipher message : AFFINE CIPHER
Enter the value of key alpha : 17
Enter the value of key beta : 20
Encrypted Message is : UBBAHK CAPJKX
Decrypted Message is : AFFINE CIPHER
*/
