/*
The Affine cipher is a type of monoalphabetic substitution cipher. Here each of the letter in the message is mapped to a number,
then encrypted using a mathematical function. The numbers are then converted back to letters to form the ciphertext
*/

import 'dart:io';

/* Encrypted Message(x) = ( a * x + b ) mod m
here a and b are the keys provided by user at the time of encryption */
String encrypt(String plain, int key_a, int key_b) {
  int length = plain.length;
  List<int> encrypt = [];

  //Iterate through whole string and replace letters
  for(int index = 0; index < length; index++){
    int char = plain[index].codeUnitAt(0);

    // blank space is not encrypted
    if(char != 32){ 
      encrypt.add((key_a * (char - 65) + key_b)% 26 + 65);
    }
    else {
       encrypt.add(char);
    }
  }
  String encrypted_string = String.fromCharCodes(encrypt);
  return encrypted_string;
}

/* Decrypted Message(x) = a_inv ( x - b ) mod m
a_inv : modular multiplicative inverse of a modulo m
1 = (a * a_inv) mod m */
String decrypt(String plain, int key_a, int key_b) {
  int length = plain.length;
  List<int> decrypt = [];

  int a_inv = 0;

  for (int index = 0; index < 26; ++index) {
		if ((key_a * index) % 26 == 1) {
			a_inv = index;
			break;
		}
	}

  //Iterate through whole string and replace letters
  for(int index = 0; index < length; index++){
    int char = plain[index].codeUnitAt(0);

    // blank space is not decrypted
    if(char != 32){
      decrypt.add((a_inv* (char + 65 - key_b))% 26 + 65);
    }
    else {
       decrypt.add(char);
    }
  }
  String decrypted_string = String.fromCharCodes(decrypt);
  return decrypted_string;
}


void main() {
    print("Enter 1 to ENCRYPT and 2 to DECRYPT : ");
    int choice = int.parse(stdin.readLineSync()!);
    
    if(choice == 1){
      print('Enter the key A :');
      int key_a = int.parse(stdin.readLineSync()!);

      print('Enter the key B :');
      int key_b = int.parse(stdin.readLineSync()!);

      print("Enter message to ENCRYPT : ");
      String toEncrypt = stdin.readLineSync()!;

      // call encrypt function
      String encrypted = encrypt(toEncrypt, key_a, key_b);
      print("\nEncrypted message is $encrypted");
    }
    else if(choice == 2){
      print('Enter the key A :');
      int key_a = int.parse(stdin.readLineSync()!);

      print('Enter the key B :');
      int key_b = int.parse(stdin.readLineSync()!);

      print("Enter message to DECRYPT : ");
      String toDecrypt = stdin.readLineSync()!;

      // call decrypt function
      String decrypted = decrypt(toDecrypt, key_a, key_b);
      print("\nDecrypted message is $decrypted");
    }
    else{
      print("Please enter either 1 or 2");
    }

}

/*
Time Complexity: O(n)
Space Complexity: O(1)
 
Sample I/O:

1)
Enter 1 to ENCRYPT and 2 to DECRYPT :
1
Enter the key A :
11
Enter the key B :
21
Enter message to ENCRYPT :
OPENSOURCE

Encrypted message is TENILTHARN

2)
Enter 1 to ENCRYPT and 2 to DECRYPT :
2
Enter the key A :
11
Enter the key B :
21
Enter message to DECRYPT :
TENILTHARN

Decrypted message is OPENSOURCE
*/

