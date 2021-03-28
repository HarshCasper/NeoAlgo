'''
In Columnar Cipher, we are given a plaintext and a key. The plaintext
is written out in rows and the ciphertext is formed by reading out
columns one by one according to the order of the key given. Key is
converted to its corresponding numerical(Ex A-0, B-1, C-2, ...... , Z-25).
Cipher text is formed by reading the columns corresponding to the lowest
numerical value in the key to highest numerical value.
'''


def key_to_pad(keyword):
''' This function takes key as argument. It then sorts
    the key according to alphabetical order and return 
    the relative position of each keyword.'''
    
    sorted_keyword = sorted(keyword)
    pad = []
    for i in keyword:
        pad.append(sorted_keyword.index(i))
    return pad



def matrix_plaintext(plaintext, keyword):
''' This funcion takes plaintext and keyword as input.
    It forms a matrix where plaintext characters are
    stored in row wise fashion.'''

    ''' To form a completely filled matrix, we check if plaintext
        is a multiple of keyword or not. If it is not, the we add
        underscores at the end of the plaintext.'''
    if len(plaintext) % len(keyword) != 0:
        empty = len(keyword) - (len(plaintext) % len(keyword))
        for i in range(empty):
            plaintext += "_"

    # If plaintext has spaces, replace it with underscores
    for i in range(len(plaintext)):
        if(plaintext[i] == " "):
            plaintext = plaintext[:i] + "_" + plaintext[i + 1:]

    # The rows and columns of the matrix
    rows = len(plaintext) // len(keyword)
    columns = len(keyword)
    
    matrix = []

    count = 0

    # Adding plaintext to the matrix in row wise fashion
    for i in range(rows):
        column_matrix = []
        for j in range(columns):
            column_matrix.append(plaintext[count])
            count = count + 1
        matrix.append(column_matrix)

    # This function returns the matrix and the final plaintext
    return plaintext, matrix



def encryption(plaintext, keyword):
''' This is the actual encrption function. It takes plaintext
    and keyword as input. It then forms ciphertext by reading
    the matrix in a column wise fashion. It used the relative
    order of key to decide the order of chosing columns.'''

    order = key_to_pad(keyword)

    plaintext, matrix = matrix_plaintext(plaintext, keyword.lower())
    enc = []
    for i in range(len(keyword)):
        for j in range(len(plaintext) // len(keyword)):
            enc.append(matrix[j][order.index(i)])
    # Returning the encrypted plaintext
    return enc

# Driver function
if __name__=='__main__':

    # Taking plaintext and keyword as input from the user
    plaintext = input("Enter a message you want to encrypt: ")
    keyword = input("Enter a key to encrypt the message : ")

    # Calling the encryption function
    enc = encryption(plaintext, keyword.lower())

    ''' Replacing the underscores in the encrypted message
        with spaces'''
    for i in range(len(enc)):
        if enc[i] == "_":
            enc[i] = " "

    # Printing the final encrypted message
    print("Encrypted plaintext message is", " "*3, ":",  ''.join(enc))

'''
Sample I/O:

    Enter a message you want to encrypt: This is a plaintext
    Enter a key to encrypt the message : Venus
    Encrypted plaintext message is     : hslei ax  n saitTipt
'''

