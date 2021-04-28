/*
Vernam Cipher is a symmetric key cryptographic algorithm and is one of the 
transposition technique that converts plain text into ciphertext.
In this algorithm the size of the key and plain text must be same.
*/

import 'dart:io';

// Function to encrypt plain text using the key provided by user
String encrypt(String plain, String key) {
  int length = plain.length;
  List<int> encrypt = [];

  //Iterate through whole string and replace letters
  for (int index = 0; index < length; index++) {
    int plain_char = plain[index].codeUnitAt(0);
    int key_char = key[index].codeUnitAt(0);
    int encrypted_char = plain_char + key_char - 130;

    if (encrypted_char >= 26) {
      encrypted_char -= 26;
    }
    encrypted_char += 65;
    encrypt.add(encrypted_char);
  }
  String encrypted_string = String.fromCharCodes(encrypt);
  return encrypted_string;
}

// Function to decrypt message using key provided by the user
String decrypt(String encrypted, String key) {
  int length = encrypted.length;
  List<int> decrypt = [];

  //Iterate through whole string and replace letters
  for (int index = 0; index < length; index++) {
    int encrypted_char = encrypted[index].codeUnitAt(0);
    int key_char = key[index].codeUnitAt(0);
    int decrypted_char;

    if (encrypted_char >= key_char) {
      decrypted_char = encrypted_char - key_char + 65;
    } else {
      decrypted_char = encrypted_char - key_char + 91;
    }
    decrypt.add(decrypted_char);
  }
  String decrypted_string = String.fromCharCodes(decrypt);
  return decrypted_string;
}

// Main function with driver code
void main() {
  print("Enter 1 to ENCRYPT and 2 to DECRYPT : ");
  int choice = int.parse(stdin.readLineSync()!);
  print("USE UPPER CASE LETTERS ONLY");
  if (choice == 1) {
    print("Enter message to ENCRYPT : ");
    String toEncrypt = stdin.readLineSync()!;

    print("Enter KEY of same length as message :");
    String key = stdin.readLineSync()!;

    if (toEncrypt.length != key.length) {
      print("Length of key and message are not same! Try Again!");
      return;
    } else {
      // call encrypt function
      String encrypted = encrypt(toEncrypt, key);
      print("\nEncrypted message is $encrypted");
    }
  } else if (choice == 2) {
    print("Enter message to DECRYPT : ");
    String toDecrypt = stdin.readLineSync()!;

    print("Enter KEY of same length as message :");
    String key = stdin.readLineSync()!;

    if (toDecrypt.length != key.length) {
      print("Length of key and message are not same! Try Again!");
      return;
    } else {
      // call decrypt function
      String decrypted = decrypt(toDecrypt, key);
      print("\nDecrypted message is $decrypted");
    }
  } else {
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
USE UPPER CASE LETTERS ONLY
Enter message to ENCRYPT :
DART
Enter KEY of same length as message :
JAVA

Encrypted message is MAMT

2)
Enter 1 to ENCRYPT and 2 to DECRYPT :
2
USE UPPER CASE LETTERS ONLY
Enter message to DECRYPT :
MAMT
Enter KEY of same length as message :
JAVA

Decrypted message is DART

*/

