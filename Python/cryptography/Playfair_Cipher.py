'''
Playfair Cipher Encryption
The Playfair cipher or Playfair square or Wheatstone-Playfair cipher
is a manual symmetric encryption technique and was the first literal
digram substitution cipher. The scheme was invented in 1854 by Charles
Wheatstone but bore the name of Lord Playfair for promoting its use.
It was used for tactical purposes by British forces in the Second Boer War
and in World War I and for the same purpose by the Australians during World War II.
This was because Playfair is reasonably fast to use and requires no special equipment.
'''
import re
import sys


def create_matrix(key_text):
    '''
    This function is used to generate a 5 x 5 matrix of the english alphabets
    using the key provided. This key matrix is used for encrypting/decrypting
    the input text.
    :param key_text: input key string
    :type str

    :return final_matrix: 5x5 matrix with all the english alphabets except j
    :type list
    '''
    lst = []
    # some processing before creating matrix
    key_text = key_text.replace(' ', '')
    key_text = key_text.lower()
    # remove all the duplicate characters from the key
    for k in key_text:
        if k not in lst:
            lst.append(k)

    # adding remaining english alphabets to the matrix
    alphabets = "abcdefghiklmnopqrstuvwtxyz"
    for alphabet in alphabets:
        if alphabet not in lst:
            lst.append(alphabet)

    # creating sub-list of length 5 to form a 5x5 matrix from the list of
    # 25 english alphabets
    final_matrix = []
    for i in range(0, len(lst), 5):
        if i + 5 <= len(lst):
            tmp = lst[i:i+5]
            final_matrix.append(tmp)

    return final_matrix


def clean_text(text):
    '''
    perform generic cleaning of the plaintext before encryption i.e.
    removal of special charcters, numbers, punctuations, etc.
    :param text: plaintext for encryption
    :type str

    :return txt: processed clean text ready for encrption
    :type str
    '''
    txt = re.sub(r'[^\w]', '', text)
    txt = re.sub(r'\_', '', txt)
    return txt


def create_digraphs(text):
    '''
    This function is responsible to creating digraphs of the input plaintext.
    The entire string is split into pairs of two characters. In case a
    pair has same characters, the first occurence of char is paired with 'X' and
    the second occurence of char is paired with the next char in the plaintext.

    :param text: input plaintext for encryption
    :type str

    :return digraphs: a list of all characters in the plaintext in pairs of two
    :type list
    '''
    digraphs = []
    # list to keep track of extra 'x' added in the input text
    flag = [True for x in text]
    i = 0
    # if the text has odd number of characters, add an 'x' to make the count even
    if len(text) % 2 != 0:
        text = text + 'x'
        flag.extend([False])

    while i + 1 < len(text):
        # checking if the current char and next char are same
        if text[i] == text[i+1] and flag[i]:
            # appending 'x' in place of repeating char
            digraphs.append([text[i], 'x'])
            new_text = text[:i+1] + 'x' + text[i+1:]
            if len(new_text) % 2 != 0:
                text = text + 'x'
                flag.extend([False])
            i = i + 1
        else:
            # pairing the current and next character
            if flag[i] or flag[i+1]:
                digraphs.append([text[i], text[i+1]])
            i = i + 2
    return digraphs


def get_location(elem, matrix):
    '''
    This function returns the row index and column index of an element
    in the matrix.
    :param elem: element whose position is to be searched
    :type str
    :param matrix: the 2D list in which the element is to be searched
    :type list

    :return w_col: column index
    :type int
    :return w_row: row index
    :type int
    '''
    for i, row in enumerate(matrix):
        if elem in row:
            w_row = i
            w_col = row.index(elem)
    return w_row, w_col


def get_new_pos(coor, method='de'):
    '''
    This function is used to calculate the position of the encrypted/decrypted char
    based on the method argument value.
    :param coor: coordinate wrt which the new position is to be calculated
    :type int
    :param method: defines whether the new position is for encryption or decryption task
    :type str

    :return int
    '''
    if method == 'en':
        if coor + 1 < 5:
            return coor + 1
        else:
            return 0
    else:
        if coor - 1 < 0:
            return 4
        else:
            return coor - 1


