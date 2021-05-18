/*
Caeser cipher is  a type of substitution cipher, i.e., each letter of 
a given text is replaced by a letter some fixed number[key] of positions down the alphabet
*/

import 'dart:io';

/* Encrypts the message by replacing individual
letters by a letter 'key' places down the alphabet */
String encrypt(String plain, int key) {
  int length = plain.length;
  List<int> encrypt = [];

  //Iterate through whole string and replace letters
  for(int index = 0; index < length; index++){
    int char = plain[index].codeUnitAt(0);

    if(plain[index].codeUnitAt(0) <= 91){
      encrypt.add(((char-65) + key) % 26 + 65);
    }
    else if(plain[index].codeUnitAt(0) >= 97){
       encrypt.add(((char-97) + key) % 26 + 65);
    }
  }
  String encrypted_string = String.fromCharCodes(encrypt);
  return encrypted_string;
}

/* Decrypts the message by replacing individual
letters by a letter 'key' places up the alphabet */
String decrypt(String plain, int key) {
  int length = plain.length;
  List<int> decrypt = [];

  //Iterate through whole string and replace letters
  for(int index = 0; index < length; index++){
    int char = plain[index].codeUnitAt(0);
  
    if(plain[index].codeUnitAt(0) <= 91){
      decrypt.add(((char-65) - key) % 26 + 65);
    }
    else if(plain[index].codeUnitAt(0) >= 97){
       decrypt.add(((char-97) - key) % 26 + 65);
    }
  }
  String decrypted_string = String.fromCharCodes(decrypt);
  return decrypted_string;
}


void main() {
    print("Enter 1 to ENCRYPT and 2 to DECRYPT : ");
    int choice = int.parse(stdin.readLineSync()!);
    
    if(choice == 1){
      print("Enter message to ENCRYPT : ");
      String toEncrypt = stdin.readLineSync()!;

      print("Enter key value:");
      int key = int.parse(stdin.readLineSync()!);

      // call encrypt function
      String encrypted = encrypt(toEncrypt, key);
      print("\nEncrypted message is $encrypted");
    }
    else if(choice == 2){
      print("Enter message to DECRYPT : ");
      String toDecrypt = stdin.readLineSync()!;

      print("Enter key value:");
      int key = int.parse(stdin.readLineSync()!);

      // call decrypt function
      String decrypted = decrypt(toDecrypt, key);
      print("\nDecrypted message is $decrypted");
    }
    else{
      print("Please enter either 1 or 2");
    }

}

/*
Time Complexity: O(n)
Space Complexity: O(n)
 
Sample I/O:

1)
Enter 1 to ENCRYPT and 2 to DECRYPT :
1
Enter message to ENCRYPT :
NEOALGO
Enter key value:
9

Encrypted message is WNXJUPX

2)
Enter 1 to ENCRYPT and 2 to DECRYPT :
2
Enter message to DECRYPT :
WNXJUPX
Enter key value:
9

Decrypted message is NEOALGO
*/


