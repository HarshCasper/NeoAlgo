'''
Keyword cipher is a form of monoalphabetic substitution. Now a encryption is 
pad is formed of alphabets from [a-z] such that the first part of encrption 
contains unique letters of the key and the rest are the remaining alphabets 
from [a-z]. That is, until the key is used up, whereupon the rest of the 
ciphertext letters are used in alphabetical order, excluding those already 
used in the key.
'''

import string

''' This function maintains a list of characters occuring in the key.
    It counts each character once. It returns the list.'''
def find_unique_char(key):

 
    unique = []
    for i in key:
        if((i not in unique) and i != " "):
            unique.append(i)
    return unique

''' This function forms the padding. It takes output of the above
    function and then appends remaining of [a-z] in the list
    and returns the list.'''
def find_pad(pad_key):


    # Calls the above function
    key = find_unique_char(pad_key)

    # This contains all character from a to z
    ALPHABET = string.ascii_lowercase

    for i in ALPHABET:
        if i not in key:
            key.append(i)
    return key

''' This function takes plaintext and key as input.
    It pads the plaintext using the keyword formed
    by calling above function.'''
def encrypt_plaintext(message, key):

    
    ALPHABET = string.ascii_lowercase
    enc = ""
    pad = find_pad(key)

    ''' This loop iterates through the whole message.
         Find index of each character in normal [a-z].
         Replaces it by the character present at the
         same index of pad.'''
    for i, j in enumerate(message):
        if j != " ":
            if j.islower():
                index = ALPHABET.index(j)
                enc += pad[index]
            else:
                index = ALPHABET.index(j.lower())
                enc += pad[index].upper()
        else:
            enc += " "
    return enc


# Calling the driver function
if __name__ == '__main__':

    # Taking plaintext as input from the user
    plaintext = input("Enter a message you want to encrypt    : ")

    # Taking keyword as input from the user
    keyword = input("Enter a keyword to encrypt the message : ")

    # Calling the function and printing the encrypted message
    encrypt = encrypt_plaintext(plaintext, keyword.lower())
    print("Encrypted plaintext is                 :", encrypt)


'''
Sample I/O:

1.)    Enter a message you want to encrypt    : This is a sample message
       Enter a keyword to encrypt the message : Mercury
       Encrypted plaintext is                 : Qbdp dp m pmilhu iuppmau

2.)    Enter a message you want to encrypt    : It can Encrypt any MesSage
       Enter a keyword to encrypt the message : KeyStrong
       Encrypted plaintext is                 : Gp ykf Tfylxip kfx DtmMkot
'''
