# Vigenere Cipher python code.

def encrypt(msg, key):
    cipher = ""
    n = len(key)
    i = 0
    for l in msg:
        # finding the index of the character
        p = int(ord(l) + ord(key[i % n])) % 26
        # to perform the shift with the key
        cipher += chr(p + ord('A'))
        i += 1
    return cipher


def decrypt(cipher, key):
    msg = ""
    n = len(key)
    j = 0
    for l in cipher:
        p = int(ord(l) - ord(key[j % n]) + 26) % 26
        msg += chr(p + ord('A'))
        j += 1
    return msg

if __name__=='__main__':
    
    # Use uppercase only
    choice = int(input("Choose 1 if you want to ENCRYPT or 2 if you want to DECRYPT: "))

    if(choice == 1):
        msg = input("Enter a plaintext message: ")
        key = input("Enter a keyword: ")

        # encrypting the message
        cipher = encrypt(msg, key)
        print("\nEncrypted message: ", cipher)

    elif(choice == 2):
        cipher = input("Enter a ciphertext: ")
        key = input("Enter a keyword: ")

        # decrypting the ciphar text
        original = decrypt(cipher, key)
        print("\nDecrypted message: ", original)

    else:
        print("\nInvalid choice.")

'''
Sample I/O:

1)
Choose 1 if you want to ENCRYPT or 2 if you want to DECRYPT: 1
Enter a plaintext message: NEOALGO
Enter a keyword: MARS

Encrypted message:  ZEFSXGF

2)
Choose 1 if you want to ENCRYPT or 2 if you want to DECRYPT: 2
Enter a ciphertext: ZEFSXGF
Enter a keyword: MARS

Decrypted message: NEOALGO

'''
