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


msg = input("Enter the plain All uppercase text: ")
key = input("Enter the key All uppercase text: ")

# encrypting the message
cipher = encrypt(msg, key)
print("The encrypted text is: ", cipher)

# decrypting the ciphar text
original = decrypt(cipher, key)
print("The decrypted(original) text is: ", msg)

'''
output:
Enter the plain All uppercase text: VIGENERECIPHER
Enter the key All uppercase text: SECRET
The encrypted text is:  NMIVRXJIEZTAWV
The decrypted(original) text is:  VIGENERECIPHER
'''