def encrypt(digraphs, matrix):
    '''
    This function is resposible for performing the encryption task. With the help of
    digraphs of the plain text and key matrix of the encryption key, it calculates
    the encrypted pair for every pair in diagraph based on the positions of the chars.

    :param digraphs: 2D list containing the plain text in the form of pairs
    :type list
    :param matrix: 2D list with 25 english alphabets formed using the key
    :type list

    :return encrypted_text: the encrypted form of plain text
    :type str
    '''
    encrypted_text = ''
    for pair in digraphs:
        # finding the location of chars in digraph pairs in key matrix
        first, last = pair
        first_row, first_col = get_location(first, matrix)
        last_row, last_col = get_location(last, matrix)
        by = ''
        # if both the chars in the pair are in same row of key matrix
        if first_row == last_row:
            en_first_col = get_new_pos(first_col, method='en')
            en_last_col = get_new_pos(last_col, method='en')
            by = 'col'
        # if both the chars in the pair are in the same column of key matrix
        elif first_col == last_col:
            en_first_row = get_new_pos(first_row, method='en')
            en_last_row = get_new_pos(last_row, method='en')
            by = 'row'
        # if both the row and column for the chars in the pair are different
        else:
            en_first_col = last_col
            en_last_col = first_col
            by = 'col'
        # find the encrypted text based on the new char positions
        if by == 'col':
            encrypted_text += matrix[first_row][en_first_col]
            encrypted_text += matrix[last_row][en_last_col]
        elif by == 'row':
            encrypted_text += matrix[en_first_row][first_col]
            encrypted_text += matrix[en_last_row][last_col]

    return encrypted_text


def decrypt(digraphs, matrix):
    '''
    This function is resposible for performing the decryption task. With the help of
    digraphs of the encrypted text and key matrix of the decryption key, it calculates
    the decrypted pair for every pair in diagraph based on the positions of the chars.

    :param digraphs: 2D list containing the encrypted text in the form of pairs
    :type list
    :param matrix: 2D list with 25 english alphabets formed using the key
    :type list

    :return encrypted_text: the decrypted form of encrypted text
    :type str
    '''
    encrypted_text = ''
    for pair in digraphs:
        # finding the location of chars in digraph pairs in key matrix
        first, last = pair
        first_row, first_col = get_location(first, matrix)
        last_row, last_col = get_location(last, matrix)
        by = ''
        # if both the chars in the pair are in same row of key matrix
        if first_row == last_row:
            en_first_col = get_new_pos(first_col)
            en_last_col = get_new_pos(last_col)
            by = 'col'
        # if both the chars in the pair are in the same column of key matrix
        elif first_col == last_col:
            en_first_row = get_new_pos(first_row)
            en_last_row = get_new_pos(last_row)
            by = 'row'
        # if both the row and column for the chars in the pair are different
        else:
            en_first_col = last_col
            en_last_col = first_col
            by = 'col'
        # find the decrypted text based on the new char positions
        if by == 'col':
            encrypted_text += matrix[first_row][en_first_col]
            encrypted_text += matrix[last_row][en_last_col]
        elif by == 'row':
            encrypted_text += matrix[en_first_row][first_col]
            encrypted_text += matrix[en_last_row][last_col]

    return encrypted_text


def main():
    option = 3
    while option != 0:
        option = int(input('Enter 1 for encrypting, 2 for decrypting and 0 to exit: '))
        # Input for encryption task
        if option == 1:
            key = input('Enter the key for encryption/decryption: ')
            key_matrix = create_matrix(key)
            text = input("Enter the plain text for encryption: ")
            plain_text = clean_text(text)
            digraphs = create_digraphs(plain_text)
            encrypted_text = encrypt(digraphs, key_matrix)
            print("Your Encrypted text is ", encrypted_text)

        # Input for decryption task
        elif option == 2:
            key = input('Enter the key for encryption/decryption: ')
            key_matrix = create_matrix(key)
            en_text = input("Enter the encrypted text for decryption: ")
            digraphs = create_digraphs(en_text)
            decrypted_text = decrypt(digraphs, key_matrix)
            print("Your Decrypted text is ", decrypted_text)
        elif option == 0:
            sys.exit(0)


if __name__ == '__main__':
    main()

'''
Sample I/O
1. plain text: Attack at dawn
key: Gravity Falls
encrypted text: GFFGBMGFNFAW
2. plain text: My name is khan
key: SRK
encrypted text: TAMBLFHRSLBM
3. plain text: life is beautiful
key: randomkey
encrypted text: TCGKHTMYRVZTCVSU
'''
