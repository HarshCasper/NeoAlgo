'''
In rail-fence cipher, we are given a plaintext message and a
numeric key. It is also called a zigzag cipher and is a form
of transposition cipher. We re-arrange the order of alphabets
in the plaintext to obtain the ciphertext. In this algorithm,
the plaintext text is written diagonally downwards and upwards
alternatively. The length of the diagonal is the keyword given.
After each alphabet has been written, the individual rows are
combined to obtain the cipher-text.
'''

import sys

'''This is the encryption function, which takes plaintext
and key as input. It then returns the ciphertext.'''

def encryption(message, keyword):

    # This is the matrix to store the plaintext
    matrix = [[] for i in range(keyword)]

    i = 0
    count = 0

    ''' After going diagonally downwards keyword number of
        times, we need to go diangonally upwards. This rev
        list contains those values after which the plaintext
        is to be stored diagonally upwards.'''
    rev = []
    for j in range(len(message)):
        temp = keyword + j * (( 2 * keyword) - 2)
        if temp <= len(message):
            rev.append(temp)
    
    value = False
    
    while (i < keyword and count < len(message)):
        matrix[i].append(message[count])
        count = count + 1

        ''' As we find the reversing point, we set value to
            be true. So, that we can decrease the value of list
            index.'''
        if count in rev:
            value = True
            dec = keyword - 1
        
        ''' If value is true, we decrement the list index keyword
            number of times'''
        if value and dec > 0:
            i = i - 1
            dec = dec - 1

        # Else we go on storing the plaintext in downwards direction
        else:
            i = i + 1

    # This string stores the final ciphertext
    enc = ""

    # We read the value of matrix row by row to form the ciphertext
    for j in range(len(matrix)):
        enc += ''.join(matrix[j])
    
    # We return the ciphertext
    return enc

# Calling the driver function
if __name__=='__main__':

    # Taking plaintext and key as input from the user
    plaintext = input("Enter a message you want to encrypt : ")
    key       = int(input("Enter a key to encrypt the message  : "))

    if key <= 0:
        print("Enter a valid key.")
        sys.exit(0)

    elif key == 1:
        encrypted_message = plaintext
        print("Encrypted plaintext is", " "*12, ":", encrypted_message)
        sys.exit(0)

    ''' Calling the encryption function on the given paintext
        and key'''
    encrypted_message = encryption(plaintext, key)

    # Printing the ciphertext we got using the encryption method
    print("Encrypted plaintext is", " "*12, ":", encrypted_message)

'''
Sample I/O:
a)
    Enter a message you want to encrypt : This is Rail Fence Cipher
    Enter a key to encrypt the message  : 4
    Encrypted plaintext is              : Ts  rhi lFeCei Riecihsanp
b)
    Enter a message you want to encrypt : thisisrisky
    Enter a key to encrypt the message  : 1
    Encrypted plaintext is              : thisisrisky
'''

