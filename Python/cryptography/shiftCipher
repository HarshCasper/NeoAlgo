#working on the cipher text
def encrypting( s, key):
    # encrypt it and print the cipher text
    cipher_text = ''
    for character in s:
        if character is ' ':
            cipher_text += character
        elif character.isupper():
            #converting the character to the ascii A=65, adding the key and applying mod 26
            # ascii of character + key - 65 gives the shift 5. 5%26 gives 5, add it to the ascii of A
            cipher_text += chr((ord(character) + key - 65) % 26 + 65)
        else:
            #converting the character to the ascii a=97, adding the key and applying mod 26
            cipher_text += chr((ord(character) + key - 97) % 26 + 97)

    #decrypt the ciphertext to plain text, should match the input plaintext
    return (cipher_text)

#take input from the user- string and the key
plain_text = str(input("Enter the plain text: "))
#keeping the key flexible
key = int(input("Enter the key: "))
cipher_text = encrypting(plain_text, key)
print(cipher_text)
#for decrytpting, provide the cipher_text and then apply key as 26-n since its reverse of encrypting
check = encrypting(cipher_text, 26-key)
print(check)
