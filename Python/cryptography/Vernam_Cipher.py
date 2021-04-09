'''In Vernam cipher, also known as the One-Time Pad, the length of the
   plaintext, ciphertext, and key is the same. A number is assigned to
   each character of the plain-text and the key according to alphabetical
   order. Both the number are added and it is greater than 26, then %26 is
   taken to form the corresponding cipher-text.
'''

import sys

'''This function assigns a number from 
   [0-25] to characters [a-z] respectively.'''

def ascii_to_dec(text): 
    ascii_text = []
    text = text.lower()
    for i in text:
        ascii_text.append(ord(i) - 97)
    return ascii_text


'''This is the encryption function which takes plaintext 
   and keyword as input. It then converts both plaintext 
   and keyword to a number. Adds them. Take %26 to form 
   the corresponding ciphertext.'''

def encryption(message, keyword):
    pad = ascii_to_dec(keyword)
    mess = ascii_to_dec(message)
    enc = []
    for i in range(len(message)):
        character = chr(((mess[i] + pad[i]) % 26) + 97)
        if message[i].islower():
            enc.append(character)
        else:
            enc.append(character.upper())
    return ''.join(enc)

'''This is the decryption function which takes ciphertext
   and keyword as input. It then converts both ciphertext
   and keyword to a number. Subtracts them. Takes %26 to 
   form the corresponding plaintext'''

def decryption(ciphertext, keyword):
    pad = ascii_to_dec(keyword)
    cipher = ascii_to_dec(ciphertext)
    dec = []
    for i in range(len(ciphertext)):
        character = chr(((cipher[i] - pad[i]) % 26) + 97)
        if ciphertext[i].islower():
            dec.append(character)
        else:
            dec.append(character.upper())
    return ''.join(dec)

# Driver function
if __name__=='__main__':

    print("-"*20, "Vernam Cipher", "-"*20)
    print("1. Encrypt a plaintext")
    print("2. Decrypt a ciphertext")
    print("3. Exit")

    # Taking choice from user
    choice = int(input("Enter your choice: "))

    if(choice == 3):
        print("Exiting program.")
        sys.exit(0)

    # If the user chooses to encrypt a message
    elif(choice == 1):

        # Take plaintext and keyword as input
        print("Plaintext and key must be of same length.")
        plaintext = input("Enter a message you want to encrypt: ")
        key = input("Enter a key to encrypt the message : ")
        
        # Check if the length of keyword is same as plaintext or not
        if(len(plaintext) != len(key)):
            print("Please enter a valid input.")
            sys.exit(0)

        # Call the encrpytion function to encrypt the text
        encrypted_message = encryption(plaintext, key)

        # Print the encrypted message
        print("Encrypted message is", " "*13, ":", encrypted_message)

    # If the user chooses to decrypt a ciphertext
    elif(choice == 2):

        # Take ciphertext and keyword as input
        print("Ciphertext and key must be of same length.")
        ciphertext = input("Enter a ciphertext you want to decrypt: ")
        key = input("Enter a key to decrypt the ciphertext : ")

        # Check if length of keyword is equal to ciphertext or not
        if(len(ciphertext) != len(key)):
            print("Please enter a valid input.")
            sys.exit(0)

        # Call the decryption function to decrypt the ciphertext
        decrypted_message = decryption(ciphertext, key)

        # Print the decrypted ciphertext
        print("Decrypted message is", " "*16, ":", decrypted_message)

    # If an invalid input is provided
    else:
        print("Invalid choice.")

'''
Sample I/O:

a)
-------------------- Vernam Cipher --------------------
1. Encrypt a plaintext
2. Decrypt a ciphertext
3. Exit
Enter your choice: 1
Plaintext and key must be of same length.
Enter a message you want to encrypt: testcase
Enter a key to encrypt the message : mercurie
Encrypted message is               : fijvwrai

b)
-------------------- Vernam Cipher --------------------
1. Encrypt a plaintext
2. Decrypt a ciphertext
3. Exit
Enter your choice: 2
Ciphertext and key must be of same length.
Enter a ciphertext you want to decrypt: fijvwrai
Enter a key to decrypt the ciphertext : mercurie
Decrypted message is                  : testcase
'''

